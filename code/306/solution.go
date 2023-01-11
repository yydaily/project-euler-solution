package main /*{{{*/

import (
	"fmt"
)

func solve(upper int) int {
	ret := upper / 34 * 5
	specialCase := []int{1, 15, 35}
	for _, i := range specialCase {
		if upper >= i {
			ret++
		}
	}

	normalCase := []int{5, 9, 21, 25, 29}
	for _, i := range normalCase {
		if upper%34 >= i {
			ret++
		}
	}

	return upper - ret
}

func main() {
	fmt.Println(solve(5))
	fmt.Println(solve(50))
	fmt.Println(solve(1000 * 1000))
}
