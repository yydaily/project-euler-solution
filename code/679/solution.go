package main

import "fmt"

var dp = [][][]int64{}
var num = []int64{181, 141, 52, 214}

func init() {
	for i := 0; i < 34; i++ {
		j_slice := [][]int64{}
		for j := 0; j < 256; j++ {
			k_slice := []int64{}
			for k := 0; k < 16; k++ {
				k_slice = append(k_slice, 0)
			}
			j_slice = append(j_slice, k_slice)
		}
		dp = append(dp, j_slice)
	}
	for i := int64(0); i < 256; i++ {
		dp[4][i][0] = 1
	}
	for i := int64(0); i < 4; i++ {
		dp[4][num[i]][1<<i] = 1
		dp[4][num[i]][0] = 0
	}
}

func getNext(val int64) int64 {
	for i := 0; i < 4; i++ {
		if val == num[i] {
			return 1 << i
		}
	}
	return 0
}

func main() {
	l := int64(30)
	for i := int64(5); i <= l; i++ {
		for j := int64(0); j < 256; j++ {
			for k := int64(0); k < 4; k++ {
				now := ((j & 63) << 2) | k
				next := getNext(now)
				for vis := int64(0); vis < 16; vis++ {
					if (vis & next) != 0 { // acc again
						continue
					}
					dp[i][now][vis|next] += dp[i-1][j][vis]
				}
			}
		}
	}
	ans := int64(0)
	for i := int64(0); i < 256; i++ {
		ans += dp[l][i][15]
	}
	fmt.Printf("%d\n", ans)
}
