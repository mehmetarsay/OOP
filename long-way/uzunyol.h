#pragma once
#include<iostream>
#include<list>
#include<vector>
using namespace std;
enum EhliyetSinifi { B, C, D, E };
//surucunun bilgilerini tutan sýnýf
class surucu
{
	friend ostream& operator << (ostream&, surucu&);
private:
	char*Ad;
	int Aduzunluk;
	unsigned int p : 5;
	unsigned int Yas;//yas 30 ile 62 arasýnda olmalýdýr
	EhliyetSinifi ehliyet;
public:
	surucu();
	surucu(string add, unsigned int, string);
	~surucu();//destracter
	surucu(const surucu&copy);//copy constructer
	surucu operator=(const surucu&assigment);//assigment operator
	char*getAd() { return Ad; }
	unsigned int getyas() { return Yas; }
	void setAd(string add) {
		Aduzunluk = add.size();
		Ad = nullptr;
		Ad = new char[Aduzunluk];
		if (Ad == nullptr)throw 2;
		for (int i = 0; i < Aduzunluk; i++)
			Ad[i] = add[i];
	}
	void setYas(unsigned int a) { Yas = a; }
};
//--------------------------------------------------------
//arac bilgilerini tutan sanal sýnýf  
class arac
{
	friend ostream& operator << (ostream&, arac&);
public:
	virtual void print(ostream &out);//sanal olmasý için yazýlmýs print fonksiyonu
	arac();
	arac(string, list<surucu>);
	virtual~arac();//destracter
	arac(const arac&copy);//copy constracter
	arac operator=(const arac&assigment);//assigment operator
	char* getplaka() { return Plaka; }
	list<surucu> getSuruculer() { return Suruculer; }
	void setplaka(string plaka){
		plakauzunluk = plaka.size();
		Plaka = nullptr;
		Plaka = new char[plakauzunluk];
		if (Plaka == nullptr)throw 2;
		for (int i = 0; i < plakauzunluk; i++)
			Plaka[i] = plaka[i];
	}
private:
	char *Plaka;
	int plakauzunluk;
	list<surucu>Suruculer;
};
//---------------------------------------------
//otobus içindeki yolcularý tutar
class yolcu
{
	friend ostream&operator<<(ostream&, yolcu&);//yazdýrma
public:
	yolcu();//default constructer
	yolcu(string add, string binis, string inis);
	~yolcu();//destructer
	yolcu(const yolcu&copy);//copy constructer
	yolcu operator=(const yolcu&assigment);//assigment operator
	char*getAd() { return Ad; }
	char* getBinisNokt() { return BinisNokt; }
	string getInisNokt() { return InisNokt; }
	void setAd(string add) {
		Aduzunluk = add.size();
		Ad = nullptr;
		Ad = new char[Aduzunluk];
		if (Ad == nullptr)throw 2;
		for (int i = 0; i < Aduzunluk; i++)
			Ad[i] = add[i];
	}
	void setBinisNokt(string Binis) {
		BinisNoktuzunluk = Binis.size();
		BinisNokt = nullptr;
		BinisNokt = new char[BinisNoktuzunluk];
		if (BinisNokt == nullptr) throw 2;
		for (int i = 0; i < BinisNoktuzunluk; i++)
			Ad[i] = Binis[i];
	}
	void setInisNokt(string inis) { InisNokt = inis; }
private:
	char*Ad;
	int Aduzunluk;//add uzunluðunu tutar
	char*BinisNokt;
	int BinisNoktuzunluk;
	string InisNokt;
};
//-------------------------------------------------
//arac sýnýfýndan turemis otobus sýnýfý
class otobus :public arac 
{
	friend ostream& operator<<(ostream&out, otobus&a);
public:
	virtual void print(ostream &out);//polimorfizim olmasý için yapýlmýþ print fonksiyonu
	otobus();//default constructer
	otobus(string plaka,list<surucu>,vector<yolcu>);
	virtual~otobus() {}//destrucetr
	vector<yolcu>getYolcular() { return Yolcular; }
private:
	vector<yolcu>Yolcular;
};
//--------------------------------------------------
//kamyona yuklenen yuk bilgileerini tutar
class yuk
{
	friend ostream& operator<<(ostream&out, yuk&a);
public:
	yuk();//default constructer
	yuk(string icerikk, double agirlikk, double haacimm,
		string alicii, string binis, string inis);
	~yuk();//destructer
	yuk(const yuk&copy);//copy construcetr
	yuk operator=(const yuk&assigment);//assigment operator
	char *geticerik() { return icerik; }
	double getagirlik() { return agirlik; }
	double gethacim() { return hacim; }
	string getalici() { return alici; }
	string getBinisNok() { return BinisNok; }
	string getInisNok() { return InisNok; }
	void seticerik(string alicii) {
		icerikuzunluk = alicii.size();
		icerik = nullptr;
		icerik = new char[icerikuzunluk];
		if (icerik == nullptr)throw 2;
		for (int i = 0; i < icerikuzunluk; i++)
			alici[i] = alicii[i];
	}
	void setagirlik(double agirlikk) { agirlik = agirlikk; }
	void sethacim(double hacimm) { hacim = hacimm; }
	void setalici(string alicii) { alici = alicii; }
	void setBinisNok(string binis) { BinisNok = binis; }
	void setInisNok(string inis) { InisNok = inis; }
private:
	char*icerik;
	int icerikuzunluk;
	double agirlik;
	double hacim;
	string alici;
	string BinisNok;
	string InisNok;
};
//arac sýnýfýndan turemiþ kamyon sýnýfý 
class kamyon :public arac
{
	friend ostream& operator<<(ostream&out, kamyon&a);
public:
	virtual void print(ostream &out);
	kamyon() { OzluSoz = nullptr; };
	kamyon(string ozlusoz,string plaka, list<surucu>suruculer, vector<yuk>yuklerr);
	~kamyon();//destructer
	kamyon(const kamyon&copy);//copy constructer
	kamyon operator=(const kamyon&assigment);//assigment operator
	vector<yuk>getYukler() { return Yukler; }
	char* getozlusoz() { return OzluSoz; }
private:
	char*OzluSoz;
	int ozlusozuzunluk;
	vector<yuk>Yukler;
};
//--------------------------------------------------


