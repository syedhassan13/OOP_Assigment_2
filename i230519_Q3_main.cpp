#include<iostream>
#include"i230519_Q3_class.h"
#include<cstring>

using namespace std;
int main()
{
	CAList tt;


	tt["OOP"] = "Dr.Ali";
	tt["OOP"] = "Mr.Shehryar";
	tt["OOP"] = "Ms.Hida";
	tt["OOP"] = "Mr.Shams";
	tt["DLD"] = "Mr.Amir";
	tt["DLD"] = "Mr.Shams";
	tt["DLD"] = "Dr.Mehwish";
	cout << tt;
	
	CAList tt2;
	tt2["Algo"] = "Mr.Owais";
	tt2["OOP"] = "Mr.Shehryar";
	tt2["Pak Stds"] = "Mr.Ajmal";
	tt2["Pak Stds"] += "Ms.Gul";
	tt2["Pak Stds"] = "Ms.Memoona";
	tt2["Islamiat"] = "Dr.Tayab";
	tt2["Islamiat"] += "Ms.Sobia";
	tt2["Islamiat"] = "Mr.Usman";
	tt2["Islamiat"] += "Ms.Gul";
	tt2["Islamiat"] += "Mr.Anas";

	CAList tt3;
	tt3 = tt + tt2;

	CAList tt4;
	tt4 = tt - tt2;

	return 0;
}
