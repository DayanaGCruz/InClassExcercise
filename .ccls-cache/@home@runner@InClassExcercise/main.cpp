// Dayana Gonzalez Cruz
// In Class Exercise
// CST210
// 02/01/2022
#include <iostream>
#include "QUADRATIC.h"
using namespace std;
int main() {
  QuadraticEquation eq( 3, 13, -10);
  QuadraticEquation eq2( 3, -12, -10);

  // add them together
  QuadraticEquation sum = eq + eq2;  
  QuadraticEquation difference = eq - eq2;

  cout << "(" << eq << ") - (" << eq2 << ") = (" << difference << ")";
  return 0;
}