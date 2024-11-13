#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <utility>
#include <string>

using namespace std;

template<typename Key, typename Value>
class Hashtable {
private:
  unsigned int sz;
  unsigned int buckets;
  vector<list<pair<Key,Value>>> storage;
public:
  Hashtable() : sz(0), buckets(11), storage(buckets) {}
  unsigned int size() const { return sz; }
  double loadfactor() const { return sz / (double)buckets; }
  void insert(const Key& k, const Value& v) {
    unsigned int h = hash<Key>{}(k);
    unsigned int p = h % buckets;
    for(pair<Key,Value>& i : storage[p]) {
      if (i.first == k) {
        i.second = v;
        return;
      }
    }
    storage[p].push_back({k,v});
    sz++;
  }
  pair<bool,Value> find(const Key& k) const {
    unsigned int h = hash<Key>{}(k);
    unsigned int p = h % buckets;
    for(pair<Key,Value> i : storage[p]) {
      if (i.first == k)
        return {true,i.second};
    }
    return {false,Value()};
  }
// private:
  void rehash() {
    unsigned int nbuckets = size() / 0.75;
    vector<list<pair<Key,Value>>> nstorage(nbuckets);
    for(unsigned int b = 0; b < buckets; b++) {
      for(pair<Key,Value> i : storage[b]) {
        unsigned int h = hash<Key>{}(i.first);
        unsigned int p = h % nbuckets;
        nstorage[p].push_back(i);
      }
    }
    storage = nstorage;
    buckets = nbuckets;
  }

  void printStats() const {
    for( unsigned int i = 0; i < buckets; i++) {
      string s(storage[i].size(),'*');
      cout << i << ":" <<  s << endl;
    }
  }
};


std::string random_string( size_t length )
{
    auto randchar = []() -> char
    {
        const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    std::string str(length,0);
    std::generate_n( str.begin(), length, randchar );
    return str;
}

int main() {
  Hashtable<string,int> x;
  for( int i = 0; i < 100; i++) {
    // cout << "Insertando " << i << endl;
    string s = random_string(10);
    // cout << s << endl;
    if (x.find(s).first) {
      cout << " Ya existe" << endl;
    }
    x.insert(s,42);
  }
  cout << x.loadfactor() << endl;
  // x.insert("Iker",40);
  // x.insert("Leidy",18);
  // x.insert("Iker", 10);

  // // cout << x.find("Leidy").first << endl;
  // // cout << x.find("Leidy").second << endl;
  // // cout << x.find("Leidy");
  // cout << x.find("Iker").second << endl;

   cout << x.size() << endl;
   x.printStats();
   x.rehash();
   x.printStats();

  cout << x.loadfactor() << endl;

}
