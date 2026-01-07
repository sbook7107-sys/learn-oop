#include <iostream>
#include <string>
using namespace std;

/*
class Animal {
public:
    virtual void talk() {
        cout << "Don't talk\n";
    }
};

class Cat : public Animal {
public:
    void talk() {
        cout << "Meo meo\n";
    }
};

class Dog : public Animal {
    void talk() {
        cout << "Gau gau";
    }
};

int main()
{
    Animal a;
    Animal* p;
    p=&a;
    p->talk();

    Cat c;
    p=&c;
    p->talk();

    Dog d;
    p=&d;
    p->talk();

    return 0;
}
*/

class Vehicle {
private:
    string hang;
public:
    Vehicle(string h) {hang = h;}
    virtual void nhap() {
        cout << "Nhap hang xe: ";
        getline(cin, hang);
    }
    virtual void xuat() {
        cout << "Hang xe: " << hang << endl;
    }
};

class Car : public Vehicle {
private:
    int soCho;
    string tenXe;
public:
    Car(string hang, int sC, string tX) : Vehicle(hang) {
        soCho = sC;
        tenXe = tX;
    }
    void nhap() override {
        Vehicle::nhap();
        cout << "\nNhap so cho: ";
        cin >> soCho;
    }
    void xuat() override {
        Vehicle::xuat();
        cout << "So cho ngoi: " << soCho;
        cout << "\nTen xe: " << tenXe << endl;
    }
};

int main() {
    Vehicle v("Toyota");
    //v.xuat();
    //cout << endl;
    Car c("Toyota", 5, "Camry");
    //c.xuat();
    Vehicle* p;
    p = &v;
    p->xuat();
    cout << endl;
    p = &c;
    p->xuat();

    return 0;
}
