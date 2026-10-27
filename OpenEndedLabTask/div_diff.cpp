#include<bits/stdc++.h>
using namespace std;
int n;
void dd(vector<double>&x,vector<double>&y)
{
    double x_val;
    cin>>x_val;
    vector<vector<double>>table(n,vector<double>(n,0));
    for(int i=0;i<n;i++)
    {
        table[i][0]=y[i];
    }
    for(int j=1;j<n;j++)
    {
        for(int i=0;i<n-j;i++)
        {
            table[i][j]=(table[i+1][j-1]-table[i][j-1])/(x[i+j]-x[i]);
        }
    }
    cout<<"\n Divided Difference Table"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            cout<<fixed<<setprecision(6)<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\n function:"<<endl;
    for(int i=0;i<n;i++)
    {
        if(i>0)cout<<" + ";
        double coeff=table[0][i];
        cout<<coeff<<" ";
        for(int j=0;j<i;j++)
        {
            cout<<"(x -"<<x[j]<<")";
        }
    }
    cout<<endl;
    double ans=0;
    for(int i=0;i<n;i++)
    {
        double coeff=table[0][i];
        double d=1;
        for(int j=0;j<i;j++ )
        {
            d*=x_val-x[j];
        }
        d*=coeff;
        ans+=d;
    }
    cout<<ans<<endl;
}
int main()
{
    cout<<"Enter no of data points"<<endl;
    cin>>n;
    vector<double>x(n),y(n);
    for(int i=0;i<n;i++)cin>>x[i];
    for(int i=0;i<n;i++)cin>>y[i];
    dd(x,y);
    return 0;
}
