#include <bits/stdc++.h>
using namespace std;

string x;

int main(){
    freopen("change.inp","r",stdin);
    freopen("change.out","w",stdout);
    cin >> x;
    int i, j;
    int n = x.size();
    x=' '+x;
    i=n-1;

    while ( x[i] >= x[i+1] && i > 0 )
        i--;
    if ( i == 0 )
        cout << 0;
    else{
        j=n;
        while (x[j] <= x[i]) j--;
        swap (x[i], x[j]);
        i=i+1; j=n;
        while ( i < j ){
            swap ( x[i], x[j]);
            i++; j--;
        }
        cout << 1 <<"\n";
        for (int i=1; i<=n; i++)
            cout << x[i];
    }
    return 0;
}
