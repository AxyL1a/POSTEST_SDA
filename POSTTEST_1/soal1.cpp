#include <iostream>
using namespace std;

int main() {

    int A[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int n = 8;

    int min = A[0];
    int index = 0;

    for(int i = 1; i < n; i++) {
        if(A[i] < min) {
            min = A[i];
            index = i;
        }
    }

    cout << "Nilai minimum  : " << min << endl;
    cout << "Indeks minimum : " << index << endl;
    return 0;
}


// Nama : Denny Mulia
// NIM : 2509106011

// Pseudocode:
// 1  min ← A[0]
// 2  for i ← 1 to n-1 do
// 3      if A[i] < min then
// 4          min ← A[i]
// 5      end if
// 6  end for
// 7  return min

// Baris | Operasi                | Cost | Frekuensi Best | Frekuensi Worst
// 1     | min = A[0]             | c1   | 1              | 1
// 2     | inisialisasi i = 1     | c2   | 1              | 1
// 3     | perbandingan i < n     | c3   | n              | n
// 4     | perbandingan A[i]<min  | c4   | n-1            | n-1
// 5     | min = A[i]             | c5   | 0              | n-1
// 6     | increment i            | c6   | n-1            | n-1
// 7     | return min             | c7   | 1              | 1

// Perhitungan Tmin(n) (Best Case)
// kondisi: elemen pertama sudah minimum, sehingga tidak pernah masuk ke dalam if
// Tmin(n) = c1 + c2 + c3(n) + c4(n-1) + c6(n-1) + c7 
// Tmin(n) = an + b
//Tmin(n) = O(n)

// Perhitungan Tmax(n) (Worst Case)
// kondisi: array terurut menurun, sehingga selalu masuk ke dalam if
// Tmax(n) = c1 + c2 + c3(n) + c4(n-1) + c5(n-1) + c6(n-1) + c7
// Tmin(n) = an + b
//Tmin(n) = O(n)

// KESIMPULAN KOMPLEKSITAS
// Best Case  : O(n)
// Worst Case : O(n)

// Karena jumlah perulangan selalu n-1 kali,maka algoritma bersifat linear
// Kompleksitas ruang : O(1)
