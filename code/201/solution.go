package main

import "fmt"

const value_upper = 300000

var ans [][]int
var back [][]int

func init() { /*{{{*/
	ans = make([][]int, 52)
	back = make([][]int, 52)
	for i := range ans {
		ans[i] = make([]int, value_upper)
		back[i] = make([]int, value_upper)
	}
} /*}}}*/
func add(a int) {
	for i := 0; i <= 50; i++ {
		for j := 0; j < value_upper-a; j++ {
			back[i+1][j+a] += ans[i][j]
			if back[i+1][j+a] > 2 {
				back[i+1][j+a] = 2
			}
		}
	}
	for i := 0; i <= 51; i++ {
		for j := 0; j < value_upper; j++ {
			ans[i][j] = back[i][j]
		}
	}
}
func main() {
	ans[0][0] = 1
	back[0][0] = 1
	for i := 1; i <= 100; i++ {
		add(i * i)
	}
	ret := 0
	for i := 0; i < value_upper; i++ {
		if ans[50][i] == 1 {
			ret += i
		}
	}
	fmt.Printf("%d\n", ret)
}
