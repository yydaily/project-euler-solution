## Chinese leftovers

Let $g(a,n,b,m)$ be the smallest non-negative solution $x$ to the system:

$$
\begin{aligned}
x &= a \bmod n\\
x &= b \bmod m
\end{aligned}
$$

if such a solution exists, otherwise $0$.

E.g. $g(2,4,4,6)=10$, but $g(3,4,4,6)=0$.

Let $\varphi(n)$ be Euler's totient function.

Let $f(n,m)=g(\varphi(n),n,\varphi(m),m)$

Find $\sum f(n,m)$ for $1000000 ≤ n < m < 1005000$
