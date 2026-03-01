#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    int Jumlah_MHS = 5;
    Mahasiswa data_MHS[5];

    for(int i = 0; i < Jumlah_MHS; i++) {
        cout << "Input Data Mahasiswa ke " << i + 1 << endl;
        cout << "Masukkan Nama = "; 
        getline(cin >> ws, data_MHS[i].nama);
        cout << "Masukkan NIM  = "; 
        cin >> data_MHS[i].nim;
        cout << "Masukkan IPK  = "; 
        cin >> data_MHS[i].ipk;
        cout << endl;
    }

    int Indeks_Tertinggi = 0;
    for(int i = 1; i < Jumlah_MHS; i++) {
        if(data_MHS[i].ipk > data_MHS[Indeks_Tertinggi].ipk) {
            Indeks_Tertinggi = i;
        }
    }

    cout << "MAHASISWA DENGAN IPK TERTINGGI" << endl;
    cout << "Nama Lengkap = " << data_MHS[Indeks_Tertinggi].nama << endl;
    cout << "Nomor Induk  = " << data_MHS[Indeks_Tertinggi].nim << endl;
    cout << "Perolehan IPK= " << data_MHS[Indeks_Tertinggi].ipk << endl;
    return 0;
}

// Nama : Denny Mulia
// NIM : 2509106011