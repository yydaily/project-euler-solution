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
	mod = 1e9 + 87
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
		ret = (buf * ret) % mod
	}
	return ret
} /*}}}*/
/*}}}*/

var p = [e7 + 10]bool{}
var l = [e7 + 10]int64{}
var cnt = [e7 + 10]int64{}
var inv = [4*e7 + 10]int64{}

func init() { /*{{{*/
	inv[1] = 1
	for i := int64(2); i <= 4*e7; i++ {
		inv[i] = mul(add(mod, mod-mod/i), inv[mod%i])
	}
	for i := int64(2); i <= e7; i++ {
		if !p[i] {
			for j := i; j <= e7; j += i {
				l[j] = i
				p[j] = true
			}
		}
	}
} /*}}}*/

var base = int64(1)

func cal(a int64) int64 {
	for a != 1 {
		x := add(1, mul(2, cnt[l[a]]))
		base = mul(base, inv[x])
		base = mul(base, add(1, mul(2, cnt[l[a]]), 2))
		cnt[l[a]]++
		a /= l[a]
	}
	return base
}
func main() {
	ans := int64(0)
	for i := int64(2); i <= e7; i++ {
		ans = add(ans, cal(i))
	}
	fmt.Println(ans)
}
