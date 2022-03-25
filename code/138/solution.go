package main /*{{{*/

import (
	"fmt"
	"reflect"
	"sort"
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
	v := []int64{}
	k, L := int64(0), int64(1)
	for i := 0; i < 14; i++ {
		k, L = -9*k-4*L-4, -20*k-9*L-8
		if L > 0 {
			v = append(v, L)
		}
	}

	k, L = 0, -1
	for i := 0; i < 14; i++ {
		k, L = -9*k-4*L+4, -20*k-9*L+8
		if L > 0 {
			v = append(v, L)
		}
	}

	sort.Slice(v, func(i, j int) bool {
		return v[i] < v[j]
	})
	ans := int64(0)
	for i := 0; i < 12; i++ {
		ans += v[i]
	}
	fmt.Println(ans)
}
