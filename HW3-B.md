# HW3-B

要用 Max Priorty Queue 做出 Maximum Spanning Tree

## 問題
1. 題目要求：路徑要盡量大，但是如果有別種接法可以走，要挑總 weight 最小的。
2. 要怎麼找出 Max ST 之後，又把最大的路徑換成更小的？
3. 換完之後需要確保沒有 cycle 嗎？


![IMG_0221](https://i.imgur.com/RVCk7Ty.jpg)

這張圖是 example 3，MST 算出來會是綠色的路徑，但是 15 那條 (1<->4) 要被換掉，換成 12 (1<->7)，因為總 weight 要最小。

## Ref
- [(19) Prim's Minimum Spanning Tree Algorithm | Graph Theory - YouTube](https://www.youtube.com/watch?v=jsmMtJpPnhU&ab_channel=WilliamFiset)

- [Minimum Spanning Tree：Prim's Algorithm using Min-Priority Queue](http://alrightchiu.github.io/SecondRound/minimum-spanning-treeprims-algorithm-using-min-priority-queue.html)