/****************************************************************
 * test_rt3.cpp -- Arithmetic for rt3_int, ints over sqrt(3).
 *
 *        Copyright 2022 Jesse I. Deutsch
 *
 * $Id:$
 ***************************************************************/

using namespace std;
#include <iostream>
#include "rtN_int.h"


int  RootN::N = 3;


                   // Here begins the program, main().
int main () {
   RootN a, b, c, d;
   
   a.set_rtnl (3);
   a.set_irrt (4);

                                 // we could change the value, but won't.
   RootN::N = 3;
   
   cout << "The area of a: " << a.area() << endl;
   cout << "The rational part of a:    " << a.get_rtnl() << endl;
   cout << "The irrational part of a:  " << a.get_irrt() << endl;
   cout << a << endl << endl;

   b.set_rtnl (5);
   b.set_irrt (-7);
   cout << "The irrational part of b:  " << b.get_irrt() << endl;
   cout << b << endl;
   
   c = a + b;
   cout << "The value of a + b: " << c << endl;
   c = a - b;
   cout << "The value of a - b: " << c << endl;
   cout << "The value of -b: " << -b << endl;

   cout << "The scalar product b*3: " << b * 3 << endl;
   cout << "The scalar product 3*b: " << 3 * b << endl;
   cout << "The norm of a: " << a.norm() << "\t The norm of b: " << b.norm() << endl << endl;

   cout << "The product of a times b: " << a * b << endl;
   c.set_irrt (1);
   cout << "A case of coefficient 1: " << c << endl << endl;

   cout << "The conjugate of b: " << b.conjugate() << endl << endl;
   
   cout << "Is b totally positive? " << b << "  " << b.is_totally_positive() << endl;
   c.set_rtnl(1);
   c.set_irrt(1);
   cout << "Is new c totally positive? " << c << "  " << c.is_totally_positive() << endl;
   
   cout << endl;
   cout << "Is b divisible by c? " << b.is_divisible(c) << endl;
   cout << "Is c divisible by b? " << c.is_divisible(b) << endl << endl;

   cout << "Current values,   b: " << b << ",   c: " << c << endl;
   d = b.div(c);
   cout << "Dividing b by c: " << d << endl;
   
   return 0;
}



