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

func sqrt(a int64) int64 {
	x := math.Sqrt(float64(a))
	return int64(x)
}

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

func cal(a int) float64 {
	ret := float64(1)
	for i := 1; i <= a; i++ {
		now := float64(2) * float64(i) / float64(a+1)
		ret *= math.Pow(now, float64(i))
	}
	return ret
}
func main() {
	ret := int64(0)
	for i := 2; i <= 15; i++ {
		ret += int64(cal(i))
	}
	fmt.Println(ret)
}
