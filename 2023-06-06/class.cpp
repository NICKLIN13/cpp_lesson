#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool debug = false;

class Person {
public:
    Person(string nm, int ag) 
        : name(nm) // name = nm;
        , age(ag) {
        sayhi();
    }
    void sayhi() {
        cout << "Hi, I am " << name << "!\n";
    }

    void setter(int n) {
        age = n;
    }

    int getter() {

        if (debug) cout << age << "\n";
        return age;
    }

    void grow() {
        setter(getter() + 1);
    }

    void say_age() {
        cout << getter() << "\n";
    }

private:
    string name;
    int age;
};

int main() {
    debug = true;

    Person p1("Amy", 22), p2("Bill", 33);

    p1.grow();

    cout << p1.getter() << "\n";

    // "Hi, I am {name}!"

    return 0;
}