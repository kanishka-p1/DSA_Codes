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
  
  void print() const {
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
  
  Fraction add(Fraction const &f2) {
    int lcm = den * f2.den;
    int x = lcm / den;
    int y = lcm / f2.den;
    int numerator = x * num + (y * f2.num);
    
    Fraction fnew(numerator, lcm);
    fnew.simplify();
    
    return fnew;
  }
  
    Fraction operator+(Fraction const &f2) const {
    int lcm = den * f2.den;
    int x = lcm / den;
    int y = lcm / f2.den;
    int numerator = x * num + (y * f2.num);
    
    Fraction fnew(numerator, lcm);
    fnew.simplify();
    
    return fnew;
  }
  
  Fraction operator*(Fraction const &f2) const {
    int n = num * f2.num;
    int d = den * f2.den;
    Fraction fnew(n, d);
    fnew.simplify();
    return fnew;
  }
  
  bool operator==(Fraction const &f2) const {
    return (num == f2.num && den == f2.den);
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
  
  //f1.add(f2);
  //f1.print();
  //f2.print();
  //f1.multipy(f2);
  //f1.print();
  //f2.print();
  
  Fraction f3 = f1.add(f2);
  Fraction f4 = f1 + f2;
  f1.print();
  f2.print();
  f3.print();
  f4.print();
  
  Fraction f5 = f1 * f2;
  f5.print();
  
  if(f1 == f2) {
    cout << "equal" << endl;
  }
  else {
    cout << "not equal" << endl;
  }
}
