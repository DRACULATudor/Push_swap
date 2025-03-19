# Push_swap Overview

## Introduction

The **Push_swap** project is designed to improve your algorithmic thinking and mastery of stack operations. The goal is to sort a stack of numbers using a limited set of operations in as few moves as possible. This project requires implementing efficient sorting algorithms while minimizing the number of operations used.

Unlike traditional sorting problems, **Push_swap** requires you to work with two stacks (`stack A` and `stack B`) and use a predefined set of operations to move numbers between them and sort them correctly. This constraint forces you to develop an efficient sorting strategy, making it a great exercise in algorithm optimization.

The main objectives of **Push_swap** are:
- Implementing efficient sorting algorithms using stack-based operations.
- Minimizing the number of moves required to sort the stack.
- Understanding and applying algorithm complexity optimizations.
- Managing memory properly and ensuring robust error handling.

---

## Compilation

```
make
```
Or, if there is no Makefile:
```
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program
```
Run the program:
```
./exec_name(check Makefile) [numbers which you want to sort ex: 5 2 1 70 80 65]

```
Rules:
```
If the stack is sorted than nothing will happen
If there are duplicates execution ends and you get an error message
If the argument/arguments number or format is wrong than you get an error message
```
## Topics Covered

### 1. **Stack Data Structure**
   - Understanding how stacks work (LIFO - Last In, First Out).
   - Implementing push, pop, swap, and rotate operations.
   - Handling stack operations efficiently.

### 2. **Sorting Algorithms**
   - **Simple Sorting (for small stacks)**:
     - Implementing a brute-force approach for very small inputs (e.g., 3 or 5 numbers).
   - **Efficient Sorting (for larger stacks)**:
     - Implementing sorting strategies such as **quick sort**, **merge sort**, or **radix sort** adapted to stack operations.

### 3. **Push_swap Operations**
   - **sa (swap a)** / **sb (swap b)** / **ss (swap a & b)** → Swapping the top two elements.
   - **pa (push a)** / **pb (push b)** → Moving elements between stacks.
   - **ra (rotate a)** / **rb (rotate b)** / **rr (rotate a & b)** → Rotating the stack upwards.
   - **rra (reverse rotate a)** / **rrb (reverse rotate b)** / **rrr (reverse rotate a & b)** → Rotating the stack downwards.

### 4. **Algorithm Optimization**
   - Minimizing the number of operations to achieve an optimal sort.
   - Using an efficient approach such as:
     - **Chunking**: Dividing the input into smaller parts for better management.
     - **Greedy algorithm**: Choosing the best immediate move to optimize later moves.
     - **Binary representation (Radix sort approach)** for large sets.

### 5. **Complexity Analysis**
   - Understanding time complexity (Big-O notation).
   - Comparing different sorting approaches and their efficiency in the given constraints.

### 6. **Error Handling and Input Validation**
   - Checking for invalid inputs (e.g., non-numeric values, duplicates).
   - Handling memory allocation failures.
   - Ensuring the program does not crash due to incorrect input.

---

## Why Is This Important?

Sorting is one of the most fundamental problems in computer science, and **Push_swap** teaches you how to:
- Implement efficient sorting algorithms in constrained environments.
- Work with stacks and understand how to manipulate them efficiently.
- Write optimized code with a focus on minimizing operations.
- Analyze algorithm complexity and improve performance.

---

## Conclusion

The **Push_swap** project is an excellent challenge that enhances your algorithmic skills and understanding of stack operations. It forces you to think about optimization, efficiency, and sorting strategies in a constrained environment. By mastering this project, you'll develop a deeper understanding of algorithm design and memory management while improving your problem-solving skills.
