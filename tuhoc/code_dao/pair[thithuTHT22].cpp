#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, A, B, ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> A >> B;

    ans += (B-A+1)*(B-A)/2;
    ans += (n-B)*(B-A+1);

    cout << ans;

    return 0;
}
