package main /*{{{*/

import (
	"fmt"
)

const mod = int64(1000000007)

var fac, fac_inv [111000100]int64

func pow(a, b int64) int64 {
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

func init() {
	fac[0] = 1
	for i := int64(1); i < int64(len(fac)); i++ {
		fac[i] = fac[i-1] * i % mod
	}
	fac_inv[len(fac_inv)-1] = pow(fac[len(fac_inv)-1], mod-2)
	for i := int64(len(fac_inv) - 2); i >= 0; i-- {
		fac_inv[i] = fac_inv[i+1] * (i + 1) % mod
	}
}

func C(a, b int64) int64 {
	if a < b {
		return 0
	}
	return fac[a] * fac_inv[b] % mod * fac_inv[a-b] % mod
}

func cal(a, b int64) int64 {
	return C(a+b-1, b-1)
}

func W(a, b, c int64) int64 {
	ans := int64(0)
	for i := int64(1); i <= a; i++ {
		base1 := C(b-1, i)
		base1 = (base1 * C(a-1, i-1)) % mod
		ans = (ans + cal(c-2*i*2, a+b+1)*base1) % mod

		base2 := C(b-1, i-1) * 2 % mod
		base2 = (base2 * C(a-1, i-1)) % mod
		ans = (ans + cal(c-(2*i-1)*2, a+b+1)*base2) % mod

		if i == 1 {
			continue
		}
		base3 := C(b-1, i-2) % mod
		base3 = (base3 * C(a-1, i-1)) % mod
		ans = (ans + cal(c-(2*i-2)*2, a+b+1)*base3) % mod
	}
	return ans
}

func main() {
	fmt.Println(W(2, 2, 4))
	fmt.Println(W(4, 4, 44))
	fmt.Println(W(1e6, 1e7, 1e8))
}
