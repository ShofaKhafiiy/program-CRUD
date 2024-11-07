#include "struktur.h"

void lihat(Pelanggan *pelanggan)
{

    FILE *file;

    file = fopen(FILENAME, "rb");
    if (!file)
    {
        printf("Tidak dapat membuka file!\n");
        return;
    }

    printf("\nDaftar Pelanggan:\n");
    printf("==========================\n");
    while (fread(pelanggan, sizeof(Pelanggan), 1, file))
    {
        printf("\n| ID: %.02d\n", pelanggan->id);
        printf("| Nama: %s\n", pelanggan->nama);
        printf("| Umur: %d\n", pelanggan->umur);
        printf("| Email: %s\n", pelanggan->email);
        if (pelanggan->bayar > pelanggan->total)
        {

            float kembalian = pelanggan->bayar - pelanggan->total;
            if (kembalian > 0)
            {
                printf("Pembayaran anda lunas dengan kembalian dana sebesar: %.2f\n", kembalian);
            }
            else
            {
                printf("Pembayaran anda lunas :]\n");
            }
        }
        else
        {

            float belum_lunas = pelanggan->total - pelanggan->bayar;
            printf("Pembayaran anda masih memiliki tanggungan kurang sebesar: %.2f.\nHarap segera dilunasi!\n", belum_lunas);
        }
    }
    printf("==========================\n");
    fclose(file);
}