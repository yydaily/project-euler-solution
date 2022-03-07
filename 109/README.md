## Darts

In the game of darts a player throws three darts at a target board which is split into twenty equal sized sections numbered one to twenty.

![](https://projecteuler.net/project/images/p109.png)  

The score of a dart is determined by the number of the region that the dart lands in. A dart landing outside the red/green outer ring scores zero. The black and cream regions inside this ring represent single scores. However, the red/green outer ring and middle ring score double and treble scores respectively.

At the centre of the board are two concentric circles called the bull region, or bulls-eye. The outer bull is worth $25$ points and the inner bull is a double, worth $50$ points.

There are many variations of rules but in the most popular game the players will begin with a score $301$ or $501$ and the first player to reduce their running total to zero is a winner. However, it is normal to play a "doubles out" system, which means that the player must land a double (including the double bulls-eye at the centre of the board) on their final dart to win; any other dart that would reduce their running total to one or lower means the score for that set of three darts is "bust".

When a player is able to finish on their current score it is called a "checkout" and the highest checkout is $170$: T$20$ T$20$ D$25$ (two treble $20$s and double bull).

There are exactly eleven distinct ways to checkout on a score of $6$:

|     |     |     |
| --- | --- | --- |
| D$3$  |     |     |
| D$1$  | D$2$  |     |
| S$2$  | D$2$  |     |
| D$2$  | D$1$  |     |
| S$4$  | D$1$  |     |
| S$1$  | S$1$  | D$2$  |
| S$1$  | T$1$  | D$1$  |
| S$1$  | S$3$  | D$1$  |
| D$1$  | D$1$  | D$1$  |
| D$1$  | S$2$  | D$1$  |
| S$2$  | S$2$  | D$1$  |

Note that D$1$ D$2$ is considered **different** to D$2$ D$1$ as they finish on different doubles. However, the combination S$1$ T$1$ D$1$ is considered the **same** as T$1$ S$1$ D$1$.

In addition we shall not include misses in considering combinations; for example, D$3$ is the **same** as $0$ D$3$ and $0$ $0$ D$3$.

Incredibly there are $42336$ distinct ways of checking out in total.

How many distinct ways can a player checkout with a score less than $100$?
