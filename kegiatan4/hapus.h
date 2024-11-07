#include "struktur.h"

void hapus(Pelanggan *pelanggan)
{
    FILE *file, *salin;

    file = fopen(FILENAME, "rb");
    if (!file)
    {
        printf("Tidak bisa membuka file!\n");
        return;
    }

    salin = fopen("salin.dat", "wb");

    if (!salin)
    {
        printf("tidak bisa membuka file sementara!\n");
        return;
    }
    int id;
    bool validasi = false;
    printf("Masukan ID yang ingin dihapus: ");
    scanf("%d", &id);
    while (fread(pelanggan, sizeof(Pelanggan), 1, file))
    {
        if (pelanggan->id != id)
        {
            fwrite(pelanggan, sizeof(Pelanggan), 1, salin);
        }
        else
        {
            validasi = true;
        }
    }
    fclose(file);
    fclose(salin);
    remove(FILENAME);
    rename("salin.dat", FILENAME);
    if (validasi)
    {
        printf("Data berhasil dihapus!\n");
    }

    else
    {
        printf("Pelanggan dengan ID %d tidak ditemukan!\n", id);
    }
}