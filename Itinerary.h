#ifndef ITINERARY_H
#define ITINERARY_H

#include "Hari.h"

struct ListItinerary
{
    NodeHari *headHari;

    ListItinerary()
    {
        headHari = nullptr;
    }

  
    void tambahHari()
    {
        int nomorHariBaru = 1;

        if (headHari == nullptr)
        {
            headHari = new NodeHari(nomorHariBaru);
        }
        else
        {
            NodeHari *temp = headHari;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            nomorHariBaru = temp->noHari + 1;
            temp->next = new NodeHari(nomorHariBaru);
        }
        cout << "[+] Hari " << nomorHariBaru << " berhasil dibuat.\n";
    }

    NodeHari *cariHari(int noHari)
    {
        NodeHari *temp = headHari;
        while (temp != nullptr)
        {
            if (temp->noHari == noHari)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void tampilkanSemuaItinerary()
    {
        cout << "\n==========================================\n";
        cout << "        DAFTAR ITINERARY TRIPBUDDY        \n";
        cout << "==========================================\n";

        if (headHari == nullptr)
        {
            cout << "Itinerary masih kosong. Silakan tambah hari terlebih dahulu.\n";
            cout << "==========================================\n";
            return;
        }

        NodeHari *tempHari = headHari;
        while (tempHari != nullptr)
        {
            cout << ">> HARI " << tempHari->noHari << ":\n";
            tempHari->tampilkanDestinasi();
            cout << "------------------------------------------\n";
            tempHari = tempHari->next;
        }
    }

    ~ListItinerary()
    {
        NodeHari *currHari = headHari;
        while (currHari != nullptr)
        {
            NodeDestinasi *currDest = currHari->headDestinasi;
            while (currDest != nullptr)
            {
                NodeDestinasi *hapusDest = currDest;
                currDest = currDest->next;
                delete hapusDest;
            }
            NodeHari *hapusHari = currHari;
            currHari = currHari->next;
            delete hapusHari;
        }
    }
};

#endif