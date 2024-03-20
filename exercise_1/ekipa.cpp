#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

class Igrac {
    public:
        string ime;
        string prezime;
        int broj;
        double cijena;

        Igrac(string ime, string prezime)
        {
            this->ime = ime;
            this->prezime = prezime;
        }

        void ispisi()
        {
            cout << setprecision(15) << broj << " " << ime << " " << prezime << " " << cijena << " EUR" << endl;
        }
};

class Ekipa {
    public:
        string naziv;

        void dodajIgraca(Igrac i)
        {
            igraci.push_back(i);
        }

        void ispisi()
        {
            cout << "Naziv ekipe: " << naziv << endl;

            // this permanently alters the vector, but it doesn't really matter?
            // if thread-safety is concerned, make a vector copy locally
            sort(igraci.begin(), igraci.end(), [](const Igrac& lhs, const Igrac& rhs) { return lhs.broj < rhs.broj; });

            cout << "Igraci:" << endl;
            for (auto& v : igraci) v.ispisi();

            cout << endl;
        }

        // https://stackoverflow.com/a/57093179
        Igrac dohvatiNajskupljeg()
        {
            return *max_element(igraci.begin(), igraci.end(), [](const Igrac& lhs, const Igrac& rhs) { return lhs.cijena > rhs.cijena; });
        }

        // https://stackoverflow.com/a/20029249
        double ukupnaCijena()
        {
            double sum = 0;
            for (const auto& v : igraci) sum += v.cijena;
            return sum;
        }

        double prosjecnaCijena()
        {
            return ukupnaCijena() / (double)igraci.size();
        }

    private:
        vector<Igrac> igraci;
};

// Potrebno je napisati program za evidenciju igrača u ekipi.
// Ekipa se sastoji od igrača, a za svakog igrača se evidentira broj na dresu, ime, prezime i trzisna cijena.
// Potrebno je omogućiti ispis svih igrača u ekipi (naziv ekipe, te popis svih igrača poredano po broju na dresu).
// Također, potrebno je omogućiti jednostavno dohvaćanje informacija u ukupnoj cijeni svih igrača, najskupljem igraču, te prosječnoj cijeni svih igrača.
// Slijedeći programski odsječak u nastavku napišite sve potrebne klase i metode kojima se dobije očekivano ponašanje programskog koda.

int main() {

    Ekipa ekipa;

    ekipa.naziv = "Tim raketa";

    Igrac i1("Luka", "Modric");

    i1.broj = 10;

    i1.cijena = 50000000;

    ekipa.dodajIgraca(i1);

    Igrac i2("Mario", "Mandzukic");

    i2.broj = 9;

    i2.cijena = 27000000;

    ekipa.dodajIgraca(i2);

    Igrac i3("Darijo", "Srna");

    i3.broj = 11;

    i3.cijena = 14500000;

    ekipa.dodajIgraca(i3);



    ekipa.ispisi();



    Igrac najskuplji = ekipa.dohvatiNajskupljeg();

    cout << "Najskuplji igrac: ";

    najskuplji.ispisi();



    cout << "Ukupna cijena svih igraca: " << ekipa.ukupnaCijena() << endl;

    cout << "Prosjecna cijena jednog igraca: " << ekipa.prosjecnaCijena() << endl;

}
