## Faulhaber's Formulas

The sum of the $k^{th}$ powers of the first $n$ positive integers can be expressed as a polynomial of degree $k+1$ with rational coefficients, the Faulhaber's Formulas:

$1^k + 2^k + \dots + n^k = \sum_{i=1}^n i^k = \sum_{i=1}^{k+1} a_i n^i = a_1n + a_2n^2 + \dots + a_nn^k + a_{k+1}n^{k+1}$
where $a_i$'s are rational coefficients that can be written as reduced fractions $p_i/q_i$ (if $a_i = 0$, we shall consider $q_i = 1$).

For example, $1^4 + 2^4 + \dots + n^4 = -\frac{1}{30}n + \frac{1}{3}n^3 + \frac{1}{2} n^4 + \frac{1}{5}n^5$

Define $D(k)$ as the value of $q_1$ for the sum of $k^{th}$ powers (i.e. the denominator of the reduced fraction $a_1$).
Define $F(m)$ as the $m^{th}$ value of $k ≥ 1$ for which $D(k) = 20010$.
You are given $D(4) = 30$ (since $a_1 = -1/30$), $D(308) = 20010$, $F(1) = 308, F(10) = 96404$.

Find $F(10^5)$.


