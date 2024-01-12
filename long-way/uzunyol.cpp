#include "uzunyol.h"
//----------------------------SURUCU------------------------------
surucu::surucu()
{
	Ad = nullptr;
	Aduzunluk = 0;
}
surucu::surucu(string ad, unsigned int yas, string ehliyett)
{
	Aduzunluk = ad.size();
	Ad = nullptr;
	Ad = new  char[Aduzunluk];
	if (Ad == nullptr)throw 1;
	for (int i = 0; i < Aduzunluk; i++) {
			Ad[i] = ad[i];
	}
	if (yas < 63 && yas>31) {
		p = yas;
		Yas = p + 32;
	}
	else if (yas == 30 ||yas == 31) {
		Yas = yas;
	}
	else
		Yas=0 ;
	//xml de strin ile aldýðým için böyle biþey yaptým string tipini ehliyetsýnýfýna çeviriyor
	if (ehliyett == "E") ehliyet=EhliyetSinifi::E;
	else if (ehliyett == "C")ehliyet = EhliyetSinifi::C;
	else if (ehliyett == "D")ehliyet = EhliyetSinifi::D;
	else if (ehliyett == "B")ehliyet = EhliyetSinifi::B;
}
surucu::~surucu()
{
	if(Ad!=nullptr)
	delete[]Ad;
}
//copy constructer
surucu::surucu(const surucu &copy)
{
	Yas = copy.Yas;
	ehliyet = copy.ehliyet;
	Aduzunluk = copy.Aduzunluk;
	Ad = new char[Aduzunluk];
	if (Ad == nullptr)
		throw 1;
	for (int i = 0; i < Aduzunluk; i++) {
		Ad[i] = copy.Ad[i];
	}
}
//asiigment
surucu surucu::operator=(const surucu &assigment)
{
	if (this == &assigment)
		return *this;
	if (Ad != nullptr)
		delete[]Ad;
	Yas = assigment.Yas;
	ehliyet = assigment.ehliyet;
	Aduzunluk = assigment.Aduzunluk;
	Ad = new char[Aduzunluk];
	if (Ad == nullptr)throw 1;
	for (int i = 0; i < Aduzunluk; i++) {
		Ad[i] = assigment.Ad[i];
	}
	return *this;
}
ostream & operator<<(ostream &out, surucu &a)
{
	out << "SURUCU ADI  ";
	for (int i = 0; i < a.Aduzunluk; i++)
		out << a.Ad[i];
	if (a.Yas != 0) {
		out << endl << "SURUCU YASI  " << a.Yas << endl;
		out << "SURUCU EHLIYET SINIFI  " << (char)('B' + a.ehliyet) << endl;
	}
	else
		cout <<endl<< "SURUCU OLMAK ICIN YASINIZ UYGUN DEGIL!!"<<endl;
	return out;
}
//--------------------------ARAC-----------------------------------
ostream & operator<<(ostream &out, arac &a)
{
	a.print(out);
	return out;
}
void arac::print(ostream & out)
{
	if (Suruculer.size() == 0)out << "SURUCU YOK" << endl;
	else {
		out << "SURUCULER " << endl << "____________________" << endl;
		for (auto it = Suruculer.begin(); it != Suruculer.end(); ++it)
			cout << *it;
	}
	out << "PLAKA  ";
	for (int i = 0; i < plakauzunluk; i++)
		out <<Plaka[i];
	out << endl;
}
arac::arac()
{
	Plaka = nullptr;
	plakauzunluk = 0;
}

arac::arac(string plaka, list<surucu>suruculer)
{
	plakauzunluk = plaka.size();
	Plaka = new char[plakauzunluk];
	if (Plaka == nullptr)throw 1;
	for (int i = 0; i < plakauzunluk; i++)
		Plaka[i] = plaka[i];
	this->Suruculer = suruculer;
}

arac::~arac()
{
	if (Plaka != nullptr)
		delete[]Plaka;
}

arac::arac(const arac & copy)
{
	Suruculer = copy.Suruculer;
	plakauzunluk = copy.plakauzunluk;
	Plaka = new char[plakauzunluk];
	if (Plaka == nullptr)
		throw 1;
	for (int i = 0; i < plakauzunluk; i++)
		Plaka = copy.Plaka;
}

arac arac::operator=(const arac & assigment)
{
	if (this == &assigment)return *this;
	if (Plaka != nullptr) delete[]Plaka;
	Suruculer = assigment.Suruculer;
	plakauzunluk = assigment.plakauzunluk;
	Plaka = new char[plakauzunluk];
	if (Plaka == nullptr)
		throw 1;
	for (int i = 0; i < plakauzunluk; i++)
		Plaka = assigment.Plaka;
	return *this;
}
//-----------------------------YOLCU-------------------------------------------
ostream & operator<<(ostream &out, yolcu &a)
{
	out << "YOlCU ADI ";
	for (int i = 0; i < a.Aduzunluk; i++)
		out << a.Ad[i];
	out <<endl<< "YOlCU BINIS NOKTASI ";
	for (int i = 0; i < a.BinisNoktuzunluk; i++)
		out << a.BinisNokt[i];
	out << endl << "YOLCU INIS NOKTASI  ";
	for(int i=0;i<a.InisNokt.size();i++)
			out<<a.InisNokt[i];
	cout << endl;
	return out;
}

yolcu::yolcu()
{
	Ad = nullptr;
	Aduzunluk = 0;
	BinisNokt = nullptr; BinisNoktuzunluk = 0;
}

yolcu::yolcu(string add, string binis, string inis)
{
	Aduzunluk = add.size();
	Ad = new char[Aduzunluk];
	if (Ad == nullptr)throw 1;
	for (int i = 0; i < Aduzunluk; i++)
		Ad[i] = add[i];
	BinisNoktuzunluk = binis.size();
	BinisNokt = new char[BinisNoktuzunluk];
	if (BinisNokt == nullptr)throw 1;
	for (int i = 0; i < BinisNoktuzunluk; i++)
		BinisNokt[i] = binis[i];
	InisNokt = inis;
}

yolcu::~yolcu()
{
	if (Ad != nullptr)delete[]Ad;
	if (BinisNokt != nullptr)delete[]BinisNokt;
}

yolcu::yolcu(const yolcu & copy)
{
	InisNokt = copy.InisNokt;
	Aduzunluk = copy.Aduzunluk;
	Ad = new char[Aduzunluk];
	if (Ad == nullptr)exit(-1);
	for (int i = 0; i < Aduzunluk; i++)
		Ad[i] = copy.Ad[i];
	BinisNoktuzunluk = copy.BinisNoktuzunluk;
	BinisNokt = new char[BinisNoktuzunluk];
	if (BinisNokt == nullptr)throw 1;
	for (int i = 0; i < BinisNoktuzunluk; i++)
		BinisNokt[i] = copy.BinisNokt[i];
}

yolcu yolcu::operator=(const yolcu & assigment)
{
	if(this==&assigment)return *this;
	if (Ad != nullptr)delete[]Ad;
	if (BinisNokt != nullptr)delete[]BinisNokt;
	InisNokt = assigment.InisNokt;
	Aduzunluk = assigment.Aduzunluk;
	Ad = new char[Aduzunluk];
	if (Ad == nullptr)throw 1;
	for (int i = 0; i < Aduzunluk; i++)
		Ad[i] = assigment.Ad[i];
	BinisNoktuzunluk = assigment.BinisNoktuzunluk;
	BinisNokt = new char[BinisNoktuzunluk];
	if (BinisNokt == nullptr)throw 1;
	for (int i = 0; i < BinisNoktuzunluk; i++)
		BinisNokt[i] = assigment.BinisNokt[i];
	return *this;
}
//------------------------OTOBUS---------------------------------
ostream & operator<<(ostream & out, otobus & a)
{
	a.print(out);
	return out;
}

void otobus::print(ostream & out)
{
	arac::print(out);
	if (Yolcular.size() == 0) { out << "YOLCU YOK" << endl; return; }
	out <<endl<< "YOLCULAR YAZDIRILIYOR   " << endl << "------------------------------" << endl;
	for (int i = 0; i < Yolcular.size(); i++)
		out << Yolcular[i] << endl;
}

otobus::otobus()
	:arac()
{
}

otobus::otobus(string plaka, list<surucu>surucler, vector<yolcu>yolcular)
	:arac(plaka,surucler)
{
	Yolcular = yolcular;
}
//------------------YUK------------------------------------------
//yazdýrma 
ostream & operator<<(ostream & out, yuk & a)
{
	out <<endl<< "YUK ICERIGI  ";
	for (int i = 0; i < a.icerikuzunluk; i++)
		out << a.icerik[i];
	out << endl << "AGIRLIK  " << a.agirlik << endl;
	out << "HACIM  " << a.hacim << endl;
	out << "ALICI  ";
	for (int i = 0; i < a.alici.size(); i++)
		out << a.alici[i];
	out <<endl<< "BINIS NOKTASI  ";
	for (int i = 0; i < a.BinisNok.size(); i++)
		out << a.BinisNok[i];
	out << endl << "INIS NOKTASI  ";
	for (int i = 0; i < a.InisNok.size(); i++)
		out << a.InisNok[i];
	out << endl;
	return out;
}
//default construcetr
yuk::yuk()
{
	icerik = nullptr;
	icerikuzunluk = 0;
}

yuk::yuk(string icerikk, double agirlikk, double haacimm, string alicii, string binis, string inis)
{
	icerikuzunluk = icerikk.size();
	icerik = nullptr;
	icerik = new char[icerikuzunluk];
	if (icerik == nullptr)throw 1;
	for (int i = 0; i < icerikuzunluk; i++)
		icerik[i] = icerikk[i];
	agirlik = agirlikk;
	hacim = haacimm;
	alici = alicii;
	BinisNok = binis;
	InisNok = inis;
}

yuk::~yuk()
{
	if (icerik != nullptr) delete[]icerik;
}

yuk::yuk(const yuk & copy)
{
	agirlik = copy.agirlik;
	hacim = copy.hacim;
	alici = copy.alici;
	BinisNok = copy.BinisNok;
	InisNok = copy.InisNok;
	icerikuzunluk = copy.icerikuzunluk;
	icerik = nullptr;
	icerik = new char[icerikuzunluk];
	if (icerik == nullptr)throw 1;
	for (int i = 0; i < icerikuzunluk; i++)
		icerik[i] = copy.icerik[i];
}

yuk yuk::operator=(const yuk & assigment)
{
	if (this == &assigment)return *this;
	if (icerik != nullptr)delete[]icerik;
	agirlik = assigment.agirlik;
	hacim = assigment.hacim;
	alici = assigment.alici;
	BinisNok = assigment.BinisNok;
	InisNok = assigment.InisNok;
	icerikuzunluk = assigment.icerikuzunluk;
	icerik = nullptr;
	icerik = new char[icerikuzunluk];
	if (icerik == nullptr)throw 1;
	for (int i = 0; i < icerikuzunluk; i++)
		icerik[i] = assigment.icerik[i];
	return *this;
}

void kamyon::print(ostream & out)
{
	arac::print(out);
	out << "OZLU SOZ  ";
	for (int i = 0; i < ozlusozuzunluk; i++)
		out << OzluSoz[i];
	if (Yukler.size() == 0) { cout <<endl<< "YUK YOK..." << endl; return; }
	out << endl <<endl<< "YUKLER YAZDIRILIYOR..\n" << "----------------------------\n";
	for (int i = 0; i < Yukler.size(); i++)
		out << Yukler[i];
	out << endl;
}

kamyon::kamyon(string ozlusoz, string plaka, list<surucu> suruculer, vector<yuk> yuklerr)
	:arac(plaka, suruculer)
{
	ozlusozuzunluk = ozlusoz.size();
	OzluSoz = nullptr;
	OzluSoz = new char[ozlusozuzunluk];
	if (OzluSoz == nullptr)throw 1 ;
	for (auto i = 0; i < ozlusozuzunluk; i++) {
		OzluSoz[i] = ozlusoz[i];
	}
	Yukler = yuklerr;
}

kamyon::~kamyon()
{
	if (OzluSoz != nullptr)
		delete[]OzluSoz;
}

kamyon::kamyon(const kamyon & copy)
{
	Yukler = copy.Yukler;
	ozlusozuzunluk = copy.ozlusozuzunluk;
	OzluSoz = nullptr;
	OzluSoz = new char[ozlusozuzunluk];
	if (OzluSoz == nullptr)throw 1;
	for (auto i = 0; i < ozlusozuzunluk; i++)
		OzluSoz[i] = copy.OzluSoz[i];
	
}

kamyon kamyon::operator=(const kamyon & assigment)
{
	if (this == &assigment)return *this;
	if (OzluSoz != nullptr)delete[]OzluSoz;
	Yukler = assigment.Yukler;
	ozlusozuzunluk = assigment.ozlusozuzunluk;
	OzluSoz = nullptr;
	OzluSoz = new char[ozlusozuzunluk];
	if (OzluSoz == nullptr)throw 1;
	for (auto i = 0; i < ozlusozuzunluk; i++)
		OzluSoz[i] = assigment.OzluSoz[i];
	return *this;
}
ostream & operator<<(ostream & out, kamyon & a)
{
	a.print(out);
	return out;
}
