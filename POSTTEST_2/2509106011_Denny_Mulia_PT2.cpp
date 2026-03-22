#include <iostream>
#include <string>

using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    double harga;
};

void swap(Hewan *a, Hewan *b) {
    // Tukar isi data menggunakan dereferensi pointer
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

void tampilData(Hewan* arr, int n) {
    if (n == 0) {
        cout << "Data masih kosong!" << endl;
        return;
    }
    cout << "\n=== DAFTAR HEWAN PAWCARE PETSHOP ===" << endl;
    for (int i = 0; i < n; i++) {
        // Akses data menggunakan pointer aritmatika
        cout << "ID " << (arr + i)->id 
             << " | Nama " << (arr + i)->nama 
             << " | Jenis " << (arr + i)->jenis 
             << " | Harga Rp" << (arr + i)->harga << endl;
    }
}

void bubbleSortNama(Hewan* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((arr + j)->nama > (arr + (j + 1))->nama) {
                // Panggil fungsi swap dengan referensi alamat
                swap(&(arr[j]), &(arr[j + 1])); 
            }
        }
    }
    cout << "Data berhasil diurutkan berdasarkan Nama A-Z" << endl;
}

void selectionSortHarga(Hewan* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->harga < (arr + minIdx)->harga) {
                minIdx = j;
            }
        }
        swap(&arr[minIdx], &arr[i]);
    }
    cout << "Data berhasil diurutkan berdasarkan Harga Termurah" << endl;
}

void linearSearchNama(Hewan* arr, int n, string target) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if ((arr + i)->nama == target) {
            cout << "\nData Ditemukan" << endl;
            cout << "ID " << (arr + i)->id << " | Harga " << (arr + i)->harga << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Hewan tidak ditemukan" << endl;
}

void fibonacciSearchID(Hewan* arr, int n, int x) {
    // Fibonacci search perlu data terurut berdasarkan ID
    // Kita urutkan dulu secara internal agar search bekerja
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((arr + j)->id > (arr + (j + 1))->id) swap(&arr[j], &arr[j + 1]);
        }
    }

    int fibM2 = 0; 
    int fibM1 = 1; 
    int fibM = fibM2 + fibM1; 

    while (fibM < n) {
        fibM2 = fibM1;
        fibM1 = fibM;
        fibM = fibM2 + fibM1;
    }

    int offset = -1;
    int iterasi = 1;

    while (fibM > 1) {
        int i = min(offset + fibM2, n - 1);
        // Tampilkan proses tiap iterasi pencarian
        cout << "Iterasi " << iterasi++ << " Cek indeks " << i << " ID " << arr[i].id << endl;

        if (arr[i].id < x) {
            fibM = fibM1;
            fibM1 = fibM2;
            fibM2 = fibM - fibM1;
            offset = i;
        } else if (arr[i].id > x) {
            fibM = fibM2;
            fibM1 = fibM1 - fibM2;
            fibM2 = fibM - fibM1;
        } else {
            cout << "ID ditemukan pada indeks " << i << " Nama " << arr[i].nama << endl;
            return;
        }
    }

    if (fibM1 && arr[offset + 1].id == x) {
        cout << "ID ditemukan pada indeks " << (offset + 1) << " Nama " << arr[offset+1].nama << endl;
    } else {
        cout << "ID tidak ditemukan" << endl;
    }
}

int main() {
    int kapasitas = 100;
    // Alokasi memori array menggunakan pointer
    Hewan* daftarHewan = new Hewan[kapasitas];
    int jumlahHewan = 0;

    // Data awal
    daftarHewan[0] = {105, "Zoro", "Kucing", 450000};
    daftarHewan[1] = {102, "Bella", "Anjing", 1200000};
    daftarHewan[2] = {104, "Mochi", "Kelinci", 250000};
    daftarHewan[3] = {101, "Asep", "Hamster", 50000};
    daftarHewan[4] = {103, "Kiki", "Burung", 150000};
    jumlahHewan = 5; 


    int pilihan;
    do {
        cout << "\n--- MENU PAWCARE PETSHOP ---" << endl;
        cout << "1. Tambah Data Hewan" << endl;
        cout << "2. Tampil Semua Data" << endl;
        cout << "3. Cari Nama (Linear)" << endl;
        cout << "4. Cari ID (Fibonacci)" << endl;
        cout << "5. Urut Nama A-Z (Bubble)" << endl;
        cout << "6. Urut Harga Termurah (Selection)" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan "; cin >> pilihan;

        if (pilihan == 1) {
            cout << "ID "; cin >> (daftarHewan + jumlahHewan)->id;
            cout << "Nama "; cin.ignore(); getline(cin, (daftarHewan + jumlahHewan)->nama);
            cout << "Jenis "; getline(cin, (daftarHewan + jumlahHewan)->jenis);
            cout << "Harga "; cin >> (daftarHewan + jumlahHewan)->harga;
            jumlahHewan++;
        } else if (pilihan == 2) {
            tampilData(daftarHewan, jumlahHewan);
        } else if (pilihan == 3) {
            string cari;
            cout << "Masukkan nama "; cin.ignore(); getline(cin, cari);
            linearSearchNama(daftarHewan, jumlahHewan, cari);
        } else if (pilihan == 4) {
            int cariID;
            cout << "Masukkan ID "; cin >> cariID;
            fibonacciSearchID(daftarHewan, jumlahHewan, cariID);
        } else if (pilihan == 5) {
            bubbleSortNama(daftarHewan, jumlahHewan);
        } else if (pilihan == 6) {
            selectionSortHarga(daftarHewan, jumlahHewan);
        }
    } while (pilihan != 0);

    // Hapus memori yang dialokasikan pointer
    delete[] daftarHewan;
    return 0;
}