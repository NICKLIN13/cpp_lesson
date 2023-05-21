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