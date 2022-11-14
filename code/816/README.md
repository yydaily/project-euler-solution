## Shortest distance among points

We create an array of points  $P_n$  in a two dimensional plane using the following random number generator: 

$s_0=290797$
$s_{n+1}=s_n^2 \bmod 50515093$

$P_n=(s_{2n},s_{2n+1})$

Let  $d(k)$  be the shortest distance of any two (distinct) points among  $P_0,\dots,P${k−1}$. 
E.g.  $d(10)=9262015.547769556$

Find  $d(2000000)$. Give your answer rounded to 9 places after the decimal point.
