#ifndef __RANDOMGEN__HH__
#define __RANDOMGEN__HH__

#include <random>
#include <string>

class UniformRandom {
private:
  std::random_device rDevice;
  std::mt19937 rEngine;
  std::uniform_int_distribution<> intDist;
  std::uniform_real_distribution<> realDist;

public:
  UniformRandom()
      : rDevice()
      , rEngine(rDevice())
      , intDist()
      , realDist() {}

  UniformRandom(double lower, double upper)
      : rDevice()
      , rEngine(rDevice())
      , intDist(lower, upper)
      , realDist(lower, upper) {}

  int nextInt() { return intDist(rEngine); }

  void setIntRange(int a, int b, bool closed = false) {
    if (closed) {
      b = std::nextafter(b, std::numeric_limits<int>::max());
      intDist = std::uniform_int_distribution<>(a, b);
    } else
      intDist = std::uniform_int_distribution<>(a, b);
  }
  double nextReal() { return realDist(rEngine); }
  void setRealRange(double a, double b, bool closed = false) {
    if (closed) {
      b = std::nextafter(b, std::numeric_limits<double>::max());
      intDist = std::uniform_int_distribution<>(a, b);
    } else
      realDist = std::uniform_real_distribution<>(a, b);
  }
};

class RandomStrings {
private:
  unsigned int minLength;
  unsigned int maxLength;
  std::string charSet;
public:
  RandomStrings(unsigned int min, unsigned int max)
    : minLength(min), maxLength(max)
    , charSet("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz")
  {}
  std::string nextString() {
    std::string result;
    UniformRandom r(minLength, maxLength);
    unsigned int sz  = r.nextInt();
    r.setIntRange(0, charSet.size()-1);
    for (unsigned int i = 0; i < sz; i++) {
      unsigned int p = r.nextInt();
      result.push_back(charSet[p]);
    } 
    return result;
  }
};

class BernoulliRandom {
private:
  std::random_device rDevice;
  std::mt19937 rEngine;
  std::bernoulli_distribution dist;

public:
  BernoulliRandom()
      : rDevice()
      , rEngine(rDevice())
      , dist(0.5) {}

  BernoulliRandom(double p)
      : rDevice()
      , rEngine(rDevice())
      , dist(p) {}

  int next() { return dist(rEngine); }
};

#endif
