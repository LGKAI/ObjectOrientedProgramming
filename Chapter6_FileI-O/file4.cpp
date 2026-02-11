#include <iostream>
#include <fstream>
using namespace std;

int main() {
	// int data[5] = {4, 5, 10, 3, 25};
	// ofstream f("abc.inp", ios::out | ios::binary);
	// if (f.is_open()){
	// 	f.write((char*)data, 5*sizeof(int));
	// 	f.close();
	// 	cout << "Check your file" << endl;
	// }

	ifstream f("abc.inp", ios::in | ios::binary);
	if (f.is_open()){
		int N;
		f.read((char*) &N, sizeof(int));
		int* data = new int[N];
		f.read((char*)data, N*sizeof(int));
		f.close();

		for (int i=0; i<N; i++)
			cout << data[i] << " ";
		}

	ifstream f("abc.txt");
	if (f.is_open()){
		int N;
		f >> N;
		int* data = new int[N];
		for (int i=0; i<N; i++)
			f >> data[i];
		f.close();

		for (int i=0; i<N; i++)
			cout << data[i] << " ";
		}

	return 0;
}
