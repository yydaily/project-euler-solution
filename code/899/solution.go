package main

import "fmt"

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func L(a int64) int64 {
	ans := int64(0)
	for i := int64(1); i <= a; i *= 2 {
		cnt := min(a, 2*i-1) - i + 1
		cnt2 := (a + 1) / 2 / i
		ans += cnt * cnt2 * 2
	}
	for i := int64(1); i <= a; i = i*2 + 1 {
		ans--
	}
	return ans
}

func qpow(a, b int64) int64 {
	ans := int64(1)
	for b > 0 {
		if b&1 == 1 {
			ans *= a
		}
		a *= a
		b >>= 1
	}
	return ans
}

func main() {
	fmt.Println(L(7))
	fmt.Println(L(49))
	fmt.Println(L(qpow(7, 17)))
}
