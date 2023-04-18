## Weak Goodstein sequence


For any positive integer n, the  **nth weak Goodstein sequence**  {g1, g2, g3, ...} is defined as:

-   $g_1  =  n$
-   for  $k  > 1, g_k$  is obtained by writing $g_{k-1}$  in base  $k$, interpreting it as a base  $k  + 1$ number, and subtracting $1$.

The sequence terminates when $g_k$ becomes $0$.

For example, the $6$th weak Goodstein sequence is $\{6, 11, 17, 25, \dots\}$:

-   $g_1  = 6$.
-   $g_2  = 11$ since $6 = 110_2, 110_3  = 12$, and $12 - 1 = 11$.
-   $g_3  = 17$ since $11 = 102_3, 102_4  = 18$, and $18 - 1 = 17$.
-   $g_4  = 25$ since $17 = 101_4, 101_5  = 26$, and $26 - 1 = 25$.

and so on.

It can be shown that every weak Goodstein sequence terminates.

Let $G(n)$ be the number of nonzero elements in the  $n$th weak Goodstein sequence.  
It can be verified that $G(2) = 3$, $G(4) = 21$ and $G(6) = 381$.  
It can also be verified that  $\sum G(n) = 2517$ for $1 ≤  n  < 8$.

Find the last $9$ digits of  $\sum G(n)$ for $1 ≤  n  < 16$.
