#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1000005
const int MOD = 727355608;

int s, a, b, c, d, cnt = 0;
ll mu4, ans;
int st[N];

bool check2(){
	for (int i = 1 ; i <= s / 2; i++) if(ans[i] != ans[s - i + 1]) return false;
	return true;
}

int main(){
    cin >> s >> a >> b >> c;
    d = s - a - b - c;

    for(int i = 2; i <= a; i += 2){
        st[++cnt] = 1;
        st[s-cnt+1] = 1;
        for (int j = 2; j <= d; j += 2){
                ans[++dem] = 0;
                ans[s-dem+1] = 0;
        }
    }

    for(int i = 2 ; i <= b ; i += 2){
        ans[++dem] = 2;
        ans[s - dem + 1] = 2;
        if ( a == 0 )
            for (int j = 2 ; j <= d ; j += 2){
                st[++dem] = 0;
                st[s - dem + 1] = 0;
            }
    }

    for(int i = 2 ; i <= c ; i += 2){
        ans[++dem] = 3;
        ans[s - dem + 1] = 3;
        if (i == 2 && a == 0 && b == 0){
 		for (int j = 2 ; j <= d ; j += 2){
 			ans[++dem] = 0;
 			ans[s - dem + 1] = 0;
            }
        }
    }

    if( s % 2 ){
    	if(a % 2) ans[++dem] = 1;
    	if(b % 2) ans[++dem] = 2;
    	if(c % 2) ans[++dem] = 3;
        if(d % 2) ans[++dem] = 0;
    }

    if(check2() == false){
        cout << "Bedao!";
        return 0;
    }

    res = ans[1];
    mu4 = 1;
    for (int i = 2 ; i <= s ; i++){
        mu4 = (mu4 * 4) % MOD;
        res = (res + ans[i] * mu4) % MOD;
    }
    cout <<res ;
    return 0;
}

