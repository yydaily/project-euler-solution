package main

import (
	"fmt"
	"math"
	"sort"
)

var number = []int64{}

func gen(a int64) {
	len := int64(0)
	digit := [5]int64{}
	for a > 0 {
		digit[len] = a % 10
		len++
		a /= 10
	}

	v, v2 := int64(0), int64(0)
	for i := len - 1; i >= 0; i-- {
		v = v*10 + digit[i]
		if i > 0 {
			v2 = v2*10 + digit[i]
		}
	}
	for i := int64(0); i < len; i++ {
		v = v*10 + digit[i]
		v2 = v2*10 + digit[i]
	}
	number = append(number, v)
	number = append(number, v2)
}

func check(a int64) bool {
	cnt := int64(0)
	for i := int64(2); i*i*i <= a; i++ {
		x := int64(math.Sqrt(float64(a - i*i*i)))
		if x > 1 && x*x+i*i*i == a {
			cnt++
		}
	}
	return cnt == 4
}

func main() {
	cnt := 0
	sum := int64(0)
	for i := int64(0); i < 100000; i++ {
		gen(i)
	}
	sort.Slice(number, func(i, j int) bool {
		return number[i] < number[j]
	})
	for _, i := range number {
		if check(i) {
			cnt++
			sum += i
		}
		if cnt == 5 {
			break
		}
	}
	fmt.Printf("%d\n", sum)
}
