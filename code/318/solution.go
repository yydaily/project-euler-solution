package main /*{{{*/

import (
	"fmt"
	"math"
)

func main() {
	ans := int64(0)
	for p := 1; p < 2011; p++ {
		for q := p + 1; p+q <= 2011; q++ {
			buf := float64(p+q) - 2*math.Sqrt(float64(p*q))
			if 0 < buf && buf < 1 {
				ans += int64(math.Ceil(-2011 / math.Log10(buf)))
			}
		}
	}
	fmt.Println(ans)
}
