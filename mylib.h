
#include <iostream>
#include <numeric>
#include <string>
#include <array>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime> 
#include <fstream>
#include <sstream>

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
using std::stringstream;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::istream;
using std::ostream;
using std::istringstream;

extern char skaiciavimo_Strategija;
extern string failoVardas;

class studentas {
	string vard, pav; // [SAUGO STUDENTO VARDA IR PAVARDE]
	vector<int> paz;  // [SAUGO NAMØ DARBU REZULTATUS]
	int egz;		  // [SAUGO EGZAMINO REZULTATÀ]
	float rez;		  // [SAUGO GALUTINÁ REZULTATÀ]
public:
	studentas();                                         // [DEFAULT KONSTRUKTORIUS]
	studentas(string v, string p, vector<int>pp, int e); // [KONSTRUKTORIUS SU PARAMETRAIS]
	studentas(const studentas& temp);					 // [KOPIJAVIMO KONSTRUKTORIUS]
	studentas& operator=(const studentas& temp);		 // [PRISKIRIMO KOPIJAVIMO OPERATORIUS]
	~studentas();										 // [DESTRUKTORIUS]

	inline string getVardas() { return vard; }			 // [GETTER]
	inline size_t getPazNr() { return paz.size(); }	     // [GETTER]

	inline void setVardas(string t) { vard = t; }        // [SETTER]

	void printas();    // [IÐVEDA STUDENTO DUOMENIS]
	void printasRez(); // [IÐVEDA GALUTINÁ PAÞYMÁ DVIEJU SKAICIU PO KABLELIO TIKSLUMU]
	void rezVid();     // [METODAS SKAIÈIUOJANTIS GALUTINÁ PAÞYMÁ PAGAL VIDURKÁ]
	void rezMed();     // [METODAS SKAIÈIUOJANTIS GALUTINÁ PAÞYMÁ PAGAL MEDIANÀ]

	double mediana(vector<int> vec);    // [FUNKCIJA SKAIÈIUOJANTI MEDIANÀ]

	void operator>>(std::istream& input);  // [PERDENGIA CIN OPERATORIØ]
	void operator<<(std::ostream& output); // [PERDENGIA COUT OPERATORIØ]
};