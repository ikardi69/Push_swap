<h1 align="center">push\_swap</h1>

<p align="center">
  <h1>📌 Overview</h1>
</p>

**push\_swap** is a 42 school algorithmic project where the goal is to sort a stack of integers with the **least number of operations** using a restricted set of stack-based instructions.

This implementation includes:

* An optimized sorting algorithm using **chunk-based sorting**
* A complete bonus implementation of the **checker** program

<p align="center">
  <h1>🧠 Project Purpose</h1>
</p>

This project is designed to:

* Develop efficient sorting algorithms in C
* Understand algorithmic complexity
* Practice memory management and input parsing
* Optimize for minimal operation counts under strict constraints

<p align="center">
  <h1>📦 Features</h1>
</p>

* **Sorting Algorithm**: Uses a chunking strategy to split data into manageable segments for optimized sorting.
* **Instruction Set**: Implements `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, and `rrr` operations.
* **Error Handling**: Robust handling for invalid inputs (duplicates, non-integers, overflows).
* **Bonus `checker`**: A second program to verify if the output instructions actually sort the stack correctly.
* **Makefile**: Includes mandatory rules `all`, `clean`, `fclean`, `re`, and `bonus`.

<p align="center">
  <h1>🛠️ How It Works</h1>
</p>

You provide a list of integers to the `push_swap` program:

```bash
$> ./push_swap 4 2 3 1
pb
pb
sa
pa
pa
```

You can validate the result using your bonus `checker`:

```bash
$> ./push_swap 3 2 1 | ./checker 3 2 1
OK
```

<p align="center">
  <h1>🚀 Performance</h1>
</p>

This implementation satisfies the official benchmark requirements:

* ≤ 700 instructions for 100 numbers
* ≤ 5500 instructions for 500 numbers

<p align="center">
  <h1>📁 Project Structure</h1>
</p>

```
.
├── Makefile
├── push_swap.c         # Main sorting logic
├── checker_bonus.c     # Bonus checker program
├── stack_utils.c       # Stack operations
├── parse.c             # Input parsing and validation
├── algo_chunks.c       # Chunking algorithm implementation
├── libft/              # Custom libft library
└── includes/
    └── push_swap.h     # Header files
```

<p align="center">
  <h1>✅ Instructions</h1>
</p>

Compile:

```bash
make
```

Run `push_swap`:

```bash
./push_swap 5 2 3 1 4
```

Run `checker` (bonus):

```bash
./push_swap 3 2 1 | ./checker 3 2 1
```

Clean:

```bash
make clean
make fclean
```

<p align="center">
  <h1>📚 Resources</h1>
</p>

* [Stack Data Structure (Wikipedia)](https://en.wikipedia.org/wiki/Stack_%28abstract_data_type%29)
* [42 Project Spec](https://projects.intra.42.fr/projects/push_swap)

<p align="center">
  <h1>🏁 Bonus Features</h1>
</p>

* Fully functioning `checker` program
* Handles both standard and erroneous input streams
* Written in compliance with the 42 Norm
