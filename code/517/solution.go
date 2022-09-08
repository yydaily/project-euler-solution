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

const upper = e7 + e6

var fac, inv = [upper]int64{}, [upper]int64{}

func init() {
	fac[0] = 1
	for i := int64(1); i < upper; i++ {
		fac[i] = (fac[i-1] * i) % mod
	}
	inv[upper-1] = qpow(fac[upper-1], mod-2)
	for i := upper - 2; i >= 0; i-- {
		inv[i] = (inv[i+1] * (i + 1)) % mod
	}
}

func C(a, b int) int64 {
	return ((fac[a] * inv[b]) % mod) * inv[a-b] % mod
}

func G(a int64) int64 {
	x := math.Sqrt(float64(a))
	ans := int64(0)
	for i := int64(0); i*i < a; i++ {
		ans = add(ans, C(int(float64(i+a)-float64(i)*x), int(i)))
	}
	return ans
}
func main() {
	fmt.Println(G(90))
	ans := int64(0)
	for i := int64(10000001); i < 10010000; i++ {
		isPrime := true
		for j := int64(2); j*j <= i; j++ {
			if i%j == 0 {
				isPrime = false
				break
			}
		}
		if isPrime {
			ans = add(ans, G(i))
		}
	}
	fmt.Println(ans)
}
