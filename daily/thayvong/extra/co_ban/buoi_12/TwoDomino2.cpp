#include<bits/stdc++.h>
using namespace std;
int a1,a2,b1,b2;
int main()
    {
 //       freopen("TwoDomino2.inp","r",stdin);
   //     freopen("TwoDomino2.out","w",stdout);
        cin>>a1>>b1>>a2>>b2;
        int s1 = abs(a1 + a2 - b1 - b2);
        int s2 = abs(b1 + b2 - a1 - a2);
        int s3 = abs(a1 + b2 - b1 - a2);
        int s4 = abs(b1 + a2 - a1 - b2);
        cout<<min({s1,s2,s3,s4});
    }
