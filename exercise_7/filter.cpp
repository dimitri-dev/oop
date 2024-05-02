#include <iostream>
#include <vector>

using namespace std;

class Filter {
public:
    virtual ~Filter() = default;

    virtual vector<int> uvjet(vector<int> vec) final {
        vector<int> rezultat;
        for (int element : vec) {
            if (provjera(element)) {
                rezultat.push_back(element);
            }
        }
        return rezultat;
    }

    virtual bool provjera(int element) = 0;
};

class FilterVeciOd : public Filter
{
    private:
        int value;

    public:
        FilterVeciOd(int value) : value(value) {}

        bool provjera(int element) override {
            return element > value;
        }
};

class FilterManjiOd : public Filter
{
    private:
        int value;

    public:
        FilterManjiOd(int value) : value(value) {}

        bool provjera(int element) override {
            return element < value;
        }
};

ostream& operator<<(ostream& os, const vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1) {
            os << " ";
        }
    }
    os << '\n';
    return os;
}

int main() {
    vector<int> v = {14, 3, 18, 5, 6, 10, 2, 8, 1, 7};

    Filter* filter = new FilterVeciOd(5);        // propusti samo vrijednosti vece od 5

    vector<int> rezultat = filter->uvjet(v);
    cout << rezultat;        // ispisuje 14 18 6 10 8 7

    delete filter;

    filter = new FilterManjiOd(5);        // propusti samo vrijednosti manje od 5

    rezultat = filter->uvjet(v);
    cout << rezultat;        // ispisuje 3 2 1
    
    delete filter;

    return 0;
}
