# Transaction Manager

A simple C++ program for managing personal finances – adding, viewing, and summarizing transactions.

---

## Features

1. **Add Transaction**  
   - Enter a title, value (income or expense), and date in `dd-mm-yyyy` format.  
   - The program validates the date format.

2. **View Transactions**  
   - Filter options:  
     1. Income  
     2. Expenses  
     3. All transactions

3. **Summary**  
   - Shows total income, total expenses, and overall balance.

---

## Date Format

- The date must be in `dd-mm-yyyy` format  
- Example: `12-09-2025`  


---

## How to Run

1. Compile the program:

```bash
g++ main.cpp -o transaction_manager