## Description

Taipei City is a vibrant city with numerous hotels, including international chain brands, boutique hotels, and locally styled unique accommodations. These hotels are connected by undirected roads. Huai Hsun, who has a great curiosity about these hotels, often chooses different lodging options to experience various styles and services.

Now, Huai Hsun plans to depart from a certain hotel, pass through other hotels, and ultimately reach her desired destination hotel. However, she faces a challenge as she is not very skilled in route perception, navigation, and directional sense. Therefore, she needs to rely on the success probability of each road so that she can choose the best route to increase her chances of reaching the destination.

Please help Huai Hsun find the path with the maximum success probability to ensure her successful arrival at the destination.

## Input

The first line consists of n and m, where n represents the number of hotels and m represents the number of edges. The hotel numbers from 0 ton−1. Next, there will be m lines, each containing three numbers separated by spaces, a_i, b_i​, p_i​. The first and second numbers represents a bidirectional connection between hotels a_i​ and b_i​, and the third number p_i​ represents the success probability of that road. Following that, provide the values for start and end, where start represents the departure point and end represents the destination.

## Output

Please output the success probability of the path with the maximum probability, rounded to the third decimal place.

## Examples

### 1

Input

```
3 3
0 1 0.5
1 2 0.5
0 2 0.2
0 2
```

Output 1

```
0.250
```

### 2

Input

```
3 1
0 1 0.5
0 2
```

Output

```
0.000
```


### 3

Input

```
7 13
0 1 0.02
0 3 0.15
0 5 0.62
0 4 0.56
0 6 0.99
1 3 0.52
1 5 0.86
1 4 1.0
2 4 0.69
2 5 0.63
2 6 0.44
2 3 0.18
4 5 0.55
4 3
```

Output

```
0.520
```