## Divisor Graph Width

For a positive integer  $n$  create a graph using its divisors as vertices. An edge is drawn between two vertices  $a<b$  if their quotient  $b/a$  is prime. The graph can be arranged into levels where vertex  $n$  is at level  0  and vertices that are a distance  $0$  from  $k$  are on level  $n$. Define  $g(n)$  to be the maximum number of vertices in a single level.

![0881_example45.jpg](https://projecteuler.net/resources/images/0881_example45.jpg?1707508801)

The example above shows that  $g(45)=2$. You are also given  $g(5040)=12$.

Find the smallest number,  $n$, such that  $g(n)≥10^4$.
