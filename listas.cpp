
#include <cassert>
#include <iostream>
#include <string>

template <typename T>
class list{
private:
  class node{
  private:
    T data_;
    node* next_;
  public:
    node(T d) : data_(d), next_(nullptr) {}

    void setnext(node* n) {next_ = n;}

    node getnext(void) {return next_;}

    bool hasnext(void) const {return next_ =! nullptr;}

    const T& getdata(void) const {return data_;}
    T& getdata(void) const {return data_;}
  };
private:
  node* first_;
  node* last_;
  size_t size_;
public:
  list(void): first_(nullptr), last_(nullptr), size_(0) {}

  list (const list<T>& other):first_(nullptr), last_(nullptr), size_(0) {

      node* t = other.first_;
      while(t!=nullptr){
        push_back(t->getdata())

        t= t->getnext();
    };

  }
  bool isempty(void) const{return first_ == nullptr}

  void push_back(const T& elem){
    node* e = new node(elem);
    if(isempty())
      first_ = e;
    else
      last_ -> setnext(e);
    last_=e;
    size_++;
    };
  private:
    void push_back(node* n){
      n->setnext(nullptr);
      if(isempty())
        first_=n;
      else
        last_->setnext(n);
      last_=n;
      size_++;
    }
  private:
    void split(list<T>& a, list<T>& b){
      node *t=first_;
      bool i = true;
      while(first_!=nullptr){
        t=first_;
        first_=first_->getnext();
        if(i)
          a.push_back(t);
        else
          b.push_back(t);
        i=!i;
      }
      size_=0;
    }
    void merge(list<T>& a, list<T>& b){
      node *ta=a.first_;
      node *tb=b.first_;
      while(ta!=nullptr && tb!=nullptr){
        if (ta->getdata() < tb->getdata()){
          node* n=ta;
          ta=ta->getnext();
          push_back(n);
        }
        else{
          node* n=ta;
          ta=ta->getnext();
          push_back(n);
        }
      }
      while(ta!=nullptr){
        node* n=ta;
        ta=ta->getnext();
        push_back(n);
      }
      while(tb!=nullptr){
        node* n=tb;
        tb=tb->getnext();
        push_back(n);
      }
      assert(ta==nullptr && tb ==nullptr)
      a.size_=0; a.first_=nullptr; a.last_=nullptr
      b.size_=0; b.first_=nullptr; b.last_=nullptr
    }
  public:
    void sort(){
      if(size()>1){
        list<T> l;
        list<T> r;
        split(l,r);
        l.sort();
        r.sort();
        merge(l,r);
      }
    }
    void push_front(const T& elem){
      node* e =new node(elem);
      if(isempty())
        last_=e;
      else
        e->setnext(first_);
      first_=e;
      size_++;
    }
    void insert(const T& elem, size_t k){
      assert(k>=0 && k<=size_)
      if(k==0)
        push_front(elem);
      else if(k==size)
        push_back(elem);
      else{
        node* before=first_;
        k--;
        while (k!=0) {
          k--;
          before=before->getnext();
        }

      }

    }




}
