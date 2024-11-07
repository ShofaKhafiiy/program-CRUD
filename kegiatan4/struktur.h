#ifndef STRUKTUR_H
#define STRUKTUR_H

#include <stdio.h>
#include <stdbool.h>
#define FILENAME "pelanggan.dat"
#define MAXNAMA 10000
#define EMAILMAX 100000

typedef struct
{
    int id;
    char nama[100];
    int umur;
    char email[100];
    float total;
    float bayar;
} Pelanggan;

typedef struct
{
    float total;
    char pilih;
    int trx;
    int pilihan;
} data;

#endif