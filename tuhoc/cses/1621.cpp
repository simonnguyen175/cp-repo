#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    set<int> s;
    for (int i = 1, x; i <= n; i ++)
        cin >> x, s.insert(x);
    cout << s.size();

    return 0;
}
