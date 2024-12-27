package main

import "fmt"

func f(a, b int64) int64 {
	if a <= b {
		return a
	}
	le, ri := b, b
	for i := int64(1); ; i *= 2 {
		le = ri + 1
		ri = ri + i
		if ri >= a {
			return b + f(a, le)
		}
	}
}

func xpow(a, b int64) int64 {
	ret := int64(1)
	for i := int64(0); i < b; i++ {
		ret *= a
	}
	return ret
}

func main() {
	fmt.Println(f(6, 1))
	fmt.Println(f(10, 3))
	fmt.Println(f(xpow(10, 17), xpow(9, 17)))
}
