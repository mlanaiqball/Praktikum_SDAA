#include <iostream>
#include <string>

// Fungsi untuk memindahkan piringan
void pindahkanPiringan(int jumlahPiringan, const std::string& menaraAsal, const std::string& menaraTujuan, const std::string& menaraSementara) {
    if (jumlahPiringan == 1) {
        std::cout << "Pindahkan piringan dari " << menaraAsal << " ke " << menaraTujuan << std::endl;
    } else {
        // Langkah 1: Pindahkan piringan dari menara asal ke menara sementara
        pindahkanPiringan(jumlahPiringan - 1, menaraAsal, menaraSementara, menaraTujuan);
        
        // Langkah 2: Pindahkan piringan dari menara asal ke menara tujuan
        std::cout << "Pindahkan piringan dari " << menaraAsal << " ke " << menaraTujuan << std::endl;
        
        // Langkah 3: Pindahkan piringan dari menara sementara ke menara tujuan
        pindahkanPiringan(jumlahPiringan - 1, menaraSementara, menaraTujuan, menaraAsal);
    }
}

int main() {
    int jumlahPiringan;
    std::string namaMenaraAsal;
    std::string namaMenaraTujuan;
    std::string namaMenaraSementara;

    // Membaca input dari pengguna
    std::cout << "Masukkan jumlah piringan: ";
    std::cin >> jumlahPiringan;

    std::cout << "Masukkan nama menara asal: ";
    std::cin >> namaMenaraAsal;

    std::cout << "Masukkan nama menara tujuan: ";
    std::cin >> namaMenaraTujuan;

    std::cout << "Masukkan nama menara sementara: ";
    std::cin >> namaMenaraSementara;

    // Memanggil fungsi untuk memindahkan piringan
    pindahkanPiringan(jumlahPiringan, namaMenaraAsal, namaMenaraTujuan, namaMenaraSementara);

    return 0;
}
      