package main /*{{{*/

import (
	"fmt"
)

func main() {
	ans := float64(0)
	base := float64(2)
	for i := 2; i <= 30; i++ {
		ans += (base - 1) / float64(i)
		base *= 2
	}
	fmt.Printf("%.2f\n", ans)
}
