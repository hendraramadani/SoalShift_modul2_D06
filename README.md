# SoalShift_modul2_D06

## Soal 1
1. Elen mempunyai pekerjaan pada studio sebagai fotografer. Suatu hari ada seorang klien yang bernama Kusuma yang meminta untuk mengubah nama file yang memiliki ekstensi .png menjadi “[namafile]_grey.png”. Karena jumlah file yang diberikan Kusuma tidak manusiawi, maka Elen meminta bantuan kalian untuk membuat suatu program C yang dapat mengubah nama secara otomatis dan diletakkan pada direktori /home/[user]/modul2/gambar.
Catatan : Tidak boleh menggunakan crontab.

Jawab:
  ### Source Code:
  
  [Source Code Soal1.c](/soal1.c)
  
  ### Penjelasan:
  1. membuat folder baru modul2
  2. memebuat folder baru "soal1" di dalam folder "modul2"
  3. membaut folder baru "gamabar" di dalam folder "soal1"
  4. membuat file c dengan nama "soal1.c"
  
  ### penjelasan algoritma
  1. memastikan direktori "/home/azzamjiul/modul2/" ada
  2. variabel "namaAsli" menyimpan direktori asal kemudian ditambahkan dengan nama file lalu disimpan di variabel "namaFile" dan ditambahi dengan nama file dengan menggunakan (nama folder)-> d_name
  3. memisahkan nama file dari ekstensi ".png" dengan fungsi strtok() dan menyimpan ekstensi file ke variable "ekstensi"
  4. membandingkan apakah ektensinya "png" atau tidak. jika iya baka variable "ganti_nama" berniali 0;
  5. variable "namaBaru" diisi dengan directory tujuan terlebih dahulu
  6. variable "namaFile" ditambahkan dengan variabel "namaTambahan" dengan menggunakan fungsi strcat()
  7. setelah itu variabel "namaBaru" yang awalnya berisi alamat directory ditambahkan dengan nama file yang sudah diberi nama tambahan.
  8. merename nama asli dengan nama yang baru.
  9. menutup directory
  10. dijalankan tiap 45 detik

## Soal 3
3. Diberikan file campur2.zip. Di dalam file tersebut terdapat folder “campur2”. 
Buatlah program C yang dapat :
  i)  mengekstrak file zip tersebut.
  ii) menyimpan daftar file dari folder “campur2” yang memiliki ekstensi .txt ke dalam file daftar.txt. 
Catatan:  
  Gunakan fork dan exec.
  Gunakan minimal 3 proses yang diakhiri dengan exec.
  Gunakan pipe
  Pastikan file daftar.txt dapat diakses dari text editor
  
  ### Source Code
  ### Jawab
