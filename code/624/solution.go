package main /*{{{*/

import (
	"fmt"
)

var (
	sqrt_5 = int64(-1)
	mod    = int64(0)
)

func Init(m int64) {
	mod = m
	for i := int64(1); ; i++ {
		if i*i%m == 5 {
			sqrt_5 = i
			return
		}
	}
}

func qpow(a, b int64) int64 {
	a %= mod
	a = (a + mod) % mod
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

func Q(a, m int64) int64 {
	Init(m)
	pow4 := qpow(4, a)
	l := qpow(1+sqrt_5, a-1)
	r := qpow(1-sqrt_5, a-1)

	lret := l * qpow(pow4-(1+sqrt_5)*l%mod, mod-2) % mod
	rret := r * qpow(pow4-(1-sqrt_5)*r%mod, mod-2) % mod

	ans := ((lret-rret)%mod + mod) % mod

	ans = (ans * 2 * qpow(sqrt_5, mod-2)) % mod

	return ans
}

func main() {
	fmt.Println(Q(2, 109))
	fmt.Println(Q(3, 109))
	fmt.Println(Q(1e18, 1e9+9))
}
