#include <stdio.h>
#include <string.h>

// Struct untuk menyimpan data produksi film
struct Film {
    char judul[50];
    char sutradara[50];
    int tahun;
    char genre[20];
};

// Fungsi untuk menambah data film
void tambahFilm(struct Film *film, int *jumlah) {
    printf("Masukkan judul film: ");
    scanf(" %[^\n]", film[*jumlah].judul);
    printf("Masukkan sutradara film: ");
    scanf(" %[^\n]", film[*jumlah].sutradara);
    printf("Masukkan tahun rilis film: ");
    scanf("%d", &film[*jumlah].tahun);
    printf("Masukkan genre film: ");
    scanf(" %[^\n]", film[*jumlah].genre);
    (*jumlah)++;
    printf("Film berhasil ditambahkan!\n");
}

// Fungsi untuk menampilkan semua data film
void tampilkanFilm(struct Film *film, int jumlah) {
    if (jumlah == 0) {
        printf("Tidak ada data film.\n");
        return;
    }
    for (int i = 0; i < jumlah; i++) {
        printf("\nFilm ke-%d\n", i + 1);
        printf("Judul: %s\n", film[i].judul);
        printf("Sutradara: %s\n", film[i].sutradara);
        printf("Tahun: %d\n", film[i].tahun);
        printf("Genre: %s\n", film[i].genre);
    }
}

// Fungsi untuk mengedit data film berdasarkan judul
void editFilm(struct Film *film, int jumlah) {
    char judul[50];
    printf("Masukkan judul film yang akan diedit: ");
    scanf(" %[^\n]", judul);

    for (int i = 0; i < jumlah; i++) {
        if (strcmp(film[i].judul, judul) == 0) {
            printf("Masukkan judul film baru: ");
            scanf(" %[^\n]", film[i].judul);
            printf("Masukkan sutradara baru: ");
            scanf(" %[^\n]", film[i].sutradara);
            printf("Masukkan tahun rilis baru: ");
            scanf("%d", &film[i].tahun);
            printf("Masukkan genre baru: ");
            scanf(" %[^\n]", film[i].genre);
            printf("Data film berhasil diubah!\n");
            return;
        }
    }
    printf("Film dengan judul '%s' tidak ditemukan.\n", judul);
}

// Fungsi untuk menghapus data film berdasarkan judul
void hapusFilm(struct Film *film, int *jumlah) {
    char judul[50];
    printf("Masukkan judul film yang akan dihapus: ");
    scanf(" %[^\n]", judul);

    for (int i = 0; i < *jumlah; i++) {
        if (strcmp(film[i].judul, judul) == 0) {
            for (int j = i; j < *jumlah - 1; j++) {
                film[j] = film[j + 1];
            }
            (*jumlah)--;
            printf("Film berhasil dihapus!\n");
            return;
        }
    }
    printf("Film dengan judul '%s' tidak ditemukan.\n", judul);
}

int main() {
    int pilihan;
    int jumlahFilm = 0;
    struct Film dataFilm[100];  // Array untuk menyimpan data film
    
    do {
        printf("\n--- Menu Pengelola Data Produksi Film ---\n");
        printf("1. Tambah Film\n");
        printf("2. Tampilkan Semua Film\n");
        printf("3. Edit Film\n");
        printf("4. Hapus Film\n");
        printf("5. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahFilm(dataFilm, &jumlahFilm);
                break;
            case 2:
                tampilkanFilm(dataFilm, jumlahFilm);
                break;
            case 3:
                editFilm(dataFilm, jumlahFilm);
                break;
            case 4:
                hapusFilm(dataFilm, &jumlahFilm);
                break;
            case 5:
                printf("Terima kasih telah menggunakan program ini.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
                break;
        }
    } while (pilihan != 5);

    return 0;
}
