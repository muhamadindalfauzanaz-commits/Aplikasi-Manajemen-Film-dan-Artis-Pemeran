#include "MLL.h"

int main(){
    ListFilm L;
    int pilih;

    createListFilm(L);
    DataFilm(L);

    // ===== HITUNG RATING ARTIS UNTUK DATA AWAL =====
    adrFilm f = L.first;
    while (f != nullptr){
        adrArtis a = f->firstArtis;
        while (a != nullptr){
            updateRatingArtis(L, a->info.namaArtis);
            a = a->next;
        }
        f = f->next;
    }

    do{
        cout << "\n==============================\n";
        cout << "        MENU UTAMA\n";
        cout << "==============================\n";
        cout << "1. Tampilkan Semua Film\n";
        cout << "2. Tambah Film\n";
        cout << "3. Update Film\n";
        cout << "4. Hapus Film\n";
        cout << "5. Cari Film berdasarkan Judul\n";
        cout << "6. Tambah Artis ke Film\n";
        cout << "7. Update Artis\n";
        cout << "8. Hapus Artis dari Film\n";
        cout << "9. Cari Artis dalam Film\n";
        cout << "10. Count Film\n";
        cout << "11. Count Artis dalam Film\n";
        cout << "12. Film dengan Rating Tertinggi dan Terendah\n";
        cout << "13. Tampilkan Artis Senior\n";
        cout << "14. Film dengan Artis Terbanyak\n";
        cout << "15. Rekomendasi Film berdasarkan Artis\n";
        cout << "16. Film Tahun Lama & Rating Tinggi\n";
        cout << "17. Artis Rating Terbesar & Film Terbanyak\n";
        cout << "0. Keluar\n";
        cout << "==============================\n";
        cout << "Pilih menu : ";
        cin >> pilih;
        cout << "==============================\n";

        if (pilih == 1) {
            printList(L);
        }else if (pilih == 2) {
            int idFilm, tahun;
            float rating;
            string judul, genre, sutradara;

            cout << "Input ID Film: ";
            cin >> idFilm;
            cout << "Judul (gunakan underscore): ";
            cin >> judul;
            cout << "Tahun rilis: ";
            cin >> tahun;
            cout << "Genre: ";
            cin >> genre;
            cout << "Rating: ";
            cin >> rating;
            cout << "Sutradara: ";
            cin >> sutradara;

            adrFilm f = createElemenFilm(idFilm, judul, tahun, genre, rating, sutradara);
            addFilm(L, f);

            cout << "Film berhasil ditambahkan!\n";
        }else if (pilih == 3) {
            string judul;
            cout << "Masukkan judul film yang ingin diupdate: ";
            cin >> judul;

            adrFilm f = findFilmByJudul(L, judul);
            if (f == nullptr){
                cout << "Film tidak ditemukan.\n";
            }else {
                string jBaru, gBaru, sBaru;
                int tBaru;
                float rBaru;

                cout << "Judul baru: ";
                cin >> jBaru;
                cout << "Tahun rilis baru: ";
                cin >> tBaru;
                cout << "Genre baru: ";
                cin >> gBaru;
                cout << "Rating baru: ";
                cin >> rBaru;
                cout << "Sutradara baru: ";
                cin >> sBaru;

                updateFilm(f, jBaru, tBaru, gBaru, rBaru, sBaru);

                adrArtis a = f->firstArtis;
                while (a != nullptr){
                updateRatingArtis(L, a->info.namaArtis);
                a = a->next;
                }

                cout << "Film berhasil diupdate!\n";
            }
        }else if (pilih == 4) {
            string judul;
            cout << "Masukkan judul film yang ingin dihapus: ";
            cin >> judul;

            deleteFilmByJudul(L, judul);
        }else if (pilih == 5) {
            string judul;
            cout << "Masukkan judul film yang dicari: ";
            cin >> judul;

            adrFilm f = findFilmByJudul(L, judul);
            if (f == nullptr){
                cout << "Film tidak ditemukan.\n";
            }else{
                printFilmInfo(f);
            }
        }else if (pilih == 6) {
            string judul;
            cout << "Masukkan judul film: ";
            cin >> judul;

            adrFilm f = findFilmByJudul(L, judul);
            if (f == nullptr) {
                cout << "Film tidak ditemukan.\n";
            }else{
                int idA, debut;
                string nama, castAs, peran;

                cout << "ID Artis: ";
                cin >> idA;
                cout << "Nama artis: ";
                cin >> nama;
                cout << "Cast as: ";
                cin >> castAs;
                cout << "Peran: ";
                cin >> peran;
                cout << "Tahun debut: ";
                cin >> debut;

                adrArtis a = createElemenArtis(idA, nama, castAs, peran, debut);
                addArtis(f, a);
                updateRatingArtis(L, nama);
                cout << "Artis berhasil ditambahkan!\n";
            }
        }else if (pilih == 7) {
            string judul, nama;
            cout << "Masukkan judul film: ";
            cin >> judul;

            adrFilm f = findFilmByJudul(L, judul);
            if (f == nullptr){
                cout << "Film tidak ditemukan.\n";
            }else{
                cout << "Nama artis yang ingin diupdate: ";
                cin >> nama;

                adrArtis a = findArtisInFilm(f, nama);
                if (a == nullptr){
                    cout << "Artis tidak ditemukan.\n";
                }else{
                    string nBaru, asBaru, pBaru;
                    int debutBaru;

                    cout << "Nama baru: ";
                    cin >> nBaru;
                    cout << "Cast as baru: ";
                    cin >> asBaru;
                    cout << "Peran baru: ";
                    cin >> pBaru;
                    cout << "Tahun debut baru: ";
                    cin >> debutBaru;

                    updateArtis(a, nBaru, asBaru, pBaru, debutBaru);
                    cout << "Artis berhasil diupdate!\n";
                }
            }
        }else if (pilih == 8) {
            string judul, nama;
            cout << "Masukkan judul film: ";
            cin >> judul;

            adrFilm f = findFilmByJudul(L, judul);
            if (f == nullptr){
                cout << "Film tidak ditemukan.\n";
            }else{
                cout << "Nama artis yang ingin dihapus: ";
                cin >> nama;

                deleteArtisFromFilm(f, nama);
            }
        }else if (pilih == 9) {
            string judul, nama;
            cout << "Masukkan judul film: ";
            cin >> judul;
            cout << "Masukkan nama artis: ";
            cin >> nama;

            adrFilm f = findFilmByJudul(L, judul);
            if (f == nullptr){
                cout << "Film tidak ditemukan.\n";
            }else{
                adrArtis a = findArtisInFilm(f, nama);
                if (a == nullptr){
                    cout << "Artis tidak ditemukan.\n";
                }else{
                    cout << "Artis ditemukan: " << endl;
                    printArtisInfo(a);
                }
            }
        }else if (pilih == 10) {
            cout << "Jumlah film: " << countFilm(L) << endl;
        }else if (pilih == 11) {
            string judul;
            cout << "Masukkan judul film: ";
            cin >> judul;

            adrFilm f = findFilmByJudul(L, judul);
            if (f == nullptr){
                cout << "Film tidak ditemukan.\n";
            }else{
                cout << "Jumlah artis: " << countArtisInFilm(f) << endl;
            }
        }else if (pilih == 12) {
            cout << "Film dengan Rating Tertinggi:\n";
            adrFilm fmax = findMaxRatingFilm(L);
            if (fmax) printFilmInfo(fmax);

            cout << "Film dengan Rating Terendah:\n";
            adrFilm fmin = findMinRatingFilm(L);
            if (fmin) printFilmInfo(fmin);
        }else if (pilih == 13) {
            int tahunSekarang;
            cout << "Masukkan tahun sekarang: ";
            cin >> tahunSekarang;
            tampilArtisSenior(L, tahunSekarang);
        }else if (pilih == 14) {
            adrFilm f = findFilmWithMostArtis(L);
            if(f){
                cout << "Film dengan artis terbanyak:\n";
                printFilmInfo(f);
            }
        }else if (pilih == 15) {
            string nama;
            cout << "Masukkan nama artis: ";
            cin >> nama;

            adrFilm f = rekomendasiFilmAktor(L, nama);
            if (f == nullptr){
                cout << "Tidak ada film untuk artis tersebut.\n";
            }else{
                cout << "Rekomendasi film terbaik:\n";
                printFilmInfo(f);
            }
        } else if (pilih == 16){
            tampilFilmTahunLamaRatingTinggi(L);
        } else if (pilih == 17){
            adrArtis a = artisRatingTerbesarFilmTerbanyak(L);
            if (a == nullptr){
                cout << "Data artis tidak ditemukan.\n";
            }else{
                cout << "\n=== Artis Terbaik ===\n";
                cout << "Nama Artis   : " << a->info.namaArtis << endl;
                cout << "Rating Artis : " << a->info.ratingArtis << endl;
                cout << "Jumlah Film  : " << countFilmByArtis(L, a->info.namaArtis) << endl;
            }
        }

    } while (pilih != 0);

    cout << "Terima kasih!\n";
}
