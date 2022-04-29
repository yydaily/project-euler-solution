## Idempotents

If we calculate $a^2$ mod $6$ for $0 ≤ a ≤ 5$ we get: $0,1,4,3,4,1$.

The largest value of $a$ such that $a^2 ≡ a$ mod $6$ is $4$.

Let's call $M(n)$ the largest value of $a < n$ such that $a^2 ≡ a$ (mod $n$).

So $M(6) = 4$.

Find $\sum M(n)$ for $1 ≤ n ≤ 10^7$.
