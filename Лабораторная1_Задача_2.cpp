#include <iostream>
#include <malloc.h>
#include <fstream>
#include<string.h>
#include <ctime>
using namespace std;
void funk(int rasm, string name) {
	ifstream fal;
	fal.open(name, ios::binary | ios::in);
	int* gg = new int [rasm];
	for (int i = 0; i < rasm; i++) {
		fal>>gg[i];
	}
	int tmp;
	for (int i = 0; i < rasm; i++) {
		for (int j = 0; j < rasm- i - 1; j++) {
			if (gg[j] > gg[j+1]) {
				tmp = gg[j];
				gg[j] = gg[j+1];
				gg[j+1] = tmp;
				
			}
		}
	}
	fal.close();
	ofstream fall;
	fall.open(name, ios::binary | ios::out);
	for (int i = 0; i < rasm; i++) {
		fall << gg[i];
	}
	delete[] gg;
}
int main(){
	srand(time(NULL));
	string name = "abc.bin";
	ofstream fail;
	fail.open(name, ios::binary|ios::out);
	int a, b;
	cin >> a;
	cin >> b;
	if (a == 0 || b == 0) {
		cout << "error";
	}
	int** matr=new int*[a];
	for (int i = 0; i < a; i++) {
		matr[i] = new int[b];
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			matr[i][j] = rand();
			fail << matr[i][j]<<" ";
		}
	}
	
	fail.close();
	
	funk(a * b, name);
	for (int i = 0; i < a; i++) {
		delete[] matr[i];
	}
	delete[] matr;
	return 0;
}

