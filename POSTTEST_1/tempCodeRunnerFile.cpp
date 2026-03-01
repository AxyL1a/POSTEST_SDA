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

// Tmin(n) = c1 + c2 + c3(n) + c4(n-1) + c6(n-1) + c7 = an + b

// Perhitungan Tmax(n) (Worst Case)
// kondisi: array terurut menurun, sehingga selalu masuk ke dalam if

// Tmax(n) = c1 + c2 + c3(n) + c4(n-1) + c5(n-1) + c6(n-1) + c7 = an + b

// KESIMPULAN KOMPLEKSITAS

// Best Case  : O(n)
// Worst Case : O(n)

// Karena jumlah perulangan selalu n-1 kali,maka algoritma bersifat linear
// Kompleksitas ruang : O(1)
