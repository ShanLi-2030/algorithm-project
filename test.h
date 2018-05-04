//Shan Li and Lucas Manker
#ifndef _TEST_H_
#define _TEST_H_

#include "func.h"
#include <algorithm>
#include <fstream>

void testQuickSort(void);
void testMergeSort(void);
void testBinSearch(void);
void testHash(void);
void testBloom(void);

void testQuickSort(void) {
	cout << "++++++++++++++++++++Testing Quick Sort++++++++++++++++++++" << endl;
	vector<int> test1 = { 46,79,4,38,55,100,57,32,59,24,73,70,22,95,84,77,43,19,68,23 };
	vector<int> test2 = test1;
	cout << "By using the built-in sort function I'll test to see if the Quicksort function is working as intended." << endl;
	cout << "Original vector:" << endl;
	print(test1);
	cout << "Vector sorted using quicksort:" << endl;
	QuickSort(test1);
	print(test1);
	cout << "Vector sorted using built-in vector sort" << endl;
	sort(test2.begin(), test2.end());
	print(test2);
	if (test1 == test2) {
		cout << "The vector using the quicksort function is equal to the vector sorted using the built-in sort." << endl;
	}
	else {
		cout << "something went wrong, and the vectors are not equal!" << endl;
	}
	system("pause");
	cout << endl << endl;
	return;
}
void testMergeSort(void) {
	int test1[20] = { 97,19,65,76,51,87,100,24,79,85,5,75,82,24,94,74,9,50,49,45 };
	int test2[20];
	for (int i = 0; i < 20; i++) {
		test2[i] = test1[i];
	}
	cout << "By using the built-in array sort function I'll test to see if the Merge sort function is working as intended." << endl;
	cout << "Original Array:" << endl;
	print(test1, 20);
	cout << "Array sorted using merge sort:" << endl;
	MS(test1, 0, 19);
	print(test1, 20);
	cout << "Array sorted using built-in array sort" << endl;
	sort(test2, test2 + 20);
	print(test2, 20);
	bool equal = true;
	for (int i = 0; i < 20; i++) {
		if (test1[i] != test2[i]) {
			equal = false;
		}
	}
	if (equal) {
		cout << "The array using the merge sort function is equal to the array sorted using the built-in sort." << endl;
	}
	else {
		cout << "something went wrong, and the arrays are not equal!" << endl;
	}
	system("pause");
	cout << endl << endl;
	return;
}
void testBinSearch(void) {
	vector<int> test1 = { 46,79,4,38,55,100,57,32,59,24,73,70,22,95,84,77,43,19,68,23 };
	cout << "Using the previous vector we can test the Bin Search method." << endl;
	print(test1);
	cout << "We'll first test if the element 77 exists within the vector (it should find it)." << endl;
	int testVar = 77;
	BinSearch(test1, testVar);
	cout << "Next we'll test to see if 300 is present within the vector (it shouldn't find it)." << endl;
	BinSearch(test1, 300);
	system("pause");
	cout << endl << endl;
}
void testHash(void) {
	cout << "We'll test the hashing function by hashing the word 'tacos' and then counting the collisions when hashing the 1000 most commonly used english words" << endl;
	int testHashString = basicHash("tacos");
	cout << "The hash of 'tacos' is " << testHashString << endl;
	cout << "Now checking collisions: " << endl;
	int collisionCount = 0;
	ifstream stream;
	stream.open("words.txt");
	if (!stream.is_open()) {
		cout << "please put the words.txt file into the correct directory" << endl;
		return;
	}
	string temp;
	while (stream >> temp) {
		int tempHash = basicHash(temp);
		if (tempHash == testHashString) {
			collisionCount++;
		}
	}
	stream.close();
	cout << "There were " << collisionCount << " recorded collisions using the hashing function" << endl;
	system("pause");
	cout << endl << endl;
	cout << "Now let's test something that will definitely get a collision, the word 'the'" << endl;
	testHashString = basicHash("the");
	stream.open("words.txt");
	while (stream >> temp) {
		int tempHash = basicHash(temp);
		if (tempHash == testHashString) {
			collisionCount++;
		}
	}
	stream.close();
	cout << "There were " << collisionCount << " recorded collisions using the hashing function" << endl;
	system("pause");
	cout << endl << endl;
}
void testBloom(void) {
	cout << "Finally let's test the bloom function." << endl;
	cout << "We'll fill up a bloom filter with the 1000 most commonly used english words from the same file used in the hash test." << endl;
	ifstream stream;
	stream.open("words.txt");
	if (!stream.is_open()) {
		cout << "something went wrong! put the words.txt file in the correct directory" << endl;
	}
	string temp;
	Bloom testBloom;
	while (stream >> temp) {
		testBloom.add(temp);
	}
	stream.close();
	cout << "We'll test if the word 'too' is probably present within the bloom filter." << endl;
	if (testBloom.search("too")) {
		cout << "'too' is probably inside!" << endl;
	}
	else {
		cout << "'too is definitely not contained within the filter!'" << endl;
	}
	system("pause");
	cout << endl << endl;

	cout << "We can then test to see if something that should not be within the filter provides a false positive." << endl;

	if (testBloom.search("onomatopoeia")) {
		cout << "'onomatopoeia' is probably inside!" << endl;
	}
	else {
		cout << "'onomatopoeia' is definitely not contained within the filter!'" << endl;
	}
	system("pause");
	cout << endl << endl;
}


#endif
