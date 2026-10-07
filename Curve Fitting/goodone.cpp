#include<bits/stdc++.h>
using namespace std;

#define eps 1e-9

int n;

vector<double> gj (vector<vector<double>> arr, int sz)
{
    int row = 0;

    for (int col=0; col<sz and row<sz; col++)
    {
        int prow = row;

        for (int i=row+1; i<sz; i++)
        {
            if (fabs(arr[i][col])>fabs(arr[prow][col])) prow = i;
        }

        if (fabs(arr[prow][col])<eps) continue;

        swap (arr[prow], arr[row]);

        double pivot = arr[row][col];

        for (int j=0; j<=sz; j++)
        {
            arr[row][j] /= pivot;
        }

        for (int i=0; i<sz; i++)
        {
            if (i==row) continue;

            double m = arr[i][col];

            for (int j=0; j<=sz; j++)
            {
                arr[i][j] -= m*arr[row][j];
            }
        }
        row++;
    }

    int rank = row;

    for (int i=rank; i<sz; i++)
    {
        if (fabs(arr[i][sz])>eps)
        {
            cout << "No solution" << endl;
            return {};
        }
    }

    if (rank<sz)
    {
        cout << "Inf solution" << endl;
        return {};
    }

    vector<double> ans(sz);
    for (int i=0; i<sz; i++)
    {
        ans[i] = arr[i][sz];
    }
    return ans;

}

void linear(vector<double>x,vector<double>y)
{
    double xi=0,yi=0,xi2=0,xiyi=0;
    for(int i=0; i<n; i++)
    {
        xi +=x[i];
        yi +=y[i];
        xi2 +=x[i]*x[i];
        xiyi+=x[i]*y[i];
    }
    vector<vector<double>>arr(2,vector<double>(3));
    arr[0][0]=n,arr[0][1]=xi,arr[0][2]=yi;
    arr[1][0]=xi,arr[1][1]=xi2,arr[1][2]=xiyi;
    vector<double>ans=gj(arr,2);
    cout<<"y ="<<" "<<ans[0]<<" + "<<ans[1]<<"x"<<endl;


}


void power_method(vector<double>x,vector<double>y)
{
    double xi=0,yi=0,xi2=0,xiyi=0;
    for(int i=0; i<n; i++)
    {
        xi +=log(x[i]);
        yi +=log(y[i]);
        xi2 +=log(x[i])*log(x[i]);
        xiyi +=log(x[i])*log(y[i]);
    }
    vector<vector<double>>arr(2,vector<double>(3));
    arr[0][0]=n,arr[0][1]=xi,arr[0][2]=yi;
    arr[1][0]=xi,arr[1][1]=xi2,arr[1][2]=xiyi;
    vector<double>ans=gj(arr,2);
     double a=exp(ans[0]);
    double b=ans[1];
    cout<<"y = "<<a<<"x^"<<b<<endl;

}
void td(vector<double>x,vector<double>y)
{
    double xi=0,yi=0,xi2=0,xiyi=0;
    for(int i=0; i<n; i++)
    {
        xi+=(x[i]);
        yi+=log(y[i]);
        xi2+=(x[i])*(x[i]);
        xiyi+=(x[i])*log(y[i]);
    }
    vector<vector<double>>arr(2,vector<double>(3));
    arr[0][0]=n,arr[0][1]=xi,arr[0][2]=yi;
    arr[1][0]=xi,arr[1][1]=xi2,arr[1][2]=xiyi;
    vector<double>ans=gj(arr,2);
 double a=exp(ans[0]);
    double b=ans[1];
        cout<<"y = "<<a<<"e^("<<b<<"x)"<<endl;

}


int main()
{
    cin >> n;

    vector<double> z(n), y(n);

    for (int i=0; i<n; i++)
    {
        cin >> z[i];
    }

    for (int i=0; i<n; i++)
    {
        cin >> y[i];
    }
    linear (z,y);
    td(z,y);
    power_method(z,y);

}
