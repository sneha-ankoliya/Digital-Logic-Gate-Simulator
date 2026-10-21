#include <iostream>
#include <limits>
#include <string>
using namespace std;

// Each function represents one digital logic gate.
// Inputs are expected to be either 0 or 1.

int ANDGate(int a, int b) {
    return a && b;
}

int ORGate(int a, int b) {
    return a || b;
}

int NOTGate(int a) {
    return !a;
}

int NANDGate(int a, int b) {
    return !(a && b);
}

int NORGate(int a, int b) {
    return !(a || b);
}

int XORGate(int a, int b) {
    return a != b;
}

int XNORGate(int a, int b) {
    return a == b;
}

// Read an integer safely. If the user types text, clear the bad input.
int readInteger(const string& prompt) {
    int value;

    while (true) {
        cout << prompt;
        if (cin >> value) {
            return value;
        }

        cout << "Invalid input. Please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Keep asking until the user enters binary input: 0 or 1.
int readBinaryInput(const string& prompt) {
    int value;

    while (true) {
        value = readInteger(prompt);

        if (value == 0 || value == 1) {
            return value;
        }

        cout << "Invalid binary input. Enter only 0 or 1.\n";
    }
}

void showGateMenu() {
    cout << "\n========== DIGITAL LOGIC GATE SIMULATOR ==========\n";
    cout << "1. AND Gate\n";
    cout << "2. OR Gate\n";
    cout << "3. NOT Gate\n";
    cout << "4. NAND Gate\n";
    cout << "5. NOR Gate\n";
    cout << "6. XOR Gate\n";
    cout << "7. XNOR Gate\n";
    cout << "8. Display all truth tables\n";
    cout << "9. Logic gate quiz\n";
    cout << "0. Exit\n";
    cout << "===================================================\n";
}

void simulateTwoInputGate(const string& gateName,
                          const string& expression,
                          int (*gateFunction)(int, int)) {
    cout << "\n--- " << gateName << " Gate ---\n";
    cout << "Boolean expression: " << expression << "\n";

    int a = readBinaryInput("Enter input A (0 or 1): ");
    int b = readBinaryInput("Enter input B (0 or 1): ");

    cout << "Input A = " << a << ", Input B = " << b << "\n";
    cout << "Output  = " << gateFunction(a, b) << "\n";
}

void simulateNotGate() {
    cout << "\n--- NOT Gate ---\n";
    cout << "Boolean expression: Y = NOT A (Y = A')\n";

    int a = readBinaryInput("Enter input A (0 or 1): ");

    cout << "Input A = " << a << "\n";
    cout << "Output  = " << NOTGate(a) << "\n";
}

void printTwoInputTruthTable(const string& gateName,
                             int (*gateFunction)(int, int)) {
    cout << "\n" << gateName << " Gate Truth Table\n";
    cout << "A  B  |  Y\n";
    cout << "---------\n";

    for (int a = 0; a <= 1; ++a) {
        for (int b = 0; b <= 1; ++b) {
            cout << a << "  " << b << "  |  "
                 << gateFunction(a, b) << "\n";
        }
    }
}

void printNotTruthTable() {
    cout << "\nNOT Gate Truth Table\n";
    cout << "A  |  Y\n";
    cout << "------\n";

    for (int a = 0; a <= 1; ++a) {
        cout << a << "  |  " << NOTGate(a) << "\n";
    }
}

void showAllTruthTables() {
    printTwoInputTruthTable("AND", ANDGate);
    printTwoInputTruthTable("OR", ORGate);
    printNotTruthTable();
    printTwoInputTruthTable("NAND", NANDGate);
    printTwoInputTruthTable("NOR", NORGate);
    printTwoInputTruthTable("XOR", XORGate);
    printTwoInputTruthTable("XNOR", XNORGate);
}

void runQuiz() {
    cout << "\n========== LOGIC GATE QUIZ ==========\n";
    cout << "Answer each question with 0 or 1.\n";

    int score = 0;
    const int totalQuestions = 5;

    // Question 1: AND
    cout << "\n1) AND gate: A=1, B=1. Output?\n";
    int answer = readBinaryInput("Your answer: ");
    if (answer == ANDGate(1, 1)) {
        cout << "Correct!\n";
        ++score;
    } else {
        cout << "Not quite. Correct answer: " << ANDGate(1, 1) << "\n";
    }

    // Question 2: OR
    cout << "\n2) OR gate: A=0, B=1. Output?\n";
    answer = readBinaryInput("Your answer: ");
    if (answer == ORGate(0, 1)) {
        cout << "Correct!\n";
        ++score;
    } else {
        cout << "Not quite. Correct answer: " << ORGate(0, 1) << "\n";
    }

    // Question 3: NOT
    cout << "\n3) NOT gate: A=1. Output?\n";
    answer = readBinaryInput("Your answer: ");
    if (answer == NOTGate(1)) {
        cout << "Correct!\n";
        ++score;
    } else {
        cout << "Not quite. Correct answer: " << NOTGate(1) << "\n";
    }

    // Question 4: XOR
    cout << "\n4) XOR gate: A=1, B=1. Output?\n";
    answer = readBinaryInput("Your answer: ");
    if (answer == XORGate(1, 1)) {
        cout << "Correct!\n";
        ++score;
    } else {
        cout << "Not quite. Correct answer: " << XORGate(1, 1) << "\n";
    }

    // Question 5: NAND
    cout << "\n5) NAND gate: A=1, B=1. Output?\n";
    answer = readBinaryInput("Your answer: ");
    if (answer == NANDGate(1, 1)) {
        cout << "Correct!\n";
        ++score;
    } else {
        cout << "Not quite. Correct answer: " << NANDGate(1, 1) << "\n";
    }

    cout << "\nYour score: " << score << " out of " << totalQuestions << "\n";
    if (score == totalQuestions) {
        cout << "Excellent! You got every answer right.\n";
    } else if (score >= 3) {
        cout << "Good work! Review the truth tables and try again.\n";
    } else {
        cout << "Keep practising. The truth-table option can help you learn.\n";
    }
}

int main() {
    int choice;

    do {
        showGateMenu();
        choice = readInteger("Choose an option: ");

        switch (choice) {
            case 1:
                simulateTwoInputGate("AND", "Y = A . B", ANDGate);
                break;
            case 2:
                simulateTwoInputGate("OR", "Y = A + B", ORGate);
                break;
            case 3:
                simulateNotGate();
                break;
            case 4:
                simulateTwoInputGate("NAND", "Y = (A . B)'", NANDGate);
                break;
            case 5:
                simulateTwoInputGate("NOR", "Y = (A + B)'", NORGate);
                break;
            case 6:
                simulateTwoInputGate("XOR", "Y = A XOR B", XORGate);
                break;
            case 7:
                simulateTwoInputGate("XNOR", "Y = A XNOR B", XNORGate);
                break;
            case 8:
                showAllTruthTables();
                break;
            case 9:
                runQuiz();
                break;
            case 0:
                cout << "\nThank you for using Digital Logic Gate Simulator!\n";
                break;
            default:
                cout << "Invalid menu option. Please choose from 0 to 9.\n";
        }

    } while (choice != 0);

    return 0;
}
