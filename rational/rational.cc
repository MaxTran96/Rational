//Max Tran CSE 374 HW#7 December 7, 2017
//This file is the implementation of Rationals and
//it should return values in lowest factored terms.
#include "rational.h"
#include <stdlib.h>
#include <stdexcept>

/* replace this line with your implementation of the Rational type */

int calcGCD(int n, int d);

// Construct Rational 0/1
Rational::Rational() {
  num = 0;
  denom = 1;
}

// Construct Rational n/1
Rational::Rational(int n) {
  num = n;
  denom = 1;
}

// Construct Rational n/d
Rational::Rational(int n, int d) {
  if(d == 0)
    throw std::invalid_argument("Dividing by 0 is undefined");

  // if numerator is 0, we ignore denomominator 
  if(n == 0) {
    num = 0;
    denom = 1;
    return;
  }

  num = n;
  denom = d;

  // if denomominator is negative && numerator is positive
  // must flip denominator, must flip numerator; 
  // if numerator and denominator are both negative, flip numerator
  // and flip the denominator
  if(denom < 0) {
    num = -num;
    denom = -denom;
  }

  int gcd = calcGCD(num, denom);
  num = num/gcd;
  denom = denom/gcd;
}

Rational Rational::plus(Rational other) const {
  int p1 = n();
  int q1 = d();

  int p2 = other.n();
  int q2 = other.d();

  return Rational( (p1*q2 + p2*q1) , q1*q2 ); 
}


Rational Rational::minus(Rational other) const {
  Rational newOther  = Rational( -1 * other.n() , other.d() );
  return plus( newOther );
}


Rational Rational::times(Rational other) const {
  int p1 = n();
  int q1 = d();

  int p2 = other.n();
  int q2 = other.d();

  return Rational( p1*p2 , q1*q2 ); 
}

 
Rational Rational::div(Rational other) const {
  return times( Rational( other.d() , other.n() ) );
}

// get numerator
int Rational::n() const {
  return num;
}


// get denominator
int Rational::d() const {
  return denom;
}





int calcGCD(int n, int d) {
  if(n == 0 || d == 0)
    return 0;
  // remove the negative sign
  n = abs(n);
  d = abs(d);
  while(n != d) {
    if(n > d) {
      n -= d;
    } else {
      d -= n;
    }
  }

  return n;
}
