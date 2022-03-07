package main

import "fmt"

func fac(a int) int {
	if a <= 1 {
		return 1
	}
	return a * fac(a-1)
}

func C(a int, b int) int {
	return fac(a) / fac(b) / fac(a-b)
}

func get_cnt(a []int) int64 {
	ret := int64(1)
	for i := 0; i < 7; i++ {
		ret *= int64(C(10, a[i]))
	}
	return ret
}

func main() {
	sum := int64(0)
	color := int64(0)
	num := make([]int, 10)
	upper := 11 * 11 * 11 * 11 * 11 * 11 * 11
	for i := 1; i < upper; i++ {
		buf := i
		total := 0
		c := int64(0)
		for j := 0; j < 7; j++ {
			num[j] = buf % 11
			buf /= 11
			if num[j] != 0 {
				c++
			}
			total += num[j]
		}
		if total == 20 {
			cnt := get_cnt(num)
			color += c * cnt
			sum += cnt
		}
	}
	fmt.Printf("%.9f\n", 1.0*float64(color)/float64(sum))
}
