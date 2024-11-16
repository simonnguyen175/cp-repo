#include<bits/stdc++.h>
using namespace std;

long long n;

long long uoc(long long n){
    long long cnt = 0;
    long long ans = 0;
    // n = i . n/i
    // luon tach duoc 1 phan <= can n va phan con lai
    // chi can tim duoc phan <= can n -> xac dinh dc phan con lai la n/phan vua tim duoc
    for (int i = 1; i <= sqrt(n); i ++){
        if ( n % i == 0 ){// kiem tra i la 1 uoc cua n
            ans += i;
            if ( i % 2 == 0 ) cnt ++;
            // n = n/i * i
            if ( n / i != i ){
                cnt ++; // neu n la so chinh phuong thi i da duoc tinh r nen ta phai xet th n = scp ko duoc dc ++
                ans += n/i;
                if ( n/i % 2 == 0 ) cnt ++;
            }
        }
    }

    return ans;
}

void bai5(){
    // so luong tu 1->b chia het cho c = b/c
    // so luong tu 1->a-1 chia het cho c = a-1/c
    // => so luong tu a->b chia cho c = b/c - (a-1)/c
}

int main(){
    cin >> n;
    cout << uoc(n);
    return 0;
}
