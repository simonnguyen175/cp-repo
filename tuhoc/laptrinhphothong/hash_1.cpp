#include <bits/stdc++.h>
using namespace std;

const int base=31;
const int MOD =1000003;

int getHashS(int  i, int  j)
{
    return (hashS[j]-hashS[i-1]*pow[j-i+1] + MOD*MOD) mod MOD;
}

int main()
{
    string s;
    cin >> s ;
    int n = s.size();
    s=' '+s;

    int pow[n+1], hashS[n+1];
    pow[0]=1;
    hashS[0]=0;

    for (int i=1; i<=n; i++)
        pow[i] = (pow[i-1] * base) % MOD;

    for (int i=1; i<=n; i++)
        hashS[i]=(hashS[i-1]*base+s[i]-'a'+1) % MOD;

}
