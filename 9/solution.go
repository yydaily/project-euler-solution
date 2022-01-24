package main

import "fmt"
import "math"

func main() {
	for i := 3;i<500;i++ {
		for j:=i+1;j<500;j++ {
			k := math.Sqrt(float64(i*i+j*j))
			if k == float64(int(k)) && i+j+int(k)==1000 {
				fmt.Printf("%d\n", i*j*int(k))
			}
		}
	}
}
