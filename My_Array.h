#pragma once
#include <fstream>
#include "sortcomp.h"
using namespace std; //äëÿ ôðåíäà
template <class T>
class My_Array
{
private:
	T* arr; // ìàññèâ êàêîãî óãîäíî òèïà
	int* a; // ìàññèâ öåëûõ ÷èñåë
	int n;
public:
	My_Array();
	My_Array(int n);
	My_Array(const My_Array& a);
	My_Array<T>& operator=(const My_Array<T>& a);
	T& operator[](int i);
	T& operator[](int i)const;
	void sort(bool(*comp)(T&, T&)) {
		insert(arr, n, comp);
	}

	friend ostream& operator<<(ostream& os, const My_Array<T>& a) {
		for (int i = 0; i < a.n; i++)
			os << a[i] << "\n";
		return os;
	}
	friend istream& operator>>(istream& os, My_Array<T>& a) {
		int n;
		os >> n;
		a.n = n;
		a.arr = new T[n];
		for (int i = 0; i < a.n; i++)
			os >> a[i];
		return os;
	}
	void writeBin(ofstream& os);
	void readBin(ifstream& os);
	~My_Array();
};

template<class T>
inline My_Array<T>::My_Array()
{
	n = 0;
	arr = nullptr;
}

template<class T>
inline My_Array<T>::My_Array(int n)
{
	this->n = n;
	arr = new T[this->n]; //âûäåëèëè ïàìÿòü
}

template<class T>
inline My_Array<T>::My_Array(const My_Array& a)
{
	this->n = a.n;
	arr = new T[n];
	for (int i = 0; i < n; i++)
		arr[i] = a.arr[i];
}

template<class T>
inline My_Array<T>& My_Array<T>::operator=(const My_Array<T>& a)
{
	delete[]arr;
	this->n = a.n;
	arr = new T[n];
	for (int i = 0; i < n; i++)
		arr[i] = a.arr[i];
	return *this;
}

template<class T>
inline T& My_Array<T>::operator[](int i)
{
	if (i >= n)throw "index error";
	return arr[i];
}

template<class T>
inline T& My_Array<T>::operator[](int i) const
{
	if ((i < 0) || (i >= n))throw "index error";
	return arr[i];
}

template<class T>
inline My_Array<T>::~My_Array()
{
	delete[] arr;
	n = 0;
	arr = nullptr;
}
template<class T>
inline void My_Array<T>::writeBin(ofstream& os)
{
	os.write((char*)arr, sizeof(T) * n);
	os.close();
}

template<class T>
inline void My_Array<T>::readBin(ifstream& os)
{
	os.seekg(0, os.end);
	int n = os.tellg() / sizeof(T);
	delete[]arr;
	arr = new T[n];
	this->n = n;
	os.seekg(0, os.beg);
	os.read((char*)arr, sizeof(T) * n);
	os.close();
}