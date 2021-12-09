#include<iostream>//standar input output
#include<string.h>//untuk mengoperasikan strcpy
#include<time.h>//mengkonversi waktu
using namespace std;

int main(){
	struct tm *Sys_T;
	time_t Tval;
	Tval = time(NULL);
	Sys_T = localtime(&Tval);//untuk mendapatkan waktu lokal komputer
	int i,b,n,j[100],harga[100],th[100],pilih,k,tsh=0,kode[5];
	char kls[100][30],nama[50];
	awal:
	cout<<"\n";
	cout<<"\t  ========= [ DAFTAR TIKET KONSER STRAY KIDS ] ========= \n";
	cout<<"\t___________________________________________________\n";
	cout<<"\t|   Kode Kelas   |    Kelas     |     Harga        |\n";
	cout<<"\t|________________|______________|__________________|\n";
	cout<<"\t|       1        |  VVIP        | Rp. 3.000.000    |\n";
	cout<<"\t|       2        |  VIP         | Rp. 2.500.000    |\n";
	cout<<"\t|       3        |  PREMIUM     | Rp. 2.000.000    |\n";
	cout<<"\t|       4        |  BIASA       | Rp. 1.500.000    |\n";
	cout<<"\t|________________|______________|__________________|\n";
	cout<<"\n";
	cout<<"\n\tMasukan Nama Pembeli : ";
	cin>>nama;
	cout<<"\n\tMasukan Banyak Kode Kelas : ";
	cin>>n;
	cout<<"\n\t__________________________________________________";
	cout<<"\n";

	for(i=1;i<=n;i++){
		cout<<"\n\tPembelian Tiket ke "<<i;
		kode:
		cout<<"\n\tKode Kelas : ";
		cin>>kode[i];
		if(kode[i]==1){
			strcpy(kls[i],"VVIP");
			harga[i]=3000000;
		}else if(kode[i]==2){
			strcpy(kls[i],"VIP");
			harga[i]=2500000;
		}else if(kode[i]==3){
			strcpy(kls[i],"PREMIUM");
			harga[i]=2000000;
		}else if(kode[i]=4){
			strcpy(kls[i],"BIASA");
			harga[i]=1500000;
		}else{
			cout<<"\n\t\t\t\tKODE KELAS SALAH !!\n";
			goto kode;
		}
		cout<<" \tMasukan Jumlah Tiket : ";
		cin>>j[i];
		cout<<"\n\t_________________________________________________\n";
	}
	
	for(i=1;i<=n;i++){
		th[i]=j[i]*harga[i];//mencari total harga masing masing kelas
		tsh=tsh+th[i];//mecari total harga keseluruhan
	}
	cout<<"	Total Harga Keseluruhan\t  : Rp. "<<tsh<<"\n";
	pil1:
	cout<<"	Masukan Jumlah Pembayaran : Rp. ";
	cin>>b;
	k=b-tsh;
	if(b>=tsh){
		system("cls");
		goto data;
	}else{
		cout<<"\n	UANG ANDA KURANG !!\n";
		cout<<"\n";
		goto pil1;
	}
	data:
		system ("cls");
	cout<<"\t===================================================================\n";
	cout<<"\t================[ DATA PEMBAYARAN TIKET KONSER ]===================\n";
	cout<<"\t===================================================================\n";
	cout<<"\n";
	cout<<"\tNama Pemesan :"<<nama;
	cout<<"\n\tDate			: "<< Sys_T->tm_mday<<" - "<< Sys_T->tm_mon+1<<" - "<< 1900+Sys_T->tm_year;
	cout<<"\n\tTime			: "<< Sys_T->tm_hour<<" : "<< Sys_T->tm_min<<" : "<< Sys_T->tm_sec;
	cout<<"\n\t________________________________________________________________\n";
	cout<<"\n\t  No |  Kelas\t|  Harga\t|   Jumlah\t|  Subtotal\t";
	cout<<"\n\t________________________________________________________________\n";
	
	for(i=1;i<=n;i++){
		printf("\n\t %d. | %s\t| Rp.%d \t| %d\t     | Rp.%d\t\n",i,kls[i],harga[i],j[i],th[i]);
	}
	cout<<"\n\t__________________________________________________________________\n";
	cout<<"\n\t  Total Harga\t\t\t\t     | Rp. "<<tsh<<"\n";
	cout<<"\n\t  Pembayaran\t\t\t\t     | Rp. "<<b<<"\n";
	cout<<"\n\t  Kembalian\t\t\t\t     | Rp. "<<k<<"\n";
	cout<<"\n\t___________________________________________________________________\n";
	pil2:
	cout<<"\n";
	cout<<"  Tekan [1] untuk lanjut membeli, dan [0] untuk selesai\n =>";
	cin>>pilih;
	cout<<"\n";
	if(pilih==0){
		goto akhir;
	}else if(pilih==1){
		goto awal;
	}else{
		cout<<"KODE INVALID !";
		goto pil2;
	}
	akhir:
	cout<<"\t\t    Tiket Yang Sudah Dibeli Tidak Dapat Ditukar....!!!\n";
	cout<<"					TERIMA KASIH \n";
	return 0;	
}
