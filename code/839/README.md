## Beans in Bowls

The sequence  $S_n$ is defined by  $S_0=290797$  and  $S_n=S_{n−1}^2 \bmod 50515093$  for  $n>0$.

There are  $N$  bowls indexed  $0,\dots ,N−1$. Initially there are  $S_n$  beans in bowl  $n$.

At each step, the smallest index  $n$  is found such that bowl  $n$  has strictly more beans than bowl  $n+1$. Then one bean is moved from bowl  $n$  to bowl  $n+1$.

Let  $B(N)$  be the number of steps needed to sort the bowls into non-descending order.  
For example,  $B(5)=0$,  $B(6)=14263289$  and  $B(100)=3284417556$.

Find  $B(10^7)$.
