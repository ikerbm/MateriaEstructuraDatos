#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <random>
#include "animals.hh"
#include "randomgen.hh"

using namespace std;

template <typename T>
class BST {
 private:
  class Node {
   private:
    T data;
    Node* left;
    Node* right;

   public:
    Node(const T& d) : data(d), left(nullptr), right(nullptr) {}

    Node* getLeft() { return left; }
    Node* getRight() { return right; }

    void setLeft(Node* n) { left = n; }
    void setRight(Node* n) { right = n; }

    bool hasLeft() const { return left != nullptr; }
    bool hasRight() const { return right != nullptr; }
    bool isLeaf() const { return !hasLeft() && !hasRight(); }

    const T& getData() const { return data; }
    T& getData() { return data; }
  };

  Node* root;
  unsigned int sz;

 public:
  BST() : root(nullptr), sz(0) {}
  BST(const BST<T>& t) {
    root = copy(t.root);
    sz = t.sz;
  }
  ~BST() { clear(root); }

 private:
  void clear(Node* n) {
    if (n == nullptr) {
      return;
    } else if (n->isLeaf()) {
      delete n;
    } else {
      clear(n->getLeft());
      clear(n->getRight());
      delete n;
    }
  }
  Node* copy(Node* n) {
    if (n == nullptr) {
      return nullptr;
    } else if (n->isLeaf()) {
      return new Node(n->getData());
    } else {
      Node* cl = copy(n->getLeft());
      Node* cr = copy(n->getRight());
      Node* r = new Node(n->getData());
      r->setLeft(cl);
      r->setRight(cr);
      return r;
    }
  }

 public:
  bool empty() const { return root == nullptr; }
  unsigned int size() const { return sz; }

  void insert(const T& e) { root = insert(e, root); }

 private:
  Node* insert(const T& e, Node* n) {
    if (n == nullptr) {
      Node* x = new Node(e);
      sz++;
      return x;
    } else if (e < n->getData()) {
      n->setLeft(insert(e, n->getLeft()));
      return n;
    } else {
      n->setRight(insert(e, n->getRight()));
      return n;
    }
  }

  bool find(const T& e) const { return find(e, root); }

 private:
  bool find(const T& e, Node* n) const {
    if (n == nullptr) {
      return false;
    } else if (e == n->getData()) {
      return true;
    } else if (e < n->getData()) {
      return find(e, n->getLeft());
    } else {
      // e > n->getData()
      return find(e, n->getRight());
    }
  }

 public:
  void print() const { return print(root); }

 private:
  void print(Node* n) const {
    if (n == nullptr) {
      return;
    } else if (n->isLeaf()) {
      cout << n->getData() << endl;
    } else {
      print(n->getLeft());
      cout << n->getData() << endl;
      print(n->getRight());
    }
  }

 public:
  void inorder(function<void(const T& e)> f) const { inorder(f, root); }
 private:
  void inorder(function<void(const T& e)> f, Node* n) const {
    if (n == nullptr) {
      return;
    } else {
      inorder(f, n->getLeft());
      f(n->getData());
      inorder(f, n->getRight());
    }
  }

 public:
  void preorder(function<void(const T& e)> f) const { preorder(f, root); }
 private:
  void preorder(function<void(const T& e)> f, Node* n) const {
    if (n == nullptr) {
      return;
    } else {
      f(n->getData());
      preorder(f, n->getLeft());
      preorder(f, n->getRight());
    }
  }

 public:
  void postorder(function<void(const T& e)> f) const { postorder(f, root); }
 private:
  void postorder(function<void(const T& e)> f, Node* n) const {
    if (n == nullptr) {
      return;
    } else {
      postorder(f, n->getLeft());
      postorder(f, n->getRight());
      f(n->getData());
    }
  }
};

int main() {

  BST<string> x;
  vector<string> animales=someAnimals();
  UniformRandom alazar(0,219);
  for(int i=0;i<219;i++){
    x.insert(animales[alazar.nextInt()]);
    cout<<alazar.nextInt()<<endl;
  }



  x.print();

  cout<<endl;
}
  //conclusiones, los animales se imprimen en orden alfabetico
  //no estoy seguro si tenemos que insertar cantidad igual a los animales en el vector,
  //o todos los animales en el vector, sin importar de que tamaño quede el arbol
  //lo voy a dejar asi para poder enfocarme en el siguiente punto
  //pero de ser de la segunda manera, solo debe crearse un vector vacio,
  //un bool inicializado en falso
  //y un ciclo while que funciones mientras el bool este falso
  //de esa manera, cada ciclo, preguntamos si el numero ya fue sacado
  //comparando el numero con el vector que creamos para añadirle los numeros ya sacados
  //como un juego de bingo
  //de esa manera puede que se agreguen mil intentos al proceso, pero aseguraremos que los animales esten todos en el arbol, sin repetir
  // este seria el fragmento de codigo que tengo en mente, pero no estoy seguro de si tengo la implementacion escrita adecuadamente

  /*bool bandera=false;
  vector<int> confirmaciones;
  while(bandera==false){
    if(confirmaciones.find(alazar.nextInt))
      {void}
    else{
      confirmacines.push_back(alazar.nextInt);
      x.insert(animales[alazar.nextInt]);
    }
    if(confirmaciones.size==220){
    bandera=true;
  }

}
