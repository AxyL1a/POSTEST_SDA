#include <iostream>
using namespace std;

void tukarDuaNilai(int* ptrSatu, int* ptrDua) {
    int wadahSementara = *ptrSatu;
    *ptrSatu = *ptrDua;
    *ptrDua = wadahSementara;
}

int main() {
    int angkaPertama, angkaKedua;
    
    cout << "Input Angka Pertama (A)= "; 
    cin >> angkaPertama;
    cout << "Input Angka Kedua (B)  = "; 
    cin >> angkaKedua;

    cout << "SEBELUM DI TUKAR" << endl;
    cout << "Nilai A = " << angkaPertama << endl;
    cout << "Nilai B = " << angkaKedua << endl;

    tukarDuaNilai(&angkaPertama, &angkaKedua);

    cout << "SESUDAH DI TUKAR" << endl;
    cout << "Nilai A = " << angkaPertama << endl;
    cout << "Nilai B = " << angkaKedua << endl;
    return 0;
}

// Nama : Denny Mulia
// NIM : 2509106011