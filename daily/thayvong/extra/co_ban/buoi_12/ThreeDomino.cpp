#include<bits/stdc++.h>
using namespace std;
int a1,a2,a3,b1,b2,b3;
int main()
    {
 //       freopen("ThreeDomino.inp","r",stdin);
    //    freopen("ThreeDomino.out","w",stdout);
        cin>>a1>>b1>>a2>>b2>>a3>>b3;
        int s1 = abs(a1 + a2 + a3 - b1 - b2 - b3);
        int s2 = abs(a1 + a2 + b3 - b1 - b2 - a3);
        int s3 = abs(a1 + b2 + a3 - b1 - a2 - b3);
        int s4 = abs(b1 + a2 + a3 - a1 - b2 - b3);
        int s5 = abs(a1 + b2 + b3 - b1 - a2 - a3);
        int s6 = abs(b1 + a2 + b3 - a1 - b2 - a3);
        int s7 = abs(b1 + b2 + a3 - a1 - a2 - b3);
        int s8 = abs(b1 + b2 + b3 - a1 - a2 - a3);
        int s9 = abs(a1 + a2 + a3 - b1 - b2 - b3);
        cout<<min({s1,s2,s3,s4,s5,s6,s7,s8});
    }
