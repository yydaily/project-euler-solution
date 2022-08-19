
## Balanced Numbers

A positive integer with $k$ (decimal) digits is called balanced if its first $\lceil k/2\rceil$ digits sum to the same value as its last $\lceil k/2\rceil$ digits, where $\lceil x\rceil$, pronounced ceiling of $x$, is the smallest integer $\ge x$, thus $\lceil \pi \rceil = 4$ and $\lceil 5\rceil = 5$.

So, for example, all palindromes are balanced, as is $13722$.

Let $T(n)$ be the sum of all balanced numbers less than $10^n$.
Thus: $T(1) = 45, T(2) = 540$ and $T(5) = 334795890$.

Find $T(47)$ mod $3^{15}$

