#include <bits/stdc++.h>
#define ii pair<int, int>
#define ll long long
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 200 + 3, MOD = 1e5;
ll n, dp[N][N];
string S;
char open_brackets[] = {'(', '[', '{'};
char close_brackets[] = {')', ']', '}'};

bool isMatch(char a, char b)
{
    for (ll i = 0; i < 3; i++)
	{
        if (a == open_brackets[i] && b == close_brackets[i])
            return true;
    }
    return false;
}

bool isOpenBracket(char a)
{
    for (ll i = 0; i < 3; i++)
	{
        if (a == open_brackets[i])
            return true;
    }
    return false;
}

bool isCloseBracket(char a)
{
    for (ll i = 0; i < 3; i++) {
        if (a == close_brackets[i])
            return true;
    }
    return false;
}

ll match(char a, char b) {
    if (a == '?' && b == '?') return 3;
    if (a == '?')
        return isCloseBracket(b);
    if (b == '?')
        return isOpenBracket(a);
    return isMatch(a, b);
}

ll getDP(ll l, ll r) {
    if ((r - l + 1) % 2 > 0) return 0; // odd length
    if (l > r) return 1;

    ll foo = dp[l][r];
    if (foo > -1) return foo;

    foo = 0;
    for (ll i = l + 1; i <= r; i++) {
        foo += getDP(l + 1, i - 1) * getDP(i + 1, r) * match(S[l], S[i]);
        foo %= MOD;
    }
    return foo;
}

int main()
{
	FASTio
    //freopen("DAUNGOAC.inp" , "r" , stdin);
	//freopen("DAUNGOAC.out" , "w" , stdout);
    cin >> n >> S;
    S = ' ' + S;

    memset(dp, -1, sizeof dp);
    cout << getDP(1, n);
}
