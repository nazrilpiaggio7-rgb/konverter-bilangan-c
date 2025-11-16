/*
Nama: Nazril Piaggio Jami Wahyudi
NRP:162024008
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// --------------------- Fungsi bantu ---------------------

// konversi biner ke desimal
int binerKeDesimal(char biner[]) {
    int panjang = strlen(biner);
    int hasil = 0;

    printf("\nProses biner ke desimal:\n");

    for (int i = 0; i < panjang; i++) {
        int bit = biner[panjang - 1 - i] - '0';
        int nilai = bit * pow(2, i);

        printf("Bit %d x 2^%d = %d\n", bit, i, nilai);

        hasil += nilai;
    }
    return hasil;
}

// konversi oktal ke desimal
int oktalKeDesimal(char oktal[]) {
    int panjang = strlen(oktal);
    int hasil = 0;

    printf("\nProses oktal ke desimal:\n");

    for (int i = 0; i < panjang; i++) {
        int digit = oktal[panjang - 1 - i] - '0';
        int nilai = digit * pow(8, i);

        printf("Digit %d x 8^%d = %d\n", digit, i, nilai);

        hasil += nilai;
    }
    return hasil;
}

// konversi heksa ke desimal
int heksaKeDesimal(char heksa[]) {
    int panjang = strlen(heksa);
    int hasil = 0;

    printf("\nProses heksa ke desimal:\n");

    for (int i = 0; i < panjang; i++) {
        char c = heksa[panjang - 1 - i];
        int digit;

        if (c >= '0' && c <= '9') digit = c - '0';
        else if (c >= 'A' && c <= 'F') digit = 10 + (c - 'A');
        else if (c >= 'a' && c <= 'f') digit = 10 + (c - 'a');

        int nilai = digit * pow(16, i);

        printf("Digit %d x 16^%d = %d\n", digit, i, nilai);

        hasil += nilai;
    }
    return hasil;
}

// konversi desimal ke biner
void desKeBiner(int n) {
    int biner[32], i = 0;

    printf("\nProses desimal ke biner:\n");

    int temp = n;
    while (temp > 0) {
        biner[i] = temp % 2;
        printf("%d / 2 = %d sisa %d\n", temp, temp / 2, temp % 2);
        temp /= 2;
        i++;
    }

    printf("Hasil biner = ");
    for (int j = i - 1; j >= 0; j--) printf("%d", biner[j]);
    printf("\n");
}

// konversi desimal ke oktal
void desKeOktal(int n) {
    int o[32], i = 0;

    printf("\nProses desimal ke oktal:\n");

    int temp = n;
    while (temp > 0) {
        o[i] = temp % 8;
        printf("%d / 8 = %d sisa %d\n", temp, temp / 8, temp % 8);
        temp /= 8;
        i++;
    }

    printf("Hasil oktal = ");
    for (int j = i - 1; j >= 0; j--) printf("%d", o[j]);
    printf("\n");
}

// konversi desimal ke heksa
void desKeHeksa(int n) {
    char h[32];
    int i = 0;

    printf("\nProses desimal ke heksa:\n");

    int temp = n;
    while (temp > 0) {
        int sisa = temp % 16;

        printf("%d / 16 = %d sisa %d\n", temp, temp / 16, sisa);

        if (sisa < 10) h[i] = sisa + '0';
        else h[i] = (sisa - 10) + 'A';

        temp /= 16;
        i++;
    }

    printf("Hasil heksa = ");
    for (int j = i - 1; j >= 0; j--) printf("%c", h[j]);
    printf("\n");
}

// --------------------- Program Utama ---------------------

int main() {
    int pilihan;
    char input[50];

    while (1) {
        printf("\n=== PROGRAM KONVERSI BILANGAN ===\n");
        printf("1.  Biner ke Desimal\n");
        printf("2.  Biner ke Oktal\n");
        printf("3.  Biner ke Heksa\n");
        printf("4.  Desimal ke Biner\n");
        printf("5.  Desimal ke Oktal\n");
        printf("6.  Desimal ke Heksa\n");
        printf("7.  Heksa ke Desimal\n");
        printf("8.  Heksa ke Biner\n");
        printf("9.  Heksa ke Oktal\n");
        printf("10. Oktal ke Desimal\n");
        printf("11. Oktal ke Biner\n");
        printf("12. Oktal ke Heksa\n");
        printf("0.  Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        if (pilihan == 0) break;

        printf("Masukkan nilai: ");
        scanf("%s", input);

        int desimal;

        switch (pilihan) {
        case 1:
            desimal = binerKeDesimal(input);
            printf("\nHasil akhir = %d\n", desimal);
            break;

        case 2:
            desimal = binerKeDesimal(input);
            desKeOktal(desimal);
            break;

        case 3:
            desimal = binerKeDesimal(input);
            desKeHeksa(desimal);
            break;

        case 4:
            desimal = atoi(input);
            desKeBiner(desimal);
            break;

        case 5:
            desimal = atoi(input);
            desKeOktal(desimal);
            break;

        case 6:
            desimal = atoi(input);
            desKeHeksa(desimal);
            break;

        case 7:
            desimal = heksaKeDesimal(input);
            printf("\nHasil akhir = %d\n", desimal);
            break;

        case 8:
            desimal = heksaKeDesimal(input);
            desKeBiner(desimal);
            break;

        case 9:
            desimal = heksaKeDesimal(input);
            desKeOktal(desimal);
            break;

        case 10:
            desimal = oktalKeDesimal(input);
            printf("\nHasil akhir = %d\n", desimal);
            break;

        case 11:
            desimal = oktalKeDesimal(input);
            desKeBiner(desimal);
            break;

        case 12:
            desimal = oktalKeDesimal(input);
            desKeHeksa(desimal);
            break;

        default:
            printf("Pilihan tidak valid!\n");
        }
    }

    return 0;
}