
#pragma once
#ifndef CAList_H
#define CAList_H
#include<iostream>
#include<cstring>
using namespace std;

struct Values {
	string valueName;
	void operator=(const string str);

};

struct Key {
	int valSize = 6;
	string keyName;

	Values* valArray = new Values[valSize];



};

class CAList {
private:
	int keySize = 7;
	Key* keyArray = new Key[keySize];
	


public:
	CAList();
	CAList(const CAList& copy);
	string& operator[](const string& str);
	void operator=(const CAList& other);
	CAList operator+(const  CAList& other);
	CAList  operator-(const CAList& other);
	~CAList();

	friend ostream& operator<<(ostream& output, const CAList& obj);
};






#endif