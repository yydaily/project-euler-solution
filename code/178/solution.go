package main /*{{{*/

import (
	"fmt"
	"math"
)

const (
	e4  = int64(10000)
	e5  = int64(100000)
	e6  = int64(1000000)
	e7  = int64(10000000)
	e8  = e4 * e4
	mod = int64(1e9 + 7)
)

func sqrt(a int64) int64 {
	x := math.Sqrt(float64(a))
	return int64(x)
}

/*}}}*/

var cnt = [50][11][1050]int64{}

func main() {
	for i := 1; i <= 9; i++ {
		cnt[1][i][1<<i] = 1
	}
	for i := 1; i < 40; i++ {
		for j := 0; j <= 9; j++ {
			for k := 0; k < 1024; k++ {
				if j > 0 {
					cnt[i+1][j-1][k|1<<(j-1)] += cnt[i][j][k]
				}
				if j < 9 {
					cnt[i+1][j+1][k|1<<(j+1)] += cnt[i][j][k]
				}
			}
		}
	}
	ans := int64(0)
	for i := 10; i <= 40; i++ {
		for j := 0; j < 10; j++ {
			ans += cnt[i][j][1023]
		}
	}
	fmt.Println(ans)
}
