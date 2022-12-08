## Modulo Summations

Let  $a_n$  be a sequence recursively defined by: $a_1=1,a_n=\left(\sum_{k=1}^{n−1}k\cdot a_k\right) \bmod n$.

So the first $10$ elements of  an  are: $1,1,0,3,0,3,5,4,1,9$.

Let  $f(N,M)$ represent the number of pairs $(p,q)$ such that:

$$1\leq p \leq q\leq N\ \  \text{and} \left(\sum_{i=p}^{q}a_i\right)\bmod M=0$$

It can be seen that $f(10,10)=4$ with the pairs $(3,3), (5,5), (7,9)$ and $(9,10)$.

You are also given that  $f(10^4,10^3)=97158$.

Find  $f(10^{12},10^6)$.
