#include"akillidizi.h"
#include<iostream>
template<class T>
AkilliDizi<T>::AkilliDizi()
{
	veri = nullptr;
	kapasite = 0;
	elemanSayisi = 0;
}
template<class T>
inline AkilliDizi<T>::AkilliDizi(T i)
{
	try {
		kapasite = 1;
		elemanSayisi = 1;
		veri = new T[kapasite];
		if (veri == nullptr) throw 16;
		veri[0] = i;
	}
	catch (int i) { cout << i << ". satýrda yer alamadým programý sonlandýrýyorum..."; exit(-1); }
}

template<class T>
AkilliDizi<T>::AkilliDizi(const T* TDizi, unsigned int elemanSayisi)
{
	try {
		this->elemanSayisi = elemanSayisi;
		kapasite = elemanSayisi;
		veri = new T[elemanSayisi];
		if (veri == nullptr)throw 29;
		for (int a = 0; a < elemanSayisi; a++) {
			veri[a] = TDizi[a];
		}
	}
	catch (int i) { cout << i << ". satýrda yer alamadým programý sonlandýrýyorum..."; exit(-1); }
}

template<class T>
AkilliDizi<T>::AkilliDizi(const vector<T>& TVector)
{
	try {
		elemanSayisi = TVector.size();
		kapasite = elemanSayisi;
		veri = new T[elemanSayisi];
		if (veri == nullptr)throw 44;
		for (int a = 0; a < elemanSayisi; a++) {
			veri[a] = TVector[a];
		}
	}
	catch (int i) { cout << i << ". satýrda yer alamadým programý sonlandýrýyorum..."; exit(-1); }
}

template<class T>
AkilliDizi<T>::~AkilliDizi()
{
	if(veri!=nullptr)
	delete[]veri;
}

template<class T>
AkilliDizi<T>::AkilliDizi(const AkilliDizi<T>& i)
{
	try {
		elemanSayisi = i.elemanSayisi;
		kapasite = i.kapasite;
		veri = nullptr;
		if (elemanSayisi != 0) {
			veri = new T[elemanSayisi];
			if (veri == nullptr)throw 68;
			for (int a = 0; a < elemanSayisi; a++) {
				veri[a] = i.veri[a];
			}
		}
	}
	catch (int i) { cout << i << ". satýrda yer alamadým programý sonlandýrýyorum..."; exit(-1); }
}

template<class T>
AkilliDizi<T> AkilliDizi<T>::operator=(const AkilliDizi<T> other)
{
	try {
		if (this == &other)
			return *this;
		if (veri != nullptr)
			delete[] veri;
		elemanSayisi = other.elemanSayisi;
		kapasite = other.kapasite;
		veri = new T[elemanSayisi];
		if (veri == nullptr)throw 88;
		for (unsigned a = 0; a < elemanSayisi; a++) {
			veri[a] = other.veri[a];
		}
	}
	catch (int i) { cout <<i<< ". satýrda yer alamadým programý sonlandýrýyorum..."; exit(-1); }
	return *this;
}

template<class T>
T AkilliDizi<T>::operator[](unsigned int a)const
{
	try
	{
		if (a > elemanSayisi) throw 1;
	}
	catch(int i)
	{
		cout << "!!!!!!!!!!!!!kapasiteyi astiniz!!!!!!!!!!!!!" << endl;
		exit(-1);
	}
	return veri[a];
}

template<class T>
AkilliDizi<T> AkilliDizi<T>::operator+(T& i)
{
	try {
		T *temp = veri;
		elemanSayisi = elemanSayisi + 1;
		kapasite = kapasite + kapasite / 2;
		veri = nullptr;
		veri = new T[elemanSayisi];
		if (veri == nullptr)throw 121;
		for (int a = 0; a < elemanSayisi - 1; a++)
			veri[a] = temp[a];
		veri[elemanSayisi - 1] = i;
	}
	catch (int i) { cout << i << ". satýrda yer alamadým programý sonlandýrýyorum..."; exit(-1); }
	return *this;
}

template<class T>
void AkilliDizi<T>::sirala()const
{
	T temp;
	for (int a = 0; a < elemanSayisi ; a++) {
		for (int b = 0; b < elemanSayisi; b++) {
			if (veri[a] < veri[b]) {
				temp = veri[b];
				veri[b] = veri[a];
				veri[a] = temp;
			}
		}
	}
	
}

template<class T>
void AkilliDizi<T>::histogram(vector<Pair<T>>& hist) const
{
	sirala();
	Pair<T>temp;
	for (int i = 0; i < elemanSayisi; i+=kacTane(veri[i])) {
		temp.eleman=veri[i];
		temp.adet=kacTane(veri[i]);
		hist.push_back(temp);
	}
}
template<class T>
unsigned AkilliDizi<T>::kacTane(T i) const
{
	int s=0;
	for (int a = 0; a < elemanSayisi; a++) {
		if (veri[a] == i) s++;
	}
	return s;
}

template<class T>
bool AkilliDizi<T>::varMi(T i) const
{
	for (int a = 0; a < elemanSayisi; a++) {
		if (veri[a] == i) return true;
	}
	return  false;
}
template<class T>
ostream& operator<<(ostream& o, AkilliDizi<T> &s)
{
	for (int a = 0; a < s.elemanSayisi; a++) {
		o <<"{"<< s.veri[a] <<"} ";
	}
	o << endl;
	return o;
}




