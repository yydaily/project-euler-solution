package main /*{{{*/

import (
	"fmt"
	"math"
)

const (
	e4  = int64(10000)
	e5  = int64(100000)
	e6  = int64(1000000)
	e7  = int64(10000000)
	e8  = e4 * e4
	e9  = e8 * 10
	mod = int64(1e9 + 7)
)

func sqrt(a int64) int64 {
	x := math.Sqrt(float64(a))
	return int64(x)
}

/*}}}*/

const people = 100
const max_dis = people >> 1

var a, b = [people]float64{}, [people]float64{}

func e(a, b int) int { /*{{{*/
	if a == b {
		return 1
	}
	return 0
} /*}}}*/
func gao() { /*{{{*/
	for i := 1; i <= max_dis; i++ {
		for x := 1; x <= 6; x++ {
			for y := 1; y <= 6; y++ {
				dis := i + e(x, 6) - e(x, 1) + e(y, 1) - e(y, 6)
				if dis == -1 {
					dis = 1
				}
				if dis > max_dis {
					dis = people - dis
				}
				b[dis] += a[i] / 36
			}
		}
	}
} /*}}}*/
func main() {
	a[max_dis] = 1
	ans := float64(0)
	for i := 1; i < 100000; i++ {
		for i := range b {
			b[i] = 0
		}
		gao()
		ans += float64(i) * b[0]
		for j := 1; j <= max_dis; j++ {
			a[j] = b[j]
		}
	}
	fmt.Printf("%4.6f\n", ans)
}
