## Removing Cubes

Starting from a positive integer  $n$, at each step we subtract from  $n$  the largest perfect cube not exceeding  $n$, until  $n$  becomes  $0$.  
For example, with  $n=100$  the procedure ends in  $4$  steps:
$$
100 \xrightarrow{-4^3} 36 \xrightarrow{-3^3} 9 \xrightarrow{-2^3} 1 \xrightarrow{-1^3} 0.
$$

Let  $D(n)$ denote the number of steps of the procedure. Thus  $D(100)=4$.

Let  $S(N)$  denote the sum of  $D(n)$  for all positive integers  $n$  **strictly less**  than  $N$.  
For example,  $S(100)=512$.

Find  $S(10^{17})$.
