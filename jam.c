#include <stdio.h>

struct Jam {
    int jam;
    int menit;
    int detik;
};

// Prosedur untuk menjumlahkan dua struct jam
void jumlahJam(struct Jam j1, struct Jam j2, struct Jam *hasil) {
    hasil->detik = j1.detik + j2.detik;
    hasil->menit = j1.menit + j2.menit;
    hasil->jam   = j1.jam   + j2.jam;

    // Normalisasi detik
    if (hasil->detik >= 60) {
        hasil->menit += hasil->detik / 60;
        hasil->detik %= 60;
    }

    // Normalisasi menit
    if (hasil->menit >= 60) {
        hasil->jam   += hasil->menit / 60;
        hasil->menit %= 60;
    }
}

int main() {
    struct Jam j1 = {2, 45, 50};
    struct Jam j2 = {1, 20, 35};
    struct Jam hasil;

    jumlahJam(j1, j2, &hasil);

    printf("Hasil Penjumlahan Jam: %02d:%02d:%02d\n", hasil.jam, hasil.menit, hasil.detik);
    return 0;
}
