package main /*{{{*/

import (
	"fmt"
)

func pow(a, b, mod int64) int64 {
	var res int64 = 1
	for b > 0 {
		if b&1 == 1 {
			res = res * a % mod
		}
		a = a * a % mod
		b >>= 1
	}
	return res
}

const (
	mod  = int64(815730721)
	mod2 = int64(752982204)
	mod3 = int64(231686832)
	mod4 = int64(71288256)
	mod5 = int64(21934848)
	mod6 = int64(6749184)
)

func C(n, mod, mod2 int64) int64 {
	ans := pow(2, pow(3, n-2, mod2), mod)
	ans2 := pow(3, (pow(3, n-3, mod2)-1)/2*3, mod)
	return ans * ans2 % mod
}

func C3(n int64) int64 {
	a := C(n, mod5, mod6)
	b := C(a, mod3, mod4)
	return C(b, mod, mod2)
}

func main() {
	fmt.Println(C(10000, mod, mod2))
	fmt.Println(C3(10000))
}
