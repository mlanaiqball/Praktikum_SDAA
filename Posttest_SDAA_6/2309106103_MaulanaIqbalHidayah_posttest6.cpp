#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Struct untuk menyimpan data produksi film sebagai node dari linked list
struct Film {
    char judul[50];
    char sutradara[50];
    int tahun;
    char genre[20];
    struct Film *next;
};

// Fibonacci Search Function
int fibonacciSearch(int arr[], int size, int x) {
    int fibMMm2 = 0; // (m-2)'th Fibonacci
    int fibMMm1 = 1; // (m-1)'th Fibonacci
    int fibM = fibMMm2 + fibMMm1; // m'th Fibonacci

    while (fibM < size) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;
    while (fibM > 1) {
        int i = (offset + fibMMm2 < size - 1) ? offset + fibMMm2 : size - 1;
        if (arr[i] < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        } else if (arr[i] > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        } else {
            return i;
        }
    }

    if (fibMMm1 && arr[offset + 1] == x) return offset + 1;
    return -1;
}

// Jump Search Function
int jumpSearch(int arr[], int size, int x) {
    int step = sqrt(size);
    int prev = 0;

    while (arr[(step < size ? step : size) - 1] < x) {
        prev = step;
        step += sqrt(size);
        if (prev >= size)
            return -1;
    }

    while (arr[prev] < x) {
        prev++;
        if (prev == (step < size ? step : size))
            return -1;
    }
    if (arr[prev] == x)
        return prev;
    return -1;
}

// Boyer-Moore String Search Function
int max(int a, int b) {
    return (a > b) ? a : b;
}

void badCharHeuristic(char *str, int size, int badchar[256]) {
    int i;
    for (i = 0; i < 256; i++)
        badchar[i] = -1;
    for (i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}

int boyerMooreSearch(char *txt, char *pat) {
    int m = strlen(pat);
    int n = strlen(txt);

    int badchar[256];
    badCharHeuristic(pat, m, badchar);

    int s = 0;
    while (s <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        if (j < 0) {
            return s; // Found
        } else {
            s += max(1, j - badchar[(int)txt[s + j]]);
        }
    }
    return -1; // Not found
}

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

// Fungsi untuk menjalankan menu searching
void searchMenu() {
    int intArr[] = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
    int size = sizeof(intArr) / sizeof(intArr[0]);
    char strArr[][50] = {"Film1", "Film2", "Film3", "Film4", "Film5"};
    char searchStr[50];
    int x, result;

    printf("\n--- Menu Searching ---\n");
    printf("1. Fibonacci Search (Integer)\n");
    printf("2. Jump Search (Integer)\n");
    printf("3. Boyer-Moore Search (String)\n");
    printf("Pilih menu: ");
    int searchChoice;
    scanf("%d", &searchChoice);

    switch (searchChoice) {
        case 1:
            printf("Masukkan angka untuk mencari: ");
            scanf("%d", &x);
            result = fibonacciSearch(intArr, size, x);
            if (result == -1)
                printf("Elemen tidak ditemukan dengan Fibonacci Search.\n");
            else
                printf("Elemen ditemukan di index %d dengan Fibonacci Search.\n", result);
            break;
        case 2:
            printf("Masukkan angka untuk mencari: ");
            scanf("%d", &x);
            result = jumpSearch(intArr, size, x);
            if (result == -1)
                printf("Elemen tidak ditemukan dengan Jump Search.\n");
            else
                printf("Elemen ditemukan di index %d dengan Jump Search.\n", result);
            break;
        case 3:
            printf("Masukkan string untuk mencari: ");
            scanf(" %[^\n]", searchStr);
            result = boyerMooreSearch(strArr[0], searchStr);
            if (result == -1)
                printf("String tidak ditemukan dengan Boyer-Moore Search.\n");
            else
                printf("String ditemukan di index %d dengan Boyer-Moore Search.\n", result);
            break;
        default:
            printf("Pilihan tidak valid!\n");
            break;
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
        printf("7. Menu Searching\n");
        printf("8. Keluar\n");
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
                searchMenu();
                break;
            case 8:
                printf("Terima kasih telah menggunakan program ini.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
                break;
        }
    } while (pilihan != 8);

    return 0;
}
