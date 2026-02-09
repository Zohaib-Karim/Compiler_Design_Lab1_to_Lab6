Compiler Design Lab Experiments (Lab 1 – Lab 6)
📘 Overview
This repository contains the complete implementation of Compiler Design Laboratory Experiments (Lab 1 to Lab 6) using C++.
Each experiment is organized into a separate folder with:

Source code
Individual README file
Sample input and output
Clear explanation of the experiment
This repository is structured to be faculty-friendly, viva-ready, and GitHub-professional.

📂 Repository Structure
Compiler_Design_LabExp-Lab1-Lab6/ │ ├── Lab-01-Lexical-Analyzer/ │ ├── lexical_analyzer.cpp │ └── README.md │ ├── Lab-02-Regex-to-NFA/ │ ├── regex_to_nfa.cpp │ └── README.md │ ├── Lab-03-NFA-to-DFA/ │ ├── nfa_to_dfa.cpp │ └── README.md │ ├── Lab-04-Left-Recursion-Elimination/ │ ├── left_recursion.cpp │ └── README.md │ ├── Lab-05-FIRST-FOLLOW/ │ ├── first_follow.cpp │ └── README.md │ ├── Lab-06-Predictive-Parsing-Table/ │ ├── predictive_parsing_table.cpp │ └── README.md │ └── README.md ← Main README

🧠 Technologies Used
Programming Language: C++
Compiler: GCC / G++
IDE: VS Code
Version Control: Git
Platform: GitHub
📖 List of Experiments
🔹 Lab 1: Lexical Analyzer
Implementation of a lexical analyzer to identify keywords, identifiers, operators, numbers, and special symbols from source code.

📁 Folder: Lab-01-Lexical-Analyzer

🔹 Lab 2: Regular Expression to NFA
Conversion of a given regular expression into an equivalent Non-Deterministic Finite Automaton (NFA).

📁 Folder: Lab-02-Regex-to-NFA

🔹 Lab 3: NFA to DFA Conversion
Conversion of a Non-Deterministic Finite Automaton (NFA) into a Deterministic Finite Automaton (DFA) using the subset construction method.

📁 Folder: Lab-03-NFA-to-DFA

🔹 Lab 4: Elimination of Left Recursion
Elimination of left recursion from a context-free grammar to make it suitable for top-down parsing.

📁 Folder: Lab-04-Left-Recursion-Elimination

🔹 Lab 5: FIRST and FOLLOW Sets
Computation of FIRST and FOLLOW sets for non-terminals in a given grammar.

📁 Folder: Lab-05-FIRST-FOLLOW

🔹 Lab 6: Predictive Parsing Table
Construction of LL(1) Predictive Parsing Table using FIRST and FOLLOW sets.

📁 Folder: Lab-06-Predictive-Parsing-Table

▶️ How to Run the Programs
Open the required .cpp file in VS Code.
Compile the program using:
g++ filename.cpp -o output
Run the program: ./output
Provide input as mentioned in the respective lab README.
📌 Notes

All experiments are implemented as per standard Compiler Design Lab syllabus. Epsilon (ε) is used where required in grammar rules. Each lab folder contains its own detailed README for better understanding.

🎓 Author

Syed Zohaib Karim

Course: Compiler Design Type: Laboratory Experiments
