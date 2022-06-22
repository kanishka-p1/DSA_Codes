#include <iostream>
using namespace std;

class Fraction {
  private:
  int num;
  int den;
  
  public:
  
  Fraction(int num, int den) {
    this->num = num;
    this->den = den;
  }
  
  int getNum() const {
    return num;
  }
  
  int getDen() const {
    return Den;
  }
  
  void setNum(int n) {
    num = n;
  }
  
  
  void setDen(int d) {
    den = d;
  }
  
  void print() {
    cout << num << "/" << den << endl;
  }
  
  void simplify() {
    int gcd = 1;
    int j = min(this->num, this->den);
    for(int i = 1; i <= j; i++) {
      if(num % i == 0 && den % i == 0) {
        gcd = i;
      }
    }
    num = num / gcd;
    den = den / gcd;
  }
  
  void add(Fraction const &f2) {
    int lcm = den * f2.den;
    int x = lcm / den;
    int y = lcm / f2.den;
    int numerator = x * num + (y * f2.num);
    
    num = numerator;
    den = lcm;
    
    simplify();
  }
  
  void multiply(Fraction const &f2) {
    num = num * f2.num;
    den = den * f2.den;
    
    simplify();
  }
  
};

int main() {
  Fraction f1(10, 2); 
  Fraction f2(15, 4);
  
  f1.add(f2);
  
  f1.print();
  f2.print();
  
  f1.multipy(f2);
  
  f1.print();
  f2.print();
}
