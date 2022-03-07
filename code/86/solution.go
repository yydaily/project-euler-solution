package main /*{{{*/

import (
	"fmt"
)

const (
	e4  = int64(10000)
	e8  = e4 * e4
	mod = 1e9 + 7
) /*}}}*/

var sqr = map[int]int{}

func Init(m int) {
	for i := 1; i <= m; i++ {
		sqr[i*i] = i
	}
}

func cal(a, b_and_c int) int {
	lower := b_and_c/2 + b_and_c%2
	upper := min(b_and_c-1, a)
	return max(0, upper-lower+1)
}

func count(a int) int {
	ret := 0
	for b_and_c := 1; b_and_c <= a*2; b_and_c++ {
		if sqr[a*a+b_and_c*b_and_c] > 0 {
			ret += cal(a, b_and_c)
		}
	}
	return ret
}

func main() {
	Init(10000)
	ans := 0
	for i := 1; i <= 10000; i++ {
		ans += count(i)
		if ans >= 1000000 {
			fmt.Println(i)
			break
		}
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	return a + b - min(a, b)
}
