#include <stdio.h>
#include <limits.h> // Diperlukan untuk INT_MAX dan INT_MIN

// Fungsi untuk mendapatkan input bilangan bulat 'n' dari pengguna.
// Tidak ada pesan prompt tambahan sesuai permintaan.
int get_n() {
    int n_val;
    scanf("%d", &n_val);
    return n_val;
}

// Fungsi untuk mendapatkan satu bilangan bulat dari pengguna.
// Asumsi input akan berada dalam rentang -100 sampai 100 sesuai deskripsi.
int get_single_number() {
    int num;
    scanf("%d", &num);
    return num;
}
// Fungsi modular untuk menemukan nilai terkecil dan terbesar dari 'count' bilangan.
// Menerima jumlah bilangan dan pointer untuk menyimpan hasil min dan max.
void find_min_max_in_series(int count, int *min_result, int *max_result) {
    // Inisialisasi min dengan nilai terbesar yang mungkin, dan max dengan nilai terkecil yang mungkin
    *min_result = INT_MAX;
    *max_result = INT_MIN;

    for (int i = 0; i < count; ++i) {
        int current_num = get_single_number();
        
        // Memperbarui nilai minimum jika ditemukan yang lebih kecil
        if (current_num < *min_result) {
            *min_result = current_num;
        }
        
        // Memperbarui nilai maksimum jika ditemukan yang lebih besar
        if (current_num > *max_result) {
            *max_result = current_num;
        }
    }
}
// Fungsi utama program
int main() {
    // Mendapatkan nilai 'n' dari pengguna
    int n = get_n();

    int min_val, max_val;
    
    // Memanggil fungsi modular untuk menemukan min dan max dari 'n' bilangan
    find_min_max_in_series(n, &min_val, &max_val);

    // Menampilkan hasil minimum, setiap output per baris tanpa teks tambahan
    printf("%d\n", min_val);
    
    // Menampilkan hasil maksimum, setiap output per baris tanpa teks tambahan
    printf("%d\n", max_val);

    return 0;
}