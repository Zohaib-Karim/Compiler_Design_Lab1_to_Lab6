#include <iostream>
#include <vector>
using namespace std;

struct Transition {
    int from;
    char symbol;
    int to;
};

int main() {
    string regex;
    cout << "Enter regular expression (single characters, use * for closure): ";
    cin >> regex;

    vector<Transition> transitions;
    int state = 0;

    for (int i = 0; i < regex.length(); i++) {
        char ch = regex[i];

        if (ch == '*') {
            // Kleene star handling
            transitions.push_back({state, 'ε', state - 1});
            transitions.push_back({state - 1, 'ε', state});
        } else {
            transitions.push_back({state, ch, state + 1});
            state++;
        }
    }

    cout << "\nNFA Transitions:\n";
    cout << "From\tSymbol\tTo\n";
    for (auto t : transitions) {
        cout << t.from << "\t" << t.symbol << "\t" << t.to << endl;
    }

    cout << "\nStart State: 0";
    cout << "\nFinal State: " << state << endl;

    return 0;
}