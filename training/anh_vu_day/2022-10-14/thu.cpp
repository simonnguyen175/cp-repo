#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    set<int> cont;
    for (int i = 1; i <= 5; i ++) cont.insert(i);
    auto it = cont.lower_bound(5);
    cout << *it << ' ' << *cont.end() << '\n';
    if ( it == cont.end() ) cout << "hi\n";
    return 0;
}
