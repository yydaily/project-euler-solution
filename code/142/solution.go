package main /*{{{*/

import (
	"fmt"
	"math"
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

var sqr = [e7]bool{}

func main() {
	for i := 1; i*i < int(e7); i++ {
		sqr[i*i] = true
	}
	for x := 6; x < int(e7); x++ {
		v := []int{}
		for j := int(math.Sqrt(float64(x))) + 1; j*j < int(e7); j++ {
			if j*j >= x*2 {
				break
			}
			if sqr[x*2-j*j] {
				v = append(v, j*j-x)
			}
		}
		for i := range v {
			for j := i + 1; j < len(v); j++ {
				if sqr[v[i]+v[j]] && sqr[v[j]-v[i]] {
					fmt.Println(x, v[j], v[i])
					fmt.Println(x + v[i] + v[j])
					return
				}
			}
		}
	}
}
