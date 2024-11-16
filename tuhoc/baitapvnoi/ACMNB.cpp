#include <bits/stdc++.h>
using namespace std;

int n, ans=0;
int a, b;
vector<int> c;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i=1; i<=2*n; i++){
        cin >> a >> b;
        ans += b;
        c.push_back(a-b);
    }
    sort(c.begin(), c.end());
    for (int i=0; i<n; i++)
        ans += c[i];
    cout << ans;
    return 0;
}
