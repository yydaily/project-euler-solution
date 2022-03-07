## Totient Chains

Let $\varphi$ be Euler's totient function, i.e. for a natural number $n$, $\varphi(n)$ is the number of $k$, $1 \le k \le n$, for which gcd($k,n$) = $1$.

By iterating $\varphi$, each positive integer generates a decreasing chain of numbers ending in $1$.

E.g. if we start with $5$ the sequence $5,4,2,1$ is generated.

Here is a listing of all chains with length $4$:

<center>$ 5,4,2,1 $</center>
<center>$ 7,6,2,1 $</center>
<center>$ 8,4,2,1 $</center>
<center>$ 9,6,2,1 $</center>
<center>$ 10,4,2,1 $</center>
<center>$ 12,4,2,1 $</center>
<center>$ 14,6,2,1 $</center>
<center>$ 18,6,2,1 $</center>

Only two of these chains start with a prime, their sum is $12$.

What is the sum of all primes less than $40000000$ which generate a chain of length $25$?
