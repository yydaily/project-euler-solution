package main /*{{{*/

import "fmt"

var dp = [51][51]float64{}

func cal(a float64) float64 {
	for i := range dp {
		for j := range dp[i] {
			dp[i][j] = 0
		}
	}
	dp[0][0] = 1
	for i := 1; i <= 50; i++ {
		for j := 0; j < 50; j++ {
			dp[i][j] += dp[i-1][j] * float64(i) / a
			if j > 0 {
				dp[i][j] += dp[i-1][j-1] * (1 - float64(i)/a)
			}
		}
	}
	return dp[50][20]
}

func main() {
	l, r := float64(50), float64(100)
	for r-l >= 1e-12 {
		if cal((l+r)/2) > 0.02 {
			l = (l + r) / 2
		} else {
			r = (l + r) / 2
		}
	}
	fmt.Printf("%.10f\n", l)
}
