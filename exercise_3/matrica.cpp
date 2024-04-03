#include <iostream>
#include <vector>

using namespace std;

class Matrica {
public:
    vector<int*> redak; // Svaki redak matrice je pokazivač na niz
    vector<int> stupac; // Broj stupaca za svaki redak matrice

    // Empty default ctor (ReSharper suggestion)
    Matrica() = default;

    // Copy ctor
    Matrica(const Matrica& m)
    {
        for (size_t i = 0; i < m.redak.size(); ++i) {
            int* new_row = new int[m.stupac[i]]; // Allocate memory for the new row
            
            copy_n(m.redak[i], m.stupac[i], new_row); // Copy elements
            
            redak.push_back(new_row); // Push the new row

            stupac.push_back(m.stupac[i]); // And it's original length
        }
    }

    // Move ctor
    // noexcept = compile-time check that we don't throw exceptions
    Matrica(Matrica&& m) noexcept
    {
        // Move the resources over
        redak = std::move(m.redak);
        stupac = std::move(m.stupac);

        // Invalidate the old matrix
        m.redak.clear();
        m.stupac.clear();
    }

    ~Matrica()
    {
        for (auto& i : redak)
        {
            delete[] i; // Free stored pointers, make sure you're the owner of said memory beforehand....
        }
    }

    // Copy assignment
    Matrica& operator = (const Matrica& m)
    {
        if (this != &m)
        {
            Matrica temp(m); // Copy ctor
            swap(redak, temp.redak);
            swap(stupac, temp.stupac);
        }

        return *this;
    }

    void dodaj(int brStupaca, int* _redak)
    {
        stupac.push_back(brStupaca);
        redak.push_back(_redak);
    }

    // const = indicates that function does not modify object's data members
    void ispis() const
    {
        for (size_t x = 0; x < stupac.size(); ++x)
        {
            const int elems = stupac[x];
            for (int i = 0; i < elems; ++i)
            {
                cout << *(redak[x] + i) << " ";
            }

            cout << '\n';
        }
    }
};

int main(int argc, char* argv[])
{
    Matrica m;
    m.dodaj(3, new int[3]{ 1, 6, 2 });  // dodaj novi redak od 3 stupca
    m.dodaj(5, new int[5]{ 5, 3, 4, 7, 0 });
    m.dodaj(4, new int[4]{ 6, 2, 6, 5 });
    m.ispis();// ispis matrice redak po redak

    // Copy ctor
    cout << '\n' << "Copy constructor test. Printing matrix: " << '\n';
    Matrica cpy = m;
    m.ispis();

    // Copy assignment
    cout << '\n' << "Copy assignment operator test. Printing matrix: " << '\n';
    Matrica cpy_assign;
    cpy_assign = m;
    cpy_assign.ispis();

    Matrica m2(std::move(m));
    cout << '\n' << "Move constructor test. Printing new matrix:" << '\n';
    m2.ispis();

    cout << '\n' << "Move constructor test. Printing old matrix (should be empty):" << '\n';
    m.ispis();
    
    return 1;
}
