## Prime Factor and Exponent

For a positive integer  $n>1$, let  $p(n)$  be the smallest prime dividing  $n$, and let  $\alpha(n)$  be its  **_p_-adic order**, i.e. the largest integer such that  $p(n)^{\alpha(n)}$  divides  $n$.

For a positive integer  $K$, define the function  $f_{K}(n)$  by:

$f_{K}(n) = \cfrac{\alpha(n)-1)}{(p(n))^K}$

Also define  $\overline{f_K}$  by:

$$\overline{f_K}=\lim_{N\rightarrow \infty} \cfrac{1}{N} \sum_{n=2}^{N} f_K(n)$$

It can be verified that  $\overline{f_1} \simeq 0.282419756159$.

Find  $\sum_{K=1}^{\infty} \overline{f_K}$. Give your answer rounded to  12  digits after the decimal point.
