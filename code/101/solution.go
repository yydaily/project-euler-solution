package main /*{{{*/

import (
	"fmt"
	"reflect"
)

const (
	e4  = int64(10000)
	e5  = int64(100000)
	e6  = int64(1000000)
	e7  = int64(10000000)
	e8  = e4 * e4
	mod = int64(1e9 + 7)
)

func add(list ...interface{}) int64 { /*{{{*/
	if len(list) == 0 {
		return 0
	}
	ret := int64(0)
	for _, i := range list {
		buf := int64(0)
		switch reflect.TypeOf(i).String() {
		case "int":
			buf = int64(i.(int))
		case "int64":
			buf = i.(int64)
		}
		ret = (ret + buf) % mod
	}
	return ret
} /*}}}*/
func mul(list ...interface{}) int64 { /*{{{*/
	if len(list) == 0 {
		return 0
	}
	ret := int64(1)
	for _, i := range list {
		buf := int64(0)
		switch reflect.TypeOf(i).String() {
		case "int":
			buf = int64(i.(int))
		case "int64":
			buf = i.(int64)
		}
		buf %= mod
		base := ret
		ret = 0
		for buf > 0 {
			if (buf & 1) == 1 {
				ret = add(ret, base)
			}
			base = add(base, base)
			buf >>= 1
		}
	}
	return ret
} /*}}}*/
func qpow(a, b int64) int64 { /*{{{*/
	ret := int64(1)
	for b > 0 {
		if (b & 1) == 1 {
			ret = mul(ret, a)
		}
		a = mul(a, a)
		b >>= 1
	}
	return ret
} /*}}}*/
/*}}}*/

func gen(v []int64) []int64 {
	if len(v) <= 2 {
		v = append(v, v[len(v)-1]*2-v[0])
		return v
	}
	diff := []int64{}
	for i := 1; i < len(v); i++ {
		diff = append(diff, v[i]-v[i-1])
	}
	diff = gen(diff)
	v = append(v, v[len(v)-1]+diff[len(diff)-1])
	return v
}
func cal(a int64) int64 {
	ans := int64(1)
	base := int64(1)
	for i := 1; i <= 10; i++ {
		base *= -a
		ans += base
	}
	return ans
}
func main() {
	ans := int64(0)
	v := []int64{}
	for i := int64(1); ; i++ {
		now := cal(i)
		v = append(v, now)
		diff := gen(v)
		if diff[len(diff)-1] == cal(i+1) {
			break
		}
		fmt.Println(diff[len(diff)-1], cal(i+1))
		ans += diff[len(diff)-1]
	}
	fmt.Println(ans)
}
