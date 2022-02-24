## Exponent Difference

For any integer $n\gt 0$ and prime number $p$ define $\upsilon_p(n)$ as the greatest integer $r$ such that $p^r$ divides $n$.

Define

$$
D(n, m) = \sum_{p\ prime} |\upsilon_p(n) - \upsilon_p(m)|
$$

For example, $D(14, 24) = 4$.

Furthermore, define

$$
S(N) = \sum_{1\le n, m\le N} D(n, m)
$$

You are given $S(10)=210$ and $S(10^2)=37018$.

Find $S(10^{12})$. Give your answer modulo $1\ 000\ 000\ 007$.
