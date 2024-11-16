#include <bits/stdc++.h>
using namespace std;
long long ax,ay,bx,by,cx,cy,m,n;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>ax>>ay>>bx>>by>>cx>>cy;
    m=(by-ay)/(bx-ax);
    n=ay-ax*m;
    if (cx*m+n==cy) cout<<"YES";
    else cout<<"NO";
}

