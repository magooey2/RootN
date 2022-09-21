/****************************************************************
 * rtN_int.cpp -- Arithmetic for rtN_int, ints over sqrt(N).
 *
 *        Copyright 2022 Jesse I. Deutsch
 *
 * $Id:$
 ***************************************************************/

using namespace std;
#include <iostream>
#include <cstdio>
#include <cstring>
#include "rtN_int.h"


                              // Constructor
RootN::RootN (int a, int b)
{
   rtnl = a;
   irrt = b;
}

                               // Getters and setters.
   void RootN::set_rtnl (int n) { rtnl = n; }  
   void RootN::set_irrt (int n) { irrt = n; }
   int  RootN::get_rtnl () { return rtnl; }
   int  RootN::get_irrt () { return irrt; }

                               // overloaded operators
RootN RootN::operator + (RootN a) { 
   return RootN (rtnl + a.rtnl, irrt + a.irrt);
}

RootN RootN::operator - (RootN a) {
    return RootN (rtnl - a.rtnl, irrt - a.irrt);
}

RootN RootN::operator - () {
   return RootN (-rtnl, -irrt);
}

RootN RootN::operator * (int a) {
    return RootN (rtnl * a, irrt * a);
}

int RootN::norm () {
   return rtnl * rtnl - RootN::N * irrt * irrt;
}

ostream& operator << (ostream& o, RootN a)
{
   char sign = '+';
   int  absval = a.get_irrt();
   char abbrev [20] = "";

   sprintf (abbrev, "rt(%d)", RootN::N); 

   if (a.get_irrt() < 0) {
     sign = '-';
     absval = - absval;
   }
                                       // separate out case of coefficient 1
   if (absval != 1) 
     o << a.get_rtnl() << " " << sign << " " << absval << " " << abbrev;
   else  
     o << a.get_rtnl() << " " << sign << " " << abbrev;
   return o;
}
                                       // Ring multiplication
RootN RootN::operator * (RootN a) { 
   RootN temp;
   temp.rtnl = rtnl * a.rtnl + RootN::N * irrt * a.irrt;
   temp.irrt = rtnl * a.irrt + irrt * a.rtnl; 
   return temp;
}
                                       // scalar mult on the left, no 
                                       // prototype inside class Root2.
RootN operator * (int a, RootN b) {
   return RootN (a * b.get_rtnl(), a * b.get_irrt());
}   


                                       // Extra functions
RootN RootN::conjugate () {
   return RootN (rtnl, -irrt);
}
   
bool RootN::is_totally_positive () {
   if (rtnl <= 0) return false;
   if (norm() <= 0) return false;
   return true;
}

bool RootN::is_divisible (RootN a) {
   int a_norm = a.norm();
   int numerator_rtnl, numerator_irrt;

   numerator_rtnl = rtnl * a.rtnl - RootN::N * irrt * a.irrt;

   numerator_irrt = irrt * a.rtnl - rtnl * a.irrt;
   if ((numerator_rtnl % a_norm == 0) and (numerator_irrt % a_norm == 0))
      return true;
   else
      return false; 
}                                      // If not divisible by b, then 
                                       // 0 + 0 sqrt(2) is returned.
RootN RootN::div (RootN b) {
   int b_norm = b.norm();
   int numerator_rtnl, numerator_irrt;
   RootN temp;

   numerator_rtnl = rtnl * b.rtnl - RootN::N * irrt * b.irrt;
   numerator_irrt = irrt * b.rtnl - rtnl * b.irrt;
   if ((numerator_rtnl % b_norm == 0) and (numerator_irrt % b_norm == 0)) {
      temp.set_rtnl(numerator_rtnl / b_norm);
      temp.set_irrt(numerator_irrt / b_norm);
#ifdef DEBUG
      cout << "From div: " << numerator_rtnl / b_norm << ",   " \
           << numerator_irrt / b_norm << endl;
#endif      
      return temp;
   }
   else {
      return temp; 
   }
}

int RootN::area () {
      int s;
      s = rtnl * irrt;
      if (s < 0) s = -s;
      return s;
   }

