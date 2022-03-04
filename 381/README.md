## (prime-k) factorial

For a prime $p$ let $S(p) = \sum_{k=1}^5 (p-k)! \bmod p $.

For example, if $p=7$, $(7-1)! + (7-2)! + (7-3)! + (7-4)! + (7-5)! = 6! + 5! + 4! + 3! + 2! = 720+120+24+6+2 = 872$.
As $872 \bmod 7 = 4$, $S(7) = 4$.

It can be verified that $\sum_{p=5}^{99} S(p) = 480$.

Find $\sum_{p=5}^{10^8} S(p)$.
