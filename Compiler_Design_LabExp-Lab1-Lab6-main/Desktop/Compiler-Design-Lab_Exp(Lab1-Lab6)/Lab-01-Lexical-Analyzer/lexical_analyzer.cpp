#include <iostream>
#include <cctype>
#include <string>
using namespace std;

bool isKeyword(string word) {
    string keywords[] = {
        "int","float","if","else","while","for","return","char","double","void"
    };
    for (string k : keywords)
        if (word == k)
            return true;
    return false;
}

bool isOperator(char ch) {
    string ops = "+-*/=%";
    return ops.find(ch) != string::npos;
}

int main() {
    string input;
    cout << "Enter the source code line:\n";
    getline(cin, input);

    string token = "";

    for (int i = 0; i <= input.length(); i++) {
        char ch = input[i];

        if (isalnum(ch)) {
            token += ch;
        } else {
            if (!token.empty()) {
                if (isKeyword(token))
                    cout << token << " : Keyword\n";
                else if (isdigit(token[0]))
                    cout << token << " : Number\n";
                else
                    cout << token << " : Identifier\n";
                token = "";
            }

            if (isOperator(ch))
                cout << ch << " : Operator\n";
            else if (!isspace(ch) && ch != '\0')
                cout << ch << " : Special Symbol\n";
        }
    }
    return 0;
}