#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
string s, a[N];

bool compare(string x, string y){
    string xy = x + y;
    string yx = y + x;
    return (xy > yx);
}

int main(){
    int n = 0;
    while ( cin >> s ){
        a[++n] = s;
    }

    sort(a + 1, a + 1 + n, compare);

    for (int i = 1; i <= n; i ++)
        cout << a[i];

    return 0;
}
