package main

import (
	"fmt"
	"math"
)

var num = [8]int64{}

func check() bool {
	now := int64(1)
	for i := int64(0); i < 8; i++ {
		now = now*100 + num[i]*10 + i + 2
	}
	x := int64(math.Sqrt(float64(now)))
	for i := x - 1; i <= x+1; i++ {
		if i*i == now {
			fmt.Println(i * 10)
			return true
		}
	}
	return false
}

func main() {
	for true {
		num[0]++
		ind := 0
		for num[ind] >= 10 {
			num[ind] -= 10
			ind++
			num[ind]++
		}
		if check() {
			break
		}
	}
}
