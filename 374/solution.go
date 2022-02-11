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
	mod = int64(982451653)
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
		ret = (buf % mod * ret) % mod
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

const query = int64(1e14)
const upper = int64(15 * e6)

var fac = [upper + 10]int64{}
var inv = [upper + 10]int64{}

func init() {
	fac[1], inv[1] = 1, 1
	for i := int64(2); i <= upper; i++ {
		fac[i] = mul(fac[i-1], i)
		inv[i] = mul(mod-mod/i, inv[mod%i])
	}
}
func cal_part1() int64 {
	ret, length, base, sum := int64(0), int64(2), int64(15), int64(8)
	for i := int64(5); sum <= query; i++ {
		ret = add(ret, mul(length, base))
		length++
		sum += i
		base = mul(base, inv[i], i-1, i+1)
	}
	return ret
}
func cal_part2() int64 {
	base, maxm, ret, length := int64(26), int64(7), int64(0), int64(2)
	for ; maxm <= query; length++ {
		ret = add(ret, mul(base, length))
		base = add(mul(base, length+3), fac[length+2])
		maxm += length + 3
	}

	base = mul(fac[length+1], length)
	for nouse := (length+1)*(length+2)/2 - 1; nouse <= query; nouse++ {
		ret = add(ret, base)
		base = mul(base, length+2, inv[length+1])
		length--
	}
	return ret
}
func main() {
	ans := int64(10)
	ans = add(ans, cal_part1(), cal_part2())
	fmt.Println(ans)
}
