## Summation of a Modular Formula

For an odd prime  $p$, define  $f(p)= \lfloor 2^{2^p} \rfloor \bmod 2^p$  
For example, when  $p=3$,  $\lfloor 28/3\rfloor =85\equiv 5(\bmod8)$  and so  $f(3)=5$.

Further define  $g(p)=f(p)\bmod p$. You are given  $g(31)=17$.

Now define  $G(N)$  to be the summation of  $g(p)$  for all odd primes less than  $N$.  
You are given  $G(100)=474$  and  $G(10^4)=2819236$.

Find $G(10^7)$
