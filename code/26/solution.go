package main

import "fmt"

func cal(a int) int {
	base := 1
	ans := 0
	m := map[int]int{}
	for base > 0 {
		base = base * 10 % a
		if m[base] > 0 {
			return ans - m[base] + 1
		}
		ans++
		m[base] = ans
		if base == 1 {
			return ans
		}
	}
	return 0
}

func main() {
	ans := 1
	for i := 3; i < 1000; i++ {
		if cal(i) > cal(ans) {
			ans = i
		}
	}
	fmt.Println(ans)
}
