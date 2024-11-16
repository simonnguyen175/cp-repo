#include <bits/stdc++.h>
using namespace std;

int K, ans[1000001];
string s;

int main(){
    freopen("xoaso.inp","r",stdin);
    freopen("xoaso.out","w",stdout);
    int N;
    cin >> K >> s ;
    N=s.size();
    s=' '+s;
    stack <int> S;
    for (long i=1; i<=N; i++){
        int tmp_int = s[i] - '0';
        if (S.empty())
            S.push(tmp_int);
        else{
            while (!S.empty() && tmp_int > S.top() && K>0){
                S.pop();
                K--;
            }
            S.push(tmp_int);
        }
    }
    while (K>0 && !S.empty()){
        S.pop();
        K--;
    }
    int n=0;
    while (!S.empty()){
        ans[++n]=S.top();
        S.pop();
    }
    for (long i=n; i>=1; i--)
        cout<<ans[i];
    return 0;
}
