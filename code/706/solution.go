package main /*{{{*/

import (
	"fmt"
)

const mod = 1e9 + 7

var (
	pre = [3][3][3][3]int64{}
	nxt = [3][3][3][3]int64{}
)

func gen() {
	for i := range pre {
		for j := range pre[i] {
			for k := range pre[i][j] {
				for l := range pre[i][j][k] {
					nxt[i][j][k][l] = 0
				}
			}
		}
	}

	for i := range pre {
		for j := range pre[i] {
			for k := range pre[i][j] {
				for l := range pre[i][j][k] {
					nxt[(i+1)%3][j][k][(l+i+1)%3] = (nxt[(i+1)%3][j][k][(l+i+1)%3] + pre[i][j][k][l]*4) % mod
					nxt[k][(i+1)%3][j][(l+k)%3] = (nxt[k][(i+1)%3][j][(l+k)%3] + pre[i][j][k][l]*3) % mod
					nxt[j][k][(i+1)%3][(l+j)%3] = (nxt[j][k][(i+1)%3][(l+j)%3] + pre[i][j][k][l]*3) % mod
				}
			}
		}
	}

	for i := range pre {
		for j := range pre[i] {
			for k := range pre[i][j] {
				for l := range pre[i][j][k] {
					pre[i][j][k][l] = nxt[i][j][k][l]
				}
			}
		}
	}
}

func cal(cnt int) int64 {
	for i := range pre {
		for j := range pre[i] {
			for k := range pre[i][j] {
				for l := range pre[i][j][k] {
					pre[i][j][k][l] = 0
				}
			}
		}
	}
	pre[1][0][0][1] = 3
	pre[0][1][0][0] = 3
	pre[0][0][1][0] = 3
	for i := 1; i < cnt; i++ {
		gen()
	}
	ans := int64(0)
	for i := range pre {
		for j := range pre[i] {
			for k := range pre[i][j] {
				ans += pre[i][j][k][0]
			}
		}
	}
	return ans % mod
}

func main() {
	fmt.Println(cal(2))
	fmt.Println(cal(6))
	fmt.Println(cal(1e5))
}
