## Not Zeckendorf

Consider the Fibonacci sequence $\big\{1, 2, 3, 5, 8, 13, 21, \dots \big\}$.

We let $f(n)$ be the number of ways of representing an integer $n\ge 0$ as the sum of different Fibonacci numbers.
For example, $16 = 3 + 13 = 1 + 2 + 13 = 3 + 5 + 8 = 1 + 2 + 5 + 8$ and hence $f(16) = 4$. By convention $f(0) = 1$.

Further we define

$$S(n) = \sum_{k=0}^nf(k)$$

You are given $S(100) = 415$ and $S(10^4) = 312807$.

Find $S(10^{13})$.
