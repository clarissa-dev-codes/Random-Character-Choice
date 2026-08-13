# Random Character Selector

A lightweight, console-based C++ application that manages a persistent list of character names using a text file. It allows users to dynamically add names, delete names, and pick a random "Chosen One" from the pool.

## 🚀 Features

- **Persistent Storage:** Automatically reads from and writes to a text file (`characters.txt`).
- **Random Selection:** Uses time-seeded randomization to ensure a unique choice every time.
- **Dynamic List Management:** Easily add or remove names directly through the console menu.

## 🛠️ How to Run

### Prerequisites
You need a C++ compiler (like `g++`) installed on your system.

### Compilation
Open your terminal or command prompt and run:
```bash
g++ -o character_selector main.cpp
```

### Execution
Run the compiled executable:
```bash
# On Linux/macOS
./character_selector

# On Windows
character_selector.exe
```

## 📂 File Structure

- `main.cpp` - The core application source code.
- `characters.txt` - The automatically generated text file where character names are saved (one name per line).

## 📝 License
This project is open-source and free to use.
