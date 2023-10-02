#include <iostream>
using namespace std;

class complex {
public:
  complex (double, double);

  double getre() {
    return re;
  }
  double getim() {
    return im;
  }

  ~complex() {};
private:
  double re;
  double im;
};

complex :: complex (double r, double i) {
  re = r;
  im = i;
}

complex operator+(complex& p1, complex& p2) {
  complex p(p1.getre() + p2.getre(), p1.getim() + p2.getim());
  return p;
}

ostream& operator<<(ostream& out, complex& p) {
  out << p.getre() << ", " << p.getim();
  return out;
}

int main() {
  complex a (1.5, 2.3);
  complex b (2.4, 7.5);
  complex c (0, 0);
  c = a + b;
  cout << c << endl;
  return 0; 
}