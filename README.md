# KNN.md
Berikut adalah Implementasi Algoritma K-Nearest Neighbor Untuk Klasifikasi Pasien Penderita Penyakit Liver di India Berdasarkan Hasil Tes Darah dengan menggunakan Borland C++.

## Metode
+ Menentukan parameter K. yaitu jumlah tetangga terdekat yang akan digunakan dalam proses klasifikasi.
+ Menghitung jarak kedekatan antara data latih dan data uji dengan menggunakan persamaan kuadrat jarak euclidian (euclidean distance).
+ Mengurutkan jarak yang terbentuk (urutan naik).
+ Menentukan jarak terdekat sampai urutan K.
+ Memasangkan kelas yang bersesuaian.
+ Mencari jumlah kelas dari tetangga yang terdekat dan tetapkan kelas tersebut sebagai kelas data uji.


## Implementasi
Implementasinya ada di file MEGAVICHA_DATMIN_UAS.CPP.

## Dataset
Data yang akan digunakan adalah data sekunder dari Indian Liver Patient Dataset. Kumpulan data ini berisi 8 atribut dan berjumlah 500 data dengan rincian 416 catatan pasien liver dan 167 catatan pasien non liver. 

Informasi Atribut:
* TB Total Bilirubin
* DB Direct Bilirubin
* Alkphos Alkaline Phosphotase
* Sgpt Alamine Aminotransferase
* Sgot Aspartate Aminotransferase
* TP Total Protiens
* ALB Albumin
* A/G Ratio Albumin and Globulin Ratio
* Selector field used to split the data into two sets (labeled by the experts)

## Deployment
File berikut harus berada pada satu folder :
```
MEGAVICHA_DATMIN_UAS.CPP
data latih.txt
```

## Authors
* **Mega Musfivawati** - *Initial work* - [megamusfiva](https://github.com/megamusfiva/)
