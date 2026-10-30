#include<bits/stdc++.h>
using namespace std;
int n;
double eps=1e-4;
double step=0.5;
vector<double>a(n);
double f(double t)
{
  return t*t*t*t - 8*t*t*t + 18*t*t - 8*t - 15;
}
double bm(double x1,double x2,int&iteration)
{
    double x0;
    while(fabs(x2-x1)>=eps)
    {
        x0=(x1+x2)/2;
        if(fabs(f(x0))<1e-12)
        {
            return x0;
        }
        else if(f(x1)*f(x0)>0)
        {
            x1=x0;
        }
        else x2=x0;
            iteration++;

    }
    return x0;

}
int main()
{ cin>>n;
    n++;
    a.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];

    }
    double xmax=1+max({fabs(a[3]/a[0]),fabs(a[2]/a[0]),fabs(a[1]/a[0]),fabs(a[4]/a[0])});
    double x1=-xmax;
    double x2=x1+step;
    int rootcnt=0;
    while(x2<=xmax)
    {
       // cout<<x1<<" "<<x2<<endl;
        if(f(x1)*f(x2)<0)
        {
            int iteration=0;
            rootcnt++;
            double root=bm(x1,x2,iteration);
            cout<<root<<endl;
            cout<<"["<<x1<< " "<<x2<<"]"<<endl;
            cout<<iteration<<endl;

        }
        x1=x2;
        x2=x1+step;
    }



}
