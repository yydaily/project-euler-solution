## Factors of Two in Binomial Coefficients

Define $g(n, m)$ to be the largest integer $k$ such that
$2^k$ divides $\tbinom{n}{m}$. For example, $\tbinom{12}{5} = 792 = 2^3 \cdot 3^2 \cdot 11$, hence $g(12,5) = 3$. Then define $F(n) = \text{max}\{g(n, m):0\le m\le n\}$. $F(10)=3$ and $F(100)=6$.

Let $S(N) = \sum_{n=1}^{N}F(n)$. You are given that $S(100)=389$ and $S(10^7)= 203222840$.

Find $S(10^{16})$.
