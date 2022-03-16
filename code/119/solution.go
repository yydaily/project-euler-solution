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

var s = []int64{}

func check(base int64) bool { /*{{{*/
	cc := base
	x := int64(0)
	for base > 0 {
		x += base % 10
		base /= 10
	}
	if x == 1 {
		return false
	}
	for cc%x == 0 {
		cc /= x
	}
	return cc == 1
} /*}}}*/

func main() {
	for i := int64(2); i <= 90; i++ { /*{{{*/
		base := i
		for base <= 10 {
			base *= i
		}
		for base <= 1e17 {
			if check(base) {
				s = append(s, base)
			}
			base *= i
		}
	} /*}}}*/
	sort.Slice(s, func(i, j int) bool {
		return s[i] < s[j]
	})
	cnt := 1
	for i := 2; ; i++ {
		if s[i] == s[i-1] {
			continue
		}
		cnt++
		if cnt == 30 {
			fmt.Println(s[i])
			break
		}
	}
}
