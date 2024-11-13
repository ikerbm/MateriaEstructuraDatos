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

//constante porque solo añade al final del vector
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
  //en el peor de los casos lineal con respecto a los elementos
  //porque analisa todo el vector
  void find(const T& elem,int pos){
    cout<<v.size()<<"tamaño"<<endl;
    while(pos<v.size()){
      if(v[pos]==elem){
        cout<<"existe"<<endl;
        return;
      }else{pos++;}
    }
    cout<<"no existe"<<endl;
    return;
  }
public:
  //no supe hacer remove pero lo intente, se que la complejidad debe ser lineal
  void remove(const T& elem){
    int pos=0;
    while(pos<v.size()){
      if(v[pos]==elem){
        intercambio(pos);
        cout<<"hecho"<<endl;
        return;
      }else{pos++;}
    }
    cout<<"no existe"<<endl;
    return;
  }
private:
  void intercambio(int pos){
    while(pos<v.size()-2){
      v[pos]=v[pos+1];
    }
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
  P.insert(6);
  P.print();
  P.find(18);
  P.find(19);
  P.remove(19);
  P.print();



}
