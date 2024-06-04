package main /*{{{*/

import (
	"fmt"
)

var cost = [10]int{6, 2, 5, 5, 4, 5, 6, 3, 7, 6}

func cal_origin(a int) int {
	if a < 10 {
		return cost[a]
	}
	return cost[a%10] + cal_origin(a/10)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func solve(a int) int {
	ret := 0
	add_and_multi := [100*100*100 + 1]int{}
	multi := [100*100*100 + 1]int{}
	for i := 1; i <= a; i++ {
		now := cal_origin(i)
		for j := 2; j*j <= i; j++ {
			if i%j == 0 {
				now = min(now, multi[i/j]+multi[j]+2)
			}
		}
		multi[i] = now

		for j := 1; j+j <= i; j++ {
			now = min(now, add_and_multi[j]+add_and_multi[i-j]+2)
		}
		add_and_multi[i] = now
		ret += now
	}
	return ret
}

func main() {
	fmt.Println(solve(100))
	fmt.Println(solve(10000))
	fmt.Println(solve(1000000))
}
