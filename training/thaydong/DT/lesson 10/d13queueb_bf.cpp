#include<bits/stdc++.h>
using namespace std;

int n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    vector<int> a(n);
    for (int &v : a) cin >> v;

    while ( a.size() ){
        int p = -1;
        for (int i = 0; i < a.size(); i += k)
            if ( p == -1 || a[p] < a[i] ) p = i;
        cout << a[p] << ' ';
        a.erase(a.begin()+p);
    }

    return 0;
}
