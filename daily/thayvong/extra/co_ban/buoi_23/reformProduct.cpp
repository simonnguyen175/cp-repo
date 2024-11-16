#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;

int n, a[1000001];
vector<int> am, duong;
long long ta=1, td=1, ans=1;

int main(){
    freopen("reformProduct.inp","r",stdin);
    freopen("reformProduct.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        if ( a[i] < 0 ) am.push_back(a[i]);
        else duong.push_back(a[i]);
    }
    sort(am.begin(), am.end());
    sort(duong.begin(), duong.end());
    for (int i=0; i<am.size(); i++){
        ta*=am[i];
        ta%=MOD;
    }
    if ( ta < 0 ){
        ta/=am[am.size()-1];
        ans*=ta;
        for (int i=0; i<duong.size(); i++){
            ans*=duong[i];
            ans%=MOD;
        }
    }
    else{
        ans*=ta;
        if ( duong[0] == 0 )
            for (int i=1; i<duong.size(); i++){
                ans*=duong[i];
                ans%=MOD;
            }
        else
            for (int i=0; i<duong.size(); i++){
                ans*=duong[i];
                ans%=MOD;
            }
    }
    cout << ans;
    return 0;
}
