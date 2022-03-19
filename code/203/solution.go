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

var num = [60][60]int64{}
var ans = int64(0)
var m = map[int64]bool{}

func cal(a int64) {
	if m[a] {
		return
	}
	m[a] = true
	cc := a
	for i := int64(2); i*i <= a; i++ {
		if a%i == 0 {
			a /= i
			if a%i == 0 {
				return
			}
		}
	}
	ans += cc
}

func main() {
	num[1][1] = 1
	for i := int64(2); i <= 51; i++ {
		for j := int64(2); j <= i; j++ {
			if j == 1 || j == i {
				num[i][j] = 1
			} else {
				num[i][j] = num[i-1][j] + num[i-1][j-1]
			}
			cal(num[i][j])
		}
	}
	fmt.Println(ans)
}
