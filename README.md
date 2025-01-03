<h1 align="center">
	<img src="https://github.com/lkilpela/42-project-badges/blob/main/badges/push_swape.png" />
</h1>

<p align="center">
	<b><i>Data Sorting Using Two Stacks in C.</i></b><br>
</p>

<p align="center">
    <img alt="score" src="https://img.shields.io/badge/score-97%2F100-brightgreen" />
<p align="center">
    <img alt="solo" src="https://img.shields.io/badge/solo-yellow" />
    <img alt="estimated time" src="https://img.shields.io/badge/estimation-60%20hours-blue" />
    <img alt="XP earned" src="https://img.shields.io/badge/XP-1855-orange" />
<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/lkilpela/push_swap?color=lightblue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/lkilpela/push_swap?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/lkilpela/push_swap?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/lkilpela/push_swap?color=green" />
</p>

## 🎮 About The Project

`push_swap` is a coding project part of the Hive Helsinki curriculum. The goal of this project is to sort data on a stack, with a limited set of operations, in the smallest number of moves possible.

In this project, the program takes a list of integers as arguments and outputs a series of operations that sort the list. The operations are limited to a specific set and the goal is to find the most efficient way to sort the list.

This project was completed as a **solo project**. It provided an opportunity to learn about data structures (specifically stacks), sorting algorithms, and algorithm optimization.

### ⭐ Features

- Efficient sorting of a stack of integers
- Limited set of operations: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`
- Visualizer to see the sorting in action
- Checker program to verify the correctness of the sort

## 🏁 Getting Started

### Prerequisites

- `gcc` or `clang`
- `make`

### 🛠️ Installation & Setup

1. Clone the repository: `git clone https://github.com/username/push_swap.git`
2. Navigate into the project directory: `cd push_swap`
3. Compile the project: `make`

### Tester

https://github.com/Tempest989/42_Push_Swap_Tester

### Visualizer

```
git clone https://github.com/ailopez-o/42Barcelona-PushSwap-ProChecker
```

### 🕹️ How it works

- The program takes as an argument a stack of integers (duplicates not allowed).
- The program outputs a list of operations that sort the stack, each operation followed by a newline.
- The checker program takes as an argument the same stack of integers and reads instructions on the standard output. Once read, checker executes them and displays `OK` if integers are sorted. Otherwise, it will display `KO`.

```
# To compile
make

# To run push_swap
./push_swap 3 2 1 6 5 8

# To run checker
./checker 3 2 1 6 5 8

This will sort the numbers and display the operations used to sort them.
```

## 📝 Evaluation Requirements

The `push_swap` project was evaluated based on the following criteria:

1. **Functionality**: The program must correctly sort a stack of integers using a second stack and a limited set of operations. The output should be the operations used to sort the list.

2. **Efficiency**: The solution should aim for the smallest number of operations. The efficiency of your algorithm will be tested against a set of random inputs.

3. **Error Handling**: The program must handle errors gracefully and provide appropriate error messages. This includes handling invalid arguments and incorrect number of arguments.

4. **Code Quality**: The code must be clear, concise, and efficient. It should be well-organized and easy to read. Proper use of functions, variables, and other programming constructs is expected.

5. **Compiling**: The project must compile without any errors or warnings using the provided Makefile.

6. **Memory Management**: The program must manage memory correctly, with no memory leaks.

### 🧑‍💻 Peer Evaluations (3/3)

Here are some of the comments received during the peer evaluation of the `pipex` project:

> **Peer 1**: "Very good work, code is well documented and relatively easy to understand. Everything works well with no leaks. Congrats!"

> **Peer 2**: "very nice project, a lot simpler than mine, wish I had come up with something as clean and simple, everything worked as intended and good luck."

> **Peer 3**: "This was an interesting perspective using arrays, it was clean looking code and also well organised directories, although perhaps a few less directories would be better ..maybe?. The explanation was clear and thorough, no leaks all outliers i could think of acted as they where supposed to! well done great job, thankyou for the pleasant company !"

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](https://github.com/lkilpela/so_long/blob/main/docs/LICENSE) file for details.

