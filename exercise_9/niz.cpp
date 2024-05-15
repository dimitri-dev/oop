#include <iostream>
#include <vector>

using namespace std;

template<typename TVector>
class Niz2
{
    public:
        // clang tidy fix --- (v(v)) => v(std::move(v))
        Niz2(vector<TVector> v) : v(std::move(v))
        {
            
        }

        vector<TVector> v;

        bool operator<(Niz2& p)
        {
            for (size_t i = 0; i < v.size(); ++i)
            {
                if (!(v[i] < p.v[i]))
                {
                    return false;
                }
            }
            return true;
        }
};

template<typename TVector>
class Niz
{
    public:
        // clang tidy fix --- (v(v)) => v(std::move(v))
        Niz(vector<TVector> v) : v(std::move(v))
        {
            
        }
        
        vector<TVector> v;
};

template<typename TVector>
bool operator<(Niz<TVector>& p1, Niz<TVector>& p2)
{
    for (size_t i = 0; i < p1.v.size(); ++i)
    {
        if (!(p1.v[i] < p2.v[i]))
        {
            return false;
        }
    }
    return true;
}

template<typename TVector>
bool operator>=(Niz<TVector>& p1, Niz<TVector>& p2)
{
    return !(p1 < p2);
}

int main() {
    vector<int> v1 = {1, 2, 3};

    vector<int> v2 = {11, 0, 13};

    Niz<int> p1(v1);

    Niz<int> p2(v2);

    cout << (p1 < p2) << '\n';  // operator <

    return 0;
}
