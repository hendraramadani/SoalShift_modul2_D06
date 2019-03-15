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
  
## Soal 2
2. Pada suatu hari Kusuma dicampakkan oleh Elen karena Elen dimenangkan oleh orang lain. Semua kenangan tentang Elen berada pada file bernama “elen.ku” pada direktori “hatiku”. Karena sedih berkepanjangan, tugas kalian sebagai teman Kusuma adalah membantunya untuk menghapus semua kenangan tentang Elen dengan membuat program C yang bisa mendeteksi owner dan group dan menghapus file “elen.ku” setiap 3 detik dengan syarat ketika owner dan grupnya menjadi “www-data”. Ternyata kamu memiliki kendala karena permission pada file “elen.ku”. Jadi, ubahlah permissionnya menjadi 777. Setelah kenangan tentang Elen terhapus, maka Kusuma bisa move on.
Catatan: Tidak boleh menggunakan crontab

  ### Source Code
  
  [Source Code Soal2.c](/soal2.c)
  
  ### Jawab
  Membuat program C untuk mendeteksi suatu file (elen.ku) dalam direktori /home/[user]/hatiku/elen.ku,Mengubah premission file bila Ownernya "www-data" dan Groupnya "www-data" menjadi 777. Dan mengatur daemon dengan waktu sleep 3 detik.
  ### Penjelasan
  1. Mengecek file elen.ku ada atau tidak dalam direktori ~/modul2/soal2/hatiku/
  2. Mengecek Owner dan Group dari file "elen.ku"
  3. Apabila Ownernya "www-data" dan Groupnya "www-data" maka ubah premission file "elen.ku" menjadi 777
  4. Setelah itu file "elen.ku" akan dihapus
  
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

## Soal 4
4. Dalam direktori /home/[user]/Documents/makanan terdapat file makan_enak.txt yang berisikan daftar makanan terkenal di Surabaya. Elen sedang melakukan diet dan seringkali tergiur untuk membaca isi makan_enak.txt karena ngidam makanan enak. Sebagai teman yang baik, Anda membantu Elen dengan membuat program C yang berjalan setiap 5 detik untuk memeriksa apakah file makan_enak.txt pernah dibuka setidaknya 30 detik yang lalu (rentang 0 - 30 detik).
Jika file itu pernah dibuka, program Anda akan membuat 1 file makan_sehat#.txt di direktori /home/[user]/Documents/makanan dengan '#' berisi bilangan bulat dari 1 sampai tak hingga untuk mengingatkan Elen agar berdiet.

Contoh:
File makan_enak.txt terakhir dibuka pada detik ke-1
Pada detik ke-10 terdapat file makan_sehat1.txt dan makan_sehat2.txt

Catatan: 
    • dilarang menggunakan crontab
    • Contoh nama file : makan_sehat1.txt, makan_sehat2.txt, dst
    
  ### Source Code
   [Source Code Soal4.c](/soal4.c)
  ### Jawab
  1. File "makan_enak.txt" di pindahkan/atau di copy ke Direktori /home/[user]/Documents/makanan
  2. Membuat file makan_sehat#.txt jika waktu sekarang - waktu buka file terakhir <=30
  3. Daemon Dijalankan selama 5 detik sekali pada rentang 0-30 detik dengan syarat memenuhi poin ke 2
  
## Soal 5
5. Kerjakan poin a dan b di bawah:
    a. Buatlah program c untuk mencatat log setiap menit dari file log pada syslog ke /home/[user]/log/[dd:MM:yyyy-hh:mm]/log#.log
    Ket:
    • Per 30 menit membuat folder /[dd:MM:yyyy-hh:mm]
    • Per menit memasukkan log#.log ke dalam folder tersebut
‘#’ : increment per menit. Mulai dari 1
    b. Buatlah program c untuk menghentikan program di atas.
NB: Dilarang menggunakan crontab dan tidak memakai argumen ketika menjalankan program.

  ### Source Code
  ### Jawab
