package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader = bufio.NewReader(os.Stdin)

func getString() string {
	text, _ := reader.ReadString('\n')
	return text[:len(text)-1]
}

func main() {
	ans := make([]int64, 100)
	for i := 0; i < 100; i++ {
		a := getString()
		for i := 0; i < len(a); i++ {
			ans[i] += int64(a[len(a)-i-1] - '0')
		}
	}
	for i := 0; i < 99; i++ {
		ans[i+1] += ans[i] / 10
		ans[i] %= 10
	}
	ind := 0
	for i := 99; i >= 0; i-- {
		if ans[i] != 0 {
			ind = i
			break
		}
	}
	for i := ind; i > ind-10; i-- {
		fmt.Printf("%d", ans[i])
	}
}
