#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(const vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

bool less_(int a, int b) {
    return a < b;
}

class Merge{
public:
void sort(vector<int> &a) {
    vector<int> aux(a.size(), 0);
    sort(a, aux, 0, a.size()-1);
    print(aux);
    print(a);
}

private:
void merge (vector<int> &a, vector<int> &aux, int lo, int mid, int hi) {
    // copy one by one
    for (int k = lo; k <= hi; k++) {
        aux[k] = a[k];
    }

    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; k++) {
        if      (i > mid)   a[k] = aux[j++];
        else if (j > hi)    a[k] = aux[i++];
        else if (less_(aux[j], aux[i]))  a[k] = aux[j++];
        else                a[k] = aux[i++];
    }
}


void sort(vector<int> &a, vector<int> &aux, int lo, int hi) {
    if (hi <= lo) return;
    int mid = lo + (hi - lo) / 2;
    sort(a, aux, lo, mid);
    sort(a, aux, mid + 1, hi);
    merge(a, aux, lo, mid, hi);
}

};


int main() {
    // cout << "Hello World!\n";
    vector<int> v = {-3, 6, 5, -1, 0, 9, 3};


    print(v);

    Merge m;
    m.sort(v);
    print(v);


}

// a = 1432
// sort(a);


// aux = a; (14 23)
// sort....
// a = {1,2,3,4}

// a = 1234
//  i     j
//  l  m  m+1 h
// {A, B, C}
// lo = 0, hi = 3
// int mid = (lo+hi)/2 = 1


// 12 23
// 1 

// CABb
// CA Bb
// C A / B b
// AC / Bb
// ABbC



// AB bC
// ABbC <- stable
// AbBC <- unstable