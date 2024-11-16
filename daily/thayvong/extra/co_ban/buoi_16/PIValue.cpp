#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    cin >> n;
    double res=0;
    for (int i=0; i<=n; i++)
        if ( i % 2 == 0 )
            res += (double) 1/(i*2+1);
        else
            res -= (double) 1/(i*2+1);
    cout << setprecision(6) << fixed << (double) 4*res;
    return 0;
}
