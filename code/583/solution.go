package main /*{{{*/

import (
	"fmt"
	"math"
	"sort"
)

func gcd(a, b int64) int64 {
	if a == 0 {
		return b
	}
	return gcd(b%a, a)
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b int64) int64 {
	// ugly but useful
	return a + b - max(a, b)
}

func sqrt(a int64) int64 {
	x := math.Sqrt(float64(a))
	return int64(x)
}

var m = map[int64][]int64{}

func cal(i, j, upper int64) {
	base1 := j*j - i*i
	base2 := 2 * i * j
	for k := upper / 2 / max(base1, base2); k >= 1; k-- {
		m[k*base1] = append(m[k*base1], base2*k)
		m[k*base2] = append(m[k*base2], base1*k)
	}
}

func cal2(a_2, hight, hight_and_b, upper int64) int64 {
	if hight_and_b <= hight*2 {
		return 0
	}

	c := sqrt(hight*hight + a_2*a_2)
	a_2 *= 2
	hight_and_b -= hight
	x := a_2*a_2 + hight_and_b*hight_and_b
	y := sqrt(x)
	if y*y == x && a_2+hight_and_b*2+c*2 <= upper {
		return a_2 + hight_and_b*2 + c*2
	}
	return 0
}

func solve(upper int64) int64 {
	m = map[int64][]int64{}
	for i := int64(1); i <= upper; i++ {
		j_upper := min(upper/4.0/i, sqrt(upper/2-i*i))
		for j := i + 1; j <= j_upper; j += 2 {
			if gcd(i, j) == 1 {
				cal(i, j, upper)
			}
		}
	}

	ans := int64(0)
	for k, v := range m {
		if len(v) <= 1 {
			continue
		}
		sort.Slice(v, func(i, j int) bool {
			return v[i] < v[j]
		})
		for i := 0; i < len(v); i++ {
			for j := i + 1; j < len(v); j++ {
				ans += cal2(k, v[i], v[j], upper)
			}
		}
	}
	return ans
}

func main() {
	fmt.Println(solve(1e4))
	fmt.Println(solve(1e7))
}
