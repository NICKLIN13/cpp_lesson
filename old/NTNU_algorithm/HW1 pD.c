#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node
{
    int x;
    int y;
    struct node *next;
    struct node *prev;
} Point;

long long cross(Point *B, Point *A, Point *T)
{
    long long ax = (long long)A->x;
    long long ay = (long long)A->y;
    long long bx = (long long)B->x;
    long long by = (long long)B->y;
    long long ty = (long long)T->y;
    long long tx = (long long)T->x;
    return (long long)(ty - by) * (bx - ax) - (by - ay) * (tx - bx);
    // return (long long)(T->y - B->y) * (B->x - A->x) - (B->y - A->y) * (T->x - B->x);
}

typedef struct queue
{
    Point *head;
    Point *tail;
} Queue;

void merge(int **arr, int l, int r, int key)
{
    int m = l + (r - l) / 2;
    int len1 = m - l + 1, len2 = r - m;
    int **L = malloc(len1 * sizeof(int *));
    int **R = malloc(len2 * sizeof(int *));
    for (int i = 0; i < len1; i++)
    {
        L[i] = malloc(2 * sizeof(int));
        L[i][0] = arr[l + i][0];
        L[i][1] = arr[l + i][1];
    }
    for (int j = 0; j < len2; j++)
    {
        R[j] = malloc(2 * sizeof(int));
        R[j][0] = arr[m + 1 + j][0];
        R[j][1] = arr[m + 1 + j][1];
    }
    int i = 0, j = 0, k = l;
    while (i < len1 && j < len2)
    {
        if (L[i][key] <= R[j][key])
            arr[k][0] = L[i][0], arr[k++][1] = L[i++][1];
        else
            arr[k][0] = R[j][0], arr[k++][1] = R[j++][1];
    }
    while (i < len1)
        arr[k][0] = L[i][0], arr[k++][1] = L[i++][1];
    while (j < len2)
        arr[k][0] = R[j][0], arr[k++][1] = R[j++][1];
    free(L), free(R);
}

void mergeSort(int **arr, int l, int r, int key)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, key);
        mergeSort(arr, m + 1, r, key);
        merge(arr, l, r, key);
    }
}

void push_front(Queue *q, int x, int y)
{
    Point *newNode = malloc(sizeof(Point));
    newNode->x = x, newNode->y = y;
    //
    if (q->head)
        q->head->prev = newNode;
    newNode->next = q->head;
    newNode->prev = NULL;
    q->head = newNode;
    if (!q->tail)
        q->tail = newNode;
}

void push_back(Queue *q, int x, int y)
{
    Point *newNode = malloc(sizeof(Point));
    newNode->x = x, newNode->y = y;
    //
    if (q->tail)
        q->tail->next = newNode;
    newNode->next = NULL;
    newNode->prev = q->tail;
    q->tail = newNode;
    if (!q->head)
        q->head = newNode;
}

void pop_front(Queue *q)
{
    if (!q->head)
        return;
    Point *delNode = q->head;
    q->head = q->head->next;
    if (q->head)
        q->head->prev = NULL;
    else
        q->tail = NULL;
    free(delNode);
}

void pop_back(Queue *q)
{
    if (!q->tail)
        return;
    Point *delNode = q->tail;
    q->tail = q->tail->prev;
    if (q->tail)
        q->tail->next = NULL;
    else
        q->head = NULL;
    free(delNode);
}

long long shoelace_formula(int **polygon, int n, bool *isZero, bool *isOdd)
{
    long long area = 0;
    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        area += ((long long)polygon[i][0] * (long long)polygon[j][1] - (long long)polygon[i][1] * (long long)polygon[j][0]);
    }
    if (area == 0)
        *isZero = true;
    if (area & 1 == 1)
        *isOdd = true;
    // printf("area: %lld\n", area);
    return area >> 1;
}

int **outerTrees(int **data, int pointsSize, int *returnSize)
{
    mergeSort(data, 0, pointsSize - 1, 0);
    Queue *q = malloc(sizeof(Queue));
    q->head = NULL, q->tail = NULL;

    int idx = 0;
    for (int i = 0; i < pointsSize; i++)
    {
        Point temp;
        temp.x = data[i][0], temp.y = data[i][1];
        while (idx >= 2 && cross(q->tail, q->tail->prev, &temp) < 0)
            pop_back(q), idx--;
        push_back(q, temp.x, temp.y), idx++;
        while (idx >= 2 && cross(q->head, q->head->next, &temp) > 0)
            pop_front(q), idx--;
        push_front(q, temp.x, temp.y), idx++;
    }
    *returnSize = idx;
    Point *temp = q->head;
    int **output = malloc((*returnSize) * sizeof(int *));
    for (int i = 0; i < (*returnSize); i++)
    {
        output[i] = malloc(2 * sizeof(int));
        output[i][0] = temp->x;
        output[i][1] = temp->y;
        temp = temp->next;
    }

    int k = 1;
    int record = 0;
    for (int i = 1; i < idx; i++)
    {
        if (output[i][0] == output[i - 1][0] && output[i][1] == output[i - 1][1])
        {
            record = i;
            continue;
        }
        output[k][0] = output[i][0];
        output[k++][1] = output[i][1];
    }
    bool isZero = false;
    bool isOdd = false;

    shoelace_formula(output, k - 1, &isZero, &isOdd);
    if (isZero == true)
    {
        *returnSize = record;
        return output;
    }
    *returnSize = k - 1;
    free(q);
    return output;
}

void main()
{
    int N;
    scanf("%d", &N);
    int **data = malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
    {
        data[i] = malloc(2 * sizeof(int));
        scanf("%d %d", &data[i][0], &data[i][1]);
    }
    int numOfCH;
    int **ansArray;
    ansArray = outerTrees(data, N, &numOfCH);
    // printf("----------------------------------\n");
    // printf("numOfCH: %d\n", numOfCH);
    // for (int i = 0; i < numOfCH; i++)
    //     printf("%d, %d\n", ansArray[i][0], ansArray[i][1]);
    bool what = false;
    bool isOdd = false;
    long long ans = shoelace_formula(ansArray, numOfCH, &what, &isOdd);
    // long double ans = shoelace_formula(ansArray, numOfCH, &what);
    // long int ans_int = (long int)ans;
    // double ans_dec = (ans - ans_int);
    // printf("%g", ans_int + ans_dec);
    if (isOdd == false)
        printf("%lld", ans);
    else
        printf("%lld.5", ans);
}