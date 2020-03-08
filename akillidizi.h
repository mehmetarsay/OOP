#pragma once
#include <vector>
#include <iostream>
#include<string.h>
#include <sstream>
using namespace std;
template<class T>
struct Pair
{
	T eleman;
	int adet;
} ; // histogramda her bir elemandan kacar adet oldugunu gosterebilecek veri tipi */
template<class T>
class AkilliDizi /* TEMPLATE OLACAK */
{
	template<class T>
	friend ostream& operator<<(ostream&, AkilliDizi<T> &);
	// Dizinin tum elemanlarini ekrana basabilecek sekilde << operatorunu asiri yukleyiniz TEMPLATE OLACAK
public:
	AkilliDizi(); /* bos bir akilli dizi olusturur*/
	AkilliDizi(T i); /* tek elamanlý ve eleman degeri i olan bir akilli dizi olustururTEMPLATE OLACAK*/
	AkilliDizi(const T* TDizi, unsigned int elemanSayisi); /* elemanSayisi elamanli bir
	akilli dizi olusturur ve intDizi elamanlarini akilli diziye atar TEMPLATE OLACAK*/
	AkilliDizi(const vector<T>& TVector); /*vektoru akilli diziye donusturur TEMPLATE OLACAK*/
	/* Dinamik bellek yonetimi icin gerekli olan fonksiyonlari yaziniz TEMPLATE OLACAK*/
	~AkilliDizi();
	AkilliDizi(const AkilliDizi<T>& i);
	AkilliDizi<T>operator=(const AkilliDizi<T>other);
	/* [] operatorunu asiri yukleyiniz. Verilen indeks degeri elemanSayisindan buyukse hata
	mesaji yazdirin. TEMPLATE OLACAK*/
	T operator[](unsigned int a)const;
	/* Akilli diye bir int degeri ekleyebilecek sekilde + operatorunu yukleyin TEMPLATE OLACAK*/
	AkilliDizi<T>operator+(T& i);
	void sirala()const; /* diziyi buyukten kucuge siralar TEMPLATE OLACAK*/
	void histogram(vector<Pair<T>>& hist) const; /* veri icinde gecen her bir elemanin kac kez
	oldugunu bulur ve bunu vektor<Pair> olarak donderir TEMPLATE OLACAK*/
	unsigned kacTane(T i) const; /* veri icinde i degerinden kac tane olduðunu sayar TEMPLATE OLACAK*/
	bool varMi(T i) const; /* veri icinde i degeri mevcutsa dogru degilse yanlis donderir	TEMPLATE OLACAK*/
private:
	T* veri; /* veriyi dinamik olarak tutar TEMPLATE OLACAK*/
	unsigned int kapasite; /* Kapasite doldugunda yeni alinacak yer mevcut kapasitenin yarisi 	olmali. Ýhtiyac daha
	fazlaysa ihtiyac + mevcut kapasitenin yarisi kadar yer alinmali.*/
	unsigned int elemanSayisi; /* dizideki mevcut eleman sayisini verir */
};
class ogrenci
{
	friend ostream& operator<<(ostream&o, ogrenci&s) {
		int a = 0, b = 0;
		cout << "[";
		while (b<s.numbrlen) {
			o << s.number[b];
			b++;
		}
		cout << "] ";
		while (a<s.namelen) {
			o << s.name[a];
			a++;
		}
		return o;
	}
public:
	ogrenci() {
		name = nullptr;
		number = nullptr;
		namelen = 0;
		numbrlen = 0;
	};
	ogrenci(string name, string number) {
		try {
			namelen = name.size();
			numbrlen = number.size();
			this->name = new char[namelen];
			if (this->name == nullptr) throw 73;
			this->number = new char[numbrlen];
			if (this->number == nullptr) throw 75;
			for (int a = 0; a < namelen; a++)
				this->name[a] = name[a];
			for (int a = 0; a < numbrlen; a++)
				this->number[a] = number[a];
		}
		catch (int i) { cout << i << ". satýrda yer alamadým programý sonlandýrýyorum..."; exit(-1); }
	}
	ogrenci(const ogrenci& copy) {
		try {
			namelen = copy.namelen;
			numbrlen = copy.numbrlen;
			name = new char[namelen];
			if (name == nullptr)throw 87;
			number = new char[numbrlen];
			if (number == nullptr)throw 89;
			for (int a = 0; a < namelen; a++)
				name[a] = copy.name[a];
			for (int a = 0; a < numbrlen; a++) {
				number[a] = copy.number[a];
			}
		}
		catch (int i) { cout << i << ". satýrda yer alamadým programý sonlandýrýyorum..."; exit(-1); }
	}
	ogrenci& operator=(const ogrenci &assigment) {
		try {
			if (this == &assigment)
				return *this;
			if (name != nullptr)
				delete[]name;
			if (number != nullptr)
				delete[]number;
			namelen = assigment.namelen;
			numbrlen = assigment.numbrlen;
			name = new char[namelen];
			if (name == nullptr)throw 109;
			number = new char[numbrlen];
			if (number == nullptr)throw 111;
			for (int a = 0; a < namelen; a++) {
				name[a] = assigment.name[a];
			}
			for (int a = 0; a < numbrlen; a++) {
				number[a] = assigment.number[a];
			}
		}
		catch (int i) { cout << i << ". satýrda yer alamadým programý sonlandýrýyorum..."; exit(-1); }
		return *this;
	}
	~ogrenci()  {
		if (name != nullptr)
		{
			delete[]name;
		}
		if(number!=nullptr)
		{
			delete[]number;
		}
	}
	bool operator<(ogrenci& a) {
		string strsayi1,strsayi2;
		for (int j = 0; j < a.numbrlen; j++)
			strsayi1.push_back(a.number[j]);
		int sayi1=0;
		sayi1 = stoi(strsayi1);
		for (int j = 0; j <this->numbrlen; j++)
			strsayi2.push_back(this->number[j]);
		int sayi2 = 0;
		sayi2 = stoi(strsayi2);
		if (sayi1 < sayi2) return true;
		return false;
	}
	bool operator==(ogrenci& a) {
		string strsayi1, strsayi2;
		for (int j = 0; j < a.numbrlen; j++)
			strsayi1.push_back(a.number[j]);
		for (int j = 0; j < a.numbrlen; j++)
			strsayi2.push_back(this->number[j]);
		string strname1, strname2;
		for (int j = 0; j < a.namelen; j++)
			strname1.push_back(a.name[j]);
		for (int j = 0; j < a.namelen; j++)
			strname2.push_back(this->name[j]);
		if ((strname1 == strname2)&& (strsayi1 == strsayi2)) return true;
		return false;
	}
private:
	char *name;
	int namelen;
	char *number;
	int numbrlen;
};

