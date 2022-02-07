package main

import "fmt"

func main() {
	a := float64(1.0)
	ind, cnt := 0, 0
	for cnt < 678910 {
		a *= 2
		ind++
		if a > 10 {
			a /= 10.0
		}
		if 1.23 <= a && a < 1.24 {
			cnt++
		}
	}
	fmt.Println(ind)
}
