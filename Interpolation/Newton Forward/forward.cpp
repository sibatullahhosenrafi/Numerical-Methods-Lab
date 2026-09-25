#include<bits/stdc++.h>
using namespace std;

double fact(int n){
    double f=1.0;

    for(int i=2; i<=n; i++)
        f*=i;

    return f;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cout<<"Enter num of data points: ";
    int n; cin>>n;

    cout<<"Enter x values (equally spaced):\n";
    vector<double> xs(n);

    for(int i=0; i<n; i++)
        cin>>xs[i];

    cout<<"Enter y values:\n";
    vector<double> ys(n);

    for(int i=0; i<n; i++)
        cin>>ys[i];

    // Forward Difference Table
    vector<vector<double>> diff(n, vector<double>(n));

    for(int i=0; i<n; i++)
        diff[i][0]=ys[i];

    for(int j=1; j<n; j++){
        for(int i=0; i+j<n; i++){
            diff[i][j]=
                diff[i+1][j-1]-diff[i][j-1];
        }
    }

    double h=xs[1]-xs[0];

    // Print table
    cout<<"\nForward Difference Table:\n";

    for(int i=0; i<n; i++){
        for(int j=0; j<n-i; j++){
            cout<<fixed<<setprecision(6)
                <<setw(12)<<diff[i][j]<<" ";
        }
        cout<<endl;
    }

    // Generate function
    cout<<"\nNewton Forward Function:\n\n";
    cout<<"P(x) = ";

    for(int i=0; i<n; i++){

        if(i>0)
            cout<<" + ";

        double coefficient=
            diff[0][i] /
            (fact(i)*pow(h,i));

        cout<<fixed<<setprecision(9)
            <<coefficient;

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

        ans+=
            (diff[0][i]/(fact(i)*pow(h,i)))
            *prod;
    }

    cout<<"\nP("<<x<<") = "
        <<fixed<<setprecision(9)<<ans<<endl;

    return 0;
}
