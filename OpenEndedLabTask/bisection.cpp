
#include<bits/stdc++.h>
using namespace std;
int n;
vector<double>a(n);
double steps=0.5;
double eps=0.0001;

double func(double x)
{
    double ans =0;
    for(int i=0; i<n; i++)
    {
        ans+=a[i]*pow(x,n-i-1);
    }
    return ans;
}

double bisection_method(double x1,double x2,int &it)
{
    it=0;

    while(abs(x2-x1)>=eps)
    {
        double x0=(x1+x2)/2;
        it++;

        if(func(x0)*func(x1)<0)
        {
            x2=x0;
        }
        else
        {
            x1=x0;
        }
    }

    return (x1+x2)/2;
}

int main()
{
    cin>>n;
    n++;
    a.resize(n);
    for(int i=0; i<n; i++)cin>>a[i];
    double xmax=sqrt(pow(a[1]/a[0],2)-2*(a[2]/a[0]));

    double x1=-xmax;
    double x2=x1+steps;

    int rootcnt=0;

    while(x2<=xmax)
    {
        if(func(x1)*func(x2)<=0)
        {
            int iterations;
            rootcnt++;

            double root=bisection_method(x1,x2,iterations);

            cout<<rootcnt<<" root: "<<fixed<<setprecision(5)<<root;
            cout<<" interval ["<<x1<<", "<<x2<<"]"<<endl;
            cout<<"Iterations: "<<iterations<<endl;
        }

        x1+=steps;
        x2+=steps;
    }

    return 0;
}

