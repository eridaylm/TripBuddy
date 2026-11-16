#ifndef HARI_H
#define HARI_H

#include "Destinasi.h"

    struct NodeHari
{
    int noHari;
    NodeDestinasi *headDestinasi; // Menunjuk ke head DLL destinasi hari ini
    NodeHari *next;

    NodeHari(int nomor)
    {
        noHari = nomor;
        headDestinasi = nullptr;
        next = nullptr;
    }

    void tambahDestinasi(string nama)
    {
        NodeDestinasi *nodeBaru = new NodeDestinasi(nama);

        if (headDestinasi == nullptr)
        {
            headDestinasi = nodeBaru;
        }
        else
        {
            NodeDestinasi *temp = headDestinasi;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = nodeBaru;
            nodeBaru->prev = temp;
        }
        cout << "[+] Destinasi \"" << nama << "\" berhasil ditambahkan ke Hari " << noHari << ".\n";
    }

    void hapusDestinasi(string nama)
    {
        if (headDestinasi == nullptr)
        {
            cout << "[!] Daftar destinasi pada Hari " << noHari << " masih kosong.\n";
            return;
        }

        NodeDestinasi *temp = headDestinasi;
        while (temp != nullptr && temp->nama != nama)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "[!] Destinasi \"" << nama << "\" tidak ditemukan pada Hari " << noHari << ".\n";
            return;
        }

        if (temp == headDestinasi)
        {
            headDestinasi = temp->next;
            if (headDestinasi != nullptr)
            {
                headDestinasi->prev = nullptr;
            }
        }
        else
        {
            temp->prev->next = temp->next;
            if (temp->next != nullptr)
            {
                temp->next->prev = temp->prev;
            }
        }

        delete temp;
        cout << "[-] Destinasi \"" << nama << "\" berhasil dihapus dari Hari " << noHari << ".\n";
    }

    void tampilkanDestinasi()
    {
        if (headDestinasi == nullptr)
        {
            cout << "   (Belum ada destinasi)\n";
            return;
        }

        NodeDestinasi *temp = headDestinasi;
        int urutan = 1;
        while (temp != nullptr)
        {
            cout << "   " << urutan++ << ". " << temp->nama
                 << " [Status: " << temp->status << "]\n";
            temp = temp->next;
        }
    }
};

#endif