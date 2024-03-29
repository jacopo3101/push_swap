# Push_swap

## Summary
Push_swap is a project aimed at sorting a set of integer data on a stack using a limited set of instructions, with the objective of achieving the lowest possible number of actions. The task involves implementing algorithms to manipulate stacks efficiently and selecting the most optimal solution for sorting data.

## Objectives
The project aims to reinforce essential skills in programming, particularly in C, and understanding basic algorithms and their complexities. Sorting algorithms play a crucial role in software development and are frequently discussed in job interviews. Thus, this project offers an opportunity to grasp these concepts thoroughly.

## Common Instructions
- The project must be implemented in C and adhere to the Norm.
- Functions should handle errors gracefully and manage memory properly.
- A Makefile must be included for compiling the project with specified flags.

## Mandatory Part
### Rules
- Two stacks named 'a' and 'b' are provided.
- Stack 'a' initially contains a random set of integers, while stack 'b' is empty.
- The goal is to sort the integers in stack 'a' in ascending order using a set of operations.
### Instructions
- `sa`, `sb`, `ss`: Swap the first two elements of stack 'a', 'b', or both respectively.
- `pa`, `pb`: Push the top element of stack 'a' onto stack 'b' or vice versa.
- `ra`, `rb`, `rr`: Rotate the elements of stack 'a', 'b', or both respectively.
- `rra`, `rrb`, `rrr`: Reverse rotate the elements of stack 'a', 'b', or both respectively.
### Example
Illustrative examples demonstrate the effects of various instructions on sorting a random list of integers.

```console
Init a and b:
2
1
3
6
5
8
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec sa:
1
2
3
6
5
8
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec pb pb pb:
6 3
5 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec ra rb (equiv. to rr):
5 2
8 1
6 3
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec rra rrb (equiv. to rrr):
6 3
5 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec sa:
5 3
6 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec pa pa pa:
1
2
3
5
6
8
_ _
a b
----------------------------------------------------------------------------------------------------------
```

## The "push_swap" Program
- The push_swap program aims to sort the stack 'a' with the fewest possible operations.
- The output should be a list of instructions separated by newline characters.
- Errors, such as invalid arguments or unsorted lists, should be handled appropriately.

## Usage
Compile the project using `make` istruction.  
Then execute `push_swap` by giving a set of integr as argument.  
`./push_swap "99 11 25 5 60 24 20 66 8 75 71 80 4 93 34 52 91 37 61 86"`

## Bonus Part
The project offers an opportunity to create a checker program to verify the sorting instructions generated by push_swap.
### The "checker" Program
- Takes a formatted list of integers as an argument representing stack 'a'.
- Reads instructions from standard input and executes them on the stack.
- Outputs "OK" if stack 'a' is sorted and 'b' is empty after execution, else "KO".
- Handles errors gracefully and provides informative error messages.

## Usage
Compile the bonus using `make bonus` istruction.  
Then execute `push_swap` and `checker` by giving them the same data set `ARG`.  
`ARG="99 11 25 5 60 24 20 66 8 75 71 80 4 93 34 52 91 37 61 86"; ./push_swap "$ARG" | ./checker "$ARG"`

## Score
![project score](/assets/score.png)