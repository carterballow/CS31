# CS31 — Introduction to Computer Science I
**UCLA | Professor Huang | 2024–2025**

C++ projects written throughout CS31, covering core programming concepts from basic I/O to object-oriented design.

---

## Projects

### Project 1 — Poll Reporter
**Concepts:** Variables, arithmetic, conditionals, formatted output

Takes voter survey data as input and calculates the percentage of voters supporting each candidate. Includes error handling for invalid input (e.g. votes exceeding surveyed count).

---

### Project 2 — Coffee Bill Calculator
**Concepts:** Strings, chars, nested conditionals, user input validation

Simulates a coffee shop checkout. The user enters their name, number of cups, coffee type, extras, and day of the week. The program validates each input and calculates the total bill with proper formatting.

---

### Project 3 — QC String Validator
**Concepts:** String parsing, loops, `assert`, boolean logic

Implements `isValidQC()` — a function that validates whether a string follows a specific QC format (groups starting with `Q`, followed by a non-zero digit count, then `C` results). Thoroughly tested with `assert` statements.

---

### Project 4 — Array Operations
**Concepts:** Arrays, functions, function prototypes, `string` comparisons

A set of utility functions operating on `string` arrays:
- `locateMaximum` — index of the lexicographically largest element
- `countFloatingPointValues` — count of strings that represent floats
- `hasNoCapitals` — checks if no string contains an uppercase letter
- `shiftLeft` — shifts elements left by a given amount, filling with a placeholder

---

### Project 5 — Frequent Flyer Account
**Concepts:** Classes, header files, object-oriented programming, multi-file projects

Two classes working together:
- `PlaneFlight` — stores flight info (name, origin, destination, cost, mileage)
- `FrequentFlyerAccount` — tracks a passenger's mileage balance, adds flights, and determines eligibility for free flights

---

### Project 6 — Beetle Game
**Concepts:** Multi-class OOP, game logic, dice simulation, namespaces

A dice-based board game where players roll to build a beetle piece by piece. Separated across multiple classes:
- `Die` — simulates a 6-sided die roll
- `Beetle` — tracks which body parts have been added
- `BeetleGame` — enforces game rules (certain parts require others first)
- `BeetleDrawing` — handles the visual representation of the beetle

---

## Setup

All projects are written in standard C++ and can be compiled with `g++`:

```bash
g++ -o output filename.cpp
./output
```

Multi-file projects (Projects 5 & 6) require compiling all `.cpp` files together:

```bash
g++ -o output *.cpp
./output
```

Project 6 includes a Visual Studio `.vcxproj` file for building in VS2022.
