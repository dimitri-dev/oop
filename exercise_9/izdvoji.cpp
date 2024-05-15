#include <iostream>
#include <vector>

using namespace std;

vector<int> izdvoji(vector<int>& v, bool (*f)(int)) {
    vector<int> ret;

    for (int i : v)
        if (f(i))
            ret.push_back(i);

    return ret;
}

int main() {
    vector<int> brojevi = {1, 4, 5, 7, 3, 6, 12, 65, 32, 8, 87, 55, 23, 22, 1, 1, 433, 66, 7, 433, 3, 32, 76, 8, 72, 256, 42};

    vector<int> rez = izdvoji(brojevi, [](int x) { return x % 3 == 0; });

    for (size_t i = 0; i < rez.size(); i++)
        cout << rez[i] << " ";
    
    //Expected output: 3 6 12 87 66 3 72 42

    return 0;
}
