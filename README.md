# lexicalAnalysis

This is a C++ program that performs lexical analysis on input tokens. It reads tokens from the user and identifies the corresponding attributes based on a predefined table.

## Prerequisites

To run this program, you need to have a C++ compiler installed on your system.

## Usage

1. Clone the repository or download the source code files.
2. Compile the code using a C++ compiler.
3. Run the compiled executable file.
4. Enter tokens at the prompt to perform lexical analysis.
5. Press Ctrl+C to exit the program.

## Code Explanation

The method used in this code is the table-driven approach in lexical analysis.
- The program uses a predefined table to determine the attributes of each token.
- The `create_table()` function initializes the table by reading data from a file.
- The `search_token()` function searches for tokens and determines their attributes based on the table.
- The `lexical_analysis()` function performs the lexical analysis on the input tokens.
- The main program loop allows the user to enter tokens and see their corresponding attributes.
