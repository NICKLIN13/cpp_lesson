#include <iostream>
using namespace std;

struct Test
{
    int N, M;
};


int main(){
    int N, M;
    cout << "Input N and M: ";
    cin >> N >> M;

    cout << N << " " << M << "\n";
    Test t = {N, M};
    cout << t.N << " " << t.M << "\n";
    return 0;
}