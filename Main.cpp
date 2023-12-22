#include "mylib.h"

int main() {
    char skaiciavimo_Strategija;
    cout << "Kaip skaiciuoti galutini bala? (v - vidurkis, m - mediana): ";
    cin >> skaiciavimo_Strategija;

    vector<studentas> grupe;
    ifstream failas("kursiokai.txt");

    try {
        if (!failas.is_open()) {
            throw std::runtime_error("Klaida atidarant failà.");
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
    }
    catch (const std::exception& e) {
        cout << "Ivyko klaida: " << e.what() << endl;
        return 1;
    }

    system("pause");
}
