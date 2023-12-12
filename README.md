<div align="center">
<h1 align="center">
<img src="https://github.com/byaliego/42-project-badges/blob/main/badges/get_next_linem.png" width="150" />
<br>GET_NEXT_LINE</h1>
<h3>◦ Reading a line from fd is way too tedious</h3>

<p align="center">
<img src="https://img.shields.io/badge/Barcelona-100000?style=flat-square&logo=42&logoColor=white&labelColor=000000&color=000000" alt="42 Barcelona" />
<img src="https://img.shields.io/github/actions/workflow/status/San-tito/get_next_line/c.yml?style=flat-square" alt="GitHub%20Actions" />
</p>
<img src="https://img.shields.io/github/license/San-tito/get_next_line?style=flat-square" alt="GitHub license" />
<img src="https://img.shields.io/github/languages/code-size/San-tito/get_next_line?style=flat-square" alt="GitHub code size" />
<img src="https://img.shields.io/github/languages/top/San-tito/get_next_line?style=flat-square" alt="GitHub top language" />
</div>

---

## 📖 Table of Contents
- [📖 Table of Contents](#-table-of-contents)
- [📍 Overview](#-overview)
- [📦 Features](#-features)
- [📂 repository Structure](#-repository-structure)
- [⚙️ Modules](#modules)
- [🚀 Getting Started](#-getting-started)
    - [🔧 Installation](#-installation)
    - [🤖 Running get_next_line](#-running-get_next_line)
    - [🧪 Tests](#-tests)
- [🛣 Roadmap](#-roadmap)
- [🤝 Contributing](#-contributing)
- [📄 License](#-license)
- [👏 Acknowledgments](#-acknowledgments)

---


## 📍 Overview

This project is about programming a function that returns a line
read from a file descriptor.

---

## 📦 Features

HTTPStatus Exception: 429

---


## 📂 Repository Structure

```sh
└── get_next_line/
    ├── get_next_line.c
    ├── get_next_line.h
    ├── get_next_line_bonus.c
    ├── get_next_line_bonus.h
    ├── get_next_line_utils.c
    └── get_next_line_utils_bonus.c

```

---


## ⚙️ Modules

<details closed><summary>Root</summary>

| File                                                                                                           | Summary                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
| ---                                                                                                            | ---                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| [get_next_line_utils_bonus.c](https://github.com/San-tito/get_next_line/blob/main/get_next_line_utils_bonus.c) | HTTPStatus Exception: 429                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| [get_next_line_utils.c](https://github.com/San-tito/get_next_line/blob/main/get_next_line_utils.c)             | The code in `get_next_line_utils.c` is part of a larger project directory called `get_next_line`. This specific file contains utility functions that are used in the implementation of the `get_next_line` function.The `check_for_newline` function checks if there is a newline character within the content of a linked list node. If there is, it returns 1, indicating that a line has been found. Otherwise, it returns 0.The `last_node` function returns a pointer to the last node in a linked list.The `add_node` function adds a new node to the end of a linked list, with the provided content.The `length_until_newline` function calculates the length of the content in a linked list until the first occurrence of a newline character.The `clear_nodes` function frees the memory allocated for the nodes in a linked list, including their content. |
| [get_next_line_bonus.h](https://github.com/San-tito/get_next_line/blob/main/get_next_line_bonus.h)             | The code provided is the header file get_next_line_bonus.h for a program that reads from a file and returns a line at a time. It includes necessary libraries and defines a struct and function prototypes. The struct t_list is used to store the content of each line and a pointer to the next line. The function prototypes define the operations to read and create lines, get a line from the list, extract any remaining content, check for a newline character, find the last node, add a new node, get the length until a newline, and clear the nodes.                                                                                                                                                                                                                                                                                                       |
| [get_next_line_bonus.c](https://github.com/San-tito/get_next_line/blob/main/get_next_line_bonus.c)             | HTTPStatus Exception: 429                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| [get_next_line.h](https://github.com/San-tito/get_next_line/blob/main/get_next_line.h)                         | The code provided is the header file get_next_line.h for a function called get_next_line. It includes necessary headers and defines a struct, t_list, which represents a linked list node. The function get_next_line reads from a file descriptor and returns the next line of text from it. Other functions in the header file are used to manipulate and manage the linked list.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| [get_next_line.c](https://github.com/San-tito/get_next_line/blob/main/get_next_line.c)                         | HTTPStatus Exception: 429                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |

</details>

---

## 🚀 Getting Started

***Dependencies***

Please ensure you have the following dependencies installed on your system:

`- ℹ️ Dependency 1`

`- ℹ️ Dependency 2`

`- ℹ️ ...`

### 🔧 Installation

1. Clone the get_next_line repository:
```sh
git clone https://github.com/San-tito/get_next_line
```

2. Change to the project directory:
```sh
cd get_next_line
```

3. Compile the dependencies:
```sh
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line*.c -o gnl
```

### 🤖 Running get_next_line

```sh
./gnl file.txt
```

### 🧪 Tests
```sh
/* No common unit test framework in C */
```

---


## 🛣 Project Roadmap

> - [X] `ℹ️  Task 1: Implement handling of multiple file descriptors at the same time`
> - [ ] `ℹ️  Task 2: Implement tests`
> - [ ] `ℹ️ ...`


---

## 🤝 Contributing

Contributions are welcome! Here are several ways you can contribute:

- **[Submit Pull Requests](https://github.com/San-tito/get_next_line/blob/main/CONTRIBUTING.md)**: Review open PRs, and submit your own PRs.
- **[Join the Discussions](https://github.com/San-tito/get_next_line/discussions)**: Share your insights, provide feedback, or ask questions.
- **[Report Issues](https://github.com/San-tito/get_next_line/issues)**: Submit bugs found or log feature requests for SAN-TITO.

---

## 📄 License


This project is protected under the [LICENSE](https://choosealicense.com/licenses) License. For more details, refer to the [LICENSE](https://choosealicense.com/licenses/) file.

---

## 👏 Acknowledgments

- [Master File I/O Operations](https://medium.com/p/5fb001d1fff5)
- [get_next_line explained: develop a function that reads a file line by line](https://www.youtube.com/watch?v=8E9siq7apUU)
- [gnlTester](https://github.com/Tripouille/gnlTester)

[**Return**](#Top)

---

