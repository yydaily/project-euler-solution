package main

import "fmt"

const Len = int(1e6)
var prime = [Len]bool{}

func main() {
	cnt:=0
	for i := 2;i<Len;i++ {
		if !prime[i] {
			cnt ++
			if cnt == 10001 {
				fmt.Printf("%d\n", i)
			}
			for j:=i<<1;j<Len;j+=i {
				prime[j] = true
			}
		}
	}
}
