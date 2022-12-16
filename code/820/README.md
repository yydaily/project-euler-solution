## $N$ th digit of Reciprocals


Let  $d_n(x)$  be the  $n^{th}$  decimal digit of the fractional part of  $x$, or  $0$  if the fractional part has fewer than  $n$  digits.

For example:

-   $d_7(1)=d_7(\frac{1}{2})=d_7(\frac{1}{4})=d_7(\frac{1}{5})=0$
-   $d_7(\frac{1}{3})=3  \text{ since  }  \frac{1}{3}=  0.3333333333...$
-   $d_7(\frac{1}{6})=6  \text{  since  }  \frac{1}{6}=  0.1666666666...$
-   $d_7(\frac{1}{7})=1  \text{  since  }  \frac{1}{7}=  0.1428571428...$

Let  $S(n)=\sum_{k=1}^nd_n\left(\cfrac{1}{k}\right)$.

You are given:

-   $S(7)=0+0+3+0+0+6+1=10$
-   $S(100)=418$

Find  $S(10^7)$.
