Script started on Sun 06 Mar 2016 10:23:23 PM PST
]0;struo006@hammer:~/CS100_new/rshell[?1034h[struo006@hammer rshell]$ ls
LICENSE  makefile  README.md  [0m[38;5;27msrc[0m  [38;5;27mtests[0m
[m]0;struo006@hammer:~/CS100_new/rshell[struo006@hammer rshell]$ make
rm -rf bin
mkdir bin
g++ -ansi -pedantic -Wall -Werror src/rshell.cpp -o bin/rshell
]0;struo006@hammer:~/CS100_new/rshell[struo006@hammer rshell]$ bin/rshell
[struo006@hammer.cs.ucr.edu]$tests -e a.out
Error missing Flag
[struo006@hammer.cs.ucr.edu]$test -e a.out exit
(False)
[struo006@hammer.cs.ucr.edu]$test -e a.out
(False)
[struo006@hammer.cs.ucr.edu]$exit
]0;struo006@hammer:~/CS100_new/rshell[struo006@hammer rshell]$ exit
exit

Script done on Sun 06 Mar 2016 10:23:58 PM PST
