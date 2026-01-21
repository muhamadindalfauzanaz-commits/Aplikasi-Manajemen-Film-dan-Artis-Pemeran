#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>
using namespace std;

// TYPE & POINTER
typedef struct elmArtis* adrArtis;
typedef struct elmFilm* adrFilm;

// STRUKTUR DATA
struct Film {
    int idFilm, tahunRilis;
    float rating;
    string judulFilm, genre, sutradara;
};

struct Artis {
    int idArtis, tahunDebut;
    string namaArtis, castAs, peran;
    float ratingArtis;
    bool isPrinted;
};

struct elmFilm{
    Film info;
    adrFilm next;
    adrFilm prev;
    adrArtis firstArtis;
};

struct elmArtis{
    Artis info;
    adrArtis next;
    adrArtis prev;
};

struct ListFilm{
    adrFilm first;
    adrFilm last;
};

// BASIC / PRIMITIVE OPERATION
void createListFilm(ListFilm &L);
bool isEmptyFilm(ListFilm L);
bool isEmptyArtist(adrFilm p);

// CRUD FILM (Basic Operation)
adrFilm createElemenFilm(int idFilm, string JudulFilm, int tahunRilis, string genre, float rating, string sutradara);
void addFilm(ListFilm &L, adrFilm P);
void updateFilm(adrFilm p, string judulBaru, int tahunBaru, string genreBaru, float ratingBaru, string sutradaraBaru);
void deleteFilmByJudul(ListFilm &L, string judulFilm);
adrFilm findFilmByJudul(ListFilm L, string judulFilm);

// CRUD ARTIS (Basic Operation)
adrArtis createElemenArtis(int idArtis, string namaArtis, string castAs, string peran, int tahunDebut);
void addArtis(adrFilm &p, adrArtis q);
void updateArtis(adrArtis q, string namaBaru, string castAsBaru, string peranBaru, int debutBaru);
void deleteArtisFromFilm(adrFilm p, string namaArtis);
adrArtis findArtisInFilm(adrFilm p, string namaArtis);

// TRAVERSE & DISPLAY
void printList(ListFilm &L);
void printFilmInfo(adrFilm p);
void printArtisInfo(adrArtis p);

// COUNT & SEARCH SUMMARY
int countFilm(ListFilm L);
int countArtisInFilm(adrFilm p);
int countFilmByArtis(ListFilm L, string namaArtis);

// SEARCH BY & AGREGASI DATA
adrFilm findMaxRatingFilm(ListFilm L);
adrFilm findMinRatingFilm(ListFilm L);
adrFilm findFilmWithMostArtis(ListFilm L);


// - COMPLEX QUERY -

// rekomendasi film terbaik berdasarkan artis
adrFilm rekomendasiFilmAktor(ListFilm L, string namaArtis);

// hitung rating artis (avg rating film)
float hitungRatingArtis(ListFilm L, string namaArtis);
void updateRatingArtis(ListFilm L, string namaArtis);

// pencarian artis lintas film
adrArtis findArtisGlobal(ListFilm L, string namaArtis);


// GROUP BY & PREVENT DUPLICATE PRINT
void resetPrintedArtis(ListFilm L);
void tandaiArtisPrinted(ListFilm L, string namaArtis);

// - QUERY KHUSUS -

// Artis senior berdasarkan tahun debut
void tampilArtisSenior(ListFilm L, int tahunSekarang);

// Film tahun lama & rating tinggi
void tampilFilmTahunLamaRatingTinggi(ListFilm L);

// Artis terbaik (rating terbesar & film terbanyak)
adrArtis artisRatingTerbesarFilmTerbanyak(ListFilm L);

// DATABASE AWAL
void DataFilm(ListFilm &L);

#endif // MLL_H_INCLUDED
