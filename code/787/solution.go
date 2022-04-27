package main

import (
	"fmt"
	"math"
)

var m = map[int64]int64{}

func F(N int64) int64 {
	if m[N] > 0 {
		return m[N]
	}
	s := N * N / 8
	z := int64(math.Sqrt(float64(N)))
	for g := int64(3); g <= z; g += 2 {
		s -= F(N / g)
	}
	for x := int64(1); x <= N/(z+1); x++ {
		s -= ((N/x+1)/2 - (N/(x+1)+1)/2) * F(x)
	}
	m[N] = s
	return s
}

func main() {
	fmt.Println(1 + 2*F(1000000000))
}
