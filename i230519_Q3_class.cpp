#pragma once
#include<iostream>
#include"i230519_Q3_class.h"
#include<cstring>
using namespace std;

int updtaeValueVAl2 = 0;
int updtaeValueVAl = 0;

CAList::CAList() {
	

	for (int i = 0;i < this->keySize;i++)
		this->keyArray[i].keyName = "\0";


	for (int i = 0;i < this->keySize;i++)
	{

		for (int j = 0;j < this->keyArray[i].valSize;j++)
		{
			this->keyArray[i].valArray[j].valueName = "\0";
		}

	}
	updtaeValueVAl2 = 0;
	updtaeValueVAl = 0;
}

CAList::CAList(const CAList& copy) {

}

string& CAList::operator[](const string& str) {


	bool keyNotRepeat = false;

	bool valueNotRepeat = false;



	for (int i = 0;i < this->keySize;i++)
	{

		if ((this->keyArray[i].keyName == "\0" || this->keyArray[0].keyName == str) && i == 0)
		{


			this->keyArray[i].keyName = str;


			return	this->keyArray[i].valArray[updtaeValueVAl++].valueName;

		}
		for (int j = 0;j < i;j++)
		{

			if ((this->keyArray[i].keyName == "\0") || (this->keyArray[i].keyName == str))
			{


				keyNotRepeat = true;
			}
			else
			{

				keyNotRepeat = false;

				break;
			}

		}
		if (keyNotRepeat == true)
		{


			static int toCheck = i;
			if (toCheck != i)
			{
				updtaeValueVAl2 = 0;
				toCheck = i;
			}
			this->keyArray[i].keyName = str;


			return	this->keyArray[i].valArray[updtaeValueVAl2++].valueName;


		}


	}


}
CAList CAList:: operator+(const CAList& other) {
	CAList temp;
	//reusibility
	temp = *this;


	int k = 0;

	for (int i = 0;other.keyArray[k].keyName != "\0";i++)
	{

		if (temp.keyArray[i].keyName == "\0")
		{


			temp.keyArray[i].keyName = other.keyArray[k].keyName;


			for (int j = 0;j < 6;j++)
			{
				if (other.keyArray[k].valArray[j].valueName == "\0")
					break;


				temp.keyArray[i].valArray[j].valueName = other.keyArray[k].valArray[j].valueName;


			}
			k++;
		}




	}



	return temp;

}

void Values::operator=(const string str) {





}
void CAList::operator=(const  CAList& other) {

	//CAList temp;
	for (int i = 0;;i++)
	{

		if (other.keyArray[i].keyName == "\0")
			break;
		//cout << i << " ";
		this->keyArray[i].keyName = other.keyArray[i].keyName;
		//cout << temp.keyArray[i].keyName << " ";

		for (int j = 0;j < 6;j++)
		{
			if (other.keyArray[i].valArray[j].valueName == "\0")
				break;
			this->keyArray[i].valArray[j].valueName = other.keyArray[i].valArray[j].valueName;
			//cout << temp.keyArray[i].valArray[j].valueName << " ";

		}

	}

}


CAList CAList:: operator-(const CAList& other) {
	CAList temp;
	//reusibilty
	//temp = *this;
	int tempi = 0;
	int tempj = 0;
	int checkCount = 0;
	int iValue = -1;
	for (int i = 0;;i++)
	{
		tempi = i;

		if (this->keyArray[i].keyName == "\0")
			break;

		for (int k = 0;k < 7;k++)
		{
			if (other.keyArray[k].keyName == "\0")
				break;

			if (this->keyArray[i].keyName == other.keyArray[k].keyName)
			{
				iValue = i;

				temp.keyArray[tempi].keyName = this->keyArray[i].keyName;
				for (int j = 0;j < 6;j++)
				{
					
					checkCount = 0;
					for (int l = 0;l < 6;l++)
					{
						if (this->keyArray[i].valArray[j].valueName != other.keyArray[k].valArray[l].valueName)
						{
							checkCount++;
						}


					}

					if (checkCount == 6)
					{


						temp.keyArray[tempi].valArray[tempj].valueName = this->keyArray[i].valArray[j].valueName;
						tempj++;
					}
					
				}
				
			
				//tempi++;
			}
			else {
				
				if (i != iValue)
				{
					temp.keyArray[i].keyName = this->keyArray[i].keyName;

					for (int j = 0;j < 6;j++)
					{
						temp.keyArray[i].valArray[j].valueName = this->keyArray[i].valArray[j].valueName;


					}
				}

			}
		}
	}
	return temp;

}

CAList::~CAList() {
	delete[] keyArray;
}



ostream& operator<<(ostream& output, const CAList& obj) {
	output << "[";
	for (int i = 0;i < 7;i++)
	{

		if (obj.keyArray[i].keyName == "\0")
			break;

		output << obj.keyArray[i].keyName << ":{";

		for (int j = 0;j < 6;j++)
		{

			if (obj.keyArray[i].valArray[j].valueName == "\0")
				break;
			output << obj.keyArray[i].valArray[j].valueName << ",";
		}
		output << "}," << endl;
	}
	output << "]";


	return output;
}
