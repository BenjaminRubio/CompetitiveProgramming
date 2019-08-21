#include <bits/stdc++.h>
using namespace std;

int nTests {0};
int nPizzas {0};
int nIngredients {0};
string pizzaName;
string ingredient;
map<string, int> english;
map<string, int> italian;

int main() {

    cin >> nTests;
    while (nTests--) {
        cin >> nPizzas;
        for (int i = 0; i < nPizzas; i++) {
            cin >> pizzaName;
            cin >> nIngredients;
            while (nIngredients--) {
                cin >> ingredient;
                italian.emplace(ingredient, 0);
                italian[ingredient] |= (1 << i);
            }
            cin >> nIngredients;
            while (nIngredients--) {
                cin >> ingredient;
                english.emplace(ingredient, 0);
                english[ingredient] |= (1 << i);
            }
        }
        for (auto const &ita : italian) {
            for (auto const &eng: english) {
                if ((ita.second & eng.second) == (ita.second | eng.second)) {
                    cout << '(' << ita.first << ", " << eng.first << ")\n";
                }
            }
        }
        cout << '\n';
        english = {};
        italian = {};
    }
}