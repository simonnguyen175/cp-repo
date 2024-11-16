#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    map<int, int> d;
    cout << d.size() << '\n';
    d[1] ++;
    cout << d[1] << '\n';
    cout << d.size() << '\n';
    d[1] --;
    cout << d[1] << '\n';
    cout << d.size() << '\n';

    return 0;
}
