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

type p struct {
	now, mod int64
}

func cal(a int64) int64 {
	if a == 9999 {
		return 0
	}
	x := []p{}
	ano := []p{}
	x = append(x, p{0, 0})
	for i := int64(1); ; i *= 10 {
		for _, j := range x {
			if j.now > 0 || j.mod > 0 {
				now := p{j.now*10 + (j.mod*10)/a, (j.mod * 10) % a}
				if now.mod == 0 {
					return now.now
				}
				ano = append(ano, now)
			}
			now := p{j.now*10 + (j.mod*10+1)/a, (j.mod*10 + 1) % a}
			if now.mod == 0 {
				return now.now
			}
			ano = append(ano, now)

			now = p{j.now*10 + (j.mod*10+2)/a, (j.mod*10 + 2) % a}
			if now.mod == 0 {
				return now.now
			}
			ano = append(ano, now)
		}
		x = ano
		ano = []p{}
	}
	return 0
}
func main() {
	ans := int64(0)
	for i := int64(1); i <= 10000; i++ {
		ans += cal(i)
	}
	fmt.Println(ans + 1111333355557778)
}
