// Latihan Soal Circular Linked List

// Soal 1: Inventaris Toko Sembako

// Kamu diminta membuat fungsi untuk menampilkan daftar barang sembako beserta stoknya yang tersimpan dalam struktur data Circular Linked List. Berbeda dengan linked list biasa, pada Circular Linked List, pointer `next` dari node terakhir tidak menunjuk ke `nullptr`, melainkan kembali menunjuk ke node `head`. 
// Lengkapi fungsi untuk melakukan traversal dan mencetak seluruh data sembako tanpa terjebak dalam *infinite loop*.


#include <iostream>
#include <string>
using namespace std;

// Struktur Node untuk Circular Linked List Toko Sembako
struct BarangNode {
    string namaBarang;
    int stok;
    BarangNode* next;

    // Constructor
    BarangNode(string nama, int jumlah) {
        namaBarang = nama;
        stok = jumlah;
        next = nullptr;
    }
};

// Fungsi insert di akhir Circular Linked List untuk membangun data
BarangNode* tambahBarang(BarangNode* head, string nama, int jumlah) {
    BarangNode* newNode = new BarangNode(nama, jumlah);
    if (head == nullptr) {
        newNode->next = newNode; // Menunjuk ke dirinya sendiri (Sirkuler)
        return newNode;
    }
    
    BarangNode* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

// @brief Fungsi untuk menampilkan semua barang dalam Circular Linked List.
// @param head Pointer ke node pertama (head) dari circular linked list.
// @logic
// 1. Base case: Jika head adalah nullptr, cetak "Gudang kosong." dan return.
// 2. Gunakan pointer sementara (temp) yang dimulai dari head.
// 3. Lakukan perulangan (do-while disarankan) untuk mencetak namaBarang dan stok.
// 4. Pindah ke node selanjutnya (temp = temp->next).
// 5. Berhenti ketika temp kembali menunjuk ke head.


// mioawwww, mioawwwww mioaww mioaw mioawwwww~~ :3
void tampilkanStokSembako(BarangNode* head) {
    // --- LENGKAPI KODE DI SINI ---
    // 1. Base case: list kosong
    if (head == nullptr) {
        cout << "Gudang kosong." << endl;
        return;
    }
    // 2. Pointer sementara dimulai dari head
    BarangNode* temp = head;

    // 3. melakukan perulangan menggunakan do-while,kenapa mengguanakan ini karena dia mengksekusi blok kode satu kali terlebih dahulu sebelum memeriksa kondisi di akhir,jadi dia proses dulu baru cek kondisinya
    do {
        // 4. Cetak data node saat ini
        cout << "- " << temp->namaBarang << ": " << temp->stok << endl;

        // 5. Maju ke node berikutnya
        temp = temp->next;

    } while (temp != head); // 6. Berhenti saat kembali ke head
    // -----------------------------
}

int main() {
    BarangNode* head = nullptr;
    
    head = tambahBarang(head, "Beras", 50);
    head = tambahBarang(head, "Minyak Goreng", 30);
    head = tambahBarang(head, "Gula Pasir", 20);
    head = tambahBarang(head, "Tepung Terigu", 15);

    cout << "Daftar Stok Sembako:" << endl;
    tampilkanStokSembako(head); 
// Harusnya output:
// Beras: 50
// Minyak Goreng: 30
// Gula Pasir: 20
// Tepung Terigu: 15

    return 0;
}

