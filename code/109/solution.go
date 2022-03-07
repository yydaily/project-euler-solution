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

func check(a int64) bool {
	return a < 100
}

func main() {
	a, b := []int64{}, []int64{}
	for i := int64(1); i <= 20; i++ {
		a = append(a, 100+i)
		a = append(a, 200+i*2)
		a = append(a, 300+i*3)
		b = append(b, 100+i*2)
	}
	a = append(a, 100+25)
	a = append(a, 200+50)
	b = append(b, 200+50)

	ans := int64(0)
	for _, k := range b {
		if check(k % 100) {
			ans++
		}
	}
	fmt.Println(ans)
	for _, i := range a {
		for _, k := range b {
			if check(i%100 + k%100) {
				ans++
			}
		}
	}
	fmt.Println(ans)

	for _, i := range a {
		for _, j := range a {
			for _, k := range b {
				if check(i%100+j%100+k%100) && j >= i {
					ans++
				}
			}
		}
	}
	fmt.Println(ans)
}
