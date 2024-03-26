package main /*{{{*/

import (
	"fmt"
)

const (
	mod  = 998244353
	inv2 = 499122177
)

var cache = map[int64]int64{}

func S(n int64) int64 {
	if cache[n] > 0 {
		return cache[n]
	}
	if n == 1 {
		cache[1] = 1
		return 1
	}

	ret := n % mod * ((n + 1) % mod) % mod * inv2 % mod

	for i := int64(2); i <= n; i++ {
		nxt := n / (n / i)
		now := S(n/i) * ((nxt - i + 1) % mod) % mod
		ret = ((ret-now)%mod + mod) % mod
		i = nxt
	}
	cache[n] = ret
	return ret
}

func G(n int64) int64 {
	ans := int64(0)

	for u := int64(1); u <= n; u++ {
		nxt := n / (n / u)
		base1 := (u + nxt) % mod * ((nxt - u + 1) % mod) % mod * inv2 % mod
		ans = (ans + base1*S(n/u)) % mod
		u = nxt
	}

	return ans
}

func main() {
	fmt.Println(G(10))
	fmt.Println(G(100000000000))
}
