#include <iostream>
#include <cassert>
#include "timer.hh"
using namespace std;

template <typename T>
class vector {
 private:
  // Attributes
  T* storage;
  int sz;
  int capacity;
  double policy;

public:
  // First constructor
  vector() {
    storage  = new T[5];
    sz       = 0;
    capacity = 5;
    policy   = 1.5;
  }
  // Second constructor
  vector(int c) {
    storage  = new T[c];
    sz       = 0;
    capacity = c;
    policy   = 1.5;
  }
  // Third constructor
  vector(int c, double p) {
    assert (p >= 1.0);
    storage  = new T[5];
    sz       = 0;
    capacity = 5;
    policy   = p;
     }
 // methods
 int waste() const {
   return capacity - sz;
 }
 void push_back(const T& elem) {
   if(sz == capacity) {resize();}

   storage[sz] = elem;
   sz++;
 }
private:
  void resize() {

    int p = capacity+1;
    T* newStorage = new T[p];
    for(int i = 0; i < sz; i++) {
      newStorage[i] = storage[i];
    }
    delete[]storage;
    storage = newStorage;
    capacity = p;
  }
public:
  int size() const {
    return sz;
  }
  const T& at(int pos) const {
    assert(pos >= 0 && pos < sz);
    return storage[pos];
  }

  T& at(int pos) {
    assert(pos >= 0 && pos < sz);
    return storage[pos];
  }

  T& operator[](int p) {
      return at(p);
  }

  const T& operator[](int p) const {
      return at(p);
  }
};


int main() {
    vector<char> a(10);
    int b;
    double t = 1000;// * 1024;
        for (double i = 0; i < t*t; i++) {
          Timer t;
          a.push_back(i);

          cout<<t.elapsed()<<endl;

        }

    return 0;
}
