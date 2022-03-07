package main /*{{{*/

import (
	"fmt"
)

const (
	e4  = int64(10000)
	e8  = e4 * e4
	mod = 1e9 + 7
) /*}}}*/

const e6 = 1000000

var num = [e6 + 10]int{}
var vis = [e6 + 10]bool{}

func cal_next(a int) int {
	ret := 1
	for i := 2; i*i <= a; i++ {
		if a%i == 0 {
			ret += i
			if a/i != i {
				ret += a / i
			}
		}
	}
	return ret
}

func cal_len(i, origin int, show bool) int {
	if i <= 2 || i > e6 {
		return -100
	}
	if vis[i] && i == origin {
		return 0
	}
	if vis[i] {
		return -100
	}
	if show {
		fmt.Printf("%d ", i)
	}
	ret := 1
	vis[i] = true
	ret += cal_len(num[i], origin, show)
	vis[i] = false
	return ret
}
func main() {
	for i := 2; i <= e6; i++ {
		num[i] = cal_next(i)
	}
	max_len, index := 0, 0
	for i := 2; i <= e6; i++ {
		len := cal_len(i, i, false)
		if len > 0 {
			cal_len(i, i, true)
			fmt.Println(": ", len)
		}
		if len > max_len {
			max_len = len
			index = i
		}
	}
	fmt.Println(max_len, index)
}
