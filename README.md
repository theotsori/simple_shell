# simple_shell
ALX GROUP UNIX shell environment
A small change.

## The program should do the following

### 0. printenv with environ
program that prints the environment using the global variable environ.

### 1. env vs environ
program that prints the address of env (the third parameter of the main function) and environ (the global variable).

### 2. getenv()
function that gets an environment variable. (without using getenv)

Prototype: char *_getenv(const char *name);
man 3 getenv

### 3. PATH
function that prints each directory contained in the the environment variable PATH, one directory per line.

### 4. PATH
function that builds a linked list of the PATH directories.

### 5. setenv
function that changes or adds an environment variable (without using setenv).

Prototype: int _setenv(const char *name, const char *value, int overwrite);
man 3 setenv

### 6. unsetenv
function that deletes the variable name from the environment (without using unsetenv).

Prototype: int _unsetenv(const char *name);
man 3 unsetenv

## Output Insructions
Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See below)
Example of error with sh:

$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
Same error with your program hsh:

$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$

## Compilation
Your shell will be compiled this way:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## Testing
Your shell should work like this in interactive mode:

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
But also in non-interactive mode:

$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
