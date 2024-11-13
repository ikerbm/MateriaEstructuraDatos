
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Heap {
  private:
    vector<T> v;
  public:
    Heap() {
      v.push_back(T());
    }
  private:
    unsigned int left(unsigned int p) const {
      return p * 2;
    }
    unsigned int right(unsigned int p) const {
      return (p *2) + 1;
    }
    unsigned int parent(unsigned int p) const {
      return p/2;
    }
    bool hasLeft(unsigned int p) const {
      return left(p) < v.size();
    }
    bool hasRight(unsigned int p) const {
      return right(p) < v.size();
    }
    void swap(unsigned p, unsigned q) {
      T temp = v[p];
      v[p] = v[q];
      v[q] = temp;
    }
  public:
    unsigned int size() const {
      return v.size();
    }

    void insert(const T& e) {
      v.push_back(e);

      unsigned int p = v.size()-1;
      while(p > 1) {
        if (v[p] > v[parent(p)]) {
          swap(p,parent(p));
        }
        p = parent(p);
      }

    }

    void print() const {
      for (int i=1; i < v.size(); i++){
        cout << v[i] << " - ";
      }
      cout << endl;
    }
};

int main() {
    return 0;
}
