package main /*{{{*/

import (
	"fmt"
)

var (
	fac          = [14]int64{}
	cnt          = [10]int64{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	total_length = int64(0)
)

func init() {
	fac[0] = 1
	for i := 1; i < 14; i++ {
		fac[i] = fac[i-1] * int64(i)
	}
}

func calculate() int64 {
	now := total_length
	ans := fac[now-1] / fac[cnt[0]] / fac[now-cnt[0]-1]
	for i := 1; i < 10; i++ {
		now -= cnt[i-1]
		ans *= fac[now] / fac[cnt[i]] / fac[now-cnt[i]]
	}
	return ans * (ans - 1) / 2
}

func dfs(remain, start int64) int64 {
	if remain == 0 {
		return calculate()
	}
	if start == 9 {
		cnt[9] = remain
		ret := calculate()
		cnt[9] = 0
		return ret
	}
	ret := int64(0)
	for i := int64(0); i <= remain; i++ {
		cnt[start] = i
		ret += dfs(remain-i, start+1)
		cnt[start] = 0
	}
	return ret
}

func S(k int64) int64 {
	total_length = k
	ans := int64(0)
	for i := int64(0); i < k; i++ {
		cnt[0] = i
		ans += dfs(k-i, 1)
	}
	return ans
}

func main() {
	fmt.Println(S(3))
	fmt.Println(S(12))
}
