#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

map<char, vector<string>> grammar;
map<char, set<char>> firstSet, followSet;
set<char> nonTerminals;
char startSymbol;

void findFirst(char c);

void findFollow(char c) {
    if (c == startSymbol)
        followSet[c].insert('$');

    for (auto g : grammar) {
        char lhs = g.first;
        for (string prod : g.second) {
            for (int i = 0; i < prod.length(); i++) {
                if (prod[i] == c) {
                    if (i + 1 < prod.length()) {
                        char next = prod[i + 1];
                        if (!isupper(next))
                            followSet[c].insert(next);
                        else {
                            for (char x : firstSet[next]) {
                                if (x != 'ε')
                                    followSet[c].insert(x);
                            }
                        }
                    } else if (lhs != c) {
                        for (char x : followSet[lhs])
                            followSet[c].insert(x);
                    }
                }
            }
        }
    }
}

void findFirst(char c) {
    for (string prod : grammar[c]) {
        if (!isupper(prod[0])) {
            firstSet[c].insert(prod[0]);
        } else {
            findFirst(prod[0]);
            for (char x : firstSet[prod[0]])
                firstSet[c].insert(x);
        }
    }
}

int main() {
    int n;
    cout << "Enter number of productions: ";
    cin >> n;

    cout << "Enter productions (Example: E=TR):\n";
    for (int i = 0; i < n; i++) {
        string prod;
        cin >> prod;
        char lhs = prod[0];
        grammar[lhs].push_back(prod.substr(2));
        nonTerminals.insert(lhs);
        if (i == 0)
            startSymbol = lhs;
    }

    for (char nt : nonTerminals)
        findFirst(nt);

    for (char nt : nonTerminals)
        findFollow(nt);

    cout << "\nFIRST Sets:\n";
    for (auto p : firstSet) {
        cout << "FIRST(" << p.first << ") = { ";
        for (char x : p.second)
            cout << x << " ";
        cout << "}\n";
    }

    cout << "\nFOLLOW Sets:\n";
    for (auto p : followSet) {
        cout << "FOLLOW(" << p.first << ") = { ";
        for (char x : p.second)
            cout << x << " ";
        cout << "}\n";
    }

    return 0;
}