package main /*{{{*/

import (
	"fmt"
)

func qpow(a, b, mod int64) int64 {
	ret := int64(1)
	for b > 0 {
		if (b & 1) > 0 {
			ret = ret * a % mod
		}
		a = a * a % mod
		b >>= 1
	}
	return ret
}

func S(a int64) int64 {
	ret := int64(0)
	cal := func(a, b int64) int64 {
		return (qpow(10, b, a*10) / a) % 10
	}
	for i := int64(1); i <= a; i++ {
		ret += cal(i, a)
	}
	return ret
}

func main() {
	fmt.Println(S(7))
	fmt.Println(S(100))
	fmt.Println(S(1000 * 1000 * 10))
}
