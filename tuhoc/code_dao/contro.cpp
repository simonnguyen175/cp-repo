#include<bits/stdc++.h>
using namespace std;

int** keepEven (int** matrix, int nRows, int nCols){
    for (int i = 1; i <= nRows; i ++)
    for (int j = 1; j <= nCols; j ++)
        if ( *(*(matrix + i) + j) % 2 == 1 )
            *(*(matrix + i) + j) = 0;
    return matrix;
}

int* selfDividingNumbers(int left, int right, int* returnSize){
    int cnt = 0;
    for (int i = left; i <= right; i ++){
        int x = i;
        bool ck = 1;
        while ( x > 0 ){
            if ( (x%10==0) || (i % (x%10)) ) {ck = 0; break;}
            x /= 10;
        }
        if ( ck == 1 ) {*(returnSize + cnt) = i; cnt ++;}
    }
    return returnSize;
}

int main(){
//    int x = 9;
//    int *ptr = &x;
//    int **pptr = &ptr;
//   cout << *pptr << ' ' << **pptr;

    int **p = new int*[6];
    for (int i = 1; i <= 5; i ++)
        p[i] = new int[5];

    for (int i = 1; i <= 5; i ++)
    for (int j = 1; j <= 5; j ++)
        *(*(p+i)+j) = 1;

    p = keepEven(p, 5, 5);

    int *t = new int[100];
    int *res = selfDividingNumbers(47, 520, t);
    for (int i = 0; i <= 10000; i ++)
        cout << *(res+i) << ' ';
    cout << '\n';

    return 0;
}
