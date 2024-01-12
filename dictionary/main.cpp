#include<iostream>
#include"Sozluk.h"
#include"kayit.h"
#include<istream>
using namespace std;
int main() {
	vector<string>aciklamalar1 = { "sayý","bir eylem","bir vucut parçasý" };
	vector<string>aciklamalar2 = { "egitim gorulen yer" };
	vector<string>aciklamalar3 = { "kara"};
	vector<string>aciklamalar4 = { "bir renk"};
	vector<string>aciklamalar5 = { "bir renk","beyaz" };
	vector<Kayit>f;
	vector<Kayit>l;
	Kayit k1("yuz", aciklamalar1);
	Kayit k2("okul", aciklamalar2);
	Kayit k3("siyah", aciklamalar3);
	Kayit k4("siyah", aciklamalar4);
	Kayit k5("ak", aciklamalar5);
	Kayit k6;
	f.push_back(k1);
	f.push_back(k2);
	f.push_back(k3);
	f.push_back(k4);
	f.push_back(k5);
	Sozluk sozluk(f);
	Sozluk sozlukdosyadanalma;
	ofstream out;
	out.open("sozluk_f_yazdýr.txt");
	out << sozluk;
	out.close();
	ifstream intstream;
	intstream.open("sozluk.txt");
	intstream >> sozlukdosyadanalma;
	cout << sozlukdosyadanalma;
	intstream.close();
	string s = { "yuz" };
	k6 = sozlukdosyadanalma[s];
	cout << k6 << endl << "--------------------" << endl;
	
}