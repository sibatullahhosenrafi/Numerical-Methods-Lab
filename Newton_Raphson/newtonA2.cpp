#include<bits/stdc++.h>
using namespace std;
double a[20];
double step=0.45;
double epsilon=0.0001;
int n;
double func(double x)
{
    double sum=0;
    for(int i=0; i<=n; i++)
    {
        sum+=a[i]*pow(x,n-i);
    }
    return sum;
}
double dfx(double x)
{
    double sum=0;
    for(int i=0; i<=n; i++)
    {
        sum+=(n-i)*a[i]*pow(x,n-i-1);
    }
    return sum;
}
double newton(double x0,int &iteration)
{
    iteration=0;
    while(true)
    {
        double x1=x0-(func(x0)/dfx(x0));

        iteration++;
        cout<<"iter "<<iteration<<" ";
        cout<<": x"<<" = "<<x1<<" , f(x)="<<func(x1)<<", dfx(x1)"<<dfx(x1)<<endl;
        if(fabs(x1-x0)<epsilon and fabs(func(x1))<epsilon)
        {
            return x1;
        }
        x0=x1;
    }
}
int main()
{
    cin>>n;
    for(int i=0; i<=n; i++)
    {
        cin>>a[i];
    }
    int mx=0;
    for(int i=1; i<=n; i++)
    {
        double t=fabs(a[i]/a[0]);
        if(t>mx)
        {
            mx=t;
        }
    }
    double xmax=1+mx;
    double x1=- xmax;
    double x2=x1+step;
    int rootcnt=0;
    while(x2<=xmax)
    {


         if(fabs(func(x1))<epsilon)
        {
            rootcnt++;
            cout<<"root :"<<rootcnt<<endl;
            cout<<x1<<endl;
            cout<<x1<<" "<<x2<<endl;
            cout<<"iteration"<<endl;

        }
        else  if(func(x1)*func(x2)<0)
        {
            int iteration;
            rootcnt++;
            cout<<"rootNo: "<<rootcnt<<endl;
            double root=newton(x1,iteration);
            cout<<"root :"<<root<<endl;
            cout<<x1<<" "<<x2<<endl;
            cout<<iteration<<endl;

        }
        x1+=step;
        x2+=step;
    }

}
#include<bits/stdc++.h>
using namespace std;
double a[20];
double step=0.45;
double epsilon=0.0001;
int n;
double func(double x)
{
    double sum=0;
    for(int i=0; i<=n; i++)
    {
        sum+=a[i]*pow(x,n-i);
    }
    return sum;
}
double dfx(double x)
{
    double sum=0;
    for(int i=0; i<=n; i++)
    {
        sum+=(n-i)*a[i]*pow(x,n-i-1);
    }
    return sum;
}
double newton(double x0,int &iteration)
{
    iteration=0;
    while(true)
    {
        double x1=x0-(func(x0)/dfx(x0));

        iteration++;
        cout<<"iter "<<iteration<<" ";
        cout<<": x"<<" = "<<x1<<" , f(x)="<<func(x1)<<", dfx(x1)"<<dfx(x1)<<endl;
        if(fabs(x1-x0)<epsilon and fabs(func(x1))<epsilon)
        {
            return x1;
        }
        x0=x1;
    }
}
int main()
{
    cin>>n;
    for(int i=0; i<=n; i++)
    {
        cin>>a[i];
    }
    int mx=0;
    for(int i=1; i<=n; i++)
    {
        double t=fabs(a[i]/a[0]);
        if(t>mx)
        {
            mx=t;
        }
    }
    double xmax=1+mx;
    double x1=- xmax;
    double x2=x1+step;
    int rootcnt=0;
    while(x2<=xmax)
    {


         if(fabs(func(x1))<epsilon)
        {
            rootcnt++;
            cout<<"root :"<<rootcnt<<endl;
            cout<<x1<<endl;
            cout<<x1<<" "<<x2<<endl;
            cout<<"iteration"<<endl;

        }
        else  if(func(x1)*func(x2)<0)
        {
            int iteration;
            rootcnt++;
            cout<<"rootNo: "<<rootcnt<<endl;
            double root=newton(x1,iteration);
            cout<<"root :"<<root<<endl;
            cout<<x1<<" "<<x2<<endl;
            cout<<iteration<<endl;

        }
        x1+=step;
        x2+=step;
    }

}
