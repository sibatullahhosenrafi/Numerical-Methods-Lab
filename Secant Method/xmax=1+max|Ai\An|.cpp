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
      }
      else if(fabs(func(x1))<epsilon)
      {    rootcnt++;
          cout<<rootcnt<<endl;
          cout<<x1<<endl;

         cout<<"Int : ["<<x1<<","<<x2<<"]"<<endl;
          cout<<"iteration 0"<<endl;
      }
      x1+=step;
      x2+=step;
  }
}
