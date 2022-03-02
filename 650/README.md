## Divisors of Binomial Product

Let $B(n) = \prod_{k=0}^n \tbinom{n}{k}$, a product of binomial coefficients.
For example, $B(5) = \tbinom{5}{0} \times \tbinom{5}{1} \times \tbinom{5}{2} \times \tbinom{5}{3} \times \tbinom{5}{4} \times \tbinom{5}{5} = 1\times 5\times 10\times 10\times 5\times 1 = 2500$.

Let $D(n) = \sum_{d|B(n)} d$, the sum of the divisors of $B(n)$.
For example, the divisors of $B(5)$ are $1, 2, 4, 5, 10, 20, 25, 50, 100, 125, 250, 500, 625, 1250\ \text{and}\ 2500$,
so $D(5) = 1 + 2 + 4 + 5 + 10 + 20 + 25 + 50 + 100 + 125 + 250 + 500 + 625 + 1250 + 2500 = 5467$.

Let $S(n) = \sum_{k=1}^n D(k)$.
You are given $S(5)=5736$, $S(10) = 141740594713218418$ and $S(100)$ mod $1\ 000\ 000\ 007 = 332792866$.

Find $S(20\ 000)$ mod $1\ 000\ 000\ 007$.
