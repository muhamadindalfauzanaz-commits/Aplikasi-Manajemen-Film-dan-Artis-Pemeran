#include "MLL.h"
#include <iostream>
using namespace std;

// Basic
void createListFilm(ListFilm &L){
    L.first = nullptr;
    L.last = nullptr;
}
bool isEmptyFilm(ListFilm L){
    return (L.first == nullptr);
}
bool isEmptyArtist(adrFilm p){
    return (p == nullptr || p->firstArtis == nullptr);
}

// Film
adrFilm createElemenFilm(int idFilm, string judulFilm, int tahunRilis, string genre, float rating, string sutradara){
    adrFilm p = new elmFilm;

    p->info.idFilm = idFilm;
    p->info.judulFilm = judulFilm;
    p->info.tahunRilis = tahunRilis;
    p->info.genre = genre;
    p->info.rating = rating;
    p->info.sutradara = sutradara;

    p->next = nullptr;
    p->prev = nullptr;
    p->firstArtis = nullptr;
    return p;
}
void addFilm(ListFilm &L, adrFilm p){
    if(isEmptyFilm(L)){
        L.first = p;
        L.last = p;
    }else{
        p->prev = L.last;
        L.last->next = p;
        L.last = p;
    }
}
void updateFilm(adrFilm p, string judulBaru, int tahunBaru, string genreBaru, float ratingBaru, string sutradaraBaru){
    if (p == nullptr) return;

    p->info.judulFilm = judulBaru;
    p->info.tahunRilis = tahunBaru;
    p->info.genre = genreBaru;
    p->info.rating = ratingBaru;
    p->info.sutradara = sutradaraBaru;
}
void deleteFilmByJudul(ListFilm &L, string judulFilm){
    adrFilm p = findFilmByJudul(L, judulFilm);

    if (p == nullptr) {
        cout << "Film tidak ditemukan\n";
        return;
    }

    // Hapus semua artis dalam film
    adrArtis a = p->firstArtis;
    while (a != nullptr) {
        adrArtis delA = a;
        a = a->next;
        delA = nullptr;
    }
    p->firstArtis = nullptr;

    // Lepas node film dari double linked list
    if (p == L.first && p == L.last) {
        // hanya satu film
        L.first = nullptr;
        L.last = nullptr;

    } else if (p == L.first) {
        L.first = p->next;
        L.first->prev = nullptr;

    } else if (p == L.last) {
        L.last = p->prev;
        L.last->next = nullptr;

    } else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }

    cout << "Film berhasil dihapus\n";

    p = nullptr;
}
adrFilm findFilmByJudul(ListFilm L, string judulFilm){
    adrFilm p;
    p = L.first;

    while(p != nullptr){
        if(p->info.judulFilm == judulFilm){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

// Artis
adrArtis createElemenArtis(int idArtis, string namaArtis, string castAs, string peran, int tahunDebut){
    adrArtis p = new elmArtis;

    p->info.idArtis = idArtis;
    p->info.namaArtis = namaArtis;
    p->info.castAs = castAs;
    p->info.peran = peran;
    p->info.tahunDebut = tahunDebut;
    p->info.ratingArtis = 0.0;
    p->info.isPrinted = false;

    p->next = nullptr;
    p->prev = nullptr;
    return p;
}
void addArtis(adrFilm &p, adrArtis q){
    adrArtis a;
    a = p->firstArtis;

    if(isEmptyArtist(p)){
        p->firstArtis = q;
    }else{
        while(a->next != nullptr){
            a = a->next;
        }
        a->next = q;
        q->prev = a;
    }
}
void updateArtis(adrArtis q, string namaBaru, string castAsBaru, string peranBaru, int debutBaru){
    if (q == nullptr) return;

    q->info.namaArtis = namaBaru;
    q->info.castAs = castAsBaru;
    q->info.peran = peranBaru;
    q->info.tahunDebut = debutBaru;
}
float hitungRatingArtis(ListFilm L, string namaArtis){
    float total = 0;
    int count = 0;

    adrFilm f = L.first;
    while (f != nullptr){
        adrArtis a = findArtisInFilm(f, namaArtis);
        if (a != nullptr){
            total += f->info.rating;
            count++;
        }
        f = f->next;
    }

    if (count == 0) return 0;
    return total / count;
}
void updateRatingArtis(ListFilm L, string namaArtis){
    float rating = hitungRatingArtis(L, namaArtis);

    adrFilm f = L.first;
    while (f != nullptr){
        adrArtis a = f->firstArtis;
        while (a != nullptr){
            if (a->info.namaArtis == namaArtis){
                a->info.ratingArtis = rating;
            }
            a = a->next;
        }
        f = f->next;
    }
}
void deleteArtisFromFilm(adrFilm p, string namaArtis){
    adrArtis q = findArtisInFilm(p, namaArtis);

    if(q == nullptr){
        cout << "Artis tidak ditemukan\n";
    }else{
        // lepas node artis
        if(q == p->firstArtis){
            p->firstArtis = q->next;
            if(p->firstArtis != nullptr){
                p->firstArtis->prev = nullptr;
            }
        } else {
            // Lepas node q
            q->prev->next = q->next;

            if(q->next != nullptr){
                q->next->prev = q->prev;
            }
        }

        q = nullptr;
        cout << "Artis berhasil dihapus\n";
    }
}
adrArtis findArtisInFilm(adrFilm p, string namaArtis){
    adrArtis q;
    q = p->firstArtis;

    while(q != nullptr){
        if(q->info.namaArtis == namaArtis){
            return q;
        }
        q = q->next;
    }
    return nullptr;
}

// Print List
void printList(ListFilm &L){
    adrFilm p;
    adrArtis q;
    p = L.first;

    if(isEmptyFilm(L)){
        cout << "List Film Kosong\n";
    }

    while(p != nullptr){
        cout << "===============================\n";
        cout << "ID Film     : " << p->info.idFilm << endl;
        cout << "Judul       : " << p->info.judulFilm << endl;
        cout << "Tahun Rilis : " << p->info.tahunRilis << endl;
        cout << "Genre       : " << p->info.genre << endl;
        cout << "Rating      : " << p->info.rating << endl;
        cout << "Sutradara   : " << p->info.sutradara << endl;

        q = p->firstArtis;
        if(q == nullptr){
            cout << "=== Belum ada artis ===\n";
        }else{
            cout << "  Daftar Artis:\n";
            while (q != nullptr) {
                cout << "    - " << q->info.namaArtis << " sebagai " << q->info.castAs << " (" << q->info.peran << "), debut " << q->info.tahunDebut << endl;
                q = q->next;
            }
        }

        p = p->next;
    }

    cout << "===============================" << endl;
}
void printFilmInfo(adrFilm p) {
    if (p == nullptr) {
        cout << "Data film tidak ditemukan.\n";
        return;
    }
    cout << "===============================\n";
    cout << "ID Film     : " << p->info.idFilm << endl;
    cout << "Judul       : " << p->info.judulFilm << endl;
    cout << "Tahun Rilis : " << p->info.tahunRilis << endl;
    cout << "Genre       : " << p->info.genre << endl;
    cout << "Rating      : " << p->info.rating << endl;
    cout << "Sutradara   : " << p->info.sutradara << endl;
    cout << "===============================\n";
}
void printArtisInfo(adrArtis p){
    if (p == nullptr){
        cout << "Data artis tidak ditemukan.\n";
        return;
    }

    cout << "-------------------------------\n";
    cout << "ID Artis     : " << p->info.idArtis << endl;
    cout << "Nama Artis   : " << p->info.namaArtis << endl;
    cout << "Cast As      : " << p->info.castAs << endl;
    cout << "Peran        : " << p->info.peran << endl;
    cout << "Tahun Debut  : " << p->info.tahunDebut << endl;
    cout << "Rating Artis : " << p->info.ratingArtis << endl;
    cout << "-------------------------------\n";
}

// Operasi khusus
int countFilm(ListFilm L){
    int i = 0;
    adrFilm p = L.first;

    while(p != nullptr){
        i++;
        p = p->next;
    }
    return i;
}

int countArtisInFilm(adrFilm p){
    int i = 0;
    adrArtis q;
    q = p->firstArtis;

    while(q != nullptr){
        i++;
        q = q->next;
    }
    return i;
}

adrFilm findMaxRatingFilm(ListFilm L){
    adrFilm p = L.first;
    adrFilm maxFilm = p;

    if(isEmptyFilm(L)){
        return nullptr;
    }

    while (p != nullptr) {
        if (p->info.rating > maxFilm->info.rating) {
            maxFilm = p;
        }
        p = p->next;
    }
    return maxFilm;
}
adrFilm findMinRatingFilm(ListFilm L){
    adrFilm p = L.first;
    adrFilm minFilm = p;

    if(isEmptyFilm(L)){
        return nullptr;
    }

    while (p != nullptr) {
        if (p->info.rating < minFilm->info.rating) {
            minFilm = p;
        }
        p = p->next;
    }
    return minFilm;
}

void resetPrintedArtis(ListFilm L){
    adrFilm f = L.first;
    while (f != nullptr){
        adrArtis a = f->firstArtis;
        while (a != nullptr){
            a->info.isPrinted = false;
            a = a->next;
        }
        f = f->next;
    }
}
void tandaiArtisPrinted(ListFilm L, string namaArtis){
    adrFilm f = L.first;
    while (f != nullptr){
        adrArtis a = f->firstArtis;
        while (a != nullptr){
            if (a->info.namaArtis == namaArtis){
                a->info.isPrinted = true;
            }
            a = a->next;
        }
        f = f->next;
    }
}
void tampilArtisSenior(ListFilm L, int tahunSekarang){
    resetPrintedArtis(L);
    bool found = false;

    adrFilm f = L.first;
    while (f != nullptr){
        adrArtis a = f->firstArtis;
        while (a != nullptr){

            if (!a->info.isPrinted){
                int lamaKarier = tahunSekarang - a->info.tahunDebut;
                if (lamaKarier >= 20){
                    updateRatingArtis(L, a->info.namaArtis);
                    tandaiArtisPrinted(L, a->info.namaArtis);
                    found = true;

                    cout << "\n==============================\n";
                    cout << "Nama Artis   : " << a->info.namaArtis << endl;
                    cout << "Tahun Debut  : " << a->info.tahunDebut << endl;
                    cout << "Rating Artis : " << a->info.ratingArtis << endl;
                    cout << "Film        : ";

                    adrFilm f2 = L.first;
                    bool first = true;
                    while (f2 != nullptr){
                        if (findArtisInFilm(f2, a->info.namaArtis) != nullptr){
                            if (!first){
                                cout << ", ";
                            }
                            cout << f2->info.judulFilm;
                            first = false;
                        }
                f2 = f2->next;
                }
                cout << endl;
                }
            }
            a = a->next;
        }
        f = f->next;
    }

    if (!found){
        cout << "\nTidak ada artis senior.\n";
    }
}

adrArtis findArtisGlobal(ListFilm L, string namaArtis){
    adrFilm f = L.first;
    while (f != nullptr){
        adrArtis a = f->firstArtis;
        while (a != nullptr){
            if (a->info.namaArtis == namaArtis){
                return a;
            }
            a = a->next;
        }
        f = f->next;
    }
    return nullptr;
}

adrFilm findFilmWithMostArtis(ListFilm L){
    if (L.first == nullptr) {
        return nullptr;
    }

    adrFilm p = L.first;
    adrFilm maxFilm = p;
    int maxCount = countArtisInFilm(p);

    p = p->next;
    while (p != nullptr) {
        int c = countArtisInFilm(p);
        if (c > maxCount) {
            maxCount = c;
            maxFilm = p;
        }
        p = p->next;
    }

    return maxFilm;
}

void tampilFilmTahunLamaRatingTinggi(ListFilm L){
    adrFilm f = L.first;
    bool found = false;

    while (f != nullptr){
        if (f->info.tahunRilis < 2005 && f->info.rating > 7.5){
            found = true;
            cout << "===============================\n";
            cout << "ID Film     : " << f->info.idFilm << endl;
            cout << "Judul       : " << f->info.judulFilm << endl;
            cout << "Tahun Rilis : " << f->info.tahunRilis << endl;
            cout << "Genre       : " << f->info.genre << endl;
            cout << "Rating      : " << f->info.rating << endl;
            cout << "Sutradara   : " << f->info.sutradara << endl;
        }
        f = f->next;
    }

    if (!found){
        cout << "Tidak ada film dengan kriteria tersebut.\n";
    }
}

int countFilmByArtis(ListFilm L, string namaArtis){
    int count = 0;
    adrFilm f = L.first;

    while (f != nullptr){
        if (findArtisInFilm(f, namaArtis) != nullptr){
            count++;
        }
        f = f->next;
    }
    return count;
}

adrArtis artisRatingTerbesarFilmTerbanyak(ListFilm L){
    resetPrintedArtis(L);

    adrArtis best = nullptr;

    adrFilm f = L.first;
    while (f != nullptr){
        adrArtis a = f->firstArtis;
        while (a != nullptr){
            if (!a->info.isPrinted){
                updateRatingArtis(L, a->info.namaArtis);
                tandaiArtisPrinted(L, a->info.namaArtis);

                if (best == nullptr){
                    best = a;
                } else {
                    if (a->info.ratingArtis > best->info.ratingArtis){
                        best = a;
                    }
                    else if (a->info.ratingArtis == best->info.ratingArtis){
                        int filmA = countFilmByArtis(L, a->info.namaArtis);
                        int filmBest = countFilmByArtis(L, best->info.namaArtis);

                        if (filmA > filmBest){
                            best = a;
                        }
                    }
                }
            }
            a = a->next;
        }
        f = f->next;
    }
    return best;
}

// rekomendasi film berdasarkan rating tertinggi
adrFilm rekomendasiFilmAktor(ListFilm L, string namaArtis){
    adrFilm bestFilm = nullptr;
    float bestRating = -1;

    adrFilm f = L.first;
    while(f != nullptr){
        adrArtis found = findArtisInFilm(f, namaArtis);
        if(found != nullptr){
            if(f->info.rating > bestRating){
                bestRating = f->info.rating;
                bestFilm = f;
            }
        }
        f = f->next;
    }

    return bestFilm;
}

// database
void DataFilm(ListFilm &L){
    // Film 1
    adrFilm f1 = createElemenFilm(
        1, "Inception", 2010, "Sci-Fi", 8.8, "Christopher_Nolan"
    );
    addFilm(L, f1);

    adrArtis a11 = createElemenArtis(101, "Leonardo_DiCaprio", "Dom_Cobb", "Protagonis", 1991);
    adrArtis a12 = createElemenArtis(102, "Joseph_Gordon-Levitt", "Arthur", "Pendukung", 1988);
    adrArtis a13 = createElemenArtis(103, "Elliot_Page", "Ariadne", "Pendukung", 2005);

    addArtis(f1, a11);
    addArtis(f1, a12);
    addArtis(f1, a13);

    // Film 2
    adrFilm f2 = createElemenFilm(
        2, "Interstellar", 2014, "Sci-Fi", 8.6, "Christopher_Nolan"
    );
    addFilm(L, f2);

    adrArtis a21 = createElemenArtis(201, "Matthew_McConaughey", "Cooper", "Protagonis", 1993);
    adrArtis a22 = createElemenArtis(202, "Anne_Hathaway", "Brand", "Pendukung", 2001);

    addArtis(f2, a21);
    addArtis(f2, a22);

    // Film 3
    adrFilm f3 = createElemenFilm(
        3, "The_Dark_Knight", 2008, "Action", 9.0, "Christopher_Nolan"
    );
    addFilm(L, f3);

    adrArtis a31 = createElemenArtis(301, "Christian_Bale", "Bruce_Wayne", "Protagonis", 1990);
    adrArtis a32 = createElemenArtis(302, "Heath_Ledger", "Joker", "Antagonis", 1992);
    adrArtis a33 = createElemenArtis(303, "Gary_Oldman", "Gordon", "Pendukung", 1980);

    addArtis(f3, a31);
    addArtis(f3, a32);
    addArtis(f3, a33);

    // Film 4
    adrFilm f4 = createElemenFilm(
        4, "The_Matrix", 1999, "Sci-Fi", 8.7, "Wachowski"
    );
    addFilm(L, f4);

    adrArtis a41 = createElemenArtis(401, "Keanu_Reeves", "Neo", "Protagonis", 1986);
    adrArtis a42 = createElemenArtis(402, "Laurence_Fishburne", "Morpheus", "Pendukung", 1972);
    adrArtis a43 = createElemenArtis(403, "Carrie-Anne_Moss", "Trinity", "Pendukung", 1991);

    addArtis(f4, a41);
    addArtis(f4, a42);
    addArtis(f4, a43);

    // Film 5
    adrFilm f5 = createElemenFilm(
        5, "Titanic", 1997, "Drama", 7.8, "James_Cameron"
    );
    addFilm(L, f5);

    adrArtis a51 = createElemenArtis(501, "Leonardo_DiCaprio", "Jack_Dawson", "Protagonis", 1991);
    adrArtis a52 = createElemenArtis(502, "Kate_Winslet", "Rose_DeWitt", "Protagonis", 1991);

    addArtis(f5, a51);
    addArtis(f5, a52);

    // Film 6
    adrFilm f6 = createElemenFilm(6, "Oppenheimer", 2023, "Biography", 8.6, "Christopher_Nolan");
    addFilm(L, f6);

    adrArtis a61 = createElemenArtis(601, "Cillian_Murphy", "Oppenheimer", "Protagonis", 1996);
    adrArtis a62 = createElemenArtis(602, "Emily_Blunt", "Kitty", "Pendukung", 2001);

    addArtis(f6, a61);
    addArtis(f6, a62);

    // Film 7
    adrFilm f7 = createElemenFilm(7, "Dune", 2021, "Sci-Fi", 8.0, "Denis_Villeneuve");
    addFilm(L, f7);

    adrArtis a71 = createElemenArtis(701, "Timothee_Chalamet", "Paul_Atreides", "Protagonis", 2014);
    adrArtis a72 = createElemenArtis(702, "Zendaya", "Chani", "Pendukung", 2010);

    addArtis(f7, a71);
    addArtis(f7, a72);

    // Film 8
    adrFilm f8 = createElemenFilm(8, "American_Psycho", 2000, "Thriller", 7.6, "Mary_Harron");
    addFilm(L, f8);

    adrArtis a81 = createElemenArtis(801, "Christian_Bale", "Patrick_Bateman", "Protagonis", 1990);

    addArtis(f8, a81);

    // Film 9
    adrFilm f9 = createElemenFilm(9, "The_Prestige", 2006, "Drama", 8.5, "Christopher_Nolan");
    addFilm(L, f9);

    adrArtis a91 = createElemenArtis(901, "Christian_Bale", "Alfred_Borden", "Protagonis", 1990);
    adrArtis a92 = createElemenArtis(902, "Hugh_Jackman", "Robert_Angier", "Protagonis", 1994);
    adrArtis a93 = createElemenArtis(903, "Scarlett_Johansson", "Olivia_Wenscombe", "Pendukung", 1994);

    addArtis(f9, a91);
    addArtis(f9, a92);
    addArtis(f9, a93);

}
