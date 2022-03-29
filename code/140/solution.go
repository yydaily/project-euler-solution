package main /*{{{*/

import (
	"fmt"
	"math"
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

var num = [6][2]int64{{-4, 5}, {-4, -5}, {0, -1}, {0, 1}, {-3, 2}, {-3, -2}}

func main() {
	v := []int64{}
	for _, i := range num {
		n, t := i[0], i[1]
		for abs(n) < 3197021343560 {
			n, t = -9*n-4*t-14, -20*n-9*t-28
			if n > 0 {
				v = append(v, n)
			}
		}
	}
	sort.Slice(v, func(i, j int) bool {
		return v[i] < v[j]
	})
	ans := int64(0)
	for i := 0; i < 30; i++ {
		ans += v[i]
	}
	fmt.Println(ans)
}

func abs(a int64) int64 {
	if a >= 0 {
		return a
	}
	return -a
}
