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

func gen(v []float64) []float64 { /*{{{*/
	ret := []float64{}
	if len(v) == 1 {
		ret = append(ret, v[0])
		return ret
	}
	for _, i := range v {
		buf := []float64{}
		for _, j := range v {
			if j == i {
				continue
			}
			buf = append(buf, j)
		}
		now := gen(buf)
		for _, j := range now {
			ret = append(ret, i+j)
			ret = append(ret, i*j)

			ret = append(ret, i-j)
			ret = append(ret, j-i)
			ret = append(ret, i/j)
			ret = append(ret, j/i)
		}
	}
	return ret
} /*}}}*/
func cal(x []float64) int { /*{{{*/
	m := map[int]bool{}
	for _, i := range x {
		if float64(int(i)) == i {
			m[int(i)] = true
		}
	}
	for i := 1; ; i++ {
		if !m[i] {
			return i - 1
		}
	}
} /*}}}*/
func main() {
	ans := 0
	for i := 1.0; i <= 20; i++ {
		for j := i + 1; j <= 20; j++ {
			for k := j + 1; k <= 20; k++ {
				for l := k + 1; l <= 20; l++ {
					v := []float64{i, j, k, l}
					now := cal(gen(v))
					if now > ans {
						ans = now
						fmt.Printf("%.0f%.0f%.0f%.0f\n", i, j, k, l)
					}
				}
			}
		}
	}
}
