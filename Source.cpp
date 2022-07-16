#include <iostream>
#include<fstream>
#include<string>
using namespace std;

#pragma pack(push, 1)

struct Person {

	char name[50];
	int age;
	double weight;

};

#pragma pack(pop)

int main() {

	//--------------- write in the file
	Person someone = { "Sag", 2000, 0.8 };
	string filename = "test.bin";

	fstream myfile;
	myfile.open(filename, ios::binary | ios::out);
	if (myfile.is_open()) {
		myfile.write(reinterpret_cast<char*>(&someone), sizeof(Person));
		myfile.close();
	}
	else {

		cout << " could not create file " + filename << endl;
	}
	//--------------- read from file
	Person someoneElse = {};
	myfile.open(filename, ios::binary | ios::in);
	if (myfile.is_open()) {
		myfile.read(reinterpret_cast<char*>(&someoneElse), sizeof(Person));
		myfile.close();
	}
	else {

		cout << " could not read from file " + filename << endl;
	}

	cout << " name is : " << someoneElse.name << endl << " age is : " << someoneElse.age << endl << " weight is : " << someoneElse.weight << endl;
	return 0;

}