#include "mylib.h"

int main() {
	std::chrono::time_point<std::chrono::system_clock> start, end;
	std::chrono::duration<double> elapsed_seconds;

	start = std::chrono::system_clock::now();
	vector<studentas> grupe;

	ofstream stude_failas("stude.txt");
	ofstream zmones_failas("zmones.txt");

	for (auto& student : grupe) {
		if (student.getRezultatas() >= 5) {
			zmones_failas << student.getVardas() << " " << student.getPavarde() << " " << student.getRezultatas();
		}
		else {
			stude_failas << student.getVardas() << " " << student.getPavarde() << " " << student.getRezultatas();
		}
	}

	stude_failas.close();
	zmones_failas.close();

	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "Failu kurimas uztruko: " << elapsed_seconds.count() << " sekundes." << std::endl;

	start = std::chrono::system_clock::now();

	char skaiciavimo_Strategija;
	cout << "Kaip skaiciuoti galutini bala? (v - vidurkis, m - mediana): ";
	cin >> skaiciavimo_Strategija;

	ifstream failas("kursiokai.txt");

	try {
		if (!failas.is_open()) {
			throw std::runtime_error("Klaida atidarant faila.");
		}

		string eilute;

		getline(failas, eilute);

		while (getline(failas, eilute)) {
			string vardas, pavarde;
			int egzaminas;
			vector<int> pazymiai;

			istringstream iss(eilute);
			iss >> vardas >> pavarde;

			int pazymys;
			while (iss >> pazymys) {
				pazymiai.push_back(pazymys);
			}

			egzaminas = pazymiai.back();
			pazymiai.pop_back();

			studentas K(vardas, pavarde, pazymiai, egzaminas);
			grupe.push_back(K);
		}

		failas.close();

		end = std::chrono::system_clock::now();
		elapsed_seconds = end - start;
		std::cout << "Duomenu nuskaitymas uztruko: " << elapsed_seconds.count() << " sekundes." << std::endl;

		start = std::chrono::system_clock::now();

		cout << grupe.size() << " studentai nuskaityti." << endl;

		printf("|%-10s|%-20s|", "[Vardas]", "[Pavarde]");
		for (int i = 0; i < grupe[0].getPazNr(); i++) {
			printf("%s%d|", "ND", i + 1);
		}
		printf("%10s|\n", "Egzaminas");

		for (auto& student : grupe) {
			student.printas();
		}

		cout << endl;

		printf("|%-10s|%-20s|", "[Vardas]", "[Pavarde]");
		printf("%10s|\n", skaiciavimo_Strategija == 'm' ? "Galutinis(m)" : "Galutinis (v)");

		for (auto& student : grupe) {
			student.printasRez();
		}


		end = std::chrono::system_clock::now();
		elapsed_seconds = end - start;
		std::cout << "Apdorojimas uztruko: " << elapsed_seconds.count() << " sekundes." << std::endl;

		start = std::chrono::system_clock::now();

		ofstream stude_failas("stude.txt");
		ofstream zmones_failas("zmones.txt");

		vector<studentas> grupe;
		int studentCount;
		cout << "Kiek studentu bus ivesta? ";
		cin >> studentCount;

		for (int i = 0; i < studentCount; i++) {
			studentas K;
			grupe.push_back(K);
		}

		if (stude_failas.is_open() && zmones_failas.is_open()) {
			for (auto& student : grupe) {
				if (student.getRezultatas() < 5.0) {
					stude_failas << student.getVardas() << " " << student.getPavarde() << " " << student.getRezultatas() << "\n";
				}
				else {
					zmones_failas << student.getVardas() << " " << student.getPavarde() << " " << student.getRezultatas() << "\n";
				}
			}

			stude_failas.close();
			zmones_failas.close();

			cout << "Studentai suskirstyti ir issaugoti failuose 'stude.txt' ir 'zmones.txt'." << endl;
		}
		else {
			cout << "Klaida atidarant naujus failus vargsiukams ir kietiakiams." << endl;
		}

		end = std::chrono::system_clock::now();
		end = std::chrono::system_clock::now();
		elapsed_seconds = end - start;
		cout << "Studentu rusiavimas uztruko: " << elapsed_seconds.count() << " sekundes." << endl;

		start = std::chrono::system_clock::now();

		int studentuKiekiai[] = { 100, 1000, 10000, 100000, 1000000 };

		for (int i = 0; i < 5; i++) {
			cin >> studentuKiekiai[i];
			int studentuKiekis = studentuKiekiai[i];
			vector<studentas> sugeneruoti_studentai;

			for (int j = 0; j < studentuKiekis; j++) {
				studentas student;
				sugeneruoti_studentai.push_back(student);
			}

			string failoVardas = "studentai" + to_string(studentuKiekis) + ".txt";

			ofstream naujas_failas(failoVardas);
			if (naujas_failas.is_open()) {
				naujas_failas << "Vardas                   Pavarde                    ND1       ND2       ND3       ND4       ND5       ND6       ND7       ND8       ND9      ND10      Egz.\n";
				for (auto& student : sugeneruoti_studentai) {
					naujas_failas << setw(25) << left << student.getVardas() << setw(25) << left << student.getPavarde();
					for (int i = 0; i < student.getPazNr(); i++) {
						naujas_failas << setw(10) << student.getND(i);
					}
					naujas_failas << setw(10) << student.getEgzaminas() << endl;
				}
				naujas_failas.close();
				cout << "Sugeneruoti duomenys ir issaugoti i faila: " << failoVardas << "." << endl;
			}
		}
		return 0;
	}

	catch (const std::exception& e) {
		cout << e.what() << endl;
		return 1;
	}

	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "Studentu generavimas ir issaugojimas uztruko: " << elapsed_seconds.count() << " sekundes." << std::endl;
}