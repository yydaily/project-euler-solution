package main /*{{{*/

import (
	"fmt"
	"math"
)

func f(x, y float64) float64 {
	return x*x + y*y
}

type point struct {
	x, y float64
}

func cal1(a, b, c point) point {
	// 返回三个点对应的三角形的外接圆圆心
	d1 := f(b.x, b.y) - f(a.x, a.y)
	d2 := f(c.x, c.y) - f(b.x, b.y)
	fm := 2 * ((c.y-b.y)*(b.x-a.x) - (b.y-a.y)*(c.x-b.x))
	ans_x := ((c.y-b.y)*d1 - (b.y-a.y)*d2) / fm
	ans_y := ((b.x-a.x)*d2 - (c.x-b.x)*d1) / fm
	return point{x: ans_x, y: ans_y}
}

func cal2(ra, rb, rc float64) point {
	// 返回三个相切圆的公切圆圆心，经典问题，参考: soddy circles
	r := (ra * rb * rc) / (ra*rb + rb*rc + ra*rc + 2*math.Sqrt(ra*rb*rc*(ra+rb+rc)))

	cos_alpha := (f(ra+r, ra+rb) - f(rb+r, 0)) / 2 / (ra + r) / (ra + rb)
	return point{x: cos_alpha * (ra + r), y: (ra + r) * math.Sin(math.Acos(cos_alpha))}
}

func cal(ra, rb, rc float64) float64 {
	cos_alpha := (f(ra+rb, ra+rc) - f(rb+rc, 0)) / 2 / (ra + rb) / (ra + rc)
	cos_beta := (f(ra+rb, rb+rc) - f(ra+rc, 0)) / 2 / (ra + rb) / (rb + rc)
	O1 := cal1(
		point{x: ra, y: 0},
		point{x: cos_alpha * ra, y: math.Sin(math.Acos(cos_alpha)) * ra},
		point{x: ra + rb - cos_beta*rb, y: rb * math.Sin(math.Acos(cos_beta))},
	)
	O2 := cal2(ra, rb, rc)

	return math.Sqrt(f(O1.x-O2.x, O1.y-O2.y))
}

func gcd2(a, b int) int {
	if a == 0 {
		return b
	}
	return gcd2(b%a, a)
}

func gcd(a, b, c int) int {
	return gcd2(a, gcd2(b, c))
}

func main() {
	cnt := 0
	ans := float64(0)
	for i := 1; i <= 100; i++ {
		for j := i + 1; j <= 100; j++ {
			for k := j + 1; k <= 100; k++ {
				if gcd(i, j, k) != 1 {
					continue
				}
				cnt++
				ans += cal(float64(i), float64(j), float64(k))
			}
		}
	}
	fmt.Printf("%.8f\n", ans/float64(cnt))
}
