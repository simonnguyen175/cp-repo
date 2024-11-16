#include <iostream>
#include <math.h>
using namespace std;

void read(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cin >> *(arr + i);
    }
}

void print(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int tongAm(int *arr, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        if (*(arr + i) < 0) {  // Truy cập phần tử qua con trỏ
            tong += *(arr + i);
        }
    }
    return tong;
}

bool nto(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int tongNto(int *arr, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        if (nto(*(arr + i))) {
            tong += *(arr + i);
        }
    }
    return tong;
}

bool Cp(int n) {
    int can = (int)sqrt(n);
    return can * can == n;
}

int tongCp(int *arr, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        if (Cp(*(arr + i))) {
            tong += *(arr + i);
        }
    }
    return tong;
}

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];
    read(arr, n);
    print(arr, n);
    cout << tongAm(arr, n) << '\n';
    cout << tongNto(arr, n) << '\n';
    cout << tongCp(arr, n) << '\n';

    delete[] arr;
    return 0;
}

