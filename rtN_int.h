/****************************************************************
 * rtN_int.h -- Header file for rtN_int - ints over sqrt(N).
 *
 *        Copyright 2022 Jesse I. Deutsch
 *
 * $Id:$
 ***************************************************************/

        // Class(es)
class RootN {
protected:               // or private?

  int rtnl;
  int irrt;
  
public:

   RootN (int = 0, int = 0);

   void set_rtnl (int);
   void set_irrt (int);
   int get_rtnl ();
   int get_irrt ();

   static int N;
//   static int NN;
   
   int area ();

   RootN operator + (RootN);
   RootN operator - (RootN);
   RootN operator - ();
   RootN operator * (int a);   // scalar mult on the right
   RootN operator * (RootN);
   int   norm ();

   RootN conjugate ();
   bool  is_totally_positive ();   
   bool  is_divisible (RootN);
   RootN div (RootN);   
};

        // Additional functions, values
ostream& operator << (ostream& o, RootN a);
                                       // scalar mult on the left, no 
                                       // prototype inside class Root2.
RootN operator * (int a, RootN b);
                                       // default value

