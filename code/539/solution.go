package main /*{{{*/

import (
	"fmt"
)

const mod = int64(987654321)

func S(l, r int64) int64 {
	ret := int64(0)
	if r <= 4 {
		for i := l; i <= r; i++ {
			if i == 1 {
				ret++
			} else {
				ret += 2
			}
		}
		return ret
	}
	if l == r {
		ret = 4 * S(l/4, l/4) % mod
		if l%4 <= 1 {
			ret -= 2
		}
		return (ret + mod) % mod
	}
	if r-l < 8 {
		for i := l; i <= r; i++ {
			ret = (ret + S(i, i)) % mod
		}
		return ret
	}
	ll := l / 4 * 4
	if ll < l {
		ll += 4
	}
	ret = (ret + S(l, ll-1)) % mod
	rr := r/4*4 - 1
	ret = (ret + S(rr+1, r)) % mod
	ret = (ret + 16*S(ll/4, rr/4)%mod - 4*(rr/4-ll/4+1)) % mod
	return (ret + mod) % mod
}

func main() {
	fmt.Println(S(1, 1e18))
}
