#include <stdio.h>
#include <limits.h> // Diperlukan untuk INT_MAX dan INT_MIN
#include <float.h>  // Diperlukan untuk DBL_MAX dan DBL_MIN

// Fungsi untuk mendapatkan input bilangan bulat 'n' dari pengguna.
// Tidak ada pesan prompt tambahan sesuai permintaan.
int get_n() {
    int n_val;
    scanf("%d", &n_val);
    return n_val;
}

// Fungsi untuk mendapatkan satu bilangan bulat dari pengguna.
int get_single_number() {
    int num;
    scanf("%d", &num);
    return num;
}

// Fungsi modular untuk menemukan nilai terkecil, terbesar,
// rata-rata terendah, dan rata-rata tertinggi dari pasangan bilangan yang berturut-turut.
// Menerima jumlah bilangan dan pointer untuk menyimpan hasil min, max, lowest_avg, dan highest_avg.
void find_stats_in_series(int count, int *min_result, int *max_result, double *lowest_avg_result, double *highest_avg_result) {
    // Inisialisasi min dengan nilai terbesar yang mungkin, dan max dengan nilai terkecil yang mungkin
    *min_result = INT_MAX;
    *max_result = INT_MIN;
    // Inisialisasi rata-rata terendah dengan nilai floating point terbesar yang mungkin
    *lowest_avg_result = DBL_MAX;
    // Inisialisasi rata-rata tertinggi dengan nilai floating point terkecil yang mungkin
    *highest_avg_result = DBL_MIN;

    int previous_num; // Menyimpan bilangan sebelumnya untuk perhitungan rata-rata
    
    // Proses input hanya jika count lebih dari 0
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

        // Perhitungan rata-rata untuk pasangan berturut-turut
        // Dimulai dari iterasi kedua (i > 0) karena baru ada pasangan
        if (i > 0) {
            double current_avg = (double)(previous_num + current_num) / 2.0;
            
            // Perbarui rata-rata terendah
            if (current_avg < *lowest_avg_result) {
                *lowest_avg_result = current_avg;
            }
            // Perbarui rata-rata tertinggi
            if (current_avg > *highest_avg_result) {
                *highest_avg_result = current_avg;
            }
        }
        
        // Simpan bilangan saat ini sebagai bilangan sebelumnya untuk iterasi berikutnya
        previous_num = current_num;
    }
}

// Fungsi utama program
int main() {
    // Mendapatkan nilai 'n' dari pengguna
    int n = get_n();

    int min_val, max_val;
    double lowest_avg_val, highest_avg_val;
    
    // Memanggil fungsi modular untuk menemukan statistik
    find_stats_in_series(n, &min_val, &max_val, &lowest_avg_val, &highest_avg_val);

    // Menampilkan hasil minimum dan maksimum
    // Jika n=0, min_val akan tetap INT_MAX dan max_val INT_MIN. Kita akan tampilkan 0 sebagai default.
    // Jika n=1, akan menampilkan nilai itu sendiri untuk min dan max.
    if (n > 0) {
        printf("%d\n", min_val);
        printf("%d\n", max_val);
    } else { // Jika n=0, tidak ada min/max yang valid
        printf("0\n"); 
        printf("0\n");
    }
    
    // Menampilkan hasil rata-rata terendah
    // Jika tidak ada pasangan yang valid (n < 2), lowest_avg_val akan tetap DBL_MAX.
    // Kita akan menampilkan 0.00 sebagai default untuk kasus ini.
    if (lowest_avg_val == DBL_MAX) { // Ini akan berlaku jika n < 2
        printf("0.00\n");
    } else {
        printf("%.2f\n", lowest_avg_val);
    }

    // Menampilkan hasil rata-rata tertinggi
    // Jika tidak ada pasangan yang valid (n < 2), highest_avg_val akan tetap DBL_MIN.
    // Kita akan menampilkan 0.00 sebagai default untuk kasus ini.
    if (highest_avg_val == DBL_MIN) { // Ini akan berlaku jika n < 2
        printf("0.00\n");
    } else {
        printf("%.2f\n", highest_avg_val);
    }

    return 0;
}