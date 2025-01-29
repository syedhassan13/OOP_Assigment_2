#pragma once
#ifndef i230519_Q2
#define i230519_Q2
class String {
public:
	char* stringCopy;
	int size;
public:
	// provide definitions of following functions
	String(); // default constructor
	String(const char* str); // initializes the string with constant c-string
	String(const String&); // copy constructor to initialize the string from the existing string
	//Length of string 
	int lengthOfString(const char* str);
	String(int x); // initializes a string of predefined size
	char* getdata (); //returns the string inside the object
	
	

	// Binary Operators 
	//Sub - script Operators
	const char operator[](int i) const; // returns the character at index [x]
	//NOTE: in above [] operator functions if i=negative int value, print ith character
	//from end //of string e.g. in case of “LOOP” if i=-1 OR i=3, it should return ‘P’
	//	similarly i = -4 OR i = 0, //return ‘L’
		// Arithmetic Operators
	
		String &operator+(const String & str); // appends a String at the end of the String
	String &operator+(const char& str); // appends a char at the end of the String
	String &operator+(const char* str); // appends a String at the end of the String
	
	String &operator-(const String& substr); //removes the substr from the String
	String &operator-(const char& str); //removes all occurrences of char from the String
	String &operator-(const char* str); //removes the str from the String
	
	// Assignment Operators
	String& operator=(const String&copy); // copies one String to another
	String& operator=(char*str); // copies one c-string to another
	
	// Logical Operators
	bool operator==(const String&) const; // returns true if two Strings are equal
	
	bool operator==(const char*) const; // returns true if the c-string is equal to the String
	
		// Unary Operators //
		//Boolean Not Operator
		bool operator!(); // returns true if the String is empty
		
	// Function-Call Operators
	//If something is not found then return -1
	int operator()(char) const; // returns the first index of the character being
	//searched
		int operator()(const String&) const; // returns the first index of the String
	//being searched
		int operator()(const char*) const; // returns the index of the c-string being
	//searched

		

		// Conversion Operator
		operator int() const; // returns the length of string
	~String(); // destructor
	friend ostream& operator<<(ostream& output, const String& str); // outputs the string
	friend istream& operator>>(istream& input, String& str); // inputs the string
	
};

/*friend ostream& operator<<(ostream& output, const String& str); // outputs the string
friend istream& operator>>(istream& input, String& str); // inputs the string*/
ostream& operator<<(ostream& output, const String& str) {
	if (str.stringCopy == NULL)
	{
		output << '\n';
		return output;
	}
		
	output << str.stringCopy;
	return output;
} // outputs the string
istream& operator>>(istream& input, String& str) {
	
	int size = 0;
	cout << "Enter the size" << endl;
	input>> size;

	char* stringcopy = new char[size+1];
	cout << "Enter the string " << endl;
	
	for (int i = 0;i < size;i++)
	{
	
		input >> stringcopy[i];
		
	}
	stringcopy[size] = '\0';
	
	
	
	str.size = size;
	str.stringCopy = new char[str.size+1];
	for (int i = 0;i < str.size+1;i++)
	{
		str.stringCopy[i] = stringcopy[i];
	

	}
	str.stringCopy[str.size] = '\0';
	
	
	delete[] stringcopy;
	
	return input;
} 

#endif
