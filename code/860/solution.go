package main /*{{{*/

import (
	"fmt"
)

const mod = int64(989898989)

var (
	fac     = [100000]int64{}
	inv_fac = [100000]int64{}
)

func qpow(a, b int64) int64 {
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

func init() {
	fac[0] = 1
	inv_fac[0] = 1
	for i := 1; i < 100000; i++ {
		fac[i] = fac[i-1] * int64(i) % mod
	}
	inv_fac[100000-1] = qpow(fac[100000-1], mod-2)
	for i := 100000 - 2; i >= 0; i-- {
		inv_fac[i] = inv_fac[i+1] * int64(i+1) % mod
	}
}

func C(a, b int64) int64 {
	return fac[a] * inv_fac[b] % mod * inv_fac[a-b] % mod
}

func abs(a int64) int64 {
	if a < 0 {
		return -a
	}
	return a
}

func F(n int64) int64 {
	ans := int64(0)
	for i := int64(0); i <= n; i++ { // 00
		for j := int64(0); i+j <= n; j++ { // 11
			x := abs(i*2-j*2) * 2
			if i+j+x > n || (n-i-j-x)%2 > 0 {
				continue
			}
			x += (n - i - j - x) / 2

			ans = (ans + C(n, i)*C(n-i, j)%mod*C(n-i-j, x)%mod) % mod
		}
	}
	return ans
}

func main() {
	fmt.Printf("F(2) = 4 = %d\n", F(2))
	fmt.Printf("F(10) = 63594 = %d\n", F(10))
	fmt.Printf("F(9898) = %d\n", F(9898))
}
