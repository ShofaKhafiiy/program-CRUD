#include <stdio.h>
#include "struktur.h"
#include "tambah.h"
#include "lihat.h"
#include "update.h"
#include "hapus.h"

void menu1()
{
    printf("\n            === Program Pencatatan Transaksi ===\n");
    printf("1. Tambah Pelanggan\n");
    printf("2. Lihat Semua Pelanggan\n");
    printf("3. Perbarui Data Pelanggan\n");
    printf("4. Hapus Data Pelanggan\n");
    printf("5. Keluar\n");
    printf("            =======================================         \n");
}

void ProgramAdmin()
{
    Pelanggan pelanggan;
    data programm;
    do
    {
        /* code */

        do
        {
            /* code */

            menu1();
            printf("Masukan Pilihan anda(1-5): ");
            scanf("%d", &programm.pilihan);
            getchar();

            if (programm.pilihan == 1)
            {
                tambah(&pelanggan);
            }
            else if (programm.pilihan == 2)
            {
                lihat(&pelanggan);
            }
            else if (programm.pilihan == 3)
            {
                update(&pelanggan);
            }
            else if (programm.pilihan == 4)
            {
                hapus(&pelanggan);
            }
            else if (programm.pilihan == 5)
            {
                printf("Terimakasih telah menggunakan program saya :)\n");
                return;
            }
            else
            {
                printf("Pilihan tidak valid!\n");
            }

        } while (programm.pilihan < 5);
        printf("Pilihan hanya 1-5!\n");
        system("pause");
    } while (programm.pilihan != 5);
}