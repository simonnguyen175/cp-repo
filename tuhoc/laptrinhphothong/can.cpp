#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long a[100];

int main(){
    freopen("can.inp","r",stdin);
    freopen("can.out","w",stdout);
    //INPUT & SETUP
    cin >> n >> m;
    int i=0;
    while (m > 0){
        i++;
        a[i]=m % 3;
        m/=3;
    }
    //SOLVE
    for (int i=1; i<=n; i++){
        if ( a[i] == 2  ){
            a[i+1]++;
            a[i]=-1;
        }
        if (a[i] == 3){
            a[i+1]++;
            a[i]=0;
        }
    }
    //OUTPUT
    long long check=0;
    for (int i=1; i<=n;i++){
        if (a[i] == -1){
                cout << i <<" ";
                check=1;
            }
    }
    if ( !check ) cout<<0;
    cout <<"\n";
    for (int i=1; i<=n; i++)
        if (a[i] == 1)
            cout << i <<" " ;
    return 0;
}
