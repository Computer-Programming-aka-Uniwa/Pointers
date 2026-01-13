<p align="center">
  <img src="https://www.especial.gr/wp-content/uploads/2019/03/panepisthmio-dut-attikhs.png" alt="UNIWA" width="150"/>
</p>

<p align="center">
  <strong>UNIVERSITY OF WEST ATTICA</strong><br>
  SCHOOL OF ENGINEERING<br>
  DEPARTMENT OF COMPUTER ENGINEERING AND INFORMATICS
</p>

---

<p align="center">
  <strong>Computer Programming</strong>
</p>

<h1 align="center">
  Arrays, Pointers, Files
</h1>

<p align="center">
  <strong>Vasileios Evangelos Athanasiou</strong><br>
  Student ID: 19390005
</p>

<p align="center">
  <a href="https://github.com/Ath21" target="_blank">GitHub</a> ·
  <a href="https://www.linkedin.com/in/vasilis-athanasiou-7036b53a4/" target="_blank">LinkedIn</a>
</p>

<p align="center">
  Supervisor: Georgios Meletiou, Laboratory Teaching Staff<br>
</p>

<p align="center">
  <a href="https://ice.uniwa.gr/en/emd_person/georgios-meletiou/" target="_blank">UNIWA Profile</a>
</p>

<p align="center">
  Athens, January 2022
</p>

---

# Project Overview

The primary goal of the application is to process a set of numbers and generate all possible combinations of six numbers that satisfy specific user-defined constraints regarding the count of even numbers and the total sum of the combination.

---

## Table of Contents


| Section | Folder / File | Description |
|------:|---------------|-------------|
| 1 | `assign/` | Assignment material |
| 1.1 | `assign/project6_1.png` | Assignment 1 description (English) |
| 1.2 | `assign/project6_2.png` | Assignment 2 description (English) |
| 1.3 | `assign/εργασία6_1.png` | Assignment 1 description (Greek) |
| 1.4 | `assign/εργασία6_2.png` | Assignment 2 description (Greek) |
| 2 | `docs/` | Theoretical documentation |
| 2.1 | `docs/Arrays-Pointers-Files.pdf` | Arrays, pointers, and file handling (English) |
| 2.2 | `docs/Πίνακες-Δείκτες-Αρχεία.pdf` | Arrays, pointers, and file handling (Greek) |
| 3 | `src/` | Source code implementations |
| 3.1 | `src/Combinations.c` | Example using pointers and arrays for combinations |
| 4 | `README.md` | Repository overview and instructions |

---


## 1. Combinations.c

The **Combinations.c** program includes the following core functionalities:

### Dynamic Data Input
- Reads a set of **N numbers** (where 6 < N ≤ 49).  
- Ensures numbers fall within the valid range **[1,49]**.  

### Constraint Setting
- Users can define filtering intervals for combinations:  
  - **Even Numbers:** Interval `[X1,X2]` for allowed number of even digits.  
  - **Sum Range:** Interval `[Y1,Y2]` for the allowed total sum.  

### Memory Management
- Uses **dynamic memory allocation** (`malloc`, `calloc`) for all major data structures.  
- Includes safety checks to verify successful memory binding.  

### Data Processing
- Sorts input numbers in ascending order before generating combinations.  
- Calculates **frequency of occurrence** for each number in the filtered list.  
- Reports **statistics** on how many combinations were filtered out by each condition.  

---

## Program Structure

The program is **modular**, consisting of specialized functions:

- `Read_N_Numbers()`: Handles input for the total count of numbers.  
- `Read_Matrix()`: Populates a dynamically allocated array with the user's numbers.  
- `Combos()`: Core logic engine that generates combinations and applies filters.  
- `Search_Evens()` & `Search_Sum()`: Validate the defined constraints.  
- `Frequency()`: Tracks how often numbers appear in valid combinations.  
- `Free_Memory()`: Frees all dynamically allocated memory upon completion.  

---

## Technical Specifications

- **Language:** C  
- **Libraries:** `stdio.h` (I/O operations), `stdlib.h` (memory management)  
- **Data Structures:** Dynamically allocated one-dimensional arrays (pointers)  

---

## Example Usage

If a user inputs **8 numbers**:  
```bash
2, 6, 7, 12, 21, 32, 43, 45
```
and sets:

- **Even number limit:** 2 to 4  
- **Sum limit:** 21 to 141  

the program will:

1. Generate 28 total combinations.  
2. Filter combinations based on the constraints.  
3. Print the valid combinations and their frequency of occurrence.  

---

# Installation & Setup Guide

This repository contains **introductory laboratory material** for the  
**Computer Programming** course at the **University of West Attica (UNIWA)**.

---

## Prerequisites

### Required Software

- **C Compiler**
  - Recommended:
    - **GCC** (Linux / macOS / Windows via MinGW or WSL)

- **Text Editor or IDE**
  - Visual Studio Code `(Recommended)`
  - Code::Blocks
  - Dev-C++
  - CLion
  - Any plain text editor

### Supported Operating Systems
- Windows
- Linux `(Recommended)`
- macOS

---

## Installation

### 1. Clone the Repository

Clone the repository to your local machine:

```bash
git clone https://github.com/Computer-Programming-aka-Uniwa/Pointers.git
```

#### Alternative (Without Git)

- Open the repository URL in your browser
- Click Code → Download ZIP
- Extract the ZIP file to a local directory

## Compiling & Running the Programs
### 2. Navigate to Source Directory
```bash
cd Pointers/src
```

### 3. Compile the Programs
```bash
gcc Combinations.c -o Combinations
```

### 4. Run the Programs
Linux / macOS
```bash
./Combinations
```
Windows
```bash
Combinations.exe
```

---

## Open the Documentation
1. Navigate to the `docs/` directory
2. Open the report corresponding to your preferred language:
    - English: `Arrays-Pointers-Files.pdf`
    - Greek: `Πίνακες-Δείκτες-Αρχεία.pdf`