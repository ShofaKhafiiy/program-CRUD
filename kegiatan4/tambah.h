
#include "struktur.h"

void transaksi(data *pembeli)
{
    pembeli->total = 0;
    do
    {
        printf("Masukan Jumlah Transaki Pembeli:\n");
        do
        {
            /* code */
            scanf("%d", &pembeli->trx);

            if (pembeli->trx > 0)
            {
                pembeli->total = pembeli->total + pembeli->trx;
            }
        } while (pembeli->trx > 0);

        printf("Apakah ingin menambahkan transaksi lagi? (y/n): ");
        scanf(" %c", &pembeli->pilih);

        while (pembeli->pilih != 'y' && pembeli->pilih != 'n')
        {
            printf("Pilihan tidak valid. Masukkan 'y' untuk mengulang atau 'n' untuk berhenti: ");
            scanf(" %c", &pembeli->pilih);
        }

    } while (pembeli->pilih == 'y');
}

void tambah(Pelanggan *pelangan)
{
    FILE *file;
    Pelanggan salin;
    data pembeli;
    bool validasi;
    do
    {
        validasi = false;
        printf("Masukan ID Pelanggan: ");
        scanf("%d", &pelangan->id);
        getchar();
        file = fopen(FILENAME, "rb");
        if (file)
        {
            while (fread(&salin, sizeof(Pelanggan), 1, file))
            {
                if (salin.id == pelangan->id)
                {
                    printf("ID sudah digunakan, gunakan ID lain!\n");
                    validasi = true;
                    break;
                }
            }
            fclose(file);
        }

    } while (validasi);

    file = fopen(FILENAME, "ab");
    if (!file)
    {
        printf("Tidak dapat membuka file!");
        return;
    }

    printf("Masukan Nama Pelanggan: ");
    fgets(pelangan->nama, sizeof(pelangan->nama), stdin);
    pelangan->nama[strcspn(pelangan->nama, "\n")] = 0;
    do
    {

        printf("Masukan Umur Pelanggan: ");
        scanf("%d", &pelangan->umur);
        getchar();
        if (pelangan->umur < 17)
        {
            printf("Umur Kurang.Ulangi lagi!\n");
        }
        else
        {
            printf("Umur Anda sudah Valid!\n");
        }

    } while (pelangan->umur < 17);

    printf("Masukan Email Pelanggan: ");
    fgets(pelangan->email, sizeof(pelangan->email), stdin);
    pelangan->email[strcspn(pelangan->email, "\n")] = 0;

    transaksi(&pembeli);
    pelangan->total = pembeli.total;

    fwrite(pelangan, sizeof(Pelanggan), 1, file);
    fclose(file);
    printf("Data berhasil ditambahkan!\n");
}