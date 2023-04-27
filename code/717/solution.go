package main /*{{{*/

import (
	"fmt"
)

func mul(a, b, m int64) int64 {
	if m <= 1e8 {
		return a * b % m
	}
	ret := int64(0)
	for b > 0 {
		if (b & 1) > 0 {
			ret = (ret + a) % m
		}
		a = a * 2 % m
		b >>= 1
	}
	return ret
}

func qpow(a, b, m int64) int64 {
	ret := int64(1)
	for b > 0 {
		if (b & 1) > 0 {
			ret = mul(ret, a, m)
		}
		a = mul(a, a, m)
		b >>= 1
	}
	return ret
}

func g(p int64) int64 {
	a := qpow(2, qpow(2, p, p-1), p)

	ans1 := (a & 1) * qpow(2, p-1, p)

	ans2 := qpow(2, p-1, p*p)

	ans2 -= 1
	if ans2 < 0 {
		ans2 += p * p
	}

	ans2 /= p
	ans2 = mul(ans2, a, p)

	return (ans1 + ans2) % p
}

func G(n int64) int64 {
	prime := make([]bool, n+1)
	p := []int64{}

	for i := int64(2); i <= n; i++ {
		if !prime[i] {
			p = append(p, i)
		}

		for _, pri := range p {
			if i*pri > n {
				break
			}
			prime[i*pri] = true
			if i%pri == 0 {
				break
			}
		}
	}

	ans := int64(0)
	for i := 1; i < len(p); i++ {
		ans += g(p[i])
	}
	return ans
}

func main() {
	fmt.Println(G(100))
	fmt.Println(G(1e4))
	fmt.Println(G(1e7))
}
