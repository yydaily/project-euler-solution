package main /*{{{*/

import (
	"reflect"
	"fmt"
)

const (
	e4 = int64(10000)
	e5 = int64(100000)
	e6 = int64(1000000)
	e7 = int64(10000000)
	e8 = e4*e4
	mod = int64(1e9+7)
) 

func add(list ...interface{}) int64 {/*{{{*/
	if len(list) == 0 {
		return 0
	}
	ret := int64(0)
	for _, i := range list {
		buf := int64(0)
		switch reflect.TypeOf(i).String(){
			case "int":
				buf = int64(i.(int))
			case "int64":
				buf = i.(int64)
		}
		ret = (ret + buf)%mod
	}
	return ret
}/*}}}*/
func mul(list ...interface{}) int64 {/*{{{*/
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
			if (buf&1) == 1 {
				ret = add(ret, base)
			}
			base = add(base, base)
			buf>>=1
		}
	}
	return ret
}/*}}}*/
func qpow(a, b int64) int64 {/*{{{*/
	ret := int64(1)
	for b > 0 {
		if (b&1) == 1 {
			ret = mul(ret, a)
		}
		a = mul(a, a)
		b>>=1
	}
	return ret
}/*}}}*/
/*}}}*/

func gen(a, b int64) (int64, int64) {
	return -3*a -4*b + 3, -2*a -3*b + 2
}
func main() {
	a, b, va, vb := int64(0), int64(0), int64(0), int64(0)
	for vb < int64(1e12) {
		a, b = gen(a, b)
		if a < 0 {
			va = -a+1
			vb = 1-b*2
		} else {
			va = a
			vb = b*2
		}
		fmt.Println(va, vb)
	}
}
