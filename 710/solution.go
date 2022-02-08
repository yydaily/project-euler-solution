package main

import "fmt"

const mod = int64(1e6)

var cnt, cnt2 = [8]int64{}, [8]int64{}

func main() {
	cnt[0] = 1
	cnt2[2] = 1

	summary_cnt := [2]int64{1, 0}
	summary_cnt2 := [2]int64{0, 0}
	for i := 1; ; i++ {
		ind, sum_ind := i&7, i&1
		cnt[ind] = 1
		if i >= 4 {
			cnt2[ind] = (-cnt2[ind^4] + cnt[ind^4] + mod) % mod
		}
		cnt[ind] = (cnt[ind] + summary_cnt[sum_ind]) % mod
		cnt2[ind] = (cnt2[ind] + summary_cnt2[sum_ind]) % mod
		if i == 42 || i == 6 || i == 20 {
			fmt.Println(i, cnt2[ind])
		}
		if i > 42 && cnt2[ind] == 0 {
			fmt.Println(i)
			break
		}
		summary_cnt[sum_ind] = (summary_cnt[sum_ind] + cnt[ind]) % mod
		summary_cnt2[sum_ind] = (summary_cnt2[sum_ind] + cnt2[ind]) % mod
	}
}
