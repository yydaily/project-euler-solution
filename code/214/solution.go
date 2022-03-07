package main

import "fmt"

var num, e []int
var maxm = 4000*10000 + 1

func init() {
	num = make([]int, maxm)
	for i := 1; i < maxm; i++ {
		num[i] = i
	}
	e = make([]int, maxm)
	for i := 2; i < maxm; i++ {
		if num[i] == i {
			for j := i; j < maxm; j += i {
				num[j] = num[j] / i * (i - 1)
			}
		}
	}
}

func main() {
	e[1] = 1
	ans := int64(0)
	for i := 2; i < maxm; i++ {
		e[i] = e[num[i]] + 1
		if e[i] == 25 && num[i] == i-1 {
			ans += int64(i)
		}
	}
	fmt.Printf("%d\n", ans)
}
