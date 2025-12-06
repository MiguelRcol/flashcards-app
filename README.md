# Flashcards Language App

A simple command-line flashcards app written in C to practice vocabulary in English, Portuguese, and Spanish.

This project is part of my learning journey in C, Git, and general software engineering: it uses structs, arrays, functions, basic file I/O (binary), and a small quiz mode.

---

## Features

- ✅ Add new flashcards (word, translation, language code: `EN` / `PT` / `ES`)
- ✅ List all stored flashcards
- ✅ Quiz mode:
  - Picks a random flashcard
  - Asks for the translation
  - Checks your answer and shows the correct one
- ✅ Persistent storage:
  - Saves flashcards to a binary file (`flashcards.dat`)
  - Automatically loads existing flashcards on startup

---

## Requirements

- C compiler (tested with `gcc`)
- Make (optional, if you want to use the provided `Makefile`)

---

## Build and Run

### Using `make` (recommended)

```bash
make        # builds the 'flashcards' executable
./flashcards
