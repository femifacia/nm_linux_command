# nm_linux_command
A brief implementation of nm linux command in C

## Requirements

### Linux
- Make
- gcc
- libc
- libelf-dev

## How to compile ?

At the root of the dir, type:

    make

or if ypu want to force compilation

    make re

## How to execute ?

    ./my_nm [arg1] [arg2] ... [argn]

for each binary, `my_nm` will act as the real nm with the standard configs.

If no args are passed to `my_nm` the command will look for a default ./a.out to read and make the analysis