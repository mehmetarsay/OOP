#include"sozluk.h"
#include"Kayit.h"
#include<iostream>
using namespace std;
// bos bir sozluk oluturur.
Sozluk::Sozluk()
{
	kayitlar = nullptr;
	toplamKayitSayisi = 0;
}
// tek bir kayittan olusan bir sozluk olusturur.

Sozluk::Sozluk(const Kayit& kayit)

{
	kayitlar = new Kayit[1];
	if (kayitlar == nullptr)
		exit(-1);
	kayitlar[0] = kayit;
	toplamKayitSayisi = 1;
}
Sozluk::Sozluk(const vector<Kayit> & kayitlar)
{
	vector<Kayit> temp = kayitlar; 

	for (unsigned i = 0; i < temp.size(); i++)
	{
		for (unsigned j = temp.size() - 1; j > i; j--)
		{
			if (temp[i].getKelime() == temp[j].getKelime())
			{
				temp[i] + temp[j];
				temp.erase(temp.begin() + j);
			}
		}
	}
	this->kayitlar = nullptr;
	this->kayitlar = new Kayit[temp.size()];
	if (this->kayitlar == nullptr)
		exit(-1);
	toplamKayitSayisi = temp.size();
	for (unsigned i = 0; i < toplamKayitSayisi; i++)
	{
		this->kayitlar[i] = temp[i];
	}

}
//Copy Consturcter
Sozluk::Sozluk(const Sozluk & copy)
{
	toplamKayitSayisi = copy.toplamKayitSayisi;
	kayitlar = nullptr;
	if (toplamKayitSayisi != 0)
	{
		kayitlar = new Kayit[toplamKayitSayisi];
		if (kayitlar == nullptr)
			exit(-1);

		for (unsigned i = 0; i < toplamKayitSayisi; i++)
		{
			kayitlar[i] = copy.kayitlar[i];
		}
	}
}
//Destructer
Sozluk::~Sozluk()
{
	if (kayitlar != nullptr)
		delete[] kayitlar;
}
//Assigment operatörünün 
const Sozluk& Sozluk::operator=(const Sozluk & other)
{
	if (this == &other)
		return *this;
	if (kayitlar != nullptr)
		delete[] kayitlar;
	toplamKayitSayisi = other.toplamKayitSayisi;
	kayitlar = new Kayit[toplamKayitSayisi];
	if (kayitlar == nullptr)
		exit(-1);
	for (unsigned i = 0; i < toplamKayitSayisi; i++)
	{
		kayitlar[i] = other.kayitlar[i];
	}
	return *this;

}
Kayit& Sozluk::operator[](const string & kelime)
{

	for (unsigned i = 0; i < toplamKayitSayisi; i++)
	{
		if (kayitlar[i].getKelime() == kelime)
			return kayitlar[i];
	}
	Kayit a;
	return a;
}
int Sozluk::getAciklamSayisi()const
{
	int temp = 0;
	for (unsigned i = 0; i < toplamKayitSayisi; i++)
	{
		temp += kayitlar[i].getAciklamaSayisi();
	}
	return temp;
}
bool Sozluk::operator ==(const Sozluk digerSozluk)
{
	if (this->getAciklamSayisi() == digerSozluk.getAciklamSayisi())
		return true;
	return false;
}

bool Sozluk::operator!=(const Sozluk digerSozluk)
{
	if (this->getAciklamSayisi() != digerSozluk.getAciklamSayisi())
		return true;
	return false;
}

bool Sozluk::operator>(const Sozluk digerSozluk)
{
	if (this->getAciklamSayisi() > digerSozluk.getAciklamSayisi())
		return true;
	return false;
}

bool Sozluk::operator<(const Sozluk digerSozluk)
{
	if (getAciklamSayisi() < digerSozluk.getAciklamSayisi())
		return true;
	return false;
}

bool Sozluk::operator<=(const Sozluk digerSozluk)
{
	if (this->getAciklamSayisi() <= digerSozluk.getAciklamSayisi())
		return true;
	return false;
}

bool Sozluk::operator>=(const Sozluk digerSozluk)
{
	if (this->getAciklamSayisi() >= digerSozluk.getAciklamSayisi())
		return true;
	return false;
}
Sozluk& Sozluk::operator+(const Sozluk & digerSozluk)
{
	vector<Kayit>temp;
	vector<Kayit>tempb;
	for (int i = 0; i < this->toplamKayitSayisi; i++) {
		temp.push_back(this->kayitlar[i]);
	}
	for (int i = 0; i < digerSozluk.toplamKayitSayisi; i++) {
		tempb.push_back(digerSozluk.kayitlar[i]);
	}
	for (int i = 0; i < this->toplamKayitSayisi; i++) {
		for (int j = 0; j < digerSozluk.toplamKayitSayisi; j++) {
			if ((temp[i].getKelime() == tempb[j].getKelime())) {
				temp[i] + tempb[j];
			}
		}
	}
	toplamKayitSayisi = temp.size();
	this->kayitlar = new Kayit[toplamKayitSayisi];
	if (this->kayitlar == nullptr) exit(-1);
	for (unsigned i = 0; i < toplamKayitSayisi; i++) {
		this->kayitlar[i] = temp[i];
	}
	return *this;
}
Sozluk& Sozluk::operator+=(const Sozluk & digerSozluk)
{
	vector<Kayit>temp;
	vector<Kayit>tempb;
	int f = 0;
	for (int i = 0; i < this->toplamKayitSayisi; i++) {
		temp.push_back(this->kayitlar[i]);
	}
	for (int i = 0; i < digerSozluk.toplamKayitSayisi; i++) {
		tempb.push_back(digerSozluk.kayitlar[i]);
	}
	for (int i = 0; i < this->toplamKayitSayisi; i++) {
		for (int j = 0; j < digerSozluk.toplamKayitSayisi; j++) {
			if ((temp[i].getKelime() == tempb[j].getKelime())) {
				temp[i] = temp[i] + tempb[j];
				f++;
			}
		}
	}
	if (f > 0) {
		toplamKayitSayisi = temp.size();
		this->kayitlar = new Kayit[toplamKayitSayisi];
		if (this->kayitlar == nullptr) exit(-1);
		for (unsigned i = 0; i < toplamKayitSayisi; i++) {
			this->kayitlar[i] = temp[i];
		}
		f = 0;
		return *this;
	}
}
Sozluk& Sozluk::operator-=(const Kayit & kayit)
{
	unsigned temp;
	for (unsigned i = 0; i < this->toplamKayitSayisi; i++)
	{
		if (this->kayitlar[i].getKelime() == kayit.getKelime())
			temp = i;
	}
	if (this->kayitlar[temp].getAciklamaSayisi() == 0)
	{
		vector<Kayit> gecici;
		for (unsigned i = 0; i < toplamKayitSayisi; i++)
		{
			if (i != temp)
				gecici.push_back(kayitlar[i]);
		}
		Sozluk a(gecici);
		*this = a;
		return *this;

	}
	else
	{
		this->kayitlar[temp].aciklamalariSilme();
		return *this;
	}
}
Sozluk& Sozluk::operator-=(const string & kelime)
{
	for (unsigned i = 0; i < this->toplamKayitSayisi; i++)
	{
		if (this->kayitlar[i].getKelime() == kelime)
			this->kayitlar[i].aciklamalariSilme();
	}
	return *this;
}
ostream& operator<<(ostream & o, const Sozluk & s)
{
	o << "Kayitli Kelime Sayisi: " << s.toplamKayitSayisi << endl;
	o << "Toplam aciklama Sayisi: " << s.getAciklamSayisi() << endl;
	return o;
}

ofstream& operator<<(ofstream& out, const Sozluk& s)
{
	
	for (int i = 0; i < s.toplamKayitSayisi; i++) {
		string m = s.kayitlar[i].getKelime();
		for (unsigned i = 0; i < m.size(); i++)
		{
			out << m[i];
		}
		out << "\n";
		vector<string> d=s.kayitlar[i].getAciklama();
		for (unsigned j = 0; j < d.size(); j++)
		{
			out << "-";
			for (unsigned k = 0; k < d[j].size(); k++) {
				out << d[j][k];
			}
			out << "\n";
		}
		out << "#"<<endl;
	}
	return out;
}

ifstream& operator>>(ifstream& in, Sozluk& s)
{
	int z = 0;
	string kelime,tutucu;
	vector<string>aciklama;
	vector<Kayit> a;
	while (!in.eof())
	{
		if (z == 0) {
			getline(in, kelime, '\n');z++;
		}
		getline(in, tutucu, '\n');
		if (tutucu == "#") {
			z = 0;
			Kayit b(kelime, aciklama);
			a.push_back(b); kelime.clear(); aciklama.clear();
			Sozluk temp(a);	s = temp;
		}
		if (z != 0) 
			aciklama.push_back(tutucu);
	}
	return in;
}
