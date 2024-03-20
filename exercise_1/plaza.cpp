#include <iostream>
#include <string>
#include <vector>


/*
Vlasnik ste niza plaža na najljepšoj plaži u Pučišću na Braču.
Na plažama iznamljujete razne predmete kao što su suncobrani, lopte, stolci i slično, te vam je već pomalo nespretno voditi evidenciju o tome koje sve plaže imate,
a pogotovo koji su sve predmeti dostupni na svakoj te ste se odlučili baciti na posao i napraviti C++ program koji će vam u tome pomoći.
Odlučili ste definirati niz plaža, i za svaku plažu bilježiti niz predmeta koje iznamljujete (kako vam ne bi nestali).

Klasa Plaza ima sljedeća svojstva:
veličinu (duljina)
GPS koordinate (double X i double Y)
niz predmeta koji su dostupni

Klasa Predmet ima sljedeća svojstva:
opis
kolicina

U main programu potrebno je od korisnika tražiti unos broja N, nakon kojeg se unose podaci o N plaža.
Nakon što se unesu sva polja, potrebno je tražiti unos broja M, koji označava broj predmeta, te je potrebno unijeti tih M predmeta (neka plaža može nuditi više predmeta).
Kod unosa pripaziti da se GPS lokacija doista odnosi na mjesto u blizini Pučišća.

Primjer izvođenja:

Unesite broj plaža (N):2
 Unesite velicinu i lokaciju za 1. plazu:
 1345
 43.346216 16.734324
 Unesite velicinu i lokaciju za 2. plazu:
 2115
 43.348236 16.734334
 Unesite broj predmeta (M): 1
 Unesite redni broj plaze kojoj pripada 1. predmet: 2
 Unesite kolicinu i opis predmeta: 19 Lopta
 
 Ispis plaza i predmeta:
 1. 43.346216 16.734324 D=1345 - predmeti:
 2. 43.348236 16.734334 D=2115 - predmeti: 19 Lopta
*/

using namespace std;

class Item {
public:
    string Description;
    double Quantity;
};

class Beach {
    public:
        double Length;
        double Latitude;
        double Longtitude;
        vector<Item> Items;
};

int main()
{
    cout << "Unesite broj plaža (N): ";
    int beachCount;
    cin >> beachCount;

    vector<Beach> beaches;

    for (int i = 0; i < beachCount; ++i)
    {
        Beach b;
        cout << "Unesite velicinu i lokaciju za " << i + 1 << ". plazu: " << endl;
        cin >> b.Length;
        cin >> b.Latitude >> b.Longtitude;

        beaches.push_back(b);
    }

    cout << "Unesite broj predmeta (M): ";
    int itemCount;
    cin >> itemCount;

    for (int i = 0; i < itemCount; ++i) {
        int b;
        cout << "Unesite redni broj plaze kojoj pripada " << i + 1 << ". predmet: ";
        cin >> b;

        if (b <= 0 || b > beaches.size()) {
            throw; // greška je, moze i neki loop but i cba
        }

        Item it;
        cout << "Unesite kolicinu i opis predmeta: ";
        cin >> it.Quantity;
        cin.ignore(); // flush io buffer, https://stackoverflow.com/questions/33316564/mixing-cin-and-getline-input-issues
        getline(cin, it.Description);

        beaches[b - 1].Items.push_back(it);
    }

    cout << "Ispis plaza i predmeta: " << endl;
    for (int i = 0; i < beaches.size(); ++i)
    {
        cout << i + 1 << ". " << beaches[i].Latitude << " " << beaches[i].Longtitude << " D=" << beaches[i].Length << " - predmeti: ";
        for (int j = 0; j < beaches[i].Items.size(); ++j) {
            cout << beaches[i].Items[j].Quantity << " " << beaches[i].Items[j].Description;
            if (j + 1 != beaches[i].Items.size()) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}
