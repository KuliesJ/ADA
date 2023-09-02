#include <iostream>
using namespace std;

// Code B
double Addition(double a, double b) { return a + b; }
double Subtraction(double a, double b) { return a - b; }
double Multiplication(double a, double b) { return a * b; }
double Division(double a, double b) { return a / b; }

int main() {
  // Code A
  float a, b, c;
  int opt;
  // enter the operands
  cin >> a >> b;
  // OPT-> 0-Addition, 1-Subtraction, 3-Multiplication, 4-Division
  cin >> opt;
  switch (opt) {
  case 0:
    c = Addition(a, b);
    break;
  case 1:
    c = Subtraction(a, b);
    break;
  case 2:
    c = Multiplication(a, b);
    break;
  case 3:
    c = Division(a, b);
    break;
    // more cases operations go here
    return 0;
  }
}
