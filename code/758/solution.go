package main

import "fmt"

const mod = int64(1e9 + 7)

func add(a, b int64) int64 {
	return (a + b) % mod
}
func mul(a, b int64) int64 {
	return a * b % mod
}
func qpow(a, b int64) int64 {
	ret := int64(1)
	for b > 0 {
		if (b & 1) != 0 {
			ret = mul(ret, a)
		}
		a = mul(a, a)
		b >>= 1
	}
	return ret
}
func cal(a, b int64) int64 {
	if a < b {
		return 0
	}
	x1 := qpow(2, a%b)
	x2 := qpow(qpow(2, b), a/b)
	x3 := add(1, mod-x2)
	x4 := qpow(add(1, mod-qpow(2, b)), mod-2)
	return mul(x1, mul(x3, x4))
}
func exgcd(a, b int64) (int64, int64, bool) {
	if b == 0 {
		return 1, 0, true
	}
	x, y, y_neg := exgcd(b, a%b)
	return y, add(x, mod-mul(y, cal(a, b))), !y_neg
}
func get_ans(a, b int64) int64 {
	x, y, y_neg := exgcd(a, b)
	x = mul(x, 2)
	y = mul(y, 2)
	if y_neg {
		y = add(mod, -y)
	} else {
		x = add(mod, -x)
	}
	return add(add(mod, -2), add(x, y))
}
func is_prime(a int64) bool {
	for i := int64(2); i < a; i++ {
		if a%i == 0 {
			return false
		}
	}
	return true
}
func main() {
	ans := int64(0)
	prime := []int64{}
	for i := int64(2); i < int64(1000); i++ {
		if is_prime(i) {
			prime = append(prime, i*i*i*i*i)
		}
	}
	for i := 0; i < len(prime); i++ {
		for j := i + 1; j < len(prime); j++ {
			ans = add(ans, get_ans(prime[i], prime[j]))
		}
	}
	fmt.Printf("%d\n", ans)
}
