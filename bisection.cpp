//Bisection Method
#include<bits/stdc++.h>
using namespace std;
#define EPSILON 0.01

double func(double x,double w,double a,double y,double z)
{
  return w*x*x*x + a*x*x + y*x+z;
}

void bisection(double a, double b,double w,double x,double y,double z)
{
  if (func(a,w,x,y,z) * func(b,w,x,y,z) >= 0)
  {
    cout << "You have not assumed right a and b\n";
    return;
  }

  double c = a;
  while (abs((b-a)/a)>= EPSILON)
  {
    c = (a+b)/2;

    if (func(c,w,x,y,z) == 0.0)
      break;

    else if (func(c,w,x,y,z)*func(a,w,x,y,z) < 0)
      b = c;
    else
      a = c;
  }
  cout << "The value of root is : " << c;
}

int main()
{
  double a =-200, b = 300;
  double w,x,y,z;
  cin>>w>>x>>y>>z;
  cout<<"f(x):"<<w<<"x^3+"<<x<<"x^2+"<<y<<"x+"<<z;
  bisection(a, b,w,x,y,z);
  return 0;
}
