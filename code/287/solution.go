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

const N = int64(24)
const limit = int64(1 << (2*N - 2))

func check(x, y int64) int64 {
	xx := x - (1 << (N - 1))
	yy := y - (1 << (N - 1))
	if xx*xx+yy*yy <= limit {
		return 1
	}
	return 0
}
func dfs(x, y, length int64) int64 {
	if length == 1 {
		return 1
		return 2
	}
	xx, yy, sub_len := x+length-1, y+length-1, length>>1
	cnt := check(x, y) + check(xx, y) + check(x, yy) + check(xx, yy) + check(x+sub_len-1, y+sub_len-1)
	if cnt == 5 || cnt == 0 {
		return 1
		return 2
	}
	return 1 + dfs(x, y+sub_len, sub_len) + dfs(x+sub_len, y+sub_len, sub_len) + dfs(x, y, sub_len) + dfs(x+sub_len, y, sub_len)
}
func main() {
	fmt.Println(dfs(0, 0, 1<<N))
}
