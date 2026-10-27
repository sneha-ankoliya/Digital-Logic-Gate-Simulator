# Digital Logic Gate Simulator

## About the Project

Digital Logic Gate Simulator is a beginner-friendly C++ console application designed to help students understand digital logic gates.

The program calculates logic gate outputs, displays truth tables, and provides a quiz to practise digital logic concepts.

## Features

- AND Gate
- OR Gate
- NOT Gate
- NAND Gate
- NOR Gate
- XOR Gate
- XNOR Gate
- Truth Table Demonstration
- Interactive Logic Quiz
- Menu-Driven Console Interface

## Technologies Used

- C++
- C++17
- GCC Compiler
- Visual Studio Code

## Project Structure

```text
DigitalLogicGateSimulator/
├── main.cpp
├── README.md
└── logic_simulator.exe
```

## How to Compile

Install a C++ compiler that supports C++17.

Run the following command in your project directory:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o logic_simulator
```

## How to Run

On Windows PowerShell:

```powershell
.\logic_simulator.exe
```

On Linux or Termux:

```bash
./logic_simulator
```

## Example: AND Gate

| Input A | Input B | Output |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

The AND gate produces an output of 1 only when both inputs are 1.

## Learning Outcomes

- Understand basic Boolean logic.
- Learn how digital logic gates operate.
- Practise C++ functions, loops, and conditional statements.
- Learn to manage and publish projects using GitHub.

## Future Improvements

- Add a graphical user interface.
- Combine multiple gates to simulate circuits.
- Save quiz scores.
- Add more practice questions.

## Author

Sneha Ankolia

## Purpose

Educational project developed for learning C++ programming and Digital Logic Design.