package main /*{{{*/

import (
	"fmt"
)

var (
	num = [1000]int{}
	dis = [1000][1000]int{}
	ans = [1000][1000]int{}
)

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func G(n int) int {
	now := 1
	for i := 1; i <= n; i++ {
		now = now * 3 % (n + 1)
		num[i] = now
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			dis[num[i]][num[j]] = abs(i - j)
		}
	}
	for j := 1; j <= n; j++ {
		for i := j; i >= 1; i-- {
			if i == j {
				ans[i][j] = 0
				continue
			}
			ans[i][j] = 1e9
			for k := i; k < j; k++ {
				ans[i][j] = min(ans[i][j], ans[i][k]+ans[k+1][j]+dis[k][j])
			}
		}
	}
	return ans[1][n]
}

func main() {
	fmt.Println(G(6))
	fmt.Println(G(16))
	fmt.Println(G(976))
}
