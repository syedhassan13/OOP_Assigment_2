 #include<iostream>
#include"i230519_Q2.h"
using namespace std;
// provide definitions of following functions

// default constructor
String::String() {
	this->stringCopy = nullptr;

}
	String::String(const char* str) {
		
		this->size = String::lengthOfString(str);
		
		if (this->size != 0)
		{
			this->stringCopy = new char[this->size + 1];
			for (int i = 0;i < this->size + 1;i++)
			{
				this->stringCopy[i] = str[i];
			}
			this->stringCopy[this->size] = '\0';
		}
		else
		{
			this->stringCopy = nullptr;
		}

	}// initializes the string with constant c-string

	//length of string
	int String::lengthOfString(const char* str)
	{
		int l = 0;
		while (*str != '\0')
		{
			l++;
			str++;
		}
		return l;
	}
	String::String(const String& copyString) {
		
		this->size = copyString.String::size;
		

		if (String::size != 0)
		{
			this->stringCopy = new char[this->size + 1];
			for (int i = 0;i < this->size + 1;i++)
			{
				this->stringCopy[i] = copyString.String::stringCopy[i];
			}
			this->stringCopy[this->size] = '\0';
		}
		else
		{
			this->stringCopy = nullptr;
		}

	
	} // copy constructor to initialize the string from the existing string
	String::String(int x) {
	
		if (x != 0)
			this->stringCopy = new char[x] {'\0'};
		else
			this->stringCopy = nullptr;
		
	} // initializes a string of predefined size
	char* String::getdata() {
		//cout << this->stringCopy;
		char* str = this->stringCopy;
		return str;
	}
	
	 
// Binary Operators 
//Sub - script Operators
	const char String::operator[](int i) const {
		for (int j = 0;j < this->size + 1;j++)
		{
			if (i == j && i>=0)
			{
				return this->stringCopy[j];
				break;
			}
			else if (i < 0)
			{
				for (int k = this->size-1;k >=0;k--)
				{
					if (i == k - this->size)
					{
						return this->stringCopy[k];
						break;
					}
					
				}
			}
	    }
	}// returns the character at index [x]
//NOTE: in above [] operator functions if i=negative int value, print ith character
//from end //of string e.g. in case of “LOOP” if i=-1 OR i=3, it should return ‘P’
//	similarly i = -4 OR i = 0, //return ‘L’
	// Arithmetic Operators
	
	String &String::operator+(const String& str) {
	
		
		//to copy stringCopy so that it can save data
		if (this->size != 0)
		{
			char* copy = new char[this->size + 1];
			for (int i = 0;i < this->size + 1;i++)
			{
				copy[i] = this->stringCopy[i];
			}
			delete[] this->stringCopy;

			if (str.stringCopy != nullptr)
			{
				int sizeCopy = this->size;
				this->size = sizeCopy + str.size;
				this->stringCopy = new char[this->size + 1];
				for (int i = 0;i < sizeCopy + 1;i++)
				{
					this->stringCopy[i] = copy[i];
				}
				for (int j = sizeCopy ,k=0;j < this->size+ 1;k++, j++)
				{
					this->stringCopy[j] = str.String::stringCopy[k];
				}
				this->stringCopy[this->size] = '\0';


			}
			

			delete[] copy;
		}
		else
			this->stringCopy = nullptr;
		
		return *this;

	} // appends a String at the end of the String
	
	String &String::operator+(const char& str) {
	
		//to copy stringCopy so that it can save data
		if (this->size != 0)
		{
			char* copy = new char[this->size + 1];
			for (int i = 0;i < this->size + 1;i++)
			{
				copy[i] = this->stringCopy[i];
			}
			delete[] this->stringCopy;

			if (str!='\0')
			{
				int sizeCopy = this->size;
				this->size =sizeCopy + 1 ;
				this->stringCopy = new char[this->size + 1];
				for (int i = 0;i < this->size+1;i++)
				{
					if (i != this->size-1)
						this->stringCopy[i] = copy[i];
					else
						this->stringCopy[i] = str;
					
				}
				
				this->stringCopy[this->size] = '\0';
				delete[] copy;

			}



		}
		



		return *this;

	} // appends a char at the end of the String
	//problem
	String &String::operator+(const char* str) {
	
		//size of str
		int sizeStr = 0;
		int i = 0;
		while (str[i] != '\0')
		{
			i++;
			sizeStr++;
		}
		if (sizeStr != 0)
		{
			char* copy = new char[this->size + 1];
			for (int i = 0;i < this->size + 1;i++)
			{
				copy[i] = this->stringCopy[i];
			}
			delete[] this->stringCopy;

			int sizeCopy = this->size;
			this->size = sizeCopy + sizeStr;
			this->stringCopy = new char[this->size + 1];
			for (int i = 0;i < sizeCopy + 1;i++)
			{
				this->stringCopy[i] = copy[i];
			}
			for (int j = sizeCopy, k = 0;j < this->size + 1;k++, j++)
			{
				this->stringCopy[j] = str[k];
			}
			this->stringCopy[this->size] = '\0';
			delete[] copy;

		}
		
		return *this;
	} // appends a String at the end of the String
	
	
	String &String::operator-(const String& substr) {

		int substrSize = 0;
		int idx = 0;
		while (substr[idx] != '\0')
		{
			substrSize++;
			idx++;
		}
	


	
		int newSize = this->size;
		int count = 0;

		int toCheckiForloop = 0;
		if (substr.stringCopy != nullptr)
		{
			for (int i = 0, k = 0;;i++)
			{
				toCheckiForloop = i;
				count = 0;
				if (this->stringCopy[i] == '\0')
					break;

				if (this->stringCopy[i] == substr.stringCopy[0])
				{
					
					for (int j = 0;j < substrSize;j++)
					{
						
						
						if (this->stringCopy[toCheckiForloop] == substr.stringCopy[j])
						{
							count++;
							toCheckiForloop++;
						}
						else
							break;
					}
					
				}
				
				if (substrSize == count)
				{
					
					newSize =newSize-substrSize;
					
				}
			}
			
			
			
			char* copy = new char[this->size + 1];
			for (int i = 0;i < this->size + 1;i++)
			{
				copy[i] = this->stringCopy[i];
			}
			delete[] this->stringCopy;
			this->stringCopy = new char[newSize + 1];


			count = 0;
			for (int i = 0, k = 0;;)
			{
				toCheckiForloop = i;
				count = 0;
				if (copy[i] == '\0')
					break;

				if (copy[i] == substr.stringCopy[0])
				{

					for (int j = 0;j < substrSize;j++)
					{


						if (copy[toCheckiForloop] == substr.stringCopy[j])
						{
							count++;
							toCheckiForloop++;
						}
						else
							break;
					}

				}
				toCheckiForloop = i;
				if (substrSize != count)
				{
					if (k < newSize) {
						this->stringCopy[k] = copy[i];
						k++;
						i++;
					}



				}
				else
				{

					i = i + substrSize;
				}
			}


			this->size = newSize;
			this->stringCopy[newSize] = '\0';
			delete[] copy;

		}
		else
			this->stringCopy = nullptr;
			
		
		
			
	
		return *this;

	} //removes the substr from the String
	
	String &String::operator-(const char& str) {
	
		int newSize = 0;
		if (str != '\0')
		{
			for (int i = 0;;i++)
			{
				if (this->stringCopy[i] == '\0')
					break;

				if (this->stringCopy[i] != str)
				{
					newSize++;
				}
			}
			

			char* copy = new char[this->size + 1];
			for (int i = 0;i < this->size + 1;i++)
			{
				copy[i] = this->stringCopy[i];
			}
			delete[] this->stringCopy;
			this->stringCopy = new char[newSize + 1];

			for (int i = 0,k=0;;i++)
			{
				if (copy[i] == '\0')
					break;

				if (copy[i] != str)
				{


					this->stringCopy[k] = copy[i];
					k++;
				}
				
					
			}
			this->size = newSize;
			this->stringCopy[newSize] = '\0';
			delete[] copy;

		}
		

		return *this;
	} //removes all occurrences of char from the String
	
	String &String::operator-(const char* str) {
	

		int substrSize = 0;
		int idx = 0;
		while (str[idx] != '\0')
		{
			substrSize++;
			idx++;
		}



		int newSize = this->size;
		int count = 0;

		int toCheckiForloop = 0;
		if (str != nullptr)
		{
			for (int i = 0, k = 0;;i++)
			{
				toCheckiForloop = i;
				count = 0;
				if (this->stringCopy[i] == '\0')
					break;

				if (this->stringCopy[i] == str[0])
				{

					for (int j = 0;j < substrSize;j++)
					{


						if (this->stringCopy[toCheckiForloop] == str[j])
						{
							count++;
							toCheckiForloop++;
						}
						else
							break;
					}

				}
				if (substrSize == count)
				{
					newSize = newSize - substrSize;
					
				}
			}
			

			char* copy = new char[this->size + 1];
			for (int i = 0;i < this->size + 1;i++)
			{
				copy[i] = this->stringCopy[i];
			}
			delete[] this->stringCopy;
			this->stringCopy = new char[newSize + 1];


			count = 0;
			for (int i = 0, k = 0;;)
			{
				toCheckiForloop = i;
				count = 0;
				if (copy[i] == '\0')
					break;

				if (copy[i] == str[0])
				{

					for (int j = 0;j < substrSize;j++)
					{


						if (copy[toCheckiForloop] == str[j])
						{
							count++;
							toCheckiForloop++;
						}
						else
							break;
					}

				}
				toCheckiForloop = i;
				
				//cout << substrSize << " " << count << endl;
				if (substrSize != count)
				{
					if (k < newSize)
					{

						this->stringCopy[k] = copy[i];
						k++;
						i++;

					}
				}
				else
					i = i + substrSize;

				
			}

			this->size = newSize;
			this->stringCopy[newSize] = '\0';
			delete[] copy;

		}
		else
			this->stringCopy = nullptr;





		return *this;

	}//removes the str from the String*/
	
// Assignment Operators
	String& String::operator=(const String&copy) {
	
		if (this->size != 0)
			delete[] this->stringCopy;

		if (copy.stringCopy != nullptr)
		{
			this->stringCopy = new char[this->size + 1];
			for (int i = 0;i < this->size + 1;i++)
			{
				this->stringCopy[i] = copy.stringCopy[i];
			}
			this->stringCopy[this->size] = '\0';


		}
		else
			this->stringCopy = nullptr;

		return *this;
	}// copies one String to another
	String& String::operator=(char*str) {

		if (this->size != 0)
			delete[] this->stringCopy;

		if (str!= nullptr)
		{
			this->stringCopy = new char[this->size + 1];
			for (int i = 0;i < this->size + 1;i++)
			{
				this->stringCopy[i] = str[i];
			}
			this->stringCopy[this->size] = '\0';


		}
		else
			this->stringCopy = nullptr;

		return *this;
	
	}// copies one c-string to another
	
// Logical Operators
	bool String::operator==(const String& copy) const {

		bool match = false;
		for (int i = 0;;i++)
		{
			if (copy.stringCopy[i] =='\0' && this->stringCopy[i] =='\0')
				break;
			if (this->stringCopy[i] == copy.stringCopy[i])
				match = true;
			else
			{
				match = false;
				break;
			}
		}
		return match;
	
	}// returns true if two Strings are equal
	
	bool String::operator==(const char*str) const {
	
		bool match = false;
		for (int i = 0;;i++)
		{
			if (str[i] == '\0' && this->stringCopy[i] == '\0')
				break;
			if (this->stringCopy[i] == str[i])
				match = true;
			else
			{
				match = false;
				break;
			}
		}
		return match;

	} // returns true if the c-string is equal to the String
	
// Unary Operators //
//Boolean Not Operator
	bool String::operator!() {
		if (this->stringCopy[0] == '\0')
			return true;
		else
			return false;
	}// returns true if the String is empty
	
// Function-Call Operators
//If something is not found then return -1
	int String::operator()(char ch) const {
	
		for (int i = 0;;i++)
		{
			if (this->stringCopy[i] == '\0')
				return -1;
			if (this->stringCopy[i] == ch)
				return i;
		}
	}// returns the first index of the character being
//searched
	int String::operator()(const String& str) const {

		for (int i = 0,k=0;;i++)
		{
			if (this->stringCopy[i] == '\0')
				return -1;
			if (this->stringCopy[i] == str.stringCopy[k])
				return i;
		}
	
	} // returns the first index of the String
//being searched
	int String::operator()(const char* cString) const {
	
		for (int i = 0,k=0;;i++)
		{
			if (this->stringCopy[i] == '\0')
				return -1;
			if (this->stringCopy[i] == cString[k])
				return i;
		}
	} // returns the index of the c-string being
//searched
	


	// Conversion Operator
	String::operator int() const {
	
		int size = 0;
		for (int i = 0;;i++)
		{
			if (this->stringCopy[i] == '\0' || this->stringCopy==NULL)
				break;
			size++;
		}
		
		return size;
	} // returns the length of string
	String::~String() {

		delete[] this->stringCopy;
	
	} // destructor

	
     


	