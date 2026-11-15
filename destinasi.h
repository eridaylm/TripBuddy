#ifndef DESTINASI_H
#define DESTINASI_H

#include <iostream>
#include <string>

using namespace std;


struct NodeDestinasi
{
    string nama;
    string status; 
    NodeDestinasi *prev;
    NodeDestinasi *next;

  
    NodeDestinasi(string namaDestinasi)
    {
        nama = namaDestinasi;
        status = "Belum";
        prev = nullptr;
        next = nullptr;
    }
};

#endif