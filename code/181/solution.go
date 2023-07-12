package main /*{{{*/

import (
	"fmt"
)

var cache = [61][41][61][41]int64{}

func cal(b, w, b_cnt, w_cnt int) int64 {
	if b*w_cnt > b_cnt*w {
		return 0
	}
	if b == 0 && w == 0 {
		return 1
	}

	if cache[b][w][b_cnt][w_cnt] > 0 {
		return cache[b][w][b_cnt][w_cnt]
	}

	ret := int64(0)
	for i := 0; i <= b; i++ {
		for j := 0; j <= w; j++ {
			if (i == 0 && j == 0) ||
				i*w_cnt > b_cnt*j ||
				(i*w_cnt == b_cnt*j && i > b_cnt) ||
				(i*w_cnt == b_cnt*j && i == b_cnt && j > w_cnt) {
				continue
			}
			ret += cal(b-i, w-j, i, j)
		}
	}
	cache[b][w][b_cnt][w_cnt] = ret
	return ret
}

func main() {
	fmt.Println(cal(3, 1, 60, 0))
	fmt.Println(cal(60, 40, 60, 0))
}
