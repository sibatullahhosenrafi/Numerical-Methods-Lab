#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cout<<"Enter num of data points: ";
    int n; cin>>n;

    cout<<"Enter x values:\n";
    vector<double> xs(n);
    for(int i=0; i<n; i++) cin>>xs[i];

    cout<<"Enter y values:\n";
    vector<double> ys(n);
    for(int i=0; i<n; i++) cin>>ys[i];

    // Divided Difference Table
    vector<vector<double>> ddiff(n, vector<double>(n));

    for(int i=0; i<n; i++)
        ddiff[i][0]=ys[i];

    for(int j=1; j<n; j++){
        for(int i=0; i+j<n; i++){
            ddiff[i][j]=
                (ddiff[i+1][j-1]-ddiff[i][j-1])
                /(xs[i+j]-xs[i]);
        }
    }

    // Print table
    cout<<"\nDivided Difference Table:\n";

    for(int i=0; i<n; i++){
        for(int j=0; j<n-i; j++){
            cout<<fixed<<setprecision(6)
                <<setw(12)<<ddiff[i][j]<<" ";
        }
        cout<<endl;
    }

    // Generate function
    cout<<"\nNewton Divided Difference Function:\n\n";
    cout<<"P(x) = ";

    for(int i=0; i<n; i++){

        if(i>0)
            cout<<" + ";

        cout<<fixed<<setprecision(9)<<ddiff[0][i];

        for(int j=0; j<i; j++){
            cout<<"(x - "<<xs[j]<<")";
        }
    }

    cout<<"\n";

    // Evaluate for any x
    cout<<"\nEnter value of x: ";
    double x;
    cin>>x;

    double ans=ys[0];
    double prod=1;

    for(int i=1; i<n; i++){
        prod*=(x-xs[i-1]);
        ans+=ddiff[0][i]*prod;
    }

    cout<<"\nP("<<x<<") = "
        <<fixed<<setprecision(9)<<ans<<endl;

    return 0;
}
