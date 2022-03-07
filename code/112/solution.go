package main

import "fmt"

func check(a int64) int64 {
	for a > 100 && a%10 == (a/10)%10 {
		a /= 10
	}
	if a <= 100 {
		return 0
	}
	if a%10 > (a/10)%10 {
		last := a % 10
		for a > 0 {
			if a%10 > last {
				return 1
			}
			last = a % 10
			a /= 10
		}
	} else {
		last := a % 10
		for a > 0 {
			if a%10 < last {
				return 1
			}
			last = a % 10
			a /= 10
		}
	}
	return 0
}
func main() {
	cnt := int64(0)
	for i := int64(1); ; i++ {
		cnt += check(i)
		if cnt*100 == 99*i {
			fmt.Println(i)
			break
		}
	}
}
