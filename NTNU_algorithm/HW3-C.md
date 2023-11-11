# HW3-C

假設能走出去的路徑把整個地圖切成左邊和右邊，各自產生左邊界和右邊界。只要有任何一坨岩漿同時碰觸到左右邊界，就會造成路線中斷。

## 問題
1. 岩漿碰一起之後怎麼合併？用 Union Find 嗎？要怎麼用？
2. 要把障礙物當成不能長大的岩漿嗎？
3. 岩漿的邊緣很多，會算很久怎麼辦？

### Ans
==岩漿擴散之後用queue把它存起來，多存一個timer去記擴散到第幾輪，把上面兩個包成一個struct。==

1. binary search的做法：
==隨著岩漿擴散，還有路可以走就存1，開始沒路可以走的時候存成0，用binary search找出什麼時候開始沒有路可以走的。==

![](https://hackmd.io/_uploads/SJo_WTXSn.jpg)
![](https://hackmd.io/_uploads/B1jOZ67rn.jpg)

2. disjoint set的做法：
==這個做法聽起來概念跟union find蠻像的，但他沒有講到非常細。==

![IMG_0222](https://i.imgur.com/0TrUnYQ.png)

## Ref

- [Flood Fill Algorithm - GeeksforGeeks](https://www.geeksforgeeks.org/flood-fill-algorithm/)
- [[演算法] 並查集 (Union-find Algorithm) - iT 邦幫忙::一起幫忙解決難題，拯救 IT 人的一天](https://ithelp.ithome.com.tw/articles/10209278)

One day, Jason has nightmare that he wakes up and finds part of bedroom has been burned out with lava. Fortunately, due to the slow flow of lava, Jason has some time to escape from bed to door.

There are five types of floor in Jason's bedroom, sizing N*M. Moreover, Jason wants to know that how long he can escape from bedroom.

type L: Lava, and there may be a lot of lava. Lava will flow out 1 unit per second(the available direction are up, left, right, and down)
type O: Obstalcle, where lava cannot flow, and Jason can not go through.
type C: Common floor, where lava can flow.
type B: Bed, where lava cannot flow, and exists only one time.
type D: Door, where lava cannot flow, and exists only one time.

Please tell Jason how much time he can escape bedroom from B to D safely.

Input:

4 5
CCCCC
CCCOC
CCCOC
BCCDL

Output:
7

Case 1:
10 10
CCCCCCCCCD
CCCCCCCCCC
CCCCCCCCCC
CCCCCCCCCC
CCCCCCCCCC
CCCCCCCCCC
CCCCCCCCCC
CCCCCCCCCC
CCCCCCCCCC
CBCCCCCCLC

Output 1:
8

Case 2:
10 10
LCCCCCCCCD
CCCCCCCCCC
CCCCCCCCCC
CCCCCCCCCC
CCCCCCCCCC
CCCCCLCCCC
CCCCCCCCCC
CCCCCCCCCC
CCCCCCCCCC
CBCCCCCCLC

Output 2:
3

Case 3:
8 8
LCCCCCCD
CCCCCCCC
CCCCCCCC
CCCCCCCC
CCCCCCCC
CCCCCCCC
CCCCCCCC
CBCCCCLC

Output 3:
5

Input：
6 4
BCCL
CCCL
CDOL
CCCC
COLC
CLCL
Output：
2