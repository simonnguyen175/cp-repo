#include<bits/stdc++.h>
using namespace std;

int n, a[10];

bool check(){
    sort(a+1, a+1+6);
    int cnt=0;
    for (int i=1; i<=3; i++)
        if ( a[i] != a[i-1] ) cnt++;
    for (int i=3; i<=6; i++)
        if ( a[i] != a[i-1] ) cnt++;
    if ( cnt > 2 ) return false;
    else return true;
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=6; j++) cin >> a[j];
        if ( check() ) cout << "Yes" <<'\n';
        else cout << "No" <<'\n';
    }
    return 0;
}
