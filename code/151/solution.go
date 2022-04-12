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
	e9  = e8 * 10
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
const length = 4

var a = [length]int{1, 1, 1, 1}

func cal(a [length]int) float64 {
	sum_cnt := 0
	for i := 0; i < length; i++ {
		sum_cnt += a[i]
	}
	ret := float64(0)
	if sum_cnt == 1 {
		if a[length-1] == 1 {
			return 0
		}
		ret = 1
	}
	for i := 0; i < length; i++ {
		if a[i] == 0 {
			continue
		}
		x := [length]int{0}
		for j := 0; j < length; j++ {
			x[j] = a[j]
		}
		x[i]--
		for j := i + 1; j < length; j++ {
			x[j]++
		}
		ret += float64(a[i]) / float64(sum_cnt) * cal(x)
	}
	return ret
}
func main() {
	fmt.Printf("%.6f\n", cal(a))
}
