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

func get_all_primes(a int64) map[int64]int { /*{{{*/
	ret := map[int64]int{}
	for i := int64(2); i*i <= a; i++ {
		for a%i == 0 {
			ret[i]++
			a /= i
		}
	}
	if a != 1 {
		ret[a]++
	}
	return ret
} /*}}}*/
func get_all_factor(a int64) []int64 { /*{{{*/
	p := get_all_primes(a)
	ret := []int64{}
	ret = append(ret, 1)
	for k, v := range p {
		s := len(ret)
		now := int64(1)
		for cnt := 1; cnt <= v; cnt++ {
			now *= k
			for x := 0; x < s; x++ {
				ret = append(ret, ret[x]*now)
			}
		}
	}
	return ret
} /*}}}*/
func gcd(a, b int64) int64 {
	if a == 0 {
		return b
	}
	return gcd(b%a, a)
}
func gen(a, b int64) (int64, int64) {
	for gcd(a+1, b) != 1 {
		a++
		b += gcd(a, b)
	}
	x := b * 100
	for _, fac := range get_all_factor(b - a - 1) {
		if fac == 1 {
			continue
		}
		x = min(x, fac-(a+1)%fac)
	}
	return a + x + 1, b + x + gcd(a+x+1, b+x)
}
func main() {
	index := int64(4)
	val := int64(13)
	ans := int64(0)

	for index <= 1e15 {
		ans = 1e15 - index + val
		index, val = gen(index, val)
		if index > 1e15 {
			break
		}
	}
	fmt.Println(ans)
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
