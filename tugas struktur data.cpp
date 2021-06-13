#include<iostream>
#include<conio.h>
#include <cstdlib>
using namespace std;

struct buku{
	int nomor_buku, harga;
	string nama_buku;
	
	buku *next;
};

buku *newData, *head=NULL, *tail=NULL, *tampil, *temp; 

//fungsi input data
void input_data(){
	int no_buku_nilai, harga_nilai;
	string nama_buku_nilai;
	
	cout << "\nMasukkan Nomor Buku: ";
	(cin >> no_buku_nilai).get();
	
	cout << "Masukkan Nama Buku: ";
	getline(cin, nama_buku_nilai);
	
	cout << "Masukkan Harga Buku: ";
	(cin >> harga_nilai).get();
	
	cout << endl;
	cout << "Buku bernomor " << no_buku_nilai << " telah terinput! \n";

	newData = new buku;
	newData->nomor_buku = no_buku_nilai;
	newData->harga = harga_nilai;
	newData->nama_buku = nama_buku_nilai;
}

// fungsi tambah data (dari belakang)
void tambahdata_belakang(){
	input_data();
	if(head == NULL){
		head = newData;
		tail = newData;
		newData->next = head;
	}
	else{
		tail->next = newData;
		tail = newData;
		tail->next = head;
	}
}

// fungsi tampil data
void cetak_data(){
	tampil = head;
	if(head==NULL){
		cout<<"Data buku kosong!";
	}
	else{
		cout << "-----------List Buku -----------\n";
		do{
			cout << "Nomor Buku  : " << tampil->nomor_buku << endl;
			cout << "Nama Buku   : " << tampil->nama_buku << endl;
			cout << "Harga Buku  : " << tampil->harga << endl;
			cout << endl;
			tampil = tampil->next;
		}
		while(tampil != head);
	}
}

// fungsi edit_harga (Sesudah di-searching)
void edit_data(){
	int harga_baru;

	cout << "Masukkan harga buku yang baru: ";
	cin >> harga_baru;
	
	temp->harga = harga_baru;
	cout << "Harga telah berubah menjadi " << temp->harga << endl << endl;
	
	cetak_data();
	
}

// fungsi searching data (untuk edit harga)
void searching_data(){	
	int no_buku_cari, index=0, flag=-1;
	
	cout << "\nMasukkan nomor buku yang dicari: ";
	cin >> no_buku_cari;
	
	temp = head;
	
	if(head==NULL){
		cout << "Maaf, data di dalam linked list belum diinput";
	}
	else{
		do{
			if(temp->nomor_buku == no_buku_cari){
				flag = 1;
				break;
			}
			else{
			      temp = temp->next;
				  index++;
			}
	    }
		while(temp!=head);
	}
	
	if(flag!=-1){
		cout << "\nNomor buku ditemukan di indeks " << index << " dengan keterangan: \n";
		cout << "Nomor Buku   : " << temp->nomor_buku << endl;
		cout << "Nama Buku    : "  << temp->nama_buku << endl;
		cout << "Harga Buku   : " << temp->harga << endl;
		cout << endl;
		
		edit_data();
	} else{
		cout << "maaf, data yang dicari tidak ditemukan";
	}
}

// fungsi utama (main)
int main(){
	cout << "Program Data Buku Dengan SLLC - Noviyana\n";
	cout << "----------------------------------------\n\n";
	
	int pilih;
	
	do{
		cout << "Pilih menu yang ada: \n";
		cout << "1. Tambah Data (belakang)\n";
		cout << "2. Cetak Data\n";
		cout << "3. Edit Data (Harga)\n";
		cout << "4. Exit\n";
	
		cout << "Kamu memilih nomor [1-4]: ";
		cin >> pilih;
		
		if (pilih==1){
			tambahdata_belakang();
			getch();
		}
		else if (pilih==2){
			cetak_data();
			getch();
		}
		else if (pilih==3){
			searching_data();
			getch();
		} 
		else{
			exit(1);
		}
		system("cls");
    } 
	while(1);
}
