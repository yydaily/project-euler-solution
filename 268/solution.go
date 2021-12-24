package main
import "fmt"
var a = [25]int64{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97}
var u = int64(1e16)
var cnt_ = map[int]int64{}

func C(a int64, b int64) int64 {/*{{{*/
	ret := int64(1)
	for i := b+1;i<=a;i++ {
		ret = ret * i / (i-b);
	}
	return ret
}/*}}}*/
func init() {/*{{{*/
	cnt_[4] = 1
	for i:=5;i<=14;i++ {
		cnt_[i] = 0
		for j:=4;j<i;j++ {
			cnt_[i] += cnt_[j] * C(int64(i), int64(j))
		}
		cnt_[i] = 1 - cnt_[i]
	}
}/*}}}*/
func cal(buf int) int64	{
	x := int64(1)
	cnt := 0
	for i := 0;i<25;i++ {
		if (buf&(1<<i)) != 0 {
			x *= a[i]
			cnt ++
			if x > u {
				return 0
			}
		}
	}
	return cnt_[cnt] * (u/x)
}

func main() {
	upper := 1<<25
	ans := int64(0)
	for i:=1;i<upper;i++ {
		ans += cal(i)
	}
	fmt.Printf("%d\n", ans);
}
