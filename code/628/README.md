## Open chess positions

A position in chess is an (orientated) arrangement of chess pieces placed on a chessboard of given size. In the following, we consider all positions in which  $n$  pawns are placed on a  $n\times n$  board in such a way, that there is a single pawn in every row and every column.

We call such a position an  _open_  position, if a rook, starting at the (empty) lower left corner and using only moves towards the right or upwards, can reach the upper right corner without moving onto any field occupied by a pawn.

Let  $f(n)$  be the number of open positions for a  $n \times n$  chessboard.  
For example,  $f(3)=2$, illustrated by the two open positions for a  $3\times 3$  chessboard below.

![Open position 1](https://projecteuler.net/project/images/p628_chess4.png)

![Open position 2](https://projecteuler.net/project/images/p628_chess5.png)

You are also given  $f(5)=70$.

Find  $f(10^8)$  modulo  $1008691207$.
