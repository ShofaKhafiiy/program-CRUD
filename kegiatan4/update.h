#include "struktur.h"
#include <string.h>

void update(Pelanggan *pelanggan)
{

    FILE *file, *salin;
    file = fopen(FILENAME, "rb");

    if (!file)
    {
        printf("Tidak dapat membuka file!\n");
    }

    salin = fopen("salin.dat", "wb");
    if (!salin)
    {
        printf("Tidak dapat membuka file sementara untuk update!\n");
        fclose(file);
    }

    int id;
    bool validasi = false;
    printf("Masukan ID yang ingin diperbarui: ");
    scanf("%d", &id);
    while (fread(pelanggan, sizeof(Pelanggan), 1, file))
    {
        if (pelanggan->id == id)
        {
            validasi = true;

            printf("Masukan ID baru: ");
            scanf("%d", &pelanggan->id);
            getchar();

            printf("Masukan Nama Baru: ");
            fgets(pelanggan->nama, sizeof(Pelanggan), stdin);
            pelanggan->nama[strcspn(pelanggan->nama, "\n")] = 0;

            printf("Masukan Usia baru: ");
            scanf("%d", &pelanggan->umur);
            getchar();

            printf("Masukan email baru: ");
            fgets(pelanggan->email, sizeof(Pelanggan), stdin);
            pelanggan->email[strcspn(pelanggan->email, "\n")] = 0;

            printf("Total transaksi yang harus di bayar: %.2f\n", pelanggan->total);
            printf("Masukan nominal pembayaran anda: ");
            scanf("%f", &pelanggan->bayar);
            fwrite(pelanggan, sizeof(Pelanggan), 1, salin);
        }
        else
        {
            fwrite(pelanggan, sizeof(Pelanggan), 1, salin);
        }
    }
    if (!validasi)
    {
        printf("Pelanggan dengan ID %d tidak ditemukan!.\n", id);
        return;
    }
    else
    {
        printf("Data berhasil diperbarui!\n");
    }
    fclose(file);
    fclose(salin);

    remove(FILENAME);
    rename("salin.dat", FILENAME);
}