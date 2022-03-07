package main

import "fmt"

var a, b, c []int64

func init() {
	a = make([]int64, 50)
	b = make([]int64, 50)
	c = make([]int64, 50)
	a[0], b[0] = 1, 1
}

func handler(x []int64, upper int) {
	for ind := range c {
		c[ind] = 0
	}
	for i := 1; i <= upper; i++ {
		for j := 0; j <= 40; j++ {
			c[j+i] += x[j]
		}
	}
}

func main() {
	for i := 1; i <= 9; i++ {
		handler(a, 4)
		copy(a, c)
	}
	for i := 1; i <= 6; i++ {
		handler(b, 6)
		copy(b, c)
	}
	sum := int64(0)
	win := int64(0)
	for i := 1; i < 50; i++ {
		for j := 1; j < 50; j++ {
			sum += a[i] * b[j]
			if i > j {
				win += a[i] * b[j]
			}
		}
	}
	fmt.Printf("%d %d\n", win, sum)
	fmt.Printf("%.10f\n", float64(win)/float64(sum))
}
