#include <iostream>
#include <string>
using namespace std;

int main() {
    string genString, explosion;
    cin >> genString >> explosion;

    string result;
    for (char ch : genString) {
        result.push_back(ch);
        if (result.size() >= explosion.size() && result.substr(result.size() - explosion.size()) == explosion) {
            result.resize(result.size() - explosion.size());
        }
    }

    if (result.empty()) {
        cout << "FRULA" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
