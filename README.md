![Flag](https://upload.wikimedia.org/wikipedia/commons/thumb/a/a5/Flag_of_the_United_Kingdom_%281-2%29.svg/255px-Flag_of_the_United_Kingdom_%281-2%29.svg.png)

# Pointers in C Programming

For the requested Assignment, click the link:
[Assignment](Assignment/)

For the Source Code, click the link:
[Code](Code/)

For the detailed Documentation, click the link:
[Documentation](Documentation/)

## Overview

This repository contains a C program that demonstrates the use of pointers in various functions. Pointers are a fundamental concept in C that allow developers to directly manipulate memory addresses, leading to efficient memory management and data handling. This program includes features for user input, dynamic memory allocation, and various operations involving arrays and matrices.

---

## Course Information
- **Course**: [Computer Programming](https://ice.uniwa.gr/education/undergraduate/courses/computer-programming/)
- **Semester**: 1
- **Program**: [UNIWA](https://www.uniwa.gr/)
- **Department**: [Informatics and Computer Engineering](https://ice.uniwa.gr/)
- **Instructor**: [Georgios Meletiou](https://ice.uniwa.gr/emd_person/17562/)

## Student Information
- **Name**: Athanasiou Vasileios Evangelos
- **Student ID**: ice19390005
- **Status**: Undergraduate

---

## Key Concepts Covered

### 1. **Dynamic Memory Allocation**
- The program utilizes `malloc` and `calloc` functions to dynamically allocate memory for arrays based on user input. This allows for flexibility in handling different sizes of data structures without knowing their size at compile time.

### 2. **Function Pointers**
- The program demonstrates how pointers can be used to pass data between functions, allowing for more modular code. Functions are defined to handle specific tasks, and pointers are used to manipulate data within these functions.

### 3. **Array Manipulation**
- Pointers provide a way to iterate over arrays and access elements using pointer arithmetic. This can improve performance and readability in operations that require accessing array elements.

### 4. **Passing by Reference**
- By using pointers, the program allows functions to modify variables defined in other functions. This is particularly useful for returning multiple values or when a function needs to alter the state of its arguments.

---

## Functions in the Program

### Key Functions:
- **`Read_N_Numbers(int, int)`**: Prompts the user to input the number of integers within a specified range and returns the count.
- **`Read_Matrix(int *, int)`**: Reads integers into a dynamically allocated array, ensuring no duplicates.
- **`Check_Memory(int *)`**: Validates dynamic memory allocations.
- **`Sort(int *, int)`**: Sorts an array of integers in ascending order using pointers.
- **`Combos(int *, int, int *, int *)`**: Generates combinations of numbers and performs operations based on user-defined limits.

### Example Use Cases:
- Calculating the frequency of numbers in generated combinations.
- Searching for specific conditions within arrays using pointer-based logic.

---

## Requirements

- **C Compiler**: GCC or any standard C compiler.
- **Operating System**: Linux/Windows/MacOS.
- **Development Environment**: Command Line or IDE.

---

## Installation and Usage

### 1. Clone the Repository
```bash
git clone https://github.com/Computer-Programming-aka-Uniwa/Pointers.git
cd Pointers
```
### 2. Compile
```bash
gcc -o Combinations Combinations.c
```

### 3. Run
```bash
./Combinations
```


![Flag](https://upload.wikimedia.org/wikipedia/commons/thumb/5/5c/Flag_of_Greece.svg/255px-Flag_of_Greece.svg.png)

# Δείκτες στη Γλώσσα Προγραμματισμού C

Για την απαιτούμενη εργασία, κάντε κλικ στον σύνδεσμο:
[Εργασία](Assignment/)

Για τον Πηγαίο Κώδικα, κάντε κλικ στον σύνδεσμο:
[Κώδικας](Code/)

Για την λεπτομερή Τεκμηρίωση, κάντε κλικ στον σύνδεσμο:
[Τεκμηρίωση](Documentation/)

## Επισκόπηση

Αυτό το αποθετήριο περιέχει ένα πρόγραμμα σε C που демонстрации τη χρήση δεικτών σε διάφορες συναρτήσεις. Οι δείκτες είναι μια θεμελιώδης έννοια στη C που επιτρέπει στους προγραμματιστές να χειρίζονται άμεσα διευθύνσεις μνήμης, οδηγώντας σε αποτελεσματική διαχείριση μνήμης και χειρισμό δεδομένων. Αυτό το πρόγραμμα περιλαμβάνει δυνατότητες για είσοδο χρηστών, δυναμική δέσμευση μνήμης και διάφορες λειτουργίες που σχετίζονται με πίνακες και μήτρες.

---

## Πληροφορίες Μαθήματος
- **Μάθημα**: Προγραμματισμός Υπολογιστών
- **Εξάμηνο**: 1
- **Πρόγραμμα Σπουδών**: [ΠΑΔΑ](https://www.uniwa.gr/)
- **Τμήμα**: [Μηχανικών Πληροφορικής και Υπολογιστών](https://ice.uniwa.gr/)
- **Διδάσκων**: [Γεώργιος Μελετίου](https://ice.uniwa.gr/emd_person/17562/)

## Πληροφορίες Φοιτητή
- **Όνομα**: Αθανασίου Βασίλειος Ευάγγελος
- **Αριθμός Μητρώου**: ice19390005
- **Κατάσταση**: Προπτυχιακός

---

## Βασικές Έννοιες που Καλύπτονται

### 1. **Δυναμική Δέσμευση Μνήμης**
- Το πρόγραμμα χρησιμοποιεί τις συναρτήσεις `malloc` και `calloc` για να δεσμεύσει δυναμικά μνήμη για πίνακες με βάση την είσοδο του χρήστη. Αυτό επιτρέπει ευελιξία στη διαχείριση διαφορετικών μεγεθών δομών δεδομένων χωρίς να γνωρίζουμε το μέγεθός τους κατά τη διάρκεια της εκτέλεσης.

### 2. **Δείκτες Συναρτήσεων**
- Το πρόγραμμα демонстрации πώς οι δείκτες μπορούν να χρησιμοποιηθούν για να περάσουν δεδομένα μεταξύ συναρτήσεων, επιτρέποντας περισσότερο αρθρωτό κώδικα. Οι συναρτήσεις ορίζονται για να χειρίζονται συγκεκριμένα καθήκοντα και οι δείκτες χρησιμοποιούνται για να χειρίζονται τα δεδομένα μέσα σε αυτές τις συναρτήσεις.

### 3. **Χειρισμός Πινάκων**
- Οι δείκτες παρέχουν έναν τρόπο να επαναλαμβάνουμε πάνω από πίνακες και να αποκτούμε πρόσβαση σε στοιχεία χρησιμοποιώντας αριθμητική δείκτη. Αυτό μπορεί να βελτιώσει την απόδοση και την αναγνωσιμότητα σε λειτουργίες που απαιτούν πρόσβαση σε στοιχεία πίνακα.

### 4. **Πέρασμα από Αναφορά**
- Χρησιμοποιώντας δείκτες, το πρόγραμμα επιτρέπει στις συναρτήσεις να τροποποιούν μεταβλητές που έχουν οριστεί σε άλλες συναρτήσεις. Αυτό είναι ιδιαίτερα χρήσιμο για την επιστροφή πολλών τιμών ή όταν μια συνάρτηση χρειάζεται να αλλάξει την κατάσταση των επιχειρημάτων της.

---

## Συναρτήσεις στο Πρόγραμμα

### Βασικές Συναρτήσεις:
- **`Read_N_Numbers(int, int)`**: Ζητά από το χρήστη να εισάγει τον αριθμό των ακέραιων μέσα σε μια καθορισμένη περιοχή και επιστρέφει τον αριθμό.
- **`Read_Matrix(int *, int)`**: Διαβάζει ακέραιους σε ένα δυναμικά δεσμευμένο πίνακα, διασφαλίζοντας ότι δεν υπάρχουν διπλότυποι.
- **`Check_Memory(int *)`**: Επικυρώνει τις δυναμικές δεσμεύσεις μνήμης.
- **`Sort(int *, int)`**: Ταξινομεί έναν πίνακα ακέραιων αριθμών σε αύξουσα σειρά χρησιμοποιώντας δείκτες.
- **`Combos(int *, int, int *, int *)`**: Δημιουργεί συνδυασμούς αριθμών και εκτελεί λειτουργίες βάσει καθορισμένων ορίων από το χρήστη.

### Παραδείγματα Χρήσης:
- Υπολογισμός της συχνότητας εμφάνισης αριθμών σε παραγόμενους συνδυασμούς.
- Αναζήτηση συγκεκριμένων συνθηκών μέσα σε πίνακες χρησιμοποιώντας λογική βασισμένη σε δείκτες.

---

## Απαιτήσεις

- **Μεταγλωττιστής C**: GCC ή οποιοσδήποτε συμβατικός μεταγλωττιστής C.
- **Λειτουργικό Σύστημα**: Linux/Windows/MacOS.
- **Περιβάλλον Ανάπτυξης**: Γραμμή εντολών ή IDE.

---

## Εγκατάσταση και Χρήση

### 1. Κλωνοποιήστε το Αποθετήριο
```bash
git clone https://github.com/Computer-Programming-aka-Uniwa/Pointers.git
cd Pointers
```

### 2. Μεταγλώττιση
```bash
gcc -o Combinations Combinations.c
```

### 3. Εκτέλεση
```bash
./Combinations
```
