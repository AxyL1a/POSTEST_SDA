#include <iostream>
using namespace std;

int* reverseArray(int* arr, int n) {
    int* ptrAwal = arr;
    int* ptrAkhir = arr + n - 1;
    
    while (ptrAwal < ptrAkhir) {
        int sementara = *ptrAwal;
        *ptrAwal = *ptrAkhir;
        *ptrAkhir = sementara;
        
        ptrAwal++;
        ptrAkhir--;
    }
    return arr;
}

int main() {
    int arrayPrima[] = {2, 3, 5, 7, 11, 13, 17};
    int n = 7;
    cout << "DATA SEBELUM DIBALIK" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Nilai = " << *(arrayPrima + i) << ", Alamat Memori = " << (arrayPrima + i) << endl;
    }

    reverseArray(arrayPrima, n);

    cout << "\nDATA SESUDAH DIBALIK" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Nilai = " << *(arrayPrima + i) << ", Alamat Memori = " << (arrayPrima + i) << endl;
    }
    return 0;
}

// Nama : Denny Mulia
// NIM : 2509106011