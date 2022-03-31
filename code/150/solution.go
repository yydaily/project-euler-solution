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

var t = int64(0)
var mod1 = int64(1 << 20)
var mod2 = int64(1 << 19)

func gen() int64 {
	t = (615949*t + 797807) % mod1
	return t - mod2
}

var sum = [1010][1010]int64{}

func main() {
	for i := 1; i <= 1000; i++ {
		for j := 1; j <= i; j++ {
			sum[i][j] = sum[i][j-1] + gen()
		}
	}
	ans := int64(2e9)
	for i := 1000; i >= 1; i-- {
		for j := 1; j <= i; j++ {
			now := int64(0)
			for l := 0; l <= 1000-i; l++ {
				now += sum[i+l][j+l] - sum[i+l][j-1]
				if now < ans {
					ans = now
				}
			}
		}
	}
	fmt.Println(ans)
}
