
#include <iostream>
#include <functional>
#include <vector>

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
        Node(const T& d) : data(d), left(nullptr), right(nullptr) {

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
      }

        Node* root;
        unsigned int sz;

      public:
        BST() : root(nullptr), sz(0) {}
        BST(const BST<T>& t) {
          root = copy(t.root);
          sz = t.sz;
        }
        ~BST() {
          clear(root);
        }
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
          if (n == nullptr) { return nullptr;}
          else if (n->isLeaf()) {
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

        void insert(const T& e) {
          root = insert(e, root);
        }
      private:
        Node* insert(const T& e, Node* n) {
          if (n == nullptr) {
            Node* x = new Node(e);
            sz++;
            return x;
          } else if(e < n->getData()) {
            n->setLeft(insert(e, n->getLeft()));
            return n;
          } else {
            n->setRight(insert(e, n->getRight()));
            return n;
          }
        }

        bool find(const T& e) const {
          return find(e, root);
        }
      private:
        bool find(const T& e, Node* n) const {
          if (n == nullptr) {
            return false;
          } else if(e == n->getData()) {
            return true;
          } else if(e < n->getData()) {
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
        void inorder(function<void(const T& e)> f) const {
          inorder(f, root);
        }
      private:
        void inorder(function<void(const T& e)> f,Node* n) const {
          if (n == nullptr){
            return;
          } else {
            inorder(f, n->getLeft());
            f(n->getData());
            inorder(f, n->getRight());
          }
        }
      };

int main() {
  std::cout << "Hello World!\n";
  return 0;
};
