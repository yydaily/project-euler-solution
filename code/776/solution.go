package main

import "fmt"

var (
	cnt = [20][200]float64{}
	val = [20][200]float64{}
)

func init() { /*{{{*/
	cnt[0][0] = 1
	for i := 0; i < 19; i++ {
		for j := 0; j < 200; j++ {
			for add := 0; add < 10 && j+add < 200; add++ {
				cnt[i+1][j+add] += cnt[i][j]
				val[i+1][j+add] += val[i][j]*10.0 + cnt[i][j]*float64(add)
			}
		}
	}
} /*}}}*/

const upper = float64(1234567890123456789)

func gao(a int64) float64 { /*{{{*/
	ret := float64(0)
	for a > 0 {
		ret += float64(a % 10)
		a /= 10
	}
	return ret
} /*}}}*/

func cal(prefix int64) float64 {
	if float64(prefix) > upper {
		return 0
	}
	prefix_sum := gao(prefix)
	max_diff := upper - float64(prefix)
	diff, index := int64(1), int64(0)
	for float64(diff)*10.0 <= float64(max_diff) {
		diff *= 10
		index++
	}

	ret := float64(0)
	for i := int64(0); i < 200; i++ {
		if cnt[index][i] > 0 && float64(i)+prefix_sum > 0 {
			ret += 1.0 * float64(val[index][i]+float64(prefix)*cnt[index][i]) / (float64(i) + prefix_sum)
		}
	}
	return ret + cal(prefix+diff)
}

func main() {
	fmt.Printf("%.13v\n", cal(0))
}
