#include <bits/stdc++.h>
using namespace std;

string s;
int d[267];

int main(){
    freopen("ReOrder.inp","r",stdin);
    freopen("ReOrder.out","w",stdout);
    cin >> s;
    memset(d,0,sizeof d);
    int c=1, tmp=0;
    char t;
    for (int i=0; i < s.size(); i++)
        d[s[i]]++;
    for (char i='a'; i<='z'; i++)
        if ( d[i] % 2 == 0 ) continue;
        else{
            tmp++;
            t=i;
            if (tmp == 2){
                cout << "no";
                return 0;
            }
        }
    string res="";
    for (char i='a'; i<='z'; i++)
        if ( d[i] > 0 )
            for (int j=1; j<=d[i]/2; j++)
                res += i;
    string st=res;
    reverse(st.begin(), st.end());
    if ( t >= 'a' && t <= 'z' )
        res+=t;
    res+=st;
    cout << res;
    return 0;
}
