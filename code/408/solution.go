package main /*{{{*/

import (
	"fmt"
	"sort"
)

const mod = int64(1e9 + 7)

var (
	fac     = make([]int64, 2e7+1)
	fac_inv = make([]int64, 2e7+1)
)

func pow(x, y int64) int64 {
	res := int64(1)
	for y > 0 {
		if y&1 == 1 {
			res = res * x % mod
		}
		x = x * x % mod
		y >>= 1
	}
	return res
}

func C(a, b int64) int64 {
	if a < b {
		return 0
	}
	return fac[a] * fac_inv[b] % mod * fac_inv[a-b] % mod
}

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func init() {
	fac[0] = 1
	for i := int64(1); i <= 2e7; i++ {
		fac[i] = fac[i-1] * i % mod
	}
	fac_inv[2e7] = pow(fac[2e7], mod-2)
	for i := int64(2e7 - 1); i >= 0; i-- {
		fac_inv[i] = fac_inv[i+1] * (i + 1) % mod
	}
}

func gen(upper int64) [][]int64 {
	ret := [][]int64{}
	for n := int64(1); n*n*n*n < upper; n++ {
		for m := n + 1; 4*m*n*n*m <= upper; m++ {
			a := m*m - n*n
			b := 2 * m * n
			if gcd(a, b) != 1 {
				continue
			}

			u := upper / (a * a)
			if u > upper/(b*b) {
				u = upper / (b * b)
			}
			for base := int64(1); base*base <= u; base++ {
				ret = append(ret, []int64{a * a * base * base, b * b * base * base})
				ret = append(ret, []int64{b * b * base * base, a * a * base * base})
			}
		}
	}
	sort.Slice(ret, func(i, j int) bool {
		if ret[i][0] != ret[j][0] {
			return ret[i][0] < ret[j][0]
		}
		return ret[i][1] < ret[j][1]
	})
	return ret
}

func to(a, b int64) int64 {
	return C(a+b, a)
}

func P(n int64) int64 {
	poi := gen(n)
	ways := make([]int64, len(poi))
	ans := to(n, n)
	for i := 0; i < len(poi); i++ {
		ways[i] = to(poi[i][0], poi[i][1])
		for j := 0; j < i; j++ {
			if poi[i][1] < poi[j][1] {
				continue
			}
			ways[i] = ((ways[i]-ways[j]*to(poi[i][0]-poi[j][0], poi[i][1]-poi[j][1])%mod)%mod + mod) % mod
		}
		ans = ((ans-ways[i]*to(n-poi[i][0], n-poi[i][1])%mod)%mod + mod) % mod
	}
	return ans
}

func main() {
	fmt.Println(P(5))
	fmt.Println(P(16))
	fmt.Println(P(1000))
	fmt.Println(P(1e7))
}
