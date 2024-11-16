#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;

int t, n;
int a[N];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while ( t -- ){
        cin >> n;
        vector<int> eve;
        int mxo = 0;
        for (int i = 1; i <= n; i ++){
            cin >> a[i];
            if ( a[i] % 2 == 0 ) eve.push_back(a[i]);
            else{
                mxo = max(mxo, a[i]);
            }
        }
        sort(eve.begin(), eve.end());
        if ( eve.size() == n || eve.size() == 0 )
            cout << 0 << '\n';
        else{
            bool ck = 1;
            for (int i = 0; i < eve.size(); i ++){
                if ( mxo < eve[i] ) { ck = 0; break; }
                else mxo += eve[i];
//                cout << mxo << ' ';
            }
//            cout << ck  << '\n';

            if ( ck == 0 ) cout << eve.size() + 1 << '\n';
            else cout << eve.size() << '\n';
        }
    }

    return 0;
}
