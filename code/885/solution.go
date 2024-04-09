package main /*{{{*/

import (
	"fmt"
)

var (
	jiecheng = [20]int64{}
	cnt      = [10]int64{}
	mod      = int64(1123455689)
)

func init() {
	jiecheng[0] = 1
	for i := 1; i < 20; i++ {
		jiecheng[i] = jiecheng[i-1] * int64(i)
	}
}

func C(a, b int64) int64 {
	if a < b {
		return 0
	}
	return jiecheng[a] / jiecheng[b] / jiecheng[a-b] % mod
}

func cal() int64 {
	sum := int64(0)
	for _, x := range cnt {
		sum += x
	}
	ret := int64(1)
	for i := 0; i < 10; i++ {
		now := sum
		if i == 0 {
			now--
		}
		ret = ret * C(now, cnt[i]) % mod
		sum -= cnt[i]
	}
	return ret
}

func dfs(index, need, now int64, ans *int64) {
	if index == 10 {
		*ans = (*ans + now*cal()) % mod
		return
	}
	buf := now
	for i := int64(0); i <= need; i++ {
		cnt[index] = i
		dfs(index+1, need-i, buf, ans)
		cnt[index] = 0
		buf = (buf*10 + index) % mod
	}
}

func S(a int64) int64 {
	ans := int64(0)
	dfs(0, a, 0, &ans)
	return ans
}

func main() {
	fmt.Println(S(1))
	fmt.Println(S(5))
	fmt.Println(S(18))
}
