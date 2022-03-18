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

var m = map[int]map[int]map[int]int64{}

func dfs(length, now, next int) int64 {
	if m[length] == nil {
		m[length] = map[int]map[int]int64{}
	}
	if m[length][now] == nil {
		m[length][now] = map[int]int64{}
	}
	if m[length][now][next] > 0 {
		return m[length][now][next]
	}
	if next == 10 || next == -1 {
		return 1
	}
	ret := int64(0)
	for i := 0; i <= length; i++ {
		ret += dfs(length-i, next, next*2-now)
	}
	m[length][now][next] = ret
	return ret
}

const l = 100

func main() {
	ans := int64(-10 * l)
	for i := 1; i <= l; i++ {
		ans += dfs(i, 1, 2)
		ans += dfs(i, 9, 8)
	}
	fmt.Println(ans)
}
