
# Setting Up - C Project

## Description

This project involves creating and managing a square in a 2D space. The goal is to simulate the setup and manipulation of a square object by configuring its size, position, and state. The project emphasizes the use of C programming concepts such as structures, memory management, and input validation. It provides a simple interface to manage the square's attributes, and serves as a hands-on exercise in C.

## Features

The **Setting Up** program allows for the following functionalities:  
- **Create Square**: Initializes a square with customizable position and size.  
- **Modify Square Attributes**: Changes the size, position, or state of the square dynamically.  
- **Display Square**: Outputs the current state and attributes of the square to the screen.  
- **Input Validation**: Ensures that the provided values for size and position are valid and within acceptable bounds.

## Installation

To compile and run the project, follow the folder structure and the commands below:

### Folder Structure:
```
/include/
  ├── my.h              # Header file containing function declarations and constants
  ├── struct_square.h   # Header file defining the structure of the square
/src/
  ├── main.c            # The main entry point of the program
  ├── square.c          # Contains the functions to manipulate the square
  └── utils.c           # Utilities like input validation, memory management
Makefile                 # The Makefile for compiling the project
README.md               # This file
```

### Compilation:
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/setting_up.git
   cd setting_up
   ```

2. Compile the project:
   ```bash
   make
   ```

3. Run the program:
   ```bash
   ./setting_up [size] [pattern (o and .)]
   ```
   or
   ```bash
   ./setting_up [map file path]
   ```

## Example

Once the program is compiled, run it and input the desired values for the square's size. For instance:

```bash
Enter the size of the square: 5
```

The program will then display the current attributes of the square, like so:

```
Square created at position (10, 20) with a size of 5.
```

## Technical Details

This project utilizes a structure to define the attributes of a square and functions to manipulate those attributes. The program dynamically allocates memory for the square and ensures proper input validation to avoid errors. It follows a modular approach with separate files for different functionalities such as input handling, square manipulation, and utilities.

### Key Functions:
- `create_square()`: Initializes a new square with the provided size and position.
- `modify_square()`: Changes the size, position, or state of the square.
- `display_square()`: Outputs the current attributes of the square to the screen.
- `validate_input()`: Ensures that the provided input values are valid.

## Contributors

This project was developed individually as part of an exercise for Epitech.
