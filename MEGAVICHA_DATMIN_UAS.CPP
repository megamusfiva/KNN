#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <fstream.h>
#include <string>
#include <iomanip.h>

ofstream KNN;

int l,K,i,j,n,jml_datalatih,OUTPUT, kelasuji;
double zz,za,nilaig,nilaib,nilai1,nilai2,total,total1,kelas1,kelas2;
double data[600][600],dataa[600][600],jarak[600],dataaa[600][600],dataaaa[600][600];
char nama[1000],file[1000],namafile[1000];

void main ()
{
	srand(time(0));
	ulang:
	clrscr();
   cout<<"\t     ====     KLASIFIKASI INDIAN LIVER PATIENT DENGAN ALGORITMA K-NN     ==== "<<endl;
	cout<<"\t =======    PRAVICHANA EL B A K (081711233088) DAN MEGA M (081711233102)    ======="<<endl;
	cout<<"\t     ====          UJIAN AKHIR SEMESTER MATA KULIAH DATA MINING          ==== "<<endl;
	cout<<"\t     =================================================================="<<endl<<endl;
   cout<<endl;

ifstream knnILPD;
knnILPD.open("data latih.txt");jml_datalatih=500;
n=jml_datalatih;

for(i=0;i<n;i++)
{
	for(j=0;j<9;j++)
	{
		knnILPD>>data[i][j];
	}
}
knnILPD.close();

cout<<"\n Penyimpanan output pada notepad : ";
cout<<"\n   Nama file	: ";
cin>>file;
cout<<"	Nomor urut file : ";
cin>>OUTPUT;

//output notepad
strcat(file," ke-");		//menambah karakter kedalam variabel
strcpy(namafile,file);//maksudnya adalah mengcopy isi file ke namafile
itoa(OUTPUT,nama,10);//misal diinputkan hasil=1234, membuat nama berisi 1234
strcat(namafile,nama);//menambah karakter nama kedalam variabel namafile
strcat(namafile,".txt");//strcat berfungsi untuk menggabungkan 2 buah string (melakukan penggabungan variabel namafile dan.txt)
KNN.open(namafile);
KNN<<"\t     ====     KLASIFIKASI INDIAN LIVER PATIENT DENGAN ALGORITMA K-NN     ==== "<<endl;
KNN<<"\t =======    PRAVICHANA EL B A K (081711233088) DAN MEGA M (081711233102)    ======="<<endl;
KNN<<"\t     ====          UJIAN AKHIR SEMESTER MATA KULIAH DATA MINING          ==== "<<endl;
KNN<<"\t     =================================================================="<<endl<<endl;

//Input Data Uji
double TB,DB,SGPT,SGOT,TP,ALB,AG,ALP;
cout<<"Masukkan jumlah tetangga terdekat (K) :  ";
cin>>K;
cout<<"\n DATA UJI "<<endl;
cout<<"Masukkan nilai Total Bilirubin (TB) :  ";
cin>>TB;
cout<<"Masukkan nilai Direct Bilirubin (DB) :  ";
cin>>DB;
cout<<"Masukkan nilai Alkaline Phosphotase (ALP) :  ";
cin>>ALP;
cout<<"Masukkan nilai Serum Glutamic Pyruvic Transaminase (SGPT) :  ";
cin>>SGPT;
cout<<"Masukkan nilai Serum Glutamat Oksaloasetat Transaminase (SGOT) :  ";
cin>>SGOT;
cout<<"Masukkan nilai Total Protein (TP) :  ";
cin>>TP;
cout<<"Masukkan nilai Albumin (ALB) :  ";
cin>>ALB;
cout<<"Masukkan nilai Albumin Globulin (A/G) :  ";
cin>>AG;
KNN<<endl<<"======================================================================================================================"<<endl;
cout<<endl<<"\n Output secara lengkap dapat dilihat pada file => "<<namafile<<endl;

//PENGGABUNGAN DATA LATIH DAN UJI
KNN<<"\n DATA LATIH DAN DATA UJI "<<endl;
KNN<<"TB"<<"\t "<<"DB"<<"\t "<<"ALP"<<"\t "<<"SGPT"<<"\t "<<"SGOT"<<"\t "<<"TP"<<"\t "<<"ALB"<<"\t "<<"AG"<<"\t "<<"CLASS"<<endl;
for(i=0;i<=500;i++)
{     data[500][0]=TB;
		data[500][1]=DB;
      data[500][2]=ALP;
      data[500][3]=SGPT;
      data[500][4]=SGOT;
      data[500][5]=TP;
      data[500][6]=ALB;
      data[500][7]=AG;
      data[500][8]=0;
      KNN<<data[i][0]<<"\t "<<data[i][1]<<"\t "<<data[i][2]<<"\t "<<data[i][3]<<"\t "<<data[i][4]<<"\t "<<data[i][5]<<"\t "<<data[i][6]<<"\t "<<data[i][7]<<"\t "<<data[i][8];
      KNN<<endl;
}
KNN<<endl<<"======================================================================================================================"<<endl;
//NORMALISASI
//Nilai MAX DAN MIN
KNN<<"\n NILAI MAXIMUM DAN MINIMUM TIAP KOLOM "<<endl;
double max0,min0,max1,min1,max2,min2,max3,min3,max4,min4,max5,min5,max6,min6,max7,min7;
KNN<<"\t "<<"MAXIMUM"<<"\t "<<"MINIMUM"<<endl;
min0=100000;max0=0;
min1=100000;max1=0;
min2=100000;max2=0;
min3=100000;max3=0;
min4=100000;max4=0;
min5=100000;max5=0;
min6=100000;max6=0;
min7=100000;max7=0;
for(i=0;i<=n;i++)
{
  		if(min0>data[i][0])//pemilihan nilai terkecil kolom 1
      { 		min0=data[i][0];}
  		if(min1>data[i][1])//pemilihan nilai terkecil kolom 2
      { 		min1=data[i][1];}
  		if(min2>data[i][2])//pemilihan nilai terkecil kolom 3
      { 		min2=data[i][2];}
  		if(min3>data[i][3])//pemilihan nilai terkecil kolom 4
      { 		min3=data[i][3];}
  		if(min4>data[i][4])//pemilihan nilai terkecil kolom 5
      { 		min4=data[i][4];}
  		if(min5>data[i][5])//pemilihan nilai terkecil kolom 6
      { 		min5=data[i][5];}
  		if(min6>data[i][6])//pemilihan nilai terkecil kolom 7
      { 		min6=data[i][6];}
  		if(min7>data[i][7])//pemilihan nilai terkecil kolom 8
      { 		min7=data[i][7];}
}
for(i=0;i<=n;i++)
{
	  	if(max0<data[i][0])//pemilihan nilai terbesar kolom 1
  		{		max0=data[i][0];}
      if(max1<data[i][1])//pemilihan nilai terbesar kolom 2
  		{		max1=data[i][1];}
      if(max2<data[i][2])//pemilihan nilai terbesar kolom 3
		{		max2=data[i][2];}
      if(max3<data[i][3])//pemilihan nilai terbesar kolom 4
  		{		max3=data[i][3];}
      if(max4<data[i][4])//pemilihan nilai terbesar kolom 5
  		{		max4=data[i][4];}
      if(max5<data[i][5])//pemilihan nilai terbesar kolom 6
  		{		max5=data[i][5];}
      if(max6<data[i][6])//pemilihan nilai terbesar kolom 7
  		{		max6=data[i][6];}
      if(max7<data[i][7])//pemilihan nilai terbesar kolom 8
  		{		max7=data[i][7];}
}

 KNN<<"TB : "<<"\t "<<max0<<"\t "<<"\t "<<min0<<endl;
 KNN<<"DB : "<<"\t "<<max1<<"\t "<<"\t "<<min1<<endl;
 KNN<<"ALP : "<<"\t "<<max2<<"\t "<<"\t "<<min2<<endl;
 KNN<<"SGPT : "<<"\t "<<max3<<"\t "<<"\t "<<min3<<endl;
 KNN<<"SGOT : "<<"\t "<<max4<<"\t "<<"\t "<<min4<<endl;
 KNN<<"TP : "<<"\t "<<max5<<"\t "<<"\t "<<min5<<endl;
 KNN<<"ALB : "<<"\t "<<max6<<"\t "<<"\t "<<min6<<endl;
 KNN<<"A/G : "<<"\t "<<max7<<"\t "<<"\t "<<min7<<endl;
 KNN<<endl<<"======================================================================================================================"<<endl;

//TABEL NORMAL
KNN<<"\n TABEL SETELAH DINORMALISASI"<<endl;
KNN<<"NO"<<"\t\t "<<"TB"<<"\t\t "<<"DB"<<"\t\t "<<"ALP"<<"\t\t "<<"SGPT"<<"\t\t "<<"SGOT"<<"\t\t "<<"TP"<<"\t\t "<<"ALB"<<"\t\t "<<"AG"<<"\t\t "<<"CLASS"<<endl;
for(j=0;j<=n;j++)
{
		dataa[j][0]=((data[j][0]-min0)/(max0-min0));
      dataa[j][1]=((data[j][1]-min1)/(max1-min1));
      dataa[j][2]=((data[j][2]-min2)/(max2-min2));
      dataa[j][3]=((data[j][3]-min3)/(max3-min3));
      dataa[j][4]=((data[j][4]-min4)/(max4-min4));
      dataa[j][5]=((data[j][5]-min5)/(max5-min5));
      dataa[j][6]=((data[j][6]-min6)/(max6-min6));
      dataa[j][7]=((data[j][7]-min7)/(max7-min7));
      KNN<<setprecision(1)<<j+1<<"\t\t "<<setprecision(1)<<dataa[j][0]<<"\t\t "<<setprecision(1)<<dataa[j][1]<<"\t\t "<<setprecision(1)<<dataa[j][2]<<"\t\t "<<setprecision(1)<<dataa[j][3]<<"\t\t "<<setprecision(1)<<dataa[j][4]<<"\t\t "<<setprecision(1)<<dataa[j][5]<<"\t\t "<<setprecision(1)<<dataa[j][6]<<"\t\t "<<setprecision(1)<<dataa[j][7]<<"\t\t "<<setprecision(1)<<data[j][8];
      KNN<<endl;
}
//MENGHITUNG JARAK
KNN<<endl<<"======================================================================================================================"<<endl;
KNN<<"\n TABEL JARAK EUCLID"<<endl;
KNN<<"NO"<<"\t "<<"JARAK"<<"\t "<<"CLASS"<<endl;
//hitung jarak
 for(j=0;j<n;j++)
 {
 	jarak[j]=sqrt(pow((dataa[j][0]-dataa[n][0]),2)+pow((dataa[j][1]-dataa[n][1]),2)+pow((dataa[j][2]-dataa[n][2]),2)+pow((dataa[j][3]-dataa[n][3]),2)+pow((dataa[j][4]-dataa[n][4]),2)+pow((dataa[j][5]-dataa[n][5]),2)+pow((dataa[j][6]-dataa[n][6]),2)+pow((dataa[j][7]-dataa[n][7]),2));
   KNN<<j+1<<"\t "<<jarak[j]<<"\t "<<data[j][8]<<endl;
 }
KNN<<endl<<endl;
KNN<<endl<<"======================================================================================================================"<<endl;
//PENGURUTAN
for(l=0;l<500;l++)
{
	for(j=0;j<499;j++)
	{
		if(jarak[j]>jarak[j+1])
		{
			zz=jarak[j];
         jarak[j]=jarak[j+1];
         jarak[j+1]=zz;
         za=data[j][8];
         data[j][8]=data[j+1][8];
         data[j+1][8]=za;
		}
   }
}
KNN<<"  JARAK TERDEKAT DENGAN JARAK UJI"<<endl;
KNN<<"NO."<<"\t "<<"Jarak"<<"\t "<<"Class"<<endl;
for(l=0;l<K;l++) //output data uji dg jarak terdekat sejumlah K inputan
{
	KNN<<l+1<<"\t "<<jarak[l]<<"\t "<<data[l][8]<<endl;
}
nilaig=0;
nilaib=0;
total1=0;

for(l=0;l<K;l++)//menghitung membership function tiap kelas
{
	if(data[l][8]==1)
	{
		nilai1=pow(jarak[l],(-2));
		nilaig=nilaig+nilai1;
	}
	else if (data[l][8]==2)
	{
		nilai2=pow(jarak[l],(-2));
		nilaib=nilaib+nilai2;
	}
	total=pow(jarak[l],(-2));
	total1=total1+total;
}
kelas1=nilaig/total1;
kelas2=nilaib/total1;
if(kelas1>kelas2) //menentukan kelas klasifikasi data uji ke-i
{
	kelasuji=1;
}
else
{
	kelasuji=2;
}
KNN<<endl;
KNN<<endl<<"======================================================================================================================"<<endl;
KNN<<"\t\t KLASIFIKASI DATA UJI "<<endl;
KNN<<"TB"<<"\t "<<"DB"<<"\t "<<"ALP"<<"\t "<<"SGPT"<<"\t "<<"SGOT"<<"\t "<<"TP"<<"\t "<<"ALB"<<"\t "<<"AG"<<"\t "<<"CLASS"<<endl;
KNN<<setprecision(3)<<TB<<"\t "<<setprecision(3)<<DB<<"\t "<<setprecision(3)<<ALP<<"\t "<<setprecision(3)<<SGPT<<"\t "<<setprecision(3)<<SGOT<<"\t "<<setprecision(3)<<TP<<"\t "<<setprecision(3)<<ALB<<"\t "<<setprecision(3)<<AG<<"\t "<<setprecision(3)<<kelasuji;
if(kelasuji==1)
{ KNN<<endl<<"\t\t Anda Didiagnosa Liver Disorder";}
else if(kelasuji==2)
{ KNN<<endl<<"\t\t Selamat, Anda baik-baik saja";}
KNN<<endl;

getch();
}


