#include <bits/stdc++.h>
using namespace std;

int t, n;
pair<long long, long long> a[100001];

int main(){
    freopen("WorkH.inp","r",stdin);
    freopen("WorkH.out","w",stdout);
    cin >> t;
    for (int i=1; i<=t; i++){
        cin >> n;
        long long ln=0;
        int pos;
        for (int i=1; i<=n; i++){
            cin >>a[i].second>> a[i].first;
            if ( a[i].second > ln ){
                    pos = i;
                    ln=a[i].second;
            }
        }

        long long s=0;
        a[pos].second=0, a[pos].first=0;
        sort (a+1,a+1+n);
        int check=0;

        for (int i=1; i<=n; i++){
            s+=a[i].second;
            if ( s > a[i].first ){
                    check=1;
                    cout << "No" <<"\n";
                    break;
                }
            }
        if ( !check )
            cout << "Yes" <<"\n";
        }
    return 0;
}
