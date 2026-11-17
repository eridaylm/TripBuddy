#include "Itinerary.h"

int main()
{
    //Inisialisasi & Tambah Hari
    ListItinerary tripBuddy;

    cout << "=== INISIALISASI HARI PERJALANAN ===\n";
    tripBuddy.tambahHari(); // Hari 1
    tripBuddy.tambahHari(); // Hari 2
    cout << "\n";

    //Cari Hari & Isi Destinasi Hari 1
    cout << "=== MENAMBAHKAN DESTINASI ===\n";
    NodeHari *hari1 = tripBuddy.cariHari(1);
    if (hari1 != nullptr)
    {
        hari1->tambahDestinasi("Candi Borobudur");
        hari1->tambahDestinasi("Museum Ullen Sentalu");
        hari1->tambahDestinasi("Jalan Malioboro");
    }

    //Isi Destinasi Hari 2 & Tampilkan Semua
    NodeHari *hari2 = tripBuddy.cariHari(2);
    if (hari2 != nullptr)
    {
        hari2->tambahDestinasi("Keraton Yogyakarta");
        hari2->tambahDestinasi("Taman Sari");
        hari2->tambahDestinasi("Pantai Parangtritis");
    }

    tripBuddy.tampilkanSemuaItinerary();

    //Hapus Destinasi & Tampilkan Hasil Akhir
    cout << "\n=== MENGHAPUS DESTINASI ===\n";
    if (hari1 != nullptr)
    {
        hari1->hapusDestinasi("Museum Ullen Sentalu");
    }

    tripBuddy.tampilkanSemuaItinerary();

    return 0;
}   