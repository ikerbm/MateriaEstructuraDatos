
#include <iostream>
using namespace std;
template <typename T>
class binarytree{
private:
//clase nodo
  class node{
    //privado nodo
  private:
    T data;
    node* left;
    node* right;
    //publico nodo
  public:
    node (const T& d):data(d),left(nullptr),right(nullptr){}
    void setleft (node* p){left=p;}
    node* getleft(){retrun left;}
    bool hasleft()const{return left!=nullptr}
    void setright (node* p){right=p;}
    node* getright(){retrun right;}
    bool hasright()const{return right!=nullptr}

    const T& getdata() const{return data;}
    T& getdata(){return data;}
    bool isleaf() const{return !hasleft() && !hasright();}
};

  node* root;
  unsigned int sz;
public:
  //constructores
  binarytree():root(nullptr),sz(0){}
  binarytree(const T& n){
    root= new node(n);
    sz=1;
  }
  binarytree(const T& n,const binarytree<T>& lst,const binarytree<T>& rst){
    root=new node(n);
    n->setleft(copy(lst->root));
    n->setright(copy(rst->root));
    sz=1+lst.sz+rst.sz;
  }
  //destructor
  ~binarytree(){
    clear(root);
    cout<<"destruido"<<endl;
  }
  //constructor de copia
  binarytree(const binarytree<T>& t){
    root=copy(t.root);
    sz=t.sz;
  }
//confirmar si esta vacio
  bool empty()const{return root==nullptr;}
//copia
private:
  node* copy(node* n){
    if(n==nullptr)
    return nullptr;
    else if(n->isleaf())
    return new node(n->getdata())
    else{
      node* cl=copy(n->getleft());
      node* cr=copy(n->getright());
      node* r=new node(n->getdata());
      r->setleft(cl);
      r->setright(cr);
      return r;
    }
  }
//parte del destructor
private:
  void clear(node* n){
    if(n==nullptr)
    return;
    else if(n->isleaf())
    delete n;
    else{
      clear(n->getleft());
      clear(n->getright());
      delete n;
    }
  }
//cantidad de elementos
  unsigned int size(){return sz;}

/* OTRA MANERA DE CALCULAR EL TAMAÑO
  unsigned int size() const{
    if empty(){
      return 0;}
    else{
      return size(root);
    }
  }


private:
  unsigned int size(node* n) const{
    if(n==nullptr) return 0;
    if(n->isleaf()){return 1}
    else{
      unsigned int ls=size(n->getleft());
      unsigned int rs=size(n->getright());
      return 1+ls+rs;
    }
  }
  */
//imprimir el arbol
//imprimir
public:
  void print(){
    print(root);
  }
private:
  void print(node* n){
    if(n==nullptr) return;
    if(n->isleaf()) cout<<n->getdata()<<endl;
    else{
      cout<<n->getdata()<<endl;
      print(n->getleft());
      print(n->getright());
  }
}
//tamaño del arbol
public:
  unsigned int height(){
    return height(root);
  }
private:
  unsigned int height(node* n){
    if(n==nullptr) return 0;
    if(n->isleaf()) return 1;
    else{
      cout<<n->getdata()<<endl;
      unsigned int hls=height(n->getleft());
      unsigned int hrs=height(n->getright());
      return 1+max(hls,hrs);
  }
}
//buscador
public:
  bool find(const T& e){
    return find(e,root);
  }
private:
  bool find(const T& e,node* n){
    if(n==nullptr) return false;
    else{
      if(n->getdata()==e){return true;}
      else{
        if(find(e,n->getleft())){return true;}
        else{
          return find(e,n->getright());}
        }
      }
    }
    //recorrido del arbol
public:
  void traverse(function<void(conts T& e)> f)const{
    traverse(f,root);
  }
private:
  void traverse((function<void(conts T& e)> f),node* n){
    if(n==nullptr)
    return;
    else{
      f(n->getdata());
      traverse(f,n->getleft());
      traverse(f,n->getright());
    }
  }


};

int main(){
  cout<<"hello world"<<endl;
  binarytree<int> cinco(5);
  binarytree<int> once(11);
  binarytree<int> seis(6,cinco,once);
  binarytree<int> dosp(2);
  binarytree<int> siete(7,dosp,seis);
  binarytree<int> cuatro(4);
  binarytree<int> e;
  binarytree<int> nueve(9,cuatro,e);
  binarytree<int> otrocinco(5,e,nueve);
  binarytree<int> todo(2,siete,otrocinco);
  cout<<"tamaño "<<todo.size()<<endl;
  cout<<"arbol"<<endl<<todo.print()<<endl;

  return 0;



}
