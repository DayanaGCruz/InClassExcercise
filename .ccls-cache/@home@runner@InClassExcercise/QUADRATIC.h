#ifndef QUADRATIC.h
#define QUADRATIC.h
#include <cmath>
using namespace std;
#include <ostream>

class QuadraticEquation {
  private:
  // coefficients a, b, and c
  //double a, b , c;
  //private utility function
  bool nonnegDiscrim();
  
  public:
  double a, b , c;
  QuadraticEquation(double, double, double);
  double getSolution1();
  double getSolution2();

  // overload the + operator as a member function 
  QuadraticEquation operator+(const QuadraticEquation& rhs);
  friend QuadraticEquation operator-(const QuadraticEquation& lhs, const QuadraticEquation& rhs);
  friend ostream& operator<<(ostream& out, const QuadraticEquation& rhs);
};

QuadraticEquation::QuadraticEquation(double a, double b, double c){
  this->a = a;
  this->b = b;
  this->c = c;
}

bool QuadraticEquation::nonnegDiscrim(){
  // calculate the discriminant
  double disc = b * b - 4 * a * c;
  return disc >= 0;
}

double QuadraticEquation::getSolution1(){
  if(!nonnegDiscrim())return 0;
  else{
    double disc = b * b - 4 * a * c;
    // need to include cmath for square root
    double solution = (-b - sqrt(disc)) / 2 * a;
    return solution; 
  }
}
double QuadraticEquation::getSolution2(){
  if(!nonnegDiscrim())return 0;
  else{
    double disc = b * b + 4 * a * c;
    // need to include cmath for square root
    double solution = (-b - sqrt(disc)) / 2 * a;
    return solution; 
  }
}

QuadraticEquation QuadraticEquation::operator+(const QuadraticEquation& rhs){
  // sum the coefficients
  double newA = this->a + rhs.a;
  double newB = this->b + rhs.b;
  double newC = this->c + rhs.c;

  // Make a new Quadratic Equation with the new coefficients
  QuadraticEquation result(newA, newB, newC);
  // return it
  return result;
}

QuadraticEquation operator-(const QuadraticEquation& lhs, QuadraticEquation& rhs) {
  // get the difference between lhs and rhs corresponding coefficients
  double newA = lhs.a - rhs.a;
  double newB = lhs.b - rhs.b;
  double newC = lhs.c - rhs.c;

  //make a quadratic equation for the result
  QuadraticEquation result(newA, newB, newC);
  return result;
}

ostream& operator<<(ostream& out, const QuadraticEquation& rhs){
  //output the first coefficient
  out << rhs.a;
  // output x^2
  out << "x^2";
  // output a '+'
  //out << " + ";
  // output the second coefficient
  out << rhs.b;
  // output a x
  out << "x";
  // output a '+'
  out << " + ";
  // output the last coefficient
  out << rhs.c;
  // return the output buffer
  return out; 

}

#endif