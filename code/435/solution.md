## Polynomials of Fibonacci numbers

The **Fibonacci numbers** $\{f_n,n≥0\}$ are defined recursively as $f_n=f_{n−1}+f_{n−2}$ with base cases $f_0=0$ and $f_1=1$.

Define the polynomials $\{F_n,n≥0\}$ as $F_n(x)=\sum_{i=0}^n f_i x^i$.

For example, $F_7(x)=x+x^2+2x^3+3x^4+5x^5+8x^6+13x^7$, and $F_7(11)=268357683$.

Let $n=10^{15}$. Find the sum $\sum_{x=0}^{100} F_n(x)$ and give your answer modulo $1307674368000 (=15!)$.
