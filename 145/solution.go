package main

import "fmt"

func rev(a int) int {
	ret := 0
	for a > 0 {
		ret = ret*10 + a%10
		a /= 10
	}
	return ret
}

func check(a int) int {
	if a%10 == 0 {
		return 0
	}
	a += rev(a)
	for a > 0 {
		if a%2 == 0 {
			return 0
		}
		a /= 10
	}
	return 1
}

func main() {
	upper := 1000 * 1000 * 100
	ans := 0
	for i := 1; i <= upper; i += 2 {
		if check(i) == 1 {
			ans++
		}
	}
	fmt.Printf("%d\n", (ans << 1))
}
