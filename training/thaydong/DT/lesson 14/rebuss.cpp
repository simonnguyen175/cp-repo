#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

string A, B, C;
int a[55], b[55], c[55], f[55][5];

void add(int &a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> A >> B >> C;
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    reverse(C.begin(), C.end());
    for (int i = 0, j = 50; i < A.size(); i ++, j --){
        if ( A[i] == '*' ) a[j] = -1;
        else a[j] = A[i] - '0';
    }

    for (int i = 0, j = 50; i < B.size(); i ++, j --){
        if ( B[i] == '*' ) b[j] = -1;
        else b[j] = B[i] - '0';
    }

    for (int i = 0, j = 50; i < C.size(); i ++, j --){
        if ( C[i] == '*' ) c[j] = -1;
        else c[j] = C[i] - '0';
    }

    f[51][0] = 1;
    for (int i = 51; i >= 1; i --)
    for (int nho = 0; nho <= 1; nho ++) if ( f[i][nho] ){
        int mna = a[i-1], mxa = a[i-1];
        int mnb = b[i-1], mxb = b[i-1];

        if ( a[i-1] == -1 ){
            mna = 0, mxa = 9;
            if ( i - 1 == 50 - A.size() + 1 ) mna = 1;
        }
        if ( b[i-1] == -1 ){
            mnb = 0, mxb = 9;
            if ( i - 1 == 50 - B.size() + 1 ) mnb = 1;
        }

        for (int j = mna; j <= mxa; j ++)
        for (int k = mnb; k <= mxb; k ++){
            int nnho = ( j + k + nho ) / 10;
            int nc = ( j + k + nho ) % 10;
            if ( c[i-1] == -1 || nc == c[i-1] )
                add(f[i-1][nnho], f[i][nho]);
        }
    }

    cout << f[1][0];

    return 0;
}
