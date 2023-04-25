package main /*{{{*/

import (
	"fmt"
	"math"
)

func L(n int64) int64 {
	m := int64(math.Sqrt(float64(n - 1)))
	ret := m*m*(m+1)*(m+1)/4 - m*m*n

	for i := m; i >= 1; i-- {
		ret += (n - 1) / i * (2*n - i*(1+(n-1)/i))
	}
	return ret
}

func main() {
	fmt.Println(L(1000))
	fmt.Println(L(1e7))
}
