#include <iostream>
#include <string>
#include <limits>

using namespace std;

// ==========================================
// 1. DOUBLY LINKED LIST (DLL) - DESTINASI
// ==========================================
struct NodeDestinasi {
    string nama;
    string status; // "Belum" atau "Selesai"
    NodeDestinasi* prev;
    NodeDestinasi* next;

    NodeDestinasi(string namaDestinasi) {
        nama = namaDestinasi;
        status = "Belum";
        prev = nullptr;
        next = nullptr;
    }
};

// ==========================================
// 2. SINGLY LINKED LIST (SLL) - HARI
// ==========================================
struct NodeHari {
    int noHari;
    NodeDestinasi* headDestinasi; // head DLL destinasi hari ini
    NodeHari* next;

    NodeHari(int nomor) {
        noHari = nomor;
        headDestinasi = nullptr;
        next = nullptr;
    }

    // DLL: tambah destinasi di akhir (Insert Last)
    void tambahDestinasi(string nama) {
        NodeDestinasi* nodeBaru = new NodeDestinasi(nama);

        if (headDestinasi == nullptr) {
            headDestinasi = nodeBaru;
        } else {
            NodeDestinasi* temp = headDestinasi;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = nodeBaru;
            nodeBaru->prev = temp;
        }
        cout << "[+] Destinasi \"" << nama << "\" berhasil ditambahkan ke Hari " << noHari << ".\n";
    }

    // DLL: hapus destinasi berdasarkan nama (Sequential Search + Delete)
    void hapusDestinasi(string nama) {
        if (headDestinasi == nullptr) {
            cout << "[!] Daftar destinasi pada Hari " << noHari << " masih kosong.\n";
            return;
        }

        NodeDestinasi* temp = headDestinasi;
        while (temp != nullptr && temp->nama != nama) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "[!] Destinasi \"" << nama << "\" tidak ditemukan pada Hari " << noHari << ".\n";
            return;
        }

        // Kasus 1: node yang dihapus adalah head
        if (temp == headDestinasi) {
            headDestinasi = temp->next;
            if (headDestinasi != nullptr) {
                headDestinasi->prev = nullptr;
            }
        }
        // Kasus 2: node di tengah atau di akhir
        else {
            temp->prev->next = temp->next;
            if (temp->next != nullptr) {
                temp->next->prev = temp->prev;
            }
        }

        delete temp;
        cout << "[-] Destinasi \"" << nama << "\" berhasil dihapus dari Hari " << noHari << ".\n";
    }

    // DLL: tampilkan semua destinasi (traversal maju)
    void tampilkanDestinasi() {
        if (headDestinasi == nullptr) {
            cout << "   (Belum ada destinasi)\n";
            return;
        }

        NodeDestinasi* temp = headDestinasi;
        int urutan = 1;
        while (temp != nullptr) {
            cout << "   " << urutan++ << ". " << temp->nama
                 << " [Status: " << temp->status << "]\n";
            temp = temp->next;
        }
    }
};

// Pengelola SLL untuk daftar hari
struct ListItinerary {
    NodeHari* headHari;

    ListItinerary() {
        headHari = nullptr;
    }

    // SLL: tambah hari baru di akhir (Insert Last)
    void tambahHari() {
        int nomorHariBaru = 1;

        if (headHari == nullptr) {
            headHari = new NodeHari(nomorHariBaru);
        } else {
            NodeHari* temp = headHari;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            nomorHariBaru = temp->noHari + 1;
            temp->next = new NodeHari(nomorHariBaru);
        }
        cout << "[+] Hari " << nomorHariBaru << " berhasil dibuat.\n";
    }

    // SLL: cari hari berdasarkan nomor (Sequential Search)
    NodeHari* cariHari(int noHari) {
        NodeHari* temp = headHari;
        while (temp != nullptr) {
            if (temp->noHari == noHari) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void tampilkanSemuaItinerary() {
        cout << "\n==========================================\n";
        cout << "       DAFTAR ITINERARY TRIPBUDDY         \n";
        cout << "==========================================\n";

        if (headHari == nullptr) {
            cout << "Itinerary masih kosong. Silakan tambah hari terlebih dahulu.\n";
            cout << "==========================================\n";
            return;
        }

        NodeHari* tempHari = headHari;
        while (tempHari != nullptr) {
            cout << ">> HARI " << tempHari->noHari << ":\n";
            tempHari->tampilkanDestinasi();
            cout << "------------------------------------------\n";
            tempHari = tempHari->next;
        }
    }

    ~ListItinerary() {
        NodeHari* currHari = headHari;
        while (currHari != nullptr) {
            NodeDestinasi* currDest = currHari->headDestinasi;
            while (currDest != nullptr) {
                NodeDestinasi* hapusDest = currDest;
                currDest = currDest->next;
                delete hapusDest;
            }
            NodeHari* hapusHari = currHari;
            currHari = currHari->next;
            delete hapusHari;
        }
    }
};

// ==========================================
// 3. FUNGSI UTAMA (MENU INTERAKTIF)
// ==========================================
int bacaAngka() {
    int angka;
    while (!(cin >> angka)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input harus angka, coba lagi: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return angka;
}

void tampilkanMenu() {
    cout << "\n===== MENU TRIPBUDDY =====\n";
    cout << "1. Tambah hari\n";
    cout << "2. Tambah destinasi\n";
    cout << "3. Hapus destinasi\n";
    cout << "4. Tampilkan itinerary\n";
    cout << "0. Keluar\n";
    cout << "Pilih menu: ";
}

int main() {
    ListItinerary tripBuddy;
    int pilihan;

    do {
        tampilkanMenu();
        pilihan = bacaAngka();

        if (pilihan == 1) {
            tripBuddy.tambahHari();
        }
        else if (pilihan == 2 || pilihan == 3) {
            cout << "Masukkan nomor hari: ";
            int no = bacaAngka();
            NodeHari* hari = tripBuddy.cariHari(no);

            if (hari == nullptr) {
                cout << "[!] Hari " << no << " tidak ditemukan.\n";
                continue;
            }

            string nama;
            cout << "Nama destinasi: ";
            getline(cin, nama);

            if (pilihan == 2) {
                hari->tambahDestinasi(nama);
            } else {
                hari->hapusDestinasi(nama);
            }
        }
        else if (pilihan == 4) {
            tripBuddy.tampilkanSemuaItinerary();
        }
        else if (pilihan == 0) {
            cout << "Program selesai.\n";
        }
        else {
            cout << "[!] Menu tidak valid.\n";
        }
    } while (pilihan != 0);

    return 0;
}