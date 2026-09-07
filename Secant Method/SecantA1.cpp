#include<bits/stdc++.h>
using namespace std;
double n;
double a[20];
double step=0.45;
double epsilon=0.0001;
double func(double x)
{
    double sum=0;
    for(int i=0; i<=n; i++)
    {
        sum+=a[i]*pow(x,n-i);
    }
    return sum;
}
double secant(double x0,double x1,int &iteration)
{
    iteration=0;
    while(true)
    {
        double x2=x1-(func(x1)*(x1-x0))/(func(x1)-func(x0));
        iteration++;
        if(fabs(x2-x1)<epsilon&&fabs(func(x2))<epsilon)
        {
            return x2;
        }
        x0=x1;
        x1=x2;

    }
}
int main()
{
    cin>>n;
    for(int i=0; i<=n; i++)
    {
        cin>>a[i];
    }
    double mx=0;
    for(int i=1; i<=n; i++)
    {
        double t=fabs(a[i]/a[0]);
        if(t>mx)
            mx=t;
    }
    double xmax=1+mx;
    double x1=-xmax;
    double x2=x1+step;
    double rootcnt=0;
    while(x2<=xmax)
    {
        if(fabs(func(x1))<epsilon)
        {
            rootcnt++;
            cout<<rootcnt<<endl;
            cout<<x1<<endl;
            cout<<"["<<x1<<" "<<x2<<"]"<<endl;
            cout<<"Iteration 0"<<endl;

        }
        else if(func(x1)*func(x2)<0)
        {
            rootcnt++;
            int iteration;
            cout<<rootcnt<<endl;
            double root=secant(x1,x2,iteration);
            cout<<root<<endl;
            cout<<"["<<x1<<" "<<x2<<"]"<<endl;
            cout<<"Iteration "<<iteration<<endl;
        }
        x1+=step;
        x2+=step;
    }
}
