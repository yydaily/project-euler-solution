package main /*{{{*/

import (
	"fmt"
	"math"
)

func cost_time(x0, y0, x1, y1, speed float64) float64 {
	x0 -= x1
	y0 -= y1
	return math.Sqrt(x0*x0+y0*y0) / speed
}

func cal(x0, y0, x1, y1, speed, target_speed float64) (float64, float64) {
	sin_theta_1 := (x1 - x0) / math.Sqrt((y1-y0)*(y1-y0)+(x1-x0)*(x1-x0))
	sin_theta_2 := sin_theta_1 / speed * target_speed
	return math.Tan(math.Asin(sin_theta_2))*10 + x1, y1 + 10
}

func cal2(x, y float64) float64 {
	ans := cost_time(0, 0, x, y, 10)
	startx, starty := float64(0), float64(0)
	for i := 9; i >= 5; i-- {
		x2, y2 := cal(startx, starty, x, y, float64(i+1), float64(i))
		ans += cost_time(x, y, x2, y2, float64(i))
		startx = x
		starty = y
		x = x2
		y = y2
	}
	return ans + cost_time(x, y, 50*math.Sqrt(2), 50*math.Sqrt(2), 10)
}

func main() {
	// https://en.wikipedia.org/wiki/Snell%27s_law
	endy := (50*math.Sqrt(2) - 50) / 2

	endx_l, endx_r := float64(0), 50*math.Sqrt(2)
	diff := float64(1)
	for diff >= 1e-12 {
		lmid := (endx_l*2 + endx_r) / 3
		rmid := (endx_r*2 + endx_l) / 3

		lvalue := cal2(lmid, endy)
		rvalue := cal2(rmid, endy)

		diff = math.Abs(rvalue - lvalue)
		if lvalue < rvalue {
			endx_r = rmid
		} else {
			endx_l = lmid
		}
	}

	fmt.Printf("%.10f\n", cal2(endx_l, endy))
}
