#include <bits/stdc++.h>
using namespace std;
const int base=31;
const int MOD=1000003;
int hashP=0;
int main()
{
    string P ;
    cin >> P;
    P=' '+P;
    for (int i=1 ; i<P.size(); i++)
        hashP=(hashP*base+P[i]-'a'+1) % MOD;
    cout << hashP;
    return 0;
}
