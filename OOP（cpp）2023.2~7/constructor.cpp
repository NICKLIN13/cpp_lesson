#include<iostream>
using namespace std;

class Car{
public:
  Car(int, double, int);
  ~Car() {};
  double getfuel() {
    return fuel;
  }
private:
  int maxSpeed, mile;
  double fuel;
};

Car :: Car(int ms, double fu, int distance) {
  maxSpeed = ms;
  fuel = fu;
  mile = distance;
}

int main() {
  Car mycar(240, 45.576, 150);
  cout << mycar.getfuel() << endl;
  return 0;
}