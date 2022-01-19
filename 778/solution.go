package main

import "fmt"

const (
	mod       = int64(1e9 + 9)
	upper     = int64(765432)
	total_cnt = int64(234567)
)

var (
	cnt     = [10][10]int64{}
	cc      = [10]int64{}
	cc_back = [10]int64{}
)

func add(a int64) {
	x := int64(0)
	for a > 0 {
		cnt[x][a%10]++
		x++
		a /= 10
	}
}

func cal(ind int64) int64 {
	for i := int64(0); i < 10; i++ {
		cc[i] = cnt[ind][i]
		cc_back[i] = 0
	}
	for round := int64(1); round < total_cnt; round++ {
		for i := int64(1); i < 10; i++ {
			for j := int64(1); j < 10; j++ {
				cc_back[(i*j)%10] = (cc_back[(i*j)%10] + cc[i]*cnt[ind][j]) % mod
			}
		}
		for i := int64(1); i < 10; i++ {
			cc[i] = cc_back[i]
			cc_back[i] = 0
		}
	}
	ret := int64(0)
	for i := int64(1); i < 10; i++ {
		ret = (ret + i*cc[i]) % mod
	}
	return ret
}

func main() {
	for i := int64(0); i <= upper; i++ {
		add(i)
	}
	ans := int64(0)
	base := int64(1)
	for i := int64(0); i < 10; i++ {
		ans = (ans + cal(i)*base) % mod
		base *= 10
	}
	fmt.Printf("%d\n", ans)
}
