/*
Class Work A1
Write a program to find all roots of any equation using the secant method. For each
root continue the loop until |x n+1/-x n|<E AND |f(x .. 1)| <E, where E =10-3.
Search interval (-|xmaxl,|xmaxl), where |xmaxl is given in eqn (i).
|Xmax |=1+ max(a i / a n) (1)
where i=0, .... ,n. The step size of the search will be 0.45.
User Input:
No. of degree of the equation: 4
Coefficients of the equation: 1,0,-5,0,4 or 1,-3,2,6,0 (from an to ag)
Output Format:
Print the function (e.g, x^4-5x^2+4=0)
Root 1: X
Search interval for root 1=[Y,Z]
Iteration needed for the root 1=I
Similarly, for the other roots
Hint: The standard polynomial equation of (highest) degree n:
anxn + an-1xn-1+ ... +a1x + ag = 0 ... (2)
*/

#include<bits/stdc++.h>
using namespace std;
double epsilon=0.00001;
double step=0.5;
int n;
double a[20];
double func(double x)
{
    double sum=0;
    for(int i=0;i<=n;i++)
    {
        sum+=a[i]*pow(x,n-i);
    }
return sum;
}
double secant(double x0,double x1,int &iteration)
{
    iteration=0;
    while(true){
    double x2=x1-(func(x1)*(x1-x0))/(func(x1)-func(x0));
    iteration++;
    double error= fabs((x2-x1)/x2);
    if(fabs(error)<epsilon)
        return x2;
        x0=x1;
        x1=x2;
    }

}
int main()
{
  cin>>n;
  for(int i=0;i<=n;i++)
  {
      cin>>a[i];
  }
  for(int i=0;i<n;i++)
  {
     cout<<a[i]<<"x^"<<n-i<<" + ";
  }
  cout<<a[n]<<endl;
  double mx=0;
  for(int i=1;i<=n;i++)
  {
      double t=fabs(a[i]/a[0]);
      if(t>mx)
        mx=t;
  }
  double xmax=1+mx;
  double x1=-xmax;
  double x2=x1+step;
  int rootcnt=0;
  while(x2<=xmax)
  {
      if(func(x1)*func(x2)<0)
      {
          int iteration;
          double root=secant(x1,x2,iteration);
          cout<<rootcnt<<endl;
          cout<<root<<endl;
          cout<<"Int : ["<<x1<<","<<x2<<"]"<<endl;
          cout<<iteration<<endl;
          // for any one root of the equation
          // break;//just break it.
      }
          // x1 can also be one root of the function so for only one root just put a break at the end;
      else if(fabs(func(x1))<epsilon)
      {    rootcnt++;
          cout<<rootcnt<<endl;
          cout<<x1<<endl;

         cout<<"Int : ["<<x1<<","<<x2<<"]"<<endl;
          cout<<"iteration 0"<<endl;
       // break
      }
      x1+=step;
      x2+=step;
  }
}
