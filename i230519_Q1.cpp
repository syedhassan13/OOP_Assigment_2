#include<iostream>
#include"i230519_Q1.h"
using namespace std;
Shop::Shop() { start = NULL; }

//Copy Constructor
Shop::Shop(const Shop& other) {
	this->start = NULL;
	Container* temp = other.start;
	int countLink = 0;
	while (temp != NULL)
	{
		temp = temp->link;
		countLink++;
	}
	Container* temp3 = other.start;
	for (int i = 0;i < countLink;i++)
	{
		//reuseibility
		add_Container(temp3->name, temp3->containerno);
		temp3 = temp3->link;
	}
	
	temp = NULL;
	temp3 = NULL;
	delete[] temp;
	delete[] temp3;

}
	
void Shop::add_Container(char* name, int containerindex) {
	
	

	Container* obj = new Container(name, containerindex);
	if (start == NULL)
	{
		start = obj;
		return;
	}
	Container* temp = start;
	while (temp->link!= NULL)
	{
		temp = temp->link;
	}
	temp->link = obj;

	
	
}




void Shop::print_Shop() {

	Container* temp = start;
	while (temp != NULL)
	{
		cout << temp->name << "-" << temp->containerno << endl;
		temp = temp->link;
	}
	temp = NULL;
	delete temp;
	
} 


void Shop::delete_Chain(int containerindex) {
	if (start == NULL)
		return;


	Container* temp1 = start;
	bool find = false;
	while (true)
	{
		if (temp1 == NULL)
			break;

		if (temp1->containerno == containerindex)
		{
			find = true;
			break;
		}
		
		temp1 = temp1->link;
		
	}
	temp1 = NULL;
	delete[] temp1;
	if (find)//check if containerindex is in article
	{
		//first corner case if first is containerindex
		if (start->containerno == containerindex)
		{
			//cout << "First case " << endl;
			Container* todelete = start;
			start = start->link;
			delete[] todelete;
			return;
		}
		//Third corne case for center node
		Container* temp = start;

		//getting n-1 node
		while (temp->link->containerno != containerindex)
		{
			temp = temp->link;
		}

		Container* toDeleteLink = temp->link;
		//n+1 node=next to next node
		temp->link = temp->link->link;

		delete[] toDeleteLink;
		temp = NULL;
		delete[] temp;
	}

	
}

//SORTING ARRAY FUNCTION//*******************************************//
void sortingArrayString(string*& array, int*& containerNo, int& size) {

	bool sorted;
	for (int i = 0;i < size;i++)
	{
		sorted = false;
		for (int j = 0;j < size-i-1;j++)
		{
			if (containerNo[j] > containerNo[j + 1])
			{
				int temp = containerNo[j + 1];
				containerNo[j + 1] = containerNo[j];
				containerNo[j] = temp;
				sorted = true;

				
				string temp1 = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp1;



			}
			
		}
		if (sorted == false)
			break;
	}
	
}
//*******************************************************************//




void Shop::Sort_Chain() {

	Container* temp = start;
	Container* temp2 = start;
	int size = 0;

	while (temp != NULL)
	{
		temp = temp->link;
		size++;
	}
	string* nameArray = new string[size];
	int* cNoArray = new int[size];
	int i = 0;
	while (temp2 != NULL)
	{

		nameArray[i] = temp2->name;
		cNoArray[i] = temp2->containerno;
		temp2 = temp2->link;
		i++;

	}
	
	sortingArrayString(nameArray, cNoArray, size);
	

	//Start = NULL creating new updted list
	start = NULL;
	char* name1 = NULL;
	for (int i = 0;i < size;i++)
	{
		string name = nameArray[i];
		int containerNo = cNoArray[i];
		int size1 = 0;
		int j = 0;
		while (name[j] != '\0')
		{

			size1++;
			j++;
		}


		 name1 = new char[size1];
		for (int i = 0;i < size1;i++)
		{
			name1[i] = name[i];
		}
		name1[size1] = '\0';

		//reusibility
		add_Container(name1, containerNo);

	}
	name1 = NULL;
	temp = NULL, temp2 = NULL, nameArray = NULL, cNoArray = NULL;
	delete[] temp;
	delete[] temp2;
	delete[] nameArray;
	delete[] cNoArray;
	delete[] name1;


	
}

void Shop::update_name_at_containerNumber(int containerindex, char* name) {

	Container* temp = start;
	while (temp!= NULL)
	{
		if (temp->containerno == containerindex)
		{
			temp->name = name;
		}
		temp = temp->link;
	}
	temp = NULL;
	delete[] temp;
	
}


//REMOVING DUPLIACE FROM NAME ARRAY********************************//
string * removingDuplicateOfArray(string* &array, int& size) {

	string* copyArray = new string[size];
	for (int i = 0;i < size;i++)
	{
		copyArray[i] = array[i];
	}
	delete[] array;
	int similarCount = 0;
	int size2 = size;
	size = 0;
	for (int i = 0;i < size2;i++)
	{
		for (int j = 0;j < size2;j++)
		{
			if (similarCount < 1)
			{
				if (copyArray[i] == copyArray[j] )
				{
					
					similarCount++;
					size++;
					if (i != j)
						size--;
				}
			}
		}
		similarCount = 0;
	}
	
	string* removeDupliacteArray = new string[size];
	similarCount = 0;
	int k = 0;
	bool checkDuplicate= false;
	for (int i = 0;i < size2;i++)
	{
		for (int j = 0;j < size2;j++)
		{
			if (similarCount < 1)
			{
				if (copyArray[i] == copyArray[j] &&j!=i)
					copyArray[j] = "\0";
			}
		}
			if (k < size && copyArray[i]!="\0")
			{
				removeDupliacteArray[k] = copyArray[i];
				k++;
			}

		similarCount = 0;
	}
	copyArray = NULL;
	delete[] copyArray;
	return removeDupliacteArray;
}
//******************************************************************// 

//REMOVING DUPLIACE FROM CONTAINERNO ARRAY*************************//
int * removingDuplicateOfArray1(int *&array, int &size) {

	int* copyArray = new int[size];
	for (int i = 0;i < size;i++)
	{
		copyArray[i] = array[i];
	}
	delete[] array;
	int similarCount = 0;
	int size2 = size;
	size = 0;
	for (int i = 0;i < size2;i++)
	{
		for (int j = 0;j < size2;j++)
		{
			if (similarCount < 1)
			{
				if (copyArray[i] == copyArray[j])
				{

					similarCount++;
					size++;
					if (i != j)
						size--;
				}
			}
		}
		similarCount = 0;
	}

	int* removeDuplicateArray = new int[size];
	similarCount = 0;
	int k = 0;
	for (int i = 0;i < size2;i++)
	{
		for (int j = 0;j < size2;j++)
		{
			if (similarCount < 1)
			{
				if (copyArray[i] == copyArray[j] && j != i)
					copyArray[j] = 0;
			}
		}
		if (k < size && copyArray[i] != 0)
		{
			removeDuplicateArray[k] = copyArray[i];
			k++;
		}

		similarCount = 0;
	}

	copyArray = NULL;
	delete[] copyArray;
	return removeDuplicateArray;
	
}
//***************************************************************//
	

	void Shop::remove_Duplicate() {
	
		Container* temp = start;
		Container* temp2 = start;
		int size = 0;

		while (temp != NULL)
		{
			temp = temp->link;
			size++;
		}
		string* nameArray = new string[size];
		int* cNoArray = new int[size];
		int i = 0;
		while (temp2 != NULL)
		{
			
			nameArray[i] = temp2->name;
			cNoArray[i] = temp2->containerno;
			temp2 = temp2->link;
			i++;
			
		}
		
	    nameArray=removingDuplicateOfArray(nameArray,size);
		cNoArray=removingDuplicateOfArray1(cNoArray,size);
		
		//Start = NULL creating new updted list
		start = NULL;
		char* name1;
		for (int i = 0;i < size;i++)
		{
			string name = nameArray[i];
			int containerNo = cNoArray[i];
			int size1 = 0;
			int j = 0;
			while (name[j] != '\0')
			{

				size1++;
				j++;
			}
			

			name1 = new char[size1];
			for (int i = 0;i < size1;i++)
			{
				name1[i] = name[i];
			}
			name1[size1] = '\0';

			//reusibility
			add_Container(name1, containerNo);

		}

		name1 = NULL;
		temp = NULL, temp2 = NULL, nameArray = NULL, cNoArray = NULL;
		delete[] temp;
		delete[] temp2;
		delete[] nameArray;
		delete[] cNoArray;
		delete[] name1;

	} 
	
	void Shop::findContainer(int containerindex) {
	
		
		Container* temp = start;
		int duplicateContainerNO = -1;
		while (temp != NULL)
		{
			if (temp->containerno == containerindex && temp->containerno != duplicateContainerNO)
			{
				cout << temp->name << endl;
				duplicateContainerNO = temp->containerno;
			}
			temp=temp->link;
		}
		temp = NULL;
		delete[] temp;
	}
	
	void Shop::findContainer(int containerindex1, int containerindex2) {
	
		
		Container* temp = start;
		int duplicateContainerNO = -1;
		while (temp != NULL)
		{
			
			if (temp->containerno >= containerindex1 && temp->containerno <= containerindex2 && temp->containerno != duplicateContainerNO)
			{
				cout << temp->name << endl;
				duplicateContainerNO = temp->containerno;
			}
			temp = temp->link;
		}
		temp = NULL;
		delete[] temp;
		
	}


	Shop::~Shop() {
		start = NULL;
		delete start;
	}
	
	


