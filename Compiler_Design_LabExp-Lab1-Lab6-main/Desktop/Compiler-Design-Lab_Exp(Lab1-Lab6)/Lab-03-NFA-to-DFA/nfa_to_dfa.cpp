#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n, t;
    cout << "Enter number of NFA states: ";
    cin >> n;

    cout << "Enter number of transitions: ";
    cin >> t;

    map<pair<int,char>, set<int>> nfa;
    set<char> symbols;

    cout << "Enter transitions (from symbol to):\n";
    for (int i = 0; i < t; i++) {
        int from, to;
        char sym;
        cin >> from >> sym >> to;
        nfa[{from, sym}].insert(to);
        symbols.insert(sym);
    }

    set<set<int>> dfaStates;
    map<set<int>, map<char, set<int>>> dfa;

    set<int> startState;
    startState.insert(0);
    dfaStates.insert(startState);

    vector<set<int>> unprocessed;
    unprocessed.push_back(startState);

    while (!unprocessed.empty()) {
        set<int> current = unprocessed.back();
        unprocessed.pop_back();

        for (char sym : symbols) {
            set<int> nextState;

            for (int s : current) {
                if (nfa.count({s, sym})) {
                    nextState.insert(
                        nfa[{s, sym}].begin(),
                        nfa[{s, sym}].end()
                    );
                }
            }

            if (!nextState.empty()) {
                dfa[current][sym] = nextState;
                if (dfaStates.insert(nextState).second) {
                    unprocessed.push_back(nextState);
                }
            }
        }
    }

    cout << "\nDFA Transition Table:\n";
    for (auto d : dfa) {
        cout << "{ ";
        for (int s : d.first) cout << s << " ";
        cout << "} : ";

        for (auto tr : d.second) {
            cout << tr.first << " -> { ";
            for (int x : tr.second) cout << x << " ";
            cout << "} ";
        }
        cout << endl;
    }

    return 0;
}