## Divisor Pairs

Let  $S(n)$  be the number of pairs  $(a,b)$  of distinct divisors of  $n$  such that  $a$  divides  $b$.  
For  $n=6$  we get the following pairs:  $(1,2),(1,3),(1,6),(2,6)$  and  $(3,6)$. So  $S(6)=5$.  
Let  $p_m\#$  be the product of the first  m  prime numbers, so  $p_2\#=2∗3=6$.  
Let  $E(m,n)$  be the highest integer  $k$  such that  $2^k$  divides  $S((p_m\#)^n)$.  
$E(2,1)=0$  since  $2^0$  is the highest power of $2$ that divides $S(6)=5$.  
Let  $Q(n)=\sum_{i=1}^n E(904961,i)$  
$Q(8)=2714886$.

Evaluate  $Q(10^{12})$.
