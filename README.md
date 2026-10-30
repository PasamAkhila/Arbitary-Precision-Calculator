# Arbitrary Precision Calculator (APC)

## Project Description

The Arbitrary Precision Calculator is a C-based application designed to perform arithmetic operations on large numbers that exceed the storage limits of standard C data types.

It uses a Doubly Linked List to store and process individual digits, enabling arithmetic operations on numbers of arbitrary length.

## Features

- Addition of large numbers
- Subtraction of large numbers
- Multiplication of large numbers
- Division of large numbers
- Supports numbers beyond standard integer limits
- Uses dynamic memory allocation

## Technologies Used

- Programming Language: C
- Data Structure: Doubly Linked List
- Concepts: Pointers, Dynamic Memory Allocation, Structures and Modular Programming

## Data Structure Used

A Doubly Linked List is used to store each digit of the input numbers in separate nodes. This allows efficient traversal and processing of large numbers during arithmetic operations.

## Operations Supported

| Operation | Description |
|---|---|
| Addition (+) | Adds two large numbers |
| Subtraction (-) | Subtracts one large number from another |
| Multiplication (*) | Multiplies two large numbers |
| Division (/) | Divides two large numbers |

## How to Compile and Run

### 1. Clone the Repository

```bash
git clone https://github.com/PasamAkhila/Arbitary-Precision-Calculator.git
```

### 2. Navigate to the Project Directory

```bash
cd Arbitary-Precision-Calculator
```

### 3. Compile the Source Files

```bash
gcc main.c dll.c functions.c operations.c -o apc
```

### 4. Run the Executable

```bash
./apc
```

## Learning Outcomes

- Improved understanding of Doubly Linked Lists.
- Practical implementation of pointers and dynamic memory allocation.
- Developed logic for arithmetic operations on large numbers.
- Improved problem-solving and modular programming skills.

## Author

**Pasam Akhila**

B.Tech – Electronics and Communication Engineering
