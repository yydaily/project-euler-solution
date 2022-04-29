package main /*{{{*/

import "fmt" /*}}}*/

const need_len = 10
const need_sum = need_len * (need_len - 1) / 2

var cnt = [need_len]int{}
var cnt_sum = 0
var sum = 0
var ans = int64(0)
var C = [15][15]int64{}

func init() {
	for i := 0; i < 15; i++ {
		for j := 0; j <= i; j++ {
			if i == j || j == 0 {
				C[i][j] = 1
			} else {
				C[i][j] = C[i-1][j] + C[i-1][j-1]
			}
		}
	}
}

func add() {
	buf := int64(1)
	len, len2 := need_len, need_len
	for i := 0; i < need_len; i++ {
		buf *= C[len][2-cnt[i]]
		len -= 2 - cnt[i]

		if i == 0 {
			buf *= C[len2-1][cnt[i]]
		} else {
			buf *= C[len2][cnt[i]]
		}
		len2 -= cnt[i]
	}
	ans += buf
}

func dfs(index int) {
	if cnt_sum > need_len {
		return
	}
	if index == need_len {
		if (2*need_sum-2*sum)%11 != 0 || cnt_sum != need_len {
			return
		}
		add()
		return
	}
	for i := 0; i < 3; i++ {
		cnt[index] = i
		sum += i * index
		cnt_sum += i
		dfs(index + 1)
		cnt_sum -= i
		sum -= i * index
		cnt[index] = 0
	}
}

func main() {
	dfs(0)
	fmt.Println(ans)
}
