# Aplikasi Manajemen Film dan Artis Pemeran
Aplikasi Manajemen Film dan Artis merupakan aplikasi berbasis bahasa C++ yang dirancang untuk mengelola data film beserta artis yang terlibat di dalamnya dengan struktur data Multi Linked List (Parent–Child) yang mendukung CRUD, traversal, pencarian, dan complex query.

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)
![Made by](https://img.shields.io/badge/Made%20by-Kelompok%20NgulikCoding-red)
![Contributor](https://img.shields.io/badge/Contributor-Muhamad%20Indal%20Fauzan%20Azima-blue)
![Contributor](https://img.shields.io/badge/Contributor-Audrey%20Fidelya-purple)

---

## Latar Belakang
Pengelolaan data film dan artis membutuhkan struktur data yang mampu merepresentasikan hubungan satu-ke-banyak (One-to-Many) secara dinamis. Oleh karena itu, aplikasi ini dikembangkan menggunakan pendekatan struktur data Multi Linked List (Parent–Child) untuk memodelkan relasi antara entitas Film dan Artis tanpa menggunakan array statis, sehingga data dapat dikelola secara fleksibel dan efisien.

Aplikasi ini dibuat sebagai bagian dari implementasi konsep Struktur Data pada mata kuliah Struktur Data.

---

## Deskripsi Aplikasi
Aplikasi ini merupakan sistem manajemen data Film dan Artis yang menerapkan struktur data Multi Linked List dengan pendekatan Parent–Child. Entitas Film berperan sebagai parent dan diimplementasikan menggunakan Double Linked List, sedangkan entitas Artis berperan sebagai child yang disimpan dalam Double Linked List pada setiap elemen Film.

Relasi yang digunakan adalah One-to-Many, di mana satu Film dapat memiliki banyak Artis, namun satu Artis hanya terikat pada satu Film. Aplikasi ini mendukung operasi CRUD, traversal, pencarian, serta complex query untuk membantu pengelolaan dan analisis data secara terstruktur, dinamis, dan efisien. Secara keseluruhan, aplikasi ini menyediakan 17 fitur utama.

---

## Tujuan Pengembangan
- Mengimplementasikan konsep Multi Linked List (Parent–Child)
- Mengelola data Film dan Artis secara dinamis
- Menerapkan operasi CRUD, traversal, dan searching
- Melakukan analisis data menggunakan complex query dan summary
- Memenuhi kebutuhan pembelajaran mata kuliah Struktur Data

---

## Fitur Utama
- Menambah, mengubah, dan menghapus data Film
- Menambah, mengubah, dan menghapus data Artis pada Film tertentu
- Menampilkan seluruh data Film beserta Artisnya
- Pencarian Film berdasarkan judul
- Pencarian Artis pada Film tertentu
- Menampilkan Film dengan rating tertinggi dan terendah
- Menampilkan Film dengan jumlah Artis terbanyak
- Menampilkan Artis senior berdasarkan lama karier
- Rekomendasi Film berdasarkan Artis
- Group By dan Summary data
- Complex Query untuk analisis data

---

## Struktur Data yang Digunakan
- Multi Linked List (Parent–Child)
- Double Linked List sebagai parent (Film)
- Double Linked List sebagai child (Artis)

---

## Entitas dan Relasi
### Entitas Film
- ID Film
- Judul Film
- Genre
- Tahun Rilis
- Rating
- Sutradara

### Entitas Artis
- ID Artis
- Nama Artis
- Cast As
- Peran
- Tahun Debut
- Rating Artis

### Relasi
- One-to-Many (1:N)  
  Satu Film dapat memiliki banyak Artis, sedangkan satu Artis hanya dimiliki oleh satu Film. Dimana Artis direpresentasikan sebagai node child yang dibuat dan disimpan secara eksklusif di dalam sub-list milik satu Film tertentu, terikat langsung pada satu parent Film dalam struktur Multi Linked List, serta tidak dikelola sebagai entitas global.

---

## Bahasa Pemrograman
- C++

---

## Struktur File
1. main.cpp  : Berisi fungsi main() dan logika utama program, termasuk menu dan pemanggilan seluruh fitur aplikasi.
2. MLL.cpp   : Berisi implementasi struktur data Multi Linked List serta fungsi-fungsi untuk mengelola data Film dan Artis.
3. MLL.h     : Berisi deklarasi struktur data, tipe data, dan prototype fungsi yang digunakan di MLL.cpp dan dipanggil oleh main.cpp.

---

## Cara Menjalankan Program
1. Buka project menggunakan compiler C++ (Code::Blocks / Dev-C++)
2. Compile seluruh file `.cpp`
3. Jalankan program
4. Gunakan menu yang tersedia untuk mengelola data Film dan Artis

---

## Status Proyek
**Completed**  
Seluruh fitur utama telah diimplementasikan dan aplikasi berjalan sesuai dengan kebutuhan fungsional.

---
