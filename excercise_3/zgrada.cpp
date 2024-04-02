#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Stan {
public:
	// Dodati klasu Stan s nekoliko proizvoljnih polja (vlasnik, velicina, koliko soba, ...).
	string Vlasnik;
	int Velicina;
	int BrojSoba;

	/* Neka klasa Stan ima samo jedan konstruktor, unutar kojeg je potrebno ispisati „Stan constructor called“ korisniku, te jedan destruktor u kojem treba ispisati "Stan destructor called" korisniku. */
	Stan() {
		cout << "Stan constructor called" << endl;
	}

	~Stan() {
		cout << "Stan destructor called" << endl;
	}
};

/*
Napraviti klasu Zgrada sa sljedećim (privatnim) poljima:

	naziv građevinske firme
	broj katova
	adresa
*/
class Zgrada {
private:
	//   Proširiti klasu Zgrada s poljem vector<Stan>

	vector<Stan> stanovi;
	string NazivGradevinskeFirme;
	int BrojKatova;
	string Adresa;

	/*
	Omogućiti korisniku kreiranje nove zgrade i postavljanje naziva građ. firme, broja katova i adrese. Treba pripaziti na sljedeća pravila:

	Naziv firme mora biti barem 5 znakova – ako je manji, odustati od postavljanja naziva i ispisati poruku korisniku
	Broj katova mora biti veći od 0. Ukoliko pravilo nije zadovoljeno, odustati od postavljanja vrijednosti, i ispisati poruku korisniku

	Sve provjere pravila je potrebno napraviti unutar klase Zgrada. (Gdje?)*/
public:
	bool PostaviNazivGradevinskeFirme(string naziv) {
		if (naziv.length() >= 5) {
			this->NazivGradevinskeFirme = naziv;
			return true;
		}
		return false;
	}

	bool PostaviAdresu(string adresa) {
		this->Adresa = adresa;
		return true;
	}

	bool PostaviBrojKatova(int brojKatova) {
		if (brojKatova > 0) {
			this->BrojKatova = brojKatova;
			return true;
		}
		return false;
	}

	void ispisSvihStanova() {
		int ctr = 0;
		for (const Stan x : stanovi)
		{
			ctr++;
			cout << ctr << ". stan: Vlasnik: " << x.Vlasnik << ", broj soba: " << x.BrojSoba << ", velicina: " << x.Velicina << endl;
		}
	}

	void dodajStan1(Stan z) {
		stanovi.push_back(z);
	}
	void dodajStan2(Stan& z) {
		stanovi.push_back(z);
	}
	void dodajStan3(Stan* z) {
		stanovi.push_back(*z);
	}

	Stan nadjiStan1(string vlasnik) {	
		for (Stan x : stanovi) {
			if (x.Vlasnik == vlasnik) {
				return x;
			}
		}

		Stan s;
		return s; // novi stan
	}
	Stan* nadjiStan2(string vlasnik) {
		for (Stan x : stanovi) {
			if (x.Vlasnik == vlasnik) {
				return &x;
			}
		}

		return NULL;
	}

	Stan& nadjiStan3(string vlasnik) {
		for (Stan x : stanovi) {
			if (x.Vlasnik == vlasnik) {
				return x;
			}
		}

		Stan s;
		return s; // novi stan
	}
};

int main() {
}
