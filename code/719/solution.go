package main

import (
	"fmt"
	"sync"
)

func check(a int64) bool {
	upper := a * a
	num := [20]int64{}
	for ind := range num {
		num[ind] = 0
	}
	for upper > 0 {
		num[0]++
		num[num[0]] = upper % 10
		upper /= 10
	}
	for i := (1 << (num[0] - 1)) - 1; i >= 1; i-- {
		sum, now := int64(0), int64(0)
		for j := 19; j > 0; j-- {
			now = now*10 + num[j]
			if j >= 2 && (i&(1<<(j-2))) > 0 {
				sum += now
				now = 0
			}
		}
		if sum+now == a {
			return true
		}
	}
	return false
}

func main() {
	ans := int64(0)
	wg := sync.WaitGroup{}
	l := sync.Mutex{}
	wg.Add(1000000)
	for i := int64(1); i <= 1000000; i++ {
		go func(ind int64) {
			defer wg.Done()
			if check(ind) {
				l.Lock()
				ans += ind * ind
				l.Unlock()
				fmt.Println(ind)
			}
		}(i)
	}
	wg.Wait()
	fmt.Printf("%d\n", ans)
}
