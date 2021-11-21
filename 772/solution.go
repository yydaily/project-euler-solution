package main

import "fmt"

var mod = int64(1e9+7)

func add(a, b int64) int64 {
	return (a+b)%mod
}

func mul(a, b int64) int64 {
	return a*b%mod
}

var upper = int64(1e8)

var prime  = []bool{}

func cal(ind int64) int64 {
	buffer := ind
	for buffer <= upper {
		buffer *= ind
	}
	buffer /= ind
	return buffer
}

func main() {
	ans := int64(1)
	for i:=int64(0);i<upper;i++ {
		prime = append(prime, false)
	}
	for i:=int64(2);i<upper;i++ {
		if(!prime[i]) {
			ans = mul(ans, cal(i))
			for j:=i*2;j<upper;j+=i {
				prime[j] = true
			}
		}
	}
	fmt.Printf("%d\n", mul(ans, 2))
}
