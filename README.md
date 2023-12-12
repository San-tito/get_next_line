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

The `get_next_line` project is a programming exercise that challenges you to implement a function capable of reading a line from a file descriptor. The primary goal is to develop a function that allows reading from a file descriptor efficiently, providing a line-by-line extraction from the given input. This project introduces the concept of static variables and encourages a deeper understanding of memory management and file I/O in the C programming language.

---

## 📦 Features

- **Prototype:** `char *get_next_line(int fd);`
- **Parameters:**
  - 📁 `fd`: The file descriptor to read from.
- **Return value:**
  - 📜 Read line: Returns the next line from the specified file descriptor.
  - `🚫 NULL`: Indicates there is nothing else to read or an error occurred.
- **External functions:** `📖 read`, `🛠️ malloc`, `🗑️ free`
- **Description:** Writes a function that reads from a file descriptor (`fd`) and returns the next line of text.

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

<details closed><summary>Mandatory</summary>

| File                                                                                                           | Summary                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
| ---                                                                                                            | ---                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| [get_next_line.c](https://github.com/San-tito/get_next_line/blob/main/get_next_line.c)                         | Implements the core functionality of `get_next_line`. Reads a line from the given file descriptor and manages the linked list operations to handle line reading. It uses utility functions to efficiently handle dynamic memory allocation, buffer reading, and linked list manipulation. The function provides an interface for retrieving the next line from a file.                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [get_next_line_utils.c](https://github.com/San-tito/get_next_line/blob/main/get_next_line_utils.c)             | Contains utility functions used in the implementation of `get_next_line`. The key functionalities include checking for a newline character in a linked list node, finding the last node in a linked list, adding a new node to the end of a linked list, calculating the length of content in a linked list until a newline character, and clearing the memory allocated for nodes in a linked list. These utilities contribute to the overall functionality of reading lines from a file.                                                                                                                                                                                                                                                                                                      |
| [get_next_line.h](https://github.com/San-tito/get_next_line/blob/main/get_next_line.h)                         | Header file defining the struct `t_list` and function prototypes for `get_next_line` and associated utilities. The struct `t_list` represents a linked list node containing the content of a line and a pointer to the next node. The function prototypes include those for reading lines, managing linked lists, and handling memory. This header provides the necessary interface for using the `get_next_line` function and associated utilities.                                                                                                                                                                                                                                                                                                              |

</details>

<details closed><summary>Bonus</summary>
    
| File                                                                                                           | Summary                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
| ---                                                                                                            | ---                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| [get_next_line_bonus.c](https://github.com/San-tito/get_next_line/blob/main/get_next_line_bonus.c)             | The `get_next_line_bonus.c` file extends the core functionality of `get_next_line` by introducing features that enable the simultaneous management of multiple file descriptors (`fd`). The primary change occurs in the `get_next_line` function, where it now maintains a static array of linked lists (`lst`) corresponding to different file descriptors. This allows the system to handle and track the state of each file descriptor independently, ensuring seamless reading of lines from multiple sources concurrently. The file orchestrates the flow and integration of these features, coordinating the initialization, reading, and cleanup processes for each file descriptor.                                                                                                                                                                                                                                                           |
| [get_next_line_utils_bonus.c](https://github.com/San-tito/get_next_line/blob/main/get_next_line_utils_bonus.c) | Contains utility functions unchanged from the mandatory implementation. These functions facilitate the core operations related to linked lists and memory management and are reused in the bonus implementation to maintain consistency and code modularity. They contribute to the effective management of linked lists within the extended `get_next_line` system, supporting operations like checking for newline characters, obtaining the last node, adding nodes, calculating length until newline, and clearing nodes.                                                                                                                                                                                                                                                                                                                   |
| [get_next_line_bonus.h](https://github.com/San-tito/get_next_line/blob/main/get_next_line_bonus.h)             | Header file for the bonus functionality, defining additional structs and function prototypes. The changes in the header are minimal and involve introducing the necessary structures and functions to support the concurrent management of multiple file descriptors. It extends the structures and functions defined in the mandatory header (`get_next_line.h`) to accommodate the new requirements. The header file ensures that the core functionality remains intact while providing an interface for the bonus features to seamlessly integrate with the existing system.                                                                                                                                                                                                                                 |

</details>

---

## 🚀 Getting Started

***Dependencies***

Please ensure you have the following dependencies installed on your system:

- ℹ️ **C Compiler**: You will need a C compiler to build and run the project.

    - Example for GCC (GNU Compiler Collection):
      ```sh
      sudo apt-get install gcc  # Ubuntu
      sudo yum install gcc      # CentOS
      ```

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
/* Not implemented */
```

---


## 🛣 Roadmap

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


This project is protected under the [UNLICENSE](https://choosealicense.com/licenses/unlicense) License. For more details, refer to the [LICENSE](LICENSE) file.

---

## 👏 Acknowledgments

- [Master File I/O Operations](https://medium.com/p/5fb001d1fff5)
- [get_next_line explained: develop a function that reads a file line by line](https://www.youtube.com/watch?v=8E9siq7apUU)
- [gnlTester](https://github.com/Tripouille/gnlTester)

[**Return**](#Top)

---

