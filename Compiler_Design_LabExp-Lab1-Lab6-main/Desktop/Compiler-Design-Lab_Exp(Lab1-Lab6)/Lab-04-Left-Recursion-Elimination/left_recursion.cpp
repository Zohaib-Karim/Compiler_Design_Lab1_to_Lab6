#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string nonTerminal;
    int n;

    cout << "Enter non-terminal: ";
    cin >> nonTerminal;

    cout << "Enter number of productions: ";
    cin >> n;

    vector<string> alpha, beta;
    cout << "Enter productions (without non-terminal on left):\n";

    for (int i = 0; i < n; i++) {
        string prod;
        cin >> prod;

        if (prod[0] == nonTerminal[0])
            alpha.push_back(prod.substr(1));
        else
            beta.push_back(prod);
    }

    if (alpha.empty()) {
        cout << "\nNo left recursion found.\n";
        return 0;
    }

    cout << "\nAfter eliminating left recursion:\n";
    cout << nonTerminal << " -> ";

    for (int i = 0; i < beta.size(); i++) {
        cout << beta[i] << nonTerminal << "' ";
        if (i != beta.size() - 1)
            cout << "| ";
    }

    cout << "\n" << nonTerminal << "' -> ";

    for (int i = 0; i < alpha.size(); i++) {
        cout << alpha[i] << nonTerminal << "' | ";
    }
    cout << "ε\n";

    return 0;
}