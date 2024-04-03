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

    /* Neka klasa Stan ima samo jedan konstruktor, unutar kojeg je potrebno ispisati „Stan constructor called“ korisniku,
     * te jedan destruktor u kojem treba ispisati "Stan destructor called" korisniku. */
    Stan()
    {
        cout << "Stan constructor called" << endl;
    }

    ~Stan()
    {
        cout << "Stan destructor called" << endl;
    }
};

/*
Napraviti klasu Zgrada sa sljedećim (privatnim) poljima:

	naziv građevinske firme
	broj katova
	adresa
*/
class Zgrada
{
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
    bool PostaviNazivGradevinskeFirme(string naziv)
    {
        if (naziv.length() >= 5)
        {
            this->NazivGradevinskeFirme = naziv;
            return true;
        }
        return false;
    }

    bool PostaviAdresu(string adresa)
    {
        this->Adresa = adresa;
        return true;
    }

    bool PostaviBrojKatova(int brojKatova)
    {
        if (brojKatova > 0)
        {
            this->BrojKatova = brojKatova;
            return true;
        }
        return false;
    }

    void ispisSvihStanova()
    {
        int ctr = 0;
        cout << "Ispis svih stanova" << '\n';
        
        for (const Stan& x : stanovi)
        {
            ctr++;
            cout << ctr << ". stan:" << '\n';
            cout << '\t' << "Vlasnik: " << x.Vlasnik << '\n';
            cout << '\t' << "Broj soba: " << x.BrojSoba << '\n';
            cout << '\t' << "Velicina: " << x.Velicina << '\n';
        }

        cout << '\n';
    }

    void dodajStan1(Stan z)
    {
        stanovi.push_back(z);
    }

    void dodajStan2(Stan& z)
    {
        stanovi.push_back(z);
    }

    void dodajStan3(Stan* z)
    {
        stanovi.push_back(*z);
    }

    Stan nadjiStan1(const string& vlasnik)
    {
        for (Stan& x : stanovi)
        {
            if (x.Vlasnik == vlasnik)
            {
                return x;
            }
        }

        throw;
    }

    Stan* nadjiStan2(const string& vlasnik)
    {
        for (Stan& x : stanovi)
        {
            if (x.Vlasnik == vlasnik)
            {
                return &x;
            }
        }

        return nullptr;
    }

    Stan& nadjiStan3(const string& vlasnik)
    {
        for (Stan& x : stanovi)
        {
            if (x.Vlasnik == vlasnik)
            {
                return x;
            }
        }
        
        throw;
    }
};

Zgrada StvoriZgradu()
{
    Zgrada z;
    
    string naziv;
    cout << "Unesite naziv gradevinske firme: ";
    getline(cin, naziv);
    while (z.PostaviNazivGradevinskeFirme(naziv) == false)
    {
        cout << "Naziv ne zadovoljava uvjete ispunjavanja." << '\n';
        cout << "Unesite naziv gradevinske firme: ";
        getline(cin, naziv);
    }
    
    string adresa;
    cout << "Unesite adresu zgrade: ";
    getline(cin, adresa);
    while (z.PostaviAdresu(adresa) == false)
    {
        cout << "Adresa ne zadovoljava uvjete ispunjavanja." << '\n';
        cout << "Unesite adresu zgrade: ";
        getline(cin, adresa);
    }

    int brojKatova;
    cout << "Unesite broj katova: ";
    cin >> brojKatova;
    while (z.PostaviBrojKatova(brojKatova) == false)
    {
        cout << "Broj katova unesen nije ispravan." << '\n';
        cout << "Unesite broj katova: ";
        cin >> brojKatova;
    }

    return z;
}

Stan StvoriStan(int x)
{
    Stan s;
    s.Vlasnik = "Vlasnik " + std::to_string(x);
    s.Velicina = 100 + x;
    s.BrojSoba = 3 + x;
    return s;
}

int main()
{
    Zgrada z = StvoriZgradu();
    
    auto stan1 = StvoriStan(1); // 1ctor
    auto stan2 = StvoriStan(2); // 1ctor
    auto stan3 = StvoriStan(3); // 1ctor
    z.dodajStan1(stan1); // 1 dtor
    z.dodajStan2(stan2); // 1 dtor
    z.dodajStan3(&stan3); // 2 dtor

    z.ispisSvihStanova();

    z.nadjiStan1("Vlasnik 1").Vlasnik = "Pero Jedan"; // 1 dtor - new object, original unchanged
    z.nadjiStan2("Vlasnik 2")->Vlasnik = "Alojzije Dva"; // 0 dtor - original object, changed
    z.nadjiStan3("Vlasnik 3").Vlasnik = "Ilija Tri"; // 0 dtor - original object, changed

    z.ispisSvihStanova();

    // 6 dtor at the end.
}
