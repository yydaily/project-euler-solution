package main

import "fmt"

func cal(a, b int64) int64 {
	if a >= b {
		return b
	}
	base := cal(a, b-1)
	cnt := base/(a-2) - 4
	ans := cnt * a
	base -= cnt * (a - 2)
	if cnt < 0 {
		cnt = 0
	}
	if base <= a-1 {
		return ans + base + 1
	}
	ans += a
	base -= a - 1
	for base >= a-2 {
		ans += a
		base -= a - 2
	}
	if base > 0 {
		ans += base + 2
	}
	return ans
}
func main() {
	ans := int64(0)
	for i := int64(3); i <= 40; i++ {
		ans += cal(i, 31)
	}
	fmt.Printf("%d\n", ans)
}
