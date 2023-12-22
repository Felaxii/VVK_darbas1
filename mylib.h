#pragma once
#include <iostream>
#include <numeric>
#include <string>
#include <array>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime> 

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::array;
using std::vector;
using std::setw;
using std::left;
using std::right;
using std::fixed;
using std::setprecision;
using std::sort;
using std::domain_error;

extern char skaiciavimo_Strategija;
extern string failoVardas;

class studentas {
	string vard, pav; 
	vector<int> paz;  
	int egz;		  
	float rez;		  
public:
	studentas();                                         
	studentas(string v, string p, vector<int>pp, int e); 
	studentas(const studentas& temp);					 
	studentas& operator=(const studentas& temp);		
	~studentas();										

	inline string getVardas() { return vard; }			 
	inline size_t getPazNr() { return paz.size(); }	     

	inline void setVardas(string t) { vard = t; }        

	void printas();    
	void printasRez(); 
	void rezVid();     
	void rezMed();     

	double mediana(vector<int> vec);    

	void operator>>(std::istream& input);  
	void operator<<(std::ostream& output); 
};