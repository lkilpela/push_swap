# Less than 2 arguments

1. Error: not enough arguments
./push_swap

# More than 2 arguments

2. Error: invalid argument format
./push_swap 1 foo 2

3. Error: integer overflow
./push_swap 1 2147483648

4. Error: empty argument
./push_swap "" 42 43

5. Error: duplicate value
./push_swap 42 42 45

# Equal to 2 arguments and second argument is a string of integers
./push_swap "42 52 1 5"