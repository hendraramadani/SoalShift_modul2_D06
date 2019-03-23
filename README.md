# SoalShift_modul2_D06

## Soal 1
1. Elen mempunyai pekerjaan pada studio sebagai fotografer. Suatu hari ada seorang klien yang bernama Kusuma yang meminta untuk mengubah nama file yang memiliki ekstensi .png menjadi “[namafile]_grey.png”. Karena jumlah file yang diberikan Kusuma tidak manusiawi, maka Elen meminta bantuan kalian untuk membuat suatu program C yang dapat mengubah nama secara otomatis dan diletakkan pada direktori /home/[user]/modul2/gambar.
Catatan : Tidak boleh menggunakan crontab.

Jawab:

  ### Source Code:
  [Source Code Soal1.c](/soal1prak.c)
  
  ### Penjelasan:
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
  
  ### Penjelasan Kodingan:
- ``DIR *dir``; adalah suatu variable dengan nama folder yang menggunakan tipe data DIR.Jika digunakan tanpa parameter, perintah ini dapat menampilkan daftar berkas-berkas dan subdirektori yang terdapat di dalam direktori aktif. Berkas ini memiliki satu parameter, yakni lokasi direktori di mana hendak menampilkan daftar isi direktori. 


- ``struct dirent *asli``; Struct adalah tipe data bentukan yang berisi kumpulan variabel-variabel yang berada dalam satu nama yang sama dan memiliki kaitan satu sama lain. Berbeda dengan array hanya berupa kumpulan variabel yang bertipe data sama, struct bisa memiliki variabel-variabel yang bertipe data sama atau berbeda, bahkan bisa menyimpan variabel yang bertipe data array atau struct itu sendiri. Variabel-variabel yang menjadi anggota struct disebut dengan elemen struct.

- ``directory=opendir ("/home/azzamjiul/modul2/")``;adalah fungsi untuk membuka direktori handle gambar yaitu direktori asal dan akan menjalankan perintah pada gambar yang akan di pindah akan membuka direktori pada home/isnaini/modul2.


- ``while ((asli = readdir(dir)) != NULL)`` untuk mengecek isi dalam folder sehingga dapat menjalankan perintah selanjutnya.


- ``namaFile=strtok(asli->d_name,".");'``; memotong nama gamabr hingga ditemukan karakter titik .


- ``ekstrak=strtok(NULL,".");``; mengambil ekstensi dari gambar;


- ``ganti_nama=strcmp(ekstrak,"png");`` ; membandingkan apakah ektensi sama dengan png.


- ``strcat(namaFile,namaTambahan);``; menambahkan karakter pada suatu ekstensi yang berbasis .png

- ``rename(namaAsli,namaBaru);``; mengganti nama awal menjadi nama terbaru hasil editan

  
## Soal 2
2. Pada suatu hari Kusuma dicampakkan oleh Elen karena Elen dimenangkan oleh orang lain. Semua kenangan tentang Elen berada pada file bernama “elen.ku” pada direktori “hatiku”. Karena sedih berkepanjangan, tugas kalian sebagai teman Kusuma adalah membantunya untuk menghapus semua kenangan tentang Elen dengan membuat program C yang bisa mendeteksi owner dan group dan menghapus file “elen.ku” setiap 3 detik dengan syarat ketika owner dan grupnya menjadi “www-data”. Ternyata kamu memiliki kendala karena permission pada file “elen.ku”. Jadi, ubahlah permissionnya menjadi 777. Setelah kenangan tentang Elen terhapus, maka Kusuma bisa move on.
Catatan: Tidak boleh menggunakan crontab

Jawab:

  ### Source Code
  [Source Code Soal2.c](/soal2.c)
  
  ### Penjelasan
  Membuat program C untuk mendeteksi suatu file (elen.ku) dalam direktori /home/[user]/hatiku/elen.ku,Mengubah premission file bila Ownernya "www-data" dan Groupnya "www-data" menjadi 777. Dan mengatur daemon dengan waktu sleep 3 detik.
  
  1. Mengecek file elen.ku ada atau tidak dalam direktori ~/modul2/soal2/hatiku/
  2. Mengecek Owner dan Group dari file "elen.ku"
  3. Apabila Ownernya "www-data" dan Groupnya "www-data" maka ubah premission file "elen.ku" menjadi 777
  4. Setelah itu file "elen.ku" akan dihapus
  
  ### Penjelasan Kodingan

- ``struct stat info`` (adalah perintah untuk menyimpan data yang kompleks berupa info dengan struktur data stat) 

- ``char elenku[] = "/home/dani/modul2/soal2/hatiku/elen.ku";`` (array elenku untuk menyimpan file elen.ku) 

- ``stat(elenku, &info)``; (menyimpan beberapa info dari file yang ditunjuk oleh array elenku)

- ``struct passwd *usr = getpwuid(info.st_uid);`` (mendapatkan info owner fileelen.ku)

- ``struct group *grp= getgrgid(info.st_gid);`` (mendapatkan info group file elen.ku)

-  ``if(!strcmp(grp->gr_name, "www-data") && !strcmp(usr->pw_name, "www-data"))`` (mengecek apakah user dan group file elen.ku sama dengan 'www-data' atau tidak).
 
-  ``chmod(elenku,i);`` (adalah suatu perintah untuk mengubah permission file elen.ku, chmod berfungsi untuk mengatur sebuah hak akses atau sebuah permission terhadap file/ directory kepada user yang dimana i = 0777.)
 
 - ``remove(elenku)``(adalah suatu perintah untuk menghapus file yang disimpan di array elenku yang tidak lain adalah file elen.ku)
 
 - ``sleep(3)``   (adalah sutau perintah delay selama 3 detik untuk menghapus file elen.ku)
 
 - ``exit(EXIT_SUCCESS)`` (adalah suatu perintah jika program berhasil, maka akan melakukan perintah Exit)
  
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
  [Source Code Soal2.c](/soal3prak.c)
  
  ### Penjelasan
  1. membuat proses anak pertama untuk melakukan proses unzip
  2. melakukan proses unzip
  3. membuat proses anak kedua untuk melakukan proses ls
  4. melakukan proses ls dan menyimpan hasil ls
  5. membuat proses anak ketiga untuk melakukan proses grep
  6. melakukan proses grep dan menyimpn hasilnya
  7. kembali ke proses parent setelah ketiga prose anak selesai
  8. melakukan penyimpanan hasil grep ke dalam filr "daftar.txt"
  
  ### Penjelasan Kodingan
  
 -   ``pipe(pipes);`` (adalah perintah untuk membuat pipe) 
        	
 -   ``pipe(pipes+2);`` (adalah perintah untuk menambah pipe)
   
 -   ``execl("/usr/bin/unzip","unzip", "campur2.zip", NULL)`` (adalah perintah untuk mengekstrak file campur2.zip)
   
 -   ``dup2(pipes[1], STDOUT_FILENO);`` (adalah perintah untuk menyimpan hasil ls yang dijalankan dan nantinya akan diduplikasi dengan menggunakan perintah dup2)
   
 -   ``dup2(pipes[0],STDIN_FILENO);``(adalah perintah untuk membaca hasil ls yang dijalankan dan nantinya akan diduplikasi dengan menggunakan perintah dup2)
  
 -  ``close(pipes[1]);`` (setiap perintah dup2 perlu close untuk dapat dihentikan)
  
 -  `` int print = read(pipes[2],hasil,sizeof(hasil));`` (adalah perintah untuk mengambil hasil grep)
   
 -  ``file = fopen("daftar.txt","w+");`` (adalah perintah yang akan membuka file daftar.txt)
   
 -   ``printf("Daftar nama file yang berformat .txt :\n%.*s\n",print,hasil);`` (adalah perintah untuk memasukkan hasil ls grep ke dalam file)
 
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
   [Source Code Soal4.c](/soalprak4.c)
   
  ### Penjelasan
  1. File "makan_enak.txt" di pindahkan/atau di copy ke Direktori /home/[user]/Documents/makanan
  2. Membuat file makan_sehat#.txt jika waktu sekarang - waktu buka file "makan_enak.txt" terakhir <=30
  3. Daemon Dijalankan selama 5 detik sekali pada rentang 0-30 detik dengan syarat memenuhi poin ke 2
  
  ### Penjelasan Kodingan
  -menjadikan "now" variable waktu
  ```
  time_t now;
  time(&now);
  ```
  -``rentang = difftime(now, info.st_atime);`` perintah untuk mencari selisih waktu dari waktu sekarang dengan waktu terakhir file dibuka
  -Membuat file makan_sehat%d.txt secara increment saat file "makan_enak.txt" dibuka jika file terakhir dibuka kurang dari 30 detik
  ```
   if(rentang<=30){
     char path[150],str[20];
     strcpy(path, "/home/azzamjiul/Documents/makanan/makan_sehat");
     sprintf(str,"%d.txt",inc);
     strcat(path,str);
     FILE *baru;
     baru = fopen(path,"w");
     fclose(baru);
     inc++;
     
     sleep(5);
     }
  ```
  
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
  [Source Code Soal5a.c](/soal5a.c)
  [Source Code Soal5b.c](/soal5b.c)
  
  ### Penjelasan
  ### Soal 5a
  Berfungsi untuk membuat file setiap 30 menit :
  ```
  while(1) {
  if(minute%30 == 0){
    time_t now = time(NULL);
    struct tm *p = localtime(&now);
    strftime(dtime, sizeof(dtime)-1, "%Y:%m:%d-%H:%M", p);
  }
  ```
  Berfungsi untuk membuat parent
  ```
    child = fork();
    if(child == 0){
      char cmd[200];
      sprintf(cmd, "%s/%s", dir, dtime);
      char *arg[4] = {"mkdir", "-p" ,cmd, NULL};
      execv("/bin/mkdir", arg);// perintah untuk membuat folder
    }
    while ((wait(&status)) > 0);
    kill(child, SIGKILL);
  ```
  
  ### Soal5b
 Menggunakan perintah "killall" | "/usr/bin/killall" untuk mengekill pid dengan nama "soal5a" 
  ```
  int main(){
    char target[15] = {"soal5a"};
    char *arg[3] = {"killall", target, NULL};
    execv("/usr/bin/killall", arg);
    return 0;
  }
  ```
