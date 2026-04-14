// nama Denny Mulia
// nim 2509106011

#include <iostream>
#include <string>

using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    double harga;
};

const int MAKS = 100;

// Queue Antrian Pet Menggunakan Array
struct AntrianPet {
    Hewan data[MAKS];
    int depan = -1;
    int belakang = -1;
};

// Stack Catatan Medis Menggunakan Array
struct CatatanMedis {
    Hewan data[MAKS];
    int atas = -1;
};

// Fungsi pengecekan underflow dan overflow
bool antrianKosong(AntrianPet* q) { return q->depan == -1; }
bool antrianPenuh(AntrianPet* q) { return q->belakang == MAKS - 1; }
bool catatanKosong(CatatanMedis* s) { return s->atas == -1; }
bool catatanPenuh(CatatanMedis* s) { return s->atas == MAKS - 1; }

// Enqueue dengan Parameter struct* dan Penanganan Overflow
void tambahAntrian(AntrianPet* q, Hewan h) {
    if (antrianPenuh(q)) {
        cout << "Antrian Penuh (Overflow)" << endl;
        return;
    }
    if (antrianKosong(q)) q->depan = 0;
    q->belakang++;
    *(q->data + q->belakang) = h; 
    cout << h.nama << " Berhasil masuk antrian" << endl;
}

// Dequeue dengan Parameter struct* dan penanganan underflow
Hewan panggilAntrian(AntrianPet* q) {
    Hewan temp = *(q->data + q->depan);
    if (q->depan == q->belakang) {
        q->depan = q->belakang = -1;
    } else {
        q->depan++;
    }
    return temp;
}

// Push Catatan medis
void tambahCatatan(CatatanMedis* s, Hewan h) {
    if (catatanPenuh(s)) {
        cout << "Catatan Penuh (Overflow)" << endl;
        return;
    }
    s->atas++;
    *(s->data + s->atas) = h;
}

// Pop Catatan medis dengan penanganan underflow
void hapusCatatan(CatatanMedis* s) {
    if (catatanKosong(s)) {
        cout << "Catatan Medis Kosong (Underflow)" << endl;
        return;
    }
    cout << "Catatan medis untuk " << (s->data + s->atas)->nama << " Dibatalkan" << endl;
    s->atas--;
}

// Swap menggunakan Dereferensi Pointer
void tukar(Hewan *a, Hewan *b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

void tampilData(Hewan* arr, int n) {
    if (n == 0) {
        cout << "Data Utama Kosong" << endl;
        return;
    }
    cout << "\n=== Daftar Hewan Pawcare Petshop ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << "ID " << (arr + i)->id 
            << " | Nama " << (arr + i)->nama 
            << " | Jenis " << (arr + i)->jenis 
            << " | Harga Rp" << (arr + i)->harga << endl;
    }
}

// Sorting Bubble Sort (Dereferensi Pointer)
void urutNama(Hewan* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((arr + j)->nama > (arr + (j + 1))->nama) {
                tukar((arr + j), (arr + j + 1)); 
            }
        }
    }
    cout << "Data Berhasil Diurutkan" << endl;
}

// Sorting Selection Sort
void urutHarga(Hewan* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int idxMin = i;
        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->harga < (arr + idxMin)->harga) {
                idxMin = j;
            }
        }
        tukar((arr + idxMin), (arr + i));
    }
    cout << "Data Berhasil Diurutkan" << endl;
}

void cariNama(Hewan* arr, int n, string target) {
    bool ketemu = false;
    for (int i = 0; i < n; i++) {
        if ((arr + i)->nama == target) {
            cout << "\nData Ditemukan" << endl;
            cout << "ID " << (arr + i)->id << " | Harga " << (arr + i)->harga << endl;
            ketemu = true;
            break;
        }
    }
    if (!ketemu) cout << "Hewan Tidak Ditemukan" << endl;
}

void cariID(Hewan* arr, int n, int x) {
    int fibM2 = 0, fibM1 = 1, fibM = fibM2 + fibM1; 
    while (fibM < n) { fibM2 = fibM1; fibM1 = fibM; fibM = fibM2 + fibM1; }
    int offset = -1;
    while (fibM > 1) {
        int i = min(offset + fibM2, n - 1);
        if ((arr + i)->id < x) {
            fibM = fibM1; fibM1 = fibM2; fibM2 = fibM - fibM1; offset = i;
        } else if ((arr + i)->id > x) {
            fibM = fibM2; fibM1 = fibM1 - fibM2; fibM2 = fibM - fibM1;
        } else {
            cout << "ID " << x << " Ditemukan yaitu " << (arr + i)->nama << endl;
            return;
        }
    }
    if (fibM1 && (arr + offset + 1)->id == x) cout << "ID " << x << " Ditemukan yaitu " << (arr + offset + 1)->nama << endl;
    else cout << "ID Tidak Ditemukan" << endl;
}


// Node untuk Linked List
struct Node {
    Hewan data;
    Node* next;
};

// Struktur Queue Linked List
struct QueueLL {
    Node* depan = nullptr;
    Node* belakang = nullptr;
};

// Struktur Stack Linked List
struct StackLL {
    Node* atas = nullptr;
};

// Operasi Queue Linked List
void enqueueLL(QueueLL* q, Hewan h) {
    Node* baru = new Node;
    baru->data = h;
    baru->next = nullptr;
    if (q->belakang == nullptr) {
        q->depan = q->belakang = baru;
    } else {
        q->belakang->next = baru;
        q->belakang = baru;
    }
    cout << h.nama << " berhasil masuk Antrian Linked List" << endl;
}

void dequeueLL(QueueLL* q) {
    if (q->depan == nullptr) {
        cout << "Antrian Linked List Kosong" << endl;
        return;
    }
    Node* temp = q->depan;
    cout << "Memproses " << temp->data.nama << " dari antrian" << endl;
    q->depan = q->depan->next;
    if (q->depan == nullptr) q->belakang = nullptr;
    delete temp;
}

// Operasi Stack Linked List
void pushLL(StackLL* s, Hewan h) {
    Node* baru = new Node;
    baru->data = h;
    baru->next = s->atas;
    s->atas = baru;
    cout << h.nama << " berhasil masuk Riwayat Medis Linked List" << endl;
}

void popLL(StackLL* s) {
    if (s->atas == nullptr) {
        cout << "Riwayat Medis Linked List Kosong" << endl;
        return;
    }
    Node* temp = s->atas;
    cout << "Menghapus riwayat medis " << temp->data.nama << endl;
    s->atas = s->atas->next;
    delete temp;
}

void peekLL(QueueLL* q, StackLL* s) {
    if (q->depan != nullptr) {
        cout << "Depan Antrian LL " << q->depan->data.nama << endl;
    } else {
        cout << "Antrian LL Kosong" << endl;
    }
    if (s->atas != nullptr) {
        cout << "Teratas Riwayat LL " << s->atas->data.nama << endl;
    } else {
        cout << "Riwayat LL Kosong" << endl;
    }
}

void tampilAntrianLL(QueueLL* q) {
    if (q->depan == nullptr) {
        cout << "Antrian LL Kosong" << endl;
        return;
    }
    Node* temp = q->depan;
    cout << "Daftar Antrian Linked List" << endl;
    while (temp != nullptr) {
        cout << "- " << temp->data.nama << " [" << temp->data.jenis << "]" << endl;
        temp = temp->next;
    }
}

void tampilRiwayatLL(StackLL* s) {
    if (s->atas == nullptr) {
        cout << "Riwayat LL Kosong" << endl;
        return;
    }
    Node* temp = s->atas;
    cout << "Daftar Riwayat Medis Linked List" << endl;
    while (temp != nullptr) {
        cout << "- " << temp->data.nama << " Selesai" << endl;
        temp = temp->next;
    }
}

int main() {
    Hewan* daftarHewan = new Hewan[MAKS];
    int jumlahHewan = 0;
    
    AntrianPet qPet;
    CatatanMedis sCatatan;
    
    // Inisialisasi struktur Linked List
    QueueLL qLL;
    StackLL sLL;

    *(daftarHewan + 0) = {105, "Rahul", "Kucing", 450000};
    *(daftarHewan + 1) = {102, "Koko", "Anjing", 1200000};
    *(daftarHewan + 2) = {104, "Rara", "Kelinci", 250000};
    *(daftarHewan + 3) = {101, "Geko", "Hamster", 50000};
    jumlahHewan = 4; 

    int pilihan;
    do {
        cout << "\n--- Menu Pawcare Petshop ---" << endl;
        cout << "1 Tambah Data Hewan" << endl;
        cout << "2 Tampil Semua Data" << endl;
        cout << "3 Cari Nama (Linear Search)" << endl;
        cout << "4 Cari ID (Fibonacci Search)" << endl;
        cout << "5 Urut Nama (Bubble Sort)" << endl;
        cout << "6 Urut Harga (Selection Sort)" << endl;
        cout << "7 Tambah Antrian Pet (Enqueue Array)" << endl;
        cout << "8 Panggil Pet (Dequeue Array)" << endl;
        cout << "9 Hapus Catatan Medis Terakhir (Pop Array)" << endl;
        cout << "10 Lihat Data Teratas (Peek Array)" << endl;
        cout << "11 Tampil Semua Antrian (Pointer Aritmatika)" << endl;
        cout << "12 Tampil Semua Catatan Medis (Pointer Aritmatika)" << endl;
        cout << "13 Enqueue (Linked List)" << endl;
        cout << "14 Dequeue (Linked List)" << endl;
        cout << "15 Push (Linked List)" << endl;
        cout << "16 Pop (Linked List)" << endl;
        cout << "17 Peek (Linked List)" << endl;
        cout << "18 Tampil Antrian (Linked List)" << endl;
        cout << "19 Tampil Riwayat (Linked List)" << endl;
        cout << "0 Keluar" << endl;
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
            string cari; cout << "Masukkan Nama "; cin.ignore(); getline(cin, cari);
            cariNama(daftarHewan, jumlahHewan, cari);
        } else if (pilihan == 4) {
            int idCari; cout << "Masukkan ID "; cin >> idCari;
            cariID(daftarHewan, jumlahHewan, idCari);
        } else if (pilihan == 5) {
            urutNama(daftarHewan, jumlahHewan);
        } else if (pilihan == 6) {
            urutHarga(daftarHewan, jumlahHewan);
        } else if (pilihan == 7) {
            int idCari; cout << "Masukkan ID Hewan Untuk Antrian "; cin >> idCari;
            bool ketemu = false;
            for(int i=0; i<jumlahHewan; i++) {
                if((daftarHewan+i)->id == idCari) {
                    tambahAntrian(&qPet, *(daftarHewan+i));
                    ketemu = true; break;
                }
            }
            if(!ketemu) cout << "ID Tidak Terdaftar" << endl;
        } else if (pilihan == 8) {
            if (!antrianKosong(&qPet)) {
                Hewan h = panggilAntrian(&qPet);
                cout << "Memanggil Pet " << h.nama << " dengan ID " << h.id << endl;
                tambahCatatan(&sCatatan, h); 
            } else cout << "Antrian Kosong (Underflow)" << endl;
        } else if (pilihan == 9) {
            hapusCatatan(&sCatatan);
        } else if (pilihan == 10) {
            if(!antrianKosong(&qPet)) cout << "Pet Terdepan Antrian " << (qPet.data + qPet.depan)->nama << endl;
            if(!catatanKosong(&sCatatan)) cout << "Catatan Terakhir Medis " << (sCatatan.data + sCatatan.atas)->nama << endl;
        } else if (pilihan == 11) {
            if(antrianKosong(&qPet)) cout << "Antrian Kosong" << endl;
            else {
                cout << "Daftar Antrian Dari Depan Ke Belakang" << endl;
                for(int i = qPet.depan; i <= qPet.belakang; i++) {
                    cout << "- " << (qPet.data + i)->nama << endl;
                }
            }
        } else if (pilihan == 12) {
            if(catatanKosong(&sCatatan)) cout << "Catatan Medis Kosong" << endl;
            else {
                cout << "Riwayat Catatan Medis Dari Terbaru Ke Lama" << endl;
                for(int i = sCatatan.atas; i >= 0; i--) {
                    cout << "- " << (sCatatan.data + i)->nama << " Selesai Ditangani" << endl;
                }
            }
        } else if (pilihan == 13) {
            int idCari; cout << "Masukkan ID Hewan Untuk Antrian LL "; cin >> idCari;
            bool ketemu = false;
            for(int i=0; i<jumlahHewan; i++) {
                if((daftarHewan+i)->id == idCari) {
                    enqueueLL(&qLL, *(daftarHewan+i));
                    ketemu = true; break;
                }
            }
            if(!ketemu) cout << "ID Tidak Terdaftar" << endl;
        } else if (pilihan == 14) {
            dequeueLL(&qLL);
        } else if (pilihan == 15) {
            int idCari; cout << "Masukkan ID Hewan Untuk Catatan LL "; cin >> idCari;
            bool ketemu = false;
            for(int i=0; i<jumlahHewan; i++) {
                if((daftarHewan+i)->id == idCari) {
                    pushLL(&sLL, *(daftarHewan+i));
                    ketemu = true; break;
                }
            }
            if(!ketemu) cout << "ID Tidak Terdaftar" << endl;
        } else if (pilihan == 16) {
            popLL(&sLL);
        } else if (pilihan == 17) {
            peekLL(&qLL, &sLL);
        } else if (pilihan == 18) {
            tampilAntrianLL(&qLL);
        } else if (pilihan == 19) {
            tampilRiwayatLL(&sLL);
        }
    } while (pilihan != 0);

    delete[] daftarHewan;
    return 0;
}