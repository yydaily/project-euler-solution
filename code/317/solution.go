package main /*{{{*/

import (
	"fmt"
	"math"
)

func solve(hight, v, g float64) float64 {
	upper := v*v/g/2 + hight
	return math.Acos(-1) * upper * upper / g * v * v
}

func main() {
	fmt.Printf("%.4f\n", solve(100, 20, 9.81))
}
