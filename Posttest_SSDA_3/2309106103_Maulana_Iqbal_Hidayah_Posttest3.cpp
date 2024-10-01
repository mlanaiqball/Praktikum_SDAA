#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct untuk menyimpan data produksi film sebagai node dari linked list
struct Film {
    char judul[50];
    char sutradara[50];
    int tahun;
    char genre[20];
    struct Film *next;  // Pointer ke node film berikutnya
};

// Fungsi untuk menambah data film ke linked list
void tambahFilm(struct Film **head) {
    struct Film *newFilm = (struct Film *)malloc(sizeof(struct Film));
    if (newFilm == NULL) {
        printf("Memori tidak cukup!\n");
        return;
    }

    printf("Masukkan judul film: ");
    scanf(" %[^\n]", newFilm->judul);
    printf("Masukkan sutradara film: ");
    scanf(" %[^\n]", newFilm->sutradara);
    printf("Masukkan tahun rilis film: ");
    scanf("%d", &newFilm->tahun);
    printf("Masukkan genre film: ");
    scanf(" %[^\n]", newFilm->genre);

    newFilm->next = NULL;

    if (*head == NULL) {
        *head = newFilm;
    } else {
        struct Film *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newFilm;
    }

    printf("Film berhasil ditambahkan!\n");
}

// Fungsi untuk menampilkan semua data film
void tampilkanFilm(struct Film *head) {
    if (head == NULL) {
        printf("Tidak ada data film.\n");
        return;
    }

    struct Film *temp = head;
    int i = 1;

    while (temp != NULL) {
        printf("\nFilm ke-%d\n", i++);
        printf("Judul: %s\n", temp->judul);
        printf("Sutradara: %s\n", temp->sutradara);
        printf("Tahun: %d\n", temp->tahun);
        printf("Genre: %s\n", temp->genre);
        temp = temp->next;
    }
}

// Fungsi untuk mengedit data film berdasarkan judul
void editFilm(struct Film *head) {
    char judul[50];
    printf("Masukkan judul film yang akan diedit: ");
    scanf(" %[^\n]", judul);

    struct Film *temp = head;

    while (temp != NULL) {
        if (strcmp(temp->judul, judul) == 0) {
            printf("Masukkan judul film baru: ");
            scanf(" %[^\n]", temp->judul);
            printf("Masukkan sutradara baru: ");
            scanf(" %[^\n]", temp->sutradara);
            printf("Masukkan tahun rilis baru: ");
            scanf("%d", &temp->tahun);
            printf("Masukkan genre baru: ");
            scanf(" %[^\n]", temp->genre);
            printf("Data film berhasil diubah!\n");
            return;
        }
        temp = temp->next;
    }

    printf("Film dengan judul '%s' tidak ditemukan.\n", judul);
}

// Fungsi untuk menghapus data film berdasarkan judul
void hapusFilm(struct Film **head) {
    char judul[50];
    printf("Masukkan judul film yang akan dihapus: ");
    scanf(" %[^\n]", judul);

    struct Film *temp = *head;
    struct Film *prev = NULL;

    // Jika film yang akan dihapus ada di head
    if (temp != NULL && strcmp(temp->judul, judul) == 0) {
        *head = temp->next;
        free(temp);
        printf("Film berhasil dihapus!\n");
        return;
    }

    // Mencari film yang akan dihapus
    while (temp != NULL && strcmp(temp->judul, judul) != 0) {
        prev = temp;
        temp = temp->next;
    }

    // Jika film tidak ditemukan
    if (temp == NULL) {
        printf("Film dengan judul '%s' tidak ditemukan.\n", judul);
        return;
    }

    // Menghapus node
    prev->next = temp->next;
    free(temp);
    printf("Film berhasil dihapus!\n");
}

int main() {
    int pilihan;
    struct Film *head = NULL;  // Pointer ke linked list untuk menyimpan data film
    
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
                tambahFilm(&head);
                break;
            case 2:
                tampilkanFilm(head);
                break;
            case 3:
                editFilm(head);
                break;
            case 4:
                hapusFilm(&head);
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
