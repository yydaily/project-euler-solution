package main /*{{{*/

import (
	"fmt"
	"math"
)

var num = [21]float64{}

func cal(a float64, b float64) float64 {
	x := (a + b) * (a + b)
	y := (100 - a - b) * (100 - a - b)
	return math.Sqrt(x - y)
}

func cal2() float64 {
	ans := num[0] + num[20]
	for i := 1; i < 21; i++ {
		ans += cal(num[i-1], num[i])
	}
	return ans * 1000
}

func main() {
	index := 0
	for i := 50; i >= 30; i -= 2 {
		num[index] = float64(i)
		index++
	}
	for i := 31; i <= 50; i += 2 {
		num[index] = float64(i)
		index++
	}
	fmt.Printf("%.0f\n", cal2())
}
