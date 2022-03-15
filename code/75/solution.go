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

func gcd(a, b int64) int64 {
	if a == 0 {
		return b
	}
	return gcd(b%a, a)
}

const upper = int64(1500000)

var cnt = map[int64]int64{}

func main() {
	for m := int64(2); m*m < upper; m++ {
		for n := int64(1); n < m; n++ {
			a := m*m - n*n
			b := 2 * n * m
			c := m*m + n*n
			if a+b+c > upper {
				break
			}
			if gcd(a, gcd(b, c)) != 1 {
				continue
			}
			base := a + b + c
			for i := base; i <= upper; i += base {
				cnt[i] = cnt[i] + 1
			}
		}
	}
	ans := int64(0)
	for _, v := range cnt {
		if v == 1 {
			ans++
		}
	}
	fmt.Println(ans)
}
