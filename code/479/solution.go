package main

import "fmt"

const mod = int64(1e9 + 7)

func add(a int64, b int64) int64 {
	a = (a + b) % mod
	return (a + mod) % mod
}
func mul(a int64, b int64) int64 {
	a = a * b % mod
	return (a + mod) % mod
}
func qpow(a int64, b int64) int64 {
	a %= mod
	a = (a + mod) % mod
	ret := int64(1)
	for b > 0 {
		if (b & 1) > 0 {
			ret = mul(ret, a)
		}
		a = mul(a, a)
		b >>= 1
	}
	return ret
}
func cal(a int64) int64 {
	ret := a
	ret = mul(ret, qpow(1-a, mod-2))
	ret = mul(ret, add(0, 1-qpow(a, 1000000)))
	return ret
}

func main() {
	ans := int64(0)
	for i := int64(1); i <= int64(1000000); i++ {
		ans = add(ans, cal(add(0, 1-i*i)))
	}
	fmt.Printf("%d\n", ans)
}
