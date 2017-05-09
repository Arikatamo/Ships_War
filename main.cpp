#include "Header.h"


int main() {
	srand(time(0));
	
	char **field_my = new char *[table_size]; 
	char **field_pc = new char *[table_size];
	char **temp_my = new char *[table_size];
	char **temp_pc = new char *[table_size];
	menu(field_my, temp_my, field_pc, temp_pc);
	

	return 0;
	
}





//
//#include <iostream>
//#include <string>
//#include <fstream>
//#include <conio.h>
//using namespace std;
//
//struct Person
//{
//	char name[50];
//	int age;
//	char gender[50];
//};
//
//int Key = 15;
//
//struct Logins
//{
//	char Login[20];
//	char Password[20];
//};
////void Show(const Person &p);
////void SaveToFile(string filename, const Person p[], int size);
////void  LoadFromFile(string filename, Person *&p, int & size);
//
//int  main()
//{
//	Logins base[2];
//	strcpy(base[0].Login, "Olena");
//	strcpy(base[0].Password, "1111");
//	strcpy(base[1].Login, "Admin");
//	strcpy(base[1].Password, "1111");
//	for (int i = 0; i < 2; i++)
//	{
//		cout << base[i].Login << base[i].Password << endl;
//	}
//	ofstream file;
//	file.open("logins.dat", ios_base::binary);
//	if (!file.is_open()) {
//		cout << "Error" << endl;
//		return -1;
//	}
//	file.write((char *)base, sizeof(Logins) * 2);
//	file.close();
//
//	Logins *temp = new Logins[2];
//	ifstream fileReader;
//	fileReader.open("logins.dat", ios_base::binary);
//	if (!fileReader.is_open()) {
//		cout << "Error" << endl;
//		return -1;
//	}
//	fileReader.read((char *)temp, sizeof(Logins) * 2);
//	fileReader.close();
//
//	for (int i = 0; i < 2; i++)
//	{
//		cout << temp[i].Login << " " << temp[i].Password << endl;
//	}
//	return 0;
//}