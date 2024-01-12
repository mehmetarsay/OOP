//Mehmet hafif arsay
//medeniyet �niversitesi bilgisayar m�hendisli�i
//18120205036
//07,06,2019
#include"uzunyol.h"
#include"tinyxml2.h"
#include <sstream> 
using namespace std;
using namespace tinyxml2;
//xml dosyas�ndan verileri okur.
int dosyadanOku(const char filename[], list<arac*> &araclar){
	int otobusayisi = 0;//dosyadaki otobus say�s�
	int kamyonayisi = 0;//dosyadaki kamyon say�s�
		XMLDocument doc;
		doc.LoadFile(filename);//dosya a�ma
		XMLElement* titlearac = doc.FirstChildElement("Araclar")->FirstChildElement("Arac");//fazla kod yazmamak i�in adresini atad�m
		while (titlearac != NULL) {//bu adres null olursa dosyada ba�ka arac kalmam�� demektir
			string titleturu = titlearac->FirstChildElement("Turu")->GetText();//arac turu tutar yap�lacak i�lemler bununla belirlenir 
			if (titleturu == "Otobus") {
				otobusayisi++;
				list<surucu>sur;
				string titleplaka = titlearac->FirstChildElement("Plaka")->GetText();//otobus plakas�n� tutar
				XMLElement* titlesurucu = titlearac->FirstChildElement("Suruculer")->FirstChildElement("Surucu");//fazla kod yazmamak i�in adres atand�
				while (titlesurucu != NULL) {//surucu say�s� kadar doner
					string surucuadi = titlesurucu->FirstChildElement("Adi")->GetText();
					string surucuyasi = titlesurucu->FirstChildElement("Yasi")->GetText();
					int yas = stoi(surucuyasi);
					string surucuEH_SI = titlesurucu->FirstChildElement("EhliyetSinifi")->GetText();
					surucu tempsurucu(surucuadi, yas, surucuEH_SI);
					sur.push_back(tempsurucu);
					titlesurucu = titlesurucu->NextSiblingElement("Surucu");
				}
				vector<yolcu>yolcuvektor;//yolcular� tutar
				XMLElement* titleyolcu = titlearac->FirstChildElement("Yolcular")->FirstChildElement("Yolcu");
				while (titleyolcu != NULL) {//yolcu say�s� kadar doner
					string yolcuadi = titleyolcu->FirstChildElement("Adi")->GetText();
					string BinisNoktasi = titleyolcu->FirstChildElement("BinisNoktasi")->GetText();
					string InisNoktasi = titleyolcu->FirstChildElement("InisNoktasi")->GetText();
					yolcu tempyolcu(yolcuadi, BinisNoktasi, InisNoktasi);
					yolcuvektor.push_back(tempyolcu);
					titleyolcu = titleyolcu->NextSiblingElement("Yolcu");
				}
				arac *otbss = new otobus(titleplaka, sur, yolcuvektor);
				if (otbss == nullptr)throw 3;
				araclar.push_back(otbss);
				titlearac = titlearac->NextSiblingElement("Arac");
			}
			if (titleturu == "Kamyon") {
				kamyonayisi++;
				list<surucu>sur;
				string titleplaka = titlearac->FirstChildElement("Plaka")->GetText();
				string titleozlusoz = titlearac->FirstChildElement("OzluSoz")->GetText();
				XMLElement* titlesurucu = titlearac->FirstChildElement("Suruculer")->FirstChildElement("Surucu");
				while (titlesurucu != NULL) {//surucu say�s� kadar doner
					string surucuadi = titlesurucu->FirstChildElement("Adi")->GetText();
					string surucuyasi = titlesurucu->FirstChildElement("Yasi")->GetText();
					int yas = stoi(surucuyasi);
					string surucuEH_SI = titlesurucu->FirstChildElement("EhliyetSinifi")->GetText();
					surucu tempsurucu(surucuadi, yas, surucuEH_SI);
					sur.push_back(tempsurucu);
					titlesurucu = titlesurucu->NextSiblingElement("Surucu");
				}
				vector<yuk>yukvektor;
				XMLElement* titleyuk = titlearac->FirstChildElement("Yukler")->FirstChildElement("Yuk");
				while (titleyuk != NULL) {
					string Icerik = titleyuk->FirstChildElement("Icerik")->GetText();
					string agirlik = titleyuk->FirstChildElement("Agirlik")->GetText();
					int Agirlik = stoi(agirlik);
					string hacim = titleyuk->FirstChildElement("Hacim")->GetText();
					int Hacim = stoi(hacim);
					string Alici = titleyuk->FirstChildElement("Alici")->GetText();
					string Binis = titleyuk->FirstChildElement("BinisNoktasi")->GetText();
					string Inis = titleyuk->FirstChildElement("InisNoktasi")->GetText();
					yuk tempyuk(Icerik, Agirlik, Hacim,Alici , Binis,Inis);
					yukvektor.push_back(tempyuk);
					titleyuk = titleyuk->NextSiblingElement("Yuk");
				}
				arac *kamyonn = new kamyon(titleozlusoz, titleplaka, sur, yukvektor);//kamyon kadar yer al�p adresi tutulur
				if (kamyonn == nullptr)throw 3;
				araclar.push_back(kamyonn);
				titlearac = titlearac->NextSiblingElement("Arac");
				
			}
		}
		cout << otobusayisi << " OTOBUS VE " << kamyonayisi << " KAMYON HAZIR...";
		return otobusayisi + kamyonayisi;
}
int main() {
	try {
		char filename[] = { "bil.xml" };//okunacak dosya ad� tutuan string
		list<arac*>araclar;
		int aracsayisi = dosyadanOku(filename, araclar);//xml okuma fonksiyonu
		cout << endl << "TOPLAM ARAC SAYISI    " << aracsayisi << endl << endl;
		int n = 1;
		for (auto const &v : araclar) {
			cout << "ARAC " << n << endl << "....................................................." << endl << endl;
			cout << *v;
			n++;
		}
		for (auto const &v : araclar)
			delete v;
	}
	catch (int n) {
		cout << n << ". sayfada yer al�namad�";
		exit(-1);
	}
	return 0;
}