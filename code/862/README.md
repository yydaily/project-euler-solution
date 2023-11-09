## Larger Digit Permutation

For a positive integer $n$ define $T(n)$ to be the number of strictly larger integers which can be formed by permuting the digits of $n$.

Leading zeros are not allowed and so for $n=2032$ the total list of permutations would be:

$$
2023, 2032, 2203, 2230, 2302, 2320, 3022, 3202, 3220
$$

giving $T(2302) = 4$.

Further define $S(k)$ to be the sum of $T(n)$ for all $k$-digit numbers $n$. You are given $S(3)=1701$.

Find $S(12)$.
