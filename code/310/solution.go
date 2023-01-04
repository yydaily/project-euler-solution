package main /*{{{*/

import (
	"fmt"
)

var (
	sg  = [200000]int64{}
	cnt = [200000]int64{}
)

func init_sg(upper int64) {
	for i := range sg {
		sg[i] = 0
		cnt[i] = 0
	}
	cnt[0] = 1
	for i := int64(1); i <= upper; i++ {
		m := map[int64]bool{}
		for j := int64(1); j*j <= i; j++ {
			m[sg[i-j*j]] = true
		}
		for j := int64(0); ; j++ {
			if m[j] {
				continue
			}
			sg[i] = j
			cnt[j]++
			break
		}
	}
}

func S(upper int64) int64 {
	init_sg(upper)
	ans1, ans2, ans3, ans4 := int64(0), int64(0), int64(0), cnt[0]
	for i := int64(0); i <= upper; i++ {
		if sg[i] == 0 {
			ans2 += upper - i
			ans3 += i
		}
	}
	buf := int64(0)
	for i := 0; cnt[i] > 0; i++ {
		for j := 0; cnt[j] > 0; j++ {
			for k := 0; cnt[k] > 0; k++ {
				if (i ^ j ^ k) == 0 {
					buf += cnt[i] * cnt[j] * cnt[k]
				}
			}
		}
	}
	ans1 = (buf - ans2*3 - ans3*3 - ans4) / 6
	return ans1 + ans2 + ans3 + ans4
}

func main() {
	fmt.Println(S(29))
	fmt.Println(S(100000))
}
