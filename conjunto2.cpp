#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class conjunto{
private:
  vector<T> v;

public:
  conjunto(){
    v.push_back(T());
  }


  void insert(const T& elem){
    v.push_back(elem);
  }
  void print() const {
    for (int i=1; i < v.size(); i++){
      cout << v[i] << " - ";
    }
    cout << endl;
  }
  void find(const T& elem){
    find(elem,0);
  }
private:
  void find(const T& elem,int pos){
    while(pos<v.size()){
      if(v[pos]==elem){
        cout<<"existe"<<endl;
        return;
      }else{pos++;}
    }
    cout<<"no existe"<<endl;
    return;
  }

};



int main(){
  conjunto<int> P;
  P.insert(48);
  P.insert(50);
  P.insert(90);
  P.insert(1);
  P.insert(19);
  P.print();
  conjunto<int> Q;
  Q.insert(2);
  Q.insert(3);
  Q.insert(17);
  Q.insert(90);
  Q.print();


}
