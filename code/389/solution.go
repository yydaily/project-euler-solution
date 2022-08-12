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

var p4 = []float64{0, 0.25, 0.25, 0.25, 0.25}
var p6 = []float64{}
var p8 = []float64{}
var p12 = []float64{}
var p20 = []float64{}
var cache = [2400][50000]float64{}

func init() {
	p6 = make([]float64, 25)
	p8 = make([]float64, 193)
	p12 = make([]float64, 2305)
	p20 = make([]float64, 46081)
}

func cal(a, b, c int) float64 {
	if c < 0 {
		return 0
	}
	if cache[a][c] == -1 {
		return 0
	}
	if cache[a][c] > 0 {
		return cache[a][c]
	}
	if c > a*b {
		return 0
	}
	if a == 0 && c == 0 {
		return 1
	}
	if a == 0 {
		return 0
	}
	ret := float64(0)
	for i := 1; i <= b; i++ {
		ret += cal(a-1, b, c-i) / float64(b)
	}
	if ret == 0 {
		cache[a][c] = -1
		return 0
	}
	cache[a][c] = ret
	return ret
}

func Cal(upper, dim int, origin, to []float64) {
	for i := range cache {
		for j := range cache[i] {
			cache[i][j] = 0
		}
	}

	for i := 1; i <= upper; i++ {
		for j := i; j <= dim*i; j++ {
			to[j] += origin[i] * cal(i, dim, j)
		}
	}
}

func main() {
	Cal(4, 6, p4, p6)
	Cal(24, 8, p6, p8)
	Cal(192, 12, p8, p12)
	Cal(2304, 20, p12, p20)

	exp := float64(0)
	for i := 1; i <= 46080; i++ {
		exp += p20[i] * float64(i)
	}

	ans := float64(0)
	for i := 1; i <= 46080; i++ {
		diff := exp - float64(i)
		ans += diff * diff * p20[i]
	}
	fmt.Printf("%.4f\n", ans)
}
