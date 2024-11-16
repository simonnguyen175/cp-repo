#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;

string sa, sb;
int p[N];

int main(){
    cin >> sa >> sb;
    sa = sb + '#' + sa;
    int n = sa.size(); sa = ' ' + sa;

    p[1] = 0;
    int k = 0;

    for (int i = 2; i <= n; i ++){
        while ( k > 0 && sa[k+1] != sa[i] ) k = p[k];
        if ( sa[k+1] == sa[i] ) k ++;
        p[i] = k;
    }

    for (int i = sb.size() + 2; i <= n; i ++)
        if ( p[i] == sb.size() ) cout << i - 2 * sb.size() << ' ';

    return 0;
}
