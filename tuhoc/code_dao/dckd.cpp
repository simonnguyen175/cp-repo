#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int n, t;
multiset<int> s;
int a[N], ans = 0;

bool check(){
    auto mn = s.begin();
    auto mx = s.rbegin();
    if ( *mx - *mn > t ) return false;
    else return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> t;
    int j = 1;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        s.insert(a[i]);
        while ( !check() && j < i ){
            auto it = s.find(a[j]);
            s.erase(it);
            j ++;
        }
        ans = max(ans, i - j + 1);
    }
    cout << ans;

    return 0;
}
