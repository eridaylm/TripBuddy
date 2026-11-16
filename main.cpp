#include "Itinerary.h"

int main()
{
    // ==========================================
    // BAGIAN 1 (Anak 1): Inisialisasi & Tambah Hari
    // ==========================================
    ListItinerary tripBuddy;

    cout << "=== INISIALISASI HARI PERJALANAN ===\n";
    tripBuddy.tambahHari(); // Hari 1
    tripBuddy.tambahHari(); // Hari 2
    cout << "\n";

    // ==========================================
    // BAGIAN 2 (Anak 2): Cari Hari & Isi Destinasi Hari 1
    // ==========================================
    cout << "=== MENAMBAHKAN DESTINASI ===\n";
    NodeHari *hari1 = tripBuddy.cariHari(1);
    if (hari1 != nullptr)
    {
        hari1->tambahDestinasi("Candi Borobudur");
        hari1->tambahDestinasi("Museum Ullen Sentalu");
        hari1->tambahDestinasi("Jalan Malioboro");
    }

    // ==========================================
    // BAGIAN 3 (Anak 3): Isi Destinasi Hari 2 & Tampilkan Semua
    // ==========================================
    NodeHari *hari2 = tripBuddy.cariHari(2);
    if (hari2 != nullptr)
    {
        hari2->tambahDestinasi("Keraton Yogyakarta");
        hari2->tambahDestinasi("Taman Sari");
        hari2->tambahDestinasi("Pantai Parangtritis");
    }

    tripBuddy.tampilkanSemuaItinerary();

    // ==========================================
    // BAGIAN 4 (Anak 4): Hapus Destinasi & Tampilkan Hasil Akhir
    // ==========================================
    cout << "\n=== MENGHAPUS DESTINASI ===\n";
    if (hari1 != nullptr)
    {
        hari1->hapusDestinasi("Museum Ullen Sentalu");
    }

    tripBuddy.tampilkanSemuaItinerary();

    return 0;
}   