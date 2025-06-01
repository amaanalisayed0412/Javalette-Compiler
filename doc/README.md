# Javalette Compiler

## Usage Instructions
To build the compiler, run the `make` command. This will generate a compiler executable `jlc`. You can then compile a Javalette program by running the executable (./jlc) and feeding the source code to `stdin`.

This will parse, type-check, and generate LLVM IR code for the provided source file. The output is written to `stdout`.

## Language Specification
The compiler implements the Javalette language as specified in the BNFC source file located at:

    src/Javalette.cf

This file defines the grammar, syntax rules, and types supported by the language. Please refer to this file for the full language specification. There are some extensions from the original file provided, namely support for one-dimensional arrays and dynamic structures (pointers and structs).

## Shift/Reduce Conflicts
Number of shift/reduce conflicts: 2

Conflict Details:

State 159

   25 Stmt: _SYMB_33 _SYMB_4 Expr _SYMB_5 Stmt •
   26     | _SYMB_33 _SYMB_4 Expr _SYMB_5 Stmt • _SYMB_30 Stmt

    _SYMB_30  shift, and go to state 164

    _SYMB_30  [reduce using rule 25 (Stmt)]
    $default  reduce using rule 25 (Stmt)

- A shift/reduce conflict occurs in the grammar involving the `if-else` statement, which is common due to the "dangling else" ambiguity.
- The conflict is resolved by allowing the parser to shift, effectively binding the `else` to the nearest unmatched `if`, as per standard convention.


State 80

   49 Expr6: _IDENT_ •
   54      | _IDENT_ • _SYMB_4 ListExpr _SYMB_5
   58      | _SYMB_4 _IDENT_ • _SYMB_5 _SYMB_36

    _SYMB_4  shift, and go to state 92
    _SYMB_5  shift, and go to state 120

    _SYMB_5   [reduce using rule 49 (Expr6)]
    $default  reduce using rule 49 (Expr6)

- This shift/reduce conflict occurs in the grammar involving the `EVar`, `EApp` and `ENullPtr` rules, all of which include a token of `Ident` type. This is not particularly harmful, because the lookahead provides the parser with the decision of whether to shift in favour of `EApp` and `ENullPtr` or reduce to `EVar`. If the lookahead is `(` or `)`, the parser will prefer to shift, not reduce. So instead of interpreting `Ident` immediately as a variable, the parser looks ahead to disambiguate function calls or null pointers.

## Extensions Implemented (Submission C)

### One-dimensional arrays:
  - Array declaration (e.g., `int[] arr;`)
  - Array allocation with `new` (e.g., `arr = new int[10];`)
  - Indexing (e.g., `arr[2] = 5;`)
  - `.length` property
  - Enhanced for-loops (e.g., `for (int x : arr)`)

### Dynamic data structures 
  - Structure definitions
  - Pointer type definitions
  - Heap allocation with `new`
  - Pointer dereferencing (e.g., `xs->next`)
  - Null pointers

### Optimization Study
  - Mem2Reg (Promote memory to registers)
  - GVN (Global Value Numbering)
  - InstCombine (Instruction Combining)
