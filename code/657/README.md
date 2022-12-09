## Incomplete words


In the context of  **formal languages**, any finite sequence of letters of a given  **alphabet**  $\sum$  is called a  **word**  over  $\sum$. We call a word  _incomplete_  if it does not contain every letter of  $\sum$.

For example, using the alphabet  $\sum={a,b,c}$, '$ab$', '$abab$' and '' (the empty word) are incomplete words over  $\sum$, while '$abac$' is a complete word over  $\sum$.

Given an alphabet  $\sum$  of  $\alpha$  letters, we define  $I(\alpha,n)$  to be the number of incomplete words over  $\sum$  with a length not exceeding  $n$.  
For example,  $I(3,0)=1,  I(3,2)=13$  and  $I(3,4)=79$.

Find  $I(10^{7},10^{12})$. Give your answer modulo  $1\ 000\ 000\ 007$.
