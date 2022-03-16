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

func main() {
	ans1 := int64(0)
	k, t := int64(8), int64(15)
	for true {
		n := k*2 + 1
		S := n*3 - 1
		if S > 1e9 {
			break
		}
		if S > 0 {
			ans1 += S
			fmt.Println(n, n, n-1)
		}
		k, t = -2*k-t-2, -3*k-2*t-2
	}

	ans2 := int64(0)
	k, t = 2, 4
	for true {
		n := k*2 + 1
		S := n*3 + 1
		if S > 1e9 {
			break
		}
		if S > 0 {
			ans2 += S
			fmt.Println(n, n, n+1)
		}
		k, t = -2*k-t-1, -3*k-2*t-1
	}
	fmt.Println(ans1 + ans2)
}
