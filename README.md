# c-programming

C programming done for my computer architecture course (CS211) at Rutgers.

### Data Structures

Implemented linked list, hash table, binary search trees in C.

### One Shot Learning

Used linear algebra to train an algorithm with data about house attributes and prices.
Calculated weight of each attribute (year built, etc.) on the house price using linear algebra.
Predicted prices of houses based on those weights for house with specific attributes.

### Bit Operations

#### First

- Set the nth value of a function
- Set the value of the nth bit of a number to its complement
- Return the value of the nth bit of a number

#### Second

- Return parity of a number

#### Third

- Return whether a bit string is a palindrome

### Assembly Interpreter

- Interpreter for a custom version of Assembly written in C.
- There are 4 general purpose regiters: ax, bx, cx, dx
- The following functions are implemented:

#### Arithmetic Instructions

| Instruction | Args | Description                                           |
|-------------|------|-------------------------------------------------------|
| add         | x y  | Add x and y, place result in y                        |
| sub         | x y  | Subtract x and y, place result in y                   |
| mul         | x y  | Multiply x and y, place result in y                   |
| div         | x y  | Divide x by y, place result in y (discard remainders) |

- Note: y must be a register