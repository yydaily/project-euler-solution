package main

import "fmt"

func cal(a int64) int64 {
	if a<=7 {
		return a * (a+1) / 2
	}
	base := int64(1)
	row := int64(1)
	for a > row * 7 {
		row *= 7
		base *= 28
	}
	cnt := int64(a/row)
	ret := cnt * (cnt+1) / 2 * base
	return ret + (cnt+1) * cal(a - cnt*row)
}

func main() {
	fmt.Printf("%d\n", cal(1000 * 1000 * 1000))
}
