package main

import (
	"fmt"
	"math"
)

var r = float64(100000)

func min(a, b float64) float64 {
	if a < b {
		return a
	}
	return b
}

func cal(i float64) float64 {
	return r - math.Sqrt(r*r-(r-i)*(r-i))
}

func check(n float64) float64 {
	sum, buf := float64(0), float64(0)
	for i := float64(0); i < r; i = i + 1 {
		upper1 := cal(i)
		upper2 := i / n
		sum += upper1
		buf += min(upper1, upper2)
	}
	return buf / sum * 1000
}

func main() {
	l, r := float64(15), 1e10
	for l+0.1 < r {
		mid := (l + r) / 2
		if check(mid) > 1 {
			l = mid
		} else {
			r = mid
		}
	}
	fmt.Printf("%.0f\n", math.Ceil(l))
}
