#include "mylib.h"

studentas::studentas() {
	srand(time(0)); // [SEEDAS RANDOM GENERATORIUI]

	cout << "Iveskite studento varda: "; cin >> vard;
	cout << "Iveskite studento pavarde: "; cin >> pav;

	cout << "Kiek pazymiu buvo semestre? ";
	int n; cin >> n;

	paz.resize(n);

	for (int i = 0; i < n; i++) {
		int k = rand() % 10 + 1; 
		paz[i] = k;
	}

	egz = rand() % 10 + 1;

	skaiciavimo_Strategija == 'm' ? rezMed() : rezVid();
}

studentas::studentas(string v, string p, vector<int> pp, int e)
{
	vard = v; pav = p; paz = pp; egz = e;
	skaiciavimo_Strategija == 'm' ? rezMed() : rezVid();
}
studentas::studentas(const studentas& temp)
{
	vard = temp.vard; pav = temp.pav;
	paz = temp.paz; egz = temp.egz;
	skaiciavimo_Strategija == 'm' ? rezMed() : rezVid();
}
studentas& studentas:: operator=(const studentas& temp)
{
	if (this == &temp) return *this;
	vard = temp.vard; pav = temp.pav;
	paz = temp.paz; egz = temp.egz;
	skaiciavimo_Strategija == 'm' ? rezMed() : rezVid();
	return *this;
}
studentas::~studentas()
{
	vard.clear(); pav.clear(); paz.clear();
	egz = 0; rez = 0;
}

void studentas::printas() {
	printf("|%-10s|%20s|", vard.c_str(), pav.c_str());
	for (auto& a : paz) printf("%3d|", a);
	printf("%10d|\n", egz);
}

void studentas::printasRez() {
	printf("|%-10s|%20s|", vard.c_str(), pav.c_str());
	printf("%10.2f|\n", rez);
}

void studentas::rezVid() {
	float sum = std::accumulate(paz.begin(), paz.end(), 0.0);
	rez = sum / paz.size() * 0.4 + egz * 0.6;
}

void studentas::rezMed() {
	rez = mediana(paz) * 0.4 + egz * 0.6;
}

double studentas::mediana(vector<int> vec) {
	typedef vector<double>::size_type vecSize;
	vecSize size = vec.size();
	if (size == 0)
		throw std::domain_error("negalima skaiciuoti medianos tusciam vektoriui");
	sort(vec.begin(), vec.end());
	vecSize vid = size / 2;
	return size % 2 == 0 ? (vec[vid] + vec[vid - 1]) / 2 : vec[vid] / 1.0;
}


void studentas::operator>>(std::istream& input) {
	cout << "Iveskite studento varda: "; input >> vard;
	cout << "Iveskite studento pavarde: "; input >> pav;
	cout << "Kiek pazymiu buvo semestre? ";
	int n; input >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cout << "Ivesk " << i + 1 << " semestro pazymi: "; input >> k; paz.push_back(k);
	}
	cout << "Iveskite egzamino pazymi: "; input >> egz;
	skaiciavimo_Strategija == 'm' ? rezMed() : rezVid(); 
}


void studentas::operator<<(std::ostream& output) {
	output << "Vardas: " << vard << endl;
	output << "Pavarde: " << pav << endl;
	output << "Pazymiai: ";
	for (auto& a : paz) output << a << " ";
	output << endl;
	output << "Egzamino pazymys: " << egz << endl;
	output << "Galutinis balas: " << fixed << setprecision(2) << rez << endl;
}

