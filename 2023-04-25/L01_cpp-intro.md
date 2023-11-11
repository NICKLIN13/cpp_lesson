# L01_cpp-intro

- 2023-04-25 
- 22:00-23:30 
- 1.5hr
（閒聊到 24:20）

https://replit.com/@NICK-algo/L01cppintro-NICKLIN13

1. 帶過 c 和 c++ 語法的轉換，包括 cin/cout, vector/nested vector
2. 基本演算法的練習，包括 nested for-loop, 介紹 GCD
3. 講解 HW2 pC 的暴力解


# TODO

1. 4/26 約 10 點測試 HW2 C, D 的答案

- [cin/cout](#cincout)
- [練習多值 input](#練習多值-input)
- [vector initialization](#vector-initialization)
- [2D array / nested array](#2d-array--nested-array)
- [演算法舉例：最小公因數 GCD](#演算法舉例最小公因數-gcd)
- [演算法舉例：等比級數求和（高斯）](#演算法舉例等比級數求和高斯)
- [HW2 pC 暴力解](#hw2-pc-暴力解)

## cin/cout

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {

  int num1 = 123, num2=0, num3=0;
  
  // scanf("%d %d", &num1, &num2);
  cin >> num1 >> num2;

  cout << "Hello Nick!\n";
  cout << num1 << " " << num2 << num3 << "\n";

  int array[N] = {0};

  for (int i = 0; i < N; i++) {
    cout << array[i] << "\n";
  }
}
```


## 練習多值 input

- TODO 下次要練習將 input 存入 nested vector

```cpp
// N M
// R

int N = 0, M = 0, R = 0;
cin >> N >> M;
cin >> R;
cout << N << "\n" << M << "\n" << R << "\n";
```


## vector initialization

```cpp

vector<int> list(10, 0);

cout << list.size() << "\n";

for (int i = 0; i < 10; i++) {
  list[i] = i;
  // list.push_back(i);
}

for (int i = 0; i < list.size(); i++) {
  cout << list[i] << "\n";
}
cout << list.size() << "\n";
```

## 2D array / nested array

```cpp

  // 輸出 3x4 array
  //
  //     j=0  1  2  3
  //
  // i=0   0  1  2  3   j+0*4
  // i=1   4  5  6  7   j+1*4
  // i=2   8  9 10 11   j+2*4   ans = i*4 + j

  int array[3][4] = {0};
  int i = 0;
  for (i = 0; i < 4; i++) {
    cout << i << " ";
  }
  cout << "\n";
  for (i = 0; i < 4; i++) {
    cout << 4 + i  << " ";
  }
  cout << "\n";
  for (i = 0; i < 4; i++) {
    cout << 8 + i  << " ";
  }
  cout << "\n";

  int ans = 0;
  
  for (int i = 0; i < 3; i++) {
    // cout << "i=" << i << "\n";
    for (int j = 0; j < 4; j++) {
      // cout << "j=" << j << " ";
      // cout << "ans=" << 4*i+j << " ";
      cout << 4*i + j << " ";
    }
    
    cout << "\n";
  }
```

## 演算法舉例：最小公因數 GCD

```
  24, 18

  24 / 18 = 1 .. 6
  18 /  6 = 3 .. 0 ans = 6

  24 / 15 = 1 .. 9
  15 /  9 = 1 .. 6
   9 /  6 = 1 .. 3
   6 /  3 = 2 .. 0 ans = 3

  24 / 17 = 1 .. 7
  17 /  7 = 2 .. 3
   7 /  3 = 2 .. 1
   2 /  1 = 2 .. 0 ans = 1
```

## 演算法舉例：等比級數求和（高斯）

1+..+100 = (1+100)*100/2

## HW2 pC 暴力解

假設有三條路徑 abc，其中 bc 不交叉，ac, ab 會交叉。

```
abc     OK? #  ans=max

000 (X) O   0
001 c   O   1
010 b   O   1
011 bc  O   2  2
100 a   O   1
101 ac  X
110 ab  X
111 abc X
```
