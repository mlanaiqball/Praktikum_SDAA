#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct untuk menyimpan data produksi film sebagai node dari linked list
struct Film {
    char judul[50];
    char sutradara[50];
    int tahun;
    char genre[20];
    struct Film *next;
};

// Fungsi untuk menambah film ke stack
void pushFilm(struct Film **top) {
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

    newFilm->next = *top;
    *top = newFilm;

    printf("Film berhasil ditambahkan ke stack!\n");
}

// Fungsi untuk menghapus film dari stack (pop)
void popFilm(struct Film **top) {
    if (*top == NULL) {
        printf("Stack film kosong!\n");
        return;
    }

    struct Film *temp = *top;
    *top = (*top)->next;
    free(temp);

    printf("Film berhasil dihapus dari stack!\n");
}

// Fungsi untuk menampilkan semua film dalam stack
void tampilkanStackFilm(struct Film *top) {
    if (top == NULL) {
        printf("Tidak ada film dalam stack.\n");
        return;
    }

    struct Film *temp = top;
    int i = 1;
    while (temp != NULL) {
        printf("\nFilm ke-%d (Stack)\n", i++);
        printf("Judul: %s\n", temp->judul);
        printf("Sutradara: %s\n", temp->sutradara);
        printf("Tahun: %d\n", temp->tahun);
        printf("Genre: %s\n", temp->genre);
        temp = temp->next;
    }
}

// Fungsi untuk menambah film ke queue
void enqueueFilm(struct Film **front, struct Film **rear) {
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

    if (*rear == NULL) {
        *front = *rear = newFilm;
    } else {
        (*rear)->next = newFilm;
        *rear = newFilm;
    }

    printf("Film berhasil ditambahkan ke queue!\n");
}

// Fungsi untuk menghapus film dari queue (dequeue)
void dequeueFilm(struct Film **front, struct Film **rear) {
    if (*front == NULL) {
        printf("Queue film kosong!\n");
        return;
    }

    struct Film *temp = *front;
    *front = (*front)->next;

    if (*front == NULL) {
        *rear = NULL;
    }

    free(temp);
    printf("Film berhasil dihapus dari queue!\n");
}

// Fungsi untuk menampilkan semua film dalam queue
void tampilkanQueueFilm(struct Film *front) {
    if (front == NULL) {
        printf("Tidak ada film dalam queue.\n");
        return;
    }

    struct Film *temp = front;
    int i = 1;
    while (temp != NULL) {
        printf("\nFilm ke-%d (Queue)\n", i++);
        printf("Judul: %s\n", temp->judul);
        printf("Sutradara: %s\n", temp->sutradara);
        printf("Tahun: %d\n", temp->tahun);
        printf("Genre: %s\n", temp->genre);
        temp = temp->next;
    }
}

int main() {
    int pilihan;
    struct Film *stackTop = NULL;  // Stack untuk film
    struct Film *queueFront = NULL, *queueRear = NULL;  // Queue untuk film
    
    do {
        printf("\n--- Menu Pengelola Data Produksi Film ---\n");
        printf("1. Tambah Film ke Stack\n");
        printf("2. Hapus Film dari Stack\n");
        printf("3. Tampilkan Semua Film dalam Stack\n");
        printf("4. Tambah Film ke Queue\n");
        printf("5. Hapus Film dari Queue\n");
        printf("6. Tampilkan Semua Film dalam Queue\n");
        printf("7. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                pushFilm(&stackTop);
                break;
            case 2:
                popFilm(&stackTop);
                break;
            case 3:
                tampilkanStackFilm(stackTop);
                break;
            case 4:
                enqueueFilm(&queueFront, &queueRear);
                break;
            case 5:
                dequeueFilm(&queueFront, &queueRear);
                break;
            case 6:
                tampilkanQueueFilm(queueFront);
                break;
            case 7:
                printf("Terima kasih telah menggunakan program ini.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
                break;
        }
    } while (pilihan != 7);

    return 0;
}
