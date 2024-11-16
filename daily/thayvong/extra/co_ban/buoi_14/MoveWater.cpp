#include <bits/stdc++.h>
using namespace std;

int t, n, s;
int a[3001], b[3001];

bool MoveWater(int i){
    if ( s % i == 0 ){
        //SETUP
        int tb= s/i; // trung bình mỗi chai
        int SoChai=0;
        // gán mảng b thay cho a
        for (int j=1; j<=n; j++){
            b[j]=a[j];
            if ( b[j] > tb ) return false; // Nếu tồn tại 1 chai lớn hơn tb thì sai
        }
        //SOLVE
        for (int j=1; j<=n; j++){
            int st=b[j]; // tổng tạm hiện tại
            while ( st < tb && j <= n ){ // nếu tổng tạm bé hơn tb thì cộng dồn chai tiếp
                j++;
                st+=b[j];
            }
            if ( st == tb ){
                SoChai++; // nếu tổng tạm bằng thì số chai +1
                continue; // tiếp tục chương trình
            }
            if ( st > tb ) return false; // nếu tổng tạm lớn hơn tb thì sai
        }
        if ( SoChai == i ) return true; // nếu số chai bằng i thì đúng
    }
    else return false; // nếu tổng không chia hết cho số chai i thì sai
}


int main(){
    cin >> t;
    for (int i=1; i<=t; i++){
        cin >> n;
        for (int i=1; i<=n; i++)
            cin >> a[i];
        s=0;
        for (int i=1; i<=n; i++)
            s+=a[i];
        for (int i=n; i>=1; i--)
            if ( MoveWater(i) ){
                cout << i <<"\n";
                break;
            }
    }
    return 0;
}
