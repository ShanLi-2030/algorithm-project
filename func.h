//Shan Li and Lucas Manker
#ifndef _FUNC_H_
#define _FUNC_H_
#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

void MS(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
template<typename T>
vector<T> QS(vector<T>& vec1, int lIndex, int rIndex);
template<typename T>
vector<T> QuickSort(vector<T>& vec1);
template<typename T>
bool BinSearch(vector<T>& vec1, int lower, int upper, T val);
template<typename T>
void BinSearch(vector<T>& vec1, T val);
template<typename T>
void print(vector<T> vect);
template<typename T>
void print(T* arr, int size);
unsigned int basicHash(string entry);
unsigned int basicHash(int entry);


struct Bloom {
	bitset <65536> table;
	int size = 65536;

	void add(string entry) {
		unsigned int entryHash = basicHash(entry);
		int temp = entryHash % size;
		table.set(temp, 1);
		unsigned int hashOne = basicHash(entryHash);
		temp = hashOne % size;
		table.set(temp, 1);
		unsigned int hashTwo = basicHash(hashOne);
		temp = hashTwo % size;
		table.set(temp, 1);
	};
	bool search(string entry) {
		unsigned int entryHash = basicHash(entry);
		int temp = entryHash % size;
		unsigned int hashOne = basicHash(entryHash);
		int tempOne = hashOne % size;
		unsigned int hashTwo = basicHash(hashOne);
		int tempTwo = hashTwo % size;
		if (table[temp] && table[tempOne] && table[tempTwo]) {
			return true;
		}
		else {
			return false;
		}
	};

};

void MS(int arr[], int l, int r) {
	if (l < r) {
		int m = (r + l) / 2;
		MS(arr, l, m);
		MS(arr, m + 1, r);
		merge(arr, l, m, r);
	}
	return;
}

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int*L;
	int*R;
	L = new int[n1];
	R = new int[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}


	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}
//chunks of this code borrowed from geeksforgeeks.org
template<typename T>
vector<T> QS(vector<T>& vec1, int lIndex, int rIndex) {
	T temp;
	int i = lIndex;
	int j = rIndex;
	T pivot = vec1[(lIndex + rIndex) / 2];

	while (i <= j) {
		while (vec1[i] < pivot) {
			i++;
		}
		while (vec1[j] > pivot) {
			j--;
		}
		if (i <= j) {
			temp = vec1[i];
			vec1[i] = vec1[j];
			vec1[j] = temp;
			i++;
			j--;
		}
	}

	if (lIndex < j) {
		QS(vec1, lIndex, j);
	}
	if (i < rIndex) {

		QS(vec1, i, rIndex);
	}
	return vec1;
}

template<typename T>
vector<T> QuickSort(vector<T>& vec1) {
	QS(vec1, 0, vec1.size() - 1);
	return vec1;
}
template<typename T>
bool BinSearch(vector<T>& vec1, int lower, int upper, T val) {
	if (upper < lower) {
		return false;
	}
	int mid = (lower + upper) / 2;
	if (val < vec1[mid]) {
		return BinSearch(vec1, lower, mid - 1, val);
	}
	else if (val > vec1[mid]) {
		return BinSearch(vec1, mid + 1, upper, val);
	}
	return true;
}

//some code in this function was adapted from Rosetta Code
template<typename T>
void BinSearch(vector<T>& vec1, T val) {
	QuickSort(vec1);
	int upper = size(vec1) - 1;
	bool result = BinSearch(vec1, 0, upper, val);
	if (result) {
		cout << val << " was found!" << endl;
	}
	else {
		cout << val << " was not found!" << endl;
	}
}
unsigned int basicHash(string entry) {
	const char* line = entry.c_str();
	int primeA = 1787;
	int primeB = 2111;
	int primeC = 3323;
	int primeH = 47;

	unsigned int hsh = primeH;
	while (*line) {
		hsh = (hsh*primeA) ^ (line[0] * primeB);
		line++;
	}
	return hsh%primeC;
}
unsigned int basicHash(int entry) {

	int primeA = 1787;
	int primeB = 2111;
	int primeC = 3323;
	int primeH = 47;

	unsigned int hsh = primeH;

	hsh = (hsh*primeA) ^ (entry * primeB);

	return hsh%primeC;
}

template<typename T>
void print(vector<T> vect) {
	cout << endl;
	vector<T> ::iterator it;
	for (it = vect.begin(); it != vect.end() - 1; it++) {
		cout << *it << " , ";
	}
	cout << *it + 1 << endl;
	cout << endl;
	return;
}

template<typename T>
void print(T* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		cout << arr[i] << " , ";
	}
	cout << arr[size - 1] << endl;
	cout << endl;
	return;
}
#endif
