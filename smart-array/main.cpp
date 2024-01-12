//MEHMET HAFÝF ARSAY MEDENÝYET ÜNÝVERSÝTESÝ 
//18120205036
#include"akillidizi.h"
#include "akillidizi.cpp"
#include<ctime>
#include <conio.h>
using namespace std;
int main() {
	srand(time(0));
	cout << "################integer#############" << endl;
	int sayi = 888,sayi1=999;
	int intdizi[] = { 4,5,6,5,4 };
	vector<int> intvector;
	for (int i = 0; i < 5; i++) {
		intvector.push_back (rand());
	}
	AkilliDizi<int>intconstructer1;
	AkilliDizi<int>intconstructer2(sayi);
	AkilliDizi<int>intconstructer3(intdizi,5);
	AkilliDizi<int>intconstructer4(intvector);
	cout << "CONSTRUCTER 1" <<endl<< intconstructer1 << endl;
	cout << "CONSTRUCTER 2" <<endl<< intconstructer2 << endl;
	cout << "CONSTRUCTER 3" <<endl<< intconstructer3 << endl;
	cout << "CONSTRUCTER 4" <<endl <<intconstructer4 << endl;
	intconstructer3.sirala();
	cout << "CONSTRUCTER 3 SIRALAMA" << endl << intconstructer3 << endl;
	intconstructer4.sirala();
	cout << "CONSTRUCTER 4 SIRALAMA " << endl << intconstructer4 << endl;
	intconstructer3 + sayi;
	cout <<sayi<< "  ILE CONSTRUCTER 3 TOPLAMA"<< endl << intconstructer3 << endl;
	intconstructer4 + sayi;
	int sayýal;
	cout << "lutfen kapasite denmesi icin sayi giriniz" << endl;
	cin >> sayýal;
	cout <<"CONSTRUCTER 3`TE "<<sayýal+1<<". ELEMANI YAZDIR"<<endl<< intconstructer3[sayýal]<< endl;
	cout << "devam etmek icin ENTER..." << endl;
	_getch();
	cout << "CONSTRUCTER 4`TE 5. ELEMANI YAZDIR " << endl;
	cout << intconstructer4[4] << endl;
	if (intconstructer3.varMi(sayi)==true)cout << "CONSTRUCTER 3`TE " << sayi << " VAR" << endl;
	else cout << "CONSTRUCTER 3`TE " << sayi << " YOK" << endl;
	if (intconstructer3.varMi(sayi1) == true)cout << "CONSTRUCTER 4`TE " << sayi1 << " VAR" << endl;
	else cout << "CONSTRUCTER 4`TE " << sayi1 << " YOK" << endl;
	cout << "--------HISTOGRAM/CONSTRUCTER3--------" << endl;
	vector<Pair<int>>pair3;
	intconstructer3.histogram(pair3);
	for (int i = 0; i < pair3.size(); i++) {
		cout <<"eleman "<< pair3[i].eleman  << " adet  " << pair3[i].adet << endl;
	}
	cout << "--------HISTOGRAM/CONSTRUCTER4---------" << endl;
	vector<Pair<int>>pair4;
	intconstructer4.histogram(pair4);
	for (int i = 0; i < pair4.size(); i++) {
		cout << "eleman " << pair4[i].eleman << " adet  " << pair4[i].adet << endl;
	}
	cout << "---------------------------------------" << endl;
	cout << "###############char###############" << endl;
	char karakter = 'm', karakter1 = 'n';
	char chardizi[] = "mqwwrwer";
	vector<char> charvector;
	for (int i = 0; i < 5; i++) {
		charvector.push_back((char)rand()%26+97);
	}
	AkilliDizi<char>charconstructer1;
	AkilliDizi<char>charconstructer2(karakter);
	AkilliDizi<char>charconstructer3(chardizi, 8);
	AkilliDizi<char>charconstructer4(charvector);
	cout << "CONSTRUCTER 1" << endl << charconstructer1 << endl;
	cout << "CONSTRUCTER 2" << endl << charconstructer2 << endl;
	cout << "CONSTRUCTER 3" << endl << charconstructer3 << endl;
	cout << "CONSTRUCTER 4" << endl << charconstructer4 << endl;
	charconstructer3.sirala();
	cout << "CONSTRUCTER 3 SIRALAMA" << endl << charconstructer3 << endl;
	charconstructer4.sirala();
	cout << "CONSTRUCTER 4 SIRALAMA " << endl << charconstructer4 << endl;
	charconstructer3 + karakter;
	cout << karakter << "  ILE CONSTRUCTER 3 TOPLAMA" << endl << charconstructer3 << endl;
	charconstructer4 + karakter;
	cout << "CONSTRUCTER 3`TE 0. ELEMANI YAZDIR" << endl << charconstructer3[0] << endl;
	cout << "CONSTRUCTER 4`TE 5. ELEMANI YAZDIR " << endl;
	cout << charconstructer4[4] << endl;
	if (charconstructer3.varMi(karakter) == true)cout << "CONSTRUCTER 3`TE " << karakter << " VAR" << endl;
	else cout << "CONSTRUCTER 3`TE " << karakter << " YOK" << endl;
	if (charconstructer3.varMi(karakter1) == true)cout << "CONSTRUCTER 4`TE " << karakter1 << " VAR" << endl;
	else cout << "CONSTRUCTER 4`TE " << karakter1 << " YOK" << endl;
	cout << "--------HISTOGRAM/CONSTRUCTER3--------" << endl;
	vector<Pair<char>>charpair3;
	charconstructer3.histogram(charpair3);
	for (int i = 0; i < charpair3.size(); i++) {
		cout << "eleman " << charpair3[i].eleman << " adet  " << charpair3[i].adet << endl;
	}
	cout << "--------HISTOGRAM/CONSTRUCTER4---------" << endl;
	vector<Pair<char>>charpair4;
	charconstructer4.histogram(charpair4);
	for (int i = 0; i < charpair4.size(); i++) {
		cout << "eleman " << charpair4[i].eleman << " adet  " << charpair4[i].adet << endl;
	}
	cout << "---------------------------------------" << endl;
	cout << "###############double###############" << endl;
	double doublesayi = 0.545, doublesayi1 = 0.897;
	double dizi[] = { 4.4,5.5,6.6,5.5,4.4 };
	vector<double> doublevector;
	for (double i = 0; i < 5; i++) {
		doublevector.push_back((double)rand()/RAND_MAX);
	}
	AkilliDizi<double>doubleconstructer1;
	AkilliDizi<double>doubleconstructer2(doublesayi);
	AkilliDizi<double>doubleconstructer3(dizi, 5);
	AkilliDizi<double>doubleconstructer4(doublevector);
	cout << "CONSTRUCTER 1" << endl << doubleconstructer1 << endl;
	cout << "CONSTRUCTER 2" << endl << doubleconstructer2 << endl;
	cout << "CONSTRUCTER 3" << endl << doubleconstructer3 << endl;
	cout << "CONSTRUCTER 4" << endl << doubleconstructer4 << endl;
	doubleconstructer3.sirala();
	cout << "CONSTRUCTER 3 SIRALAMA" << endl << doubleconstructer3 << endl;
	doubleconstructer4.sirala();
	cout << "CONSTRUCTER 4 SIRALAMA " << endl << doubleconstructer4 << endl;
	doubleconstructer3 + doublesayi;
	cout << doublesayi << "  ILE CONSTRUCTER 3 TOPLAMA" << endl << doubleconstructer3 << endl;
	doubleconstructer4 + doublesayi;
	cout << "CONSTRUCTER 3`TE 0. ELEMANI YAZDIR" << endl << doubleconstructer3[0] << endl;
	cout << "CONSTRUCTER 4`TE 5. ELEMANI YAZDIR " << endl;
	cout << doubleconstructer4[4] << endl;
	if (doubleconstructer3.varMi(doublesayi) == true)cout << "CONSTRUCTER 3`TE " << doublesayi << " VAR" << endl;
	else cout << "CONSTRUCTER 3`TE " << doublesayi << " YOK" << endl;
	if (doubleconstructer3.varMi(doublesayi1) == true)cout << "CONSTRUCTER 4`TE " << doublesayi1 << " VAR" << endl;
	else cout << "CONSTRUCTER 4`TE " << doublesayi1 << " YOK" << endl;
	cout << "--------HISTOGRAM/CONSTRUCTER3--------" << endl;
	vector<Pair<double>>doublepair3;
	doubleconstructer3.histogram(doublepair3);
	for (double i = 0; i < doublepair3.size(); i++) {
		cout << "eleman " << doublepair3[i].eleman << " adet  " << doublepair3[i].adet << endl;
	}
	cout << "--------HISTOGRAM/CONSTRUCTER4---------" << endl;
	vector<Pair<double>>doublepair4;
	doubleconstructer4.histogram(doublepair4);
	for (double i = 0; i < doublepair4.size(); i++) {
		cout << "eleman " << doublepair4[i].eleman << " adet  " << doublepair4[i].adet << endl;
	}
	cout << "---------------------------------------" << endl;
	cout << "############ogrenci###############" << endl;
	ogrenci birogrenci("Fernando Muslera","1"), birogrenci1 ("Semih Kaya", "26");
	ogrenci o1("Omer Bayram", "19"), o2("Yuto Nagatomo", "55"), o3("Martin Lines", "14");
	ogrenci v1("Luyindama", "27"), v2("Luyindama", "27"), v3("Selcuk Inan", "8"), v4("Younes Belhanda", "10");
	ogrenci ogrencidizi[] = { o1,o2,o3 };
	vector<ogrenci> ogrencivector;
	ogrencivector.push_back(v1);
	ogrencivector.push_back(v2);
	ogrencivector.push_back(v3);
	ogrencivector.push_back(v4);
	AkilliDizi<ogrenci>ogrenciconstructer1;
	AkilliDizi<ogrenci>ogrenciconstructer2(birogrenci);
	AkilliDizi<ogrenci>ogrenciconstructer3(ogrencidizi, 3);
	AkilliDizi<ogrenci>ogrenciconstructer4(ogrencivector);
	cout << "CONSTRUCTER 1" << endl << ogrenciconstructer1 << endl;
	cout << "CONSTRUCTER 2" << endl << ogrenciconstructer2 << endl;
	cout << "CONSTRUCTER 3" << endl << ogrenciconstructer3 << endl;
	cout << "CONSTRUCTER 4" << endl << ogrenciconstructer4 << endl;
	ogrenciconstructer3.sirala();
	cout << "CONSTRUCTER 3 SIRALAMA" << endl << ogrenciconstructer3 << endl;
	ogrenciconstructer4.sirala();
	cout << "CONSTRUCTER 4 SIRALAMA " << endl << ogrenciconstructer4 << endl;
	ogrenciconstructer3 + birogrenci;
	cout << birogrenci << "  ILE CONSTRUCTER 3 TOPLAMA" << endl << ogrenciconstructer3 << endl;
	ogrenciconstructer4 + birogrenci;
	ogrenciconstructer1 = ogrenciconstructer3[0];
	cout << "CONSTRUCTER 3`TE 0. ELEMANI YAZDIR" << endl << ogrenciconstructer1 << endl;
	if (ogrenciconstructer3.varMi(birogrenci) == true)cout << "CONSTRUCTER 3`TE " << birogrenci << " VAR" << endl;
	else cout << "CONSTRUCTER 3`TE " << birogrenci << " YOK" << endl;
	if (ogrenciconstructer3.varMi(birogrenci1) == true)cout << "CONSTRUCTER 4`TE " << birogrenci1 << " VAR" << endl;
	else cout << "CONSTRUCTER 4`TE " << birogrenci1 << " YOK" << endl;
	cout << "--------HISTOGRAM/CONSTRUCTER3-----------" << endl;
	vector<Pair<ogrenci>>ogrencipair3;
	ogrenciconstructer3.histogram(ogrencipair3);
	for (int i = 0; i < ogrencipair3.size(); i++) {
		cout << "eleman " << ogrencipair3[i].eleman << " adet  " << ogrencipair3[i].adet << endl;
	}
	cout << "--------HISTOGRAM/CONSTRUCTER4---------" << endl;
	vector<Pair<ogrenci>>ogrencipair4;
	ogrenciconstructer4.histogram(ogrencipair4);
	for (int i = 0; i < ogrencipair4.size(); i++) {
		cout << "eleman " << ogrencipair4[i].eleman << " adet  " << ogrencipair4[i].adet << endl;
	}
	cout << "---------------------------------------" << endl;
}