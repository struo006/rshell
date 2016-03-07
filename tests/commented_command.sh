Script started on Sun 06 Mar 2016 10:18:27 PM PST
]0;struo006@hammer:~/CS100_new/rshell[?1034h[struo006@hammer rshell]$ ls
LICENSE  makefile  README.md  [0m[38;5;27msrc[0m  [38;5;27mtests[0[]0;struo006@hammer:~/CS100_new/rshell[struo006@hammer rshell]$ make
[m]0;struo006@hammer:~/CS100_new/rshell[struo006@hammer rshell]$ make
rm -rf bin
mkdir bin
g++ -ansi -pedantic -Wall -Werror src/rshell.cpp -o bin/rshell
]0;struo006@hammer:~/CS100_new/rshell[struo006@hammer rshell]$ bin/rshell
[struo006@hammer.cs.ucr.edu]$test -ea.out
(False)
[struo006@hammer.cs.ucr.edu]$test -e a.out #hello
(False)
[struo006@hammer.cs.ucr.edu]$#hello test -e a.out
[struo006@hammer.cs.ucr.edu]$test #-e a.out
Error missing Flag
[struo006@hammer.cs.ucr.edu]$test #-e       a.out
Error missing Flag
[struo006@hammer.cs.ucr.edu]$test    #-e  #a.uot
(False)
[struo006@hammer.cs.ucr.edu]$echo a # hello
a
[struo006@hammer.cs.ucr.edu]$#echo a
[struo006@hammer.cs.ucr.edu]$echo #hello

[struo006@hammer.cs.ucr.edu]$ls #-a
bin  LICENSE  makefile	README.md  src	tests
[struo006@hammer.cs.ucr.edu]$pwd
/home/csmajs/struo006/CS100_new/rshell
[struo006@hammer.cs.ucr.edu]$pwd #me
/home/csmajs/struo006/CS100_new/rshell
[struo006@hammer.cs.ucr.edu]$exit
]0;struo006@hammer:~/CS100_new/rshell[struo006@hammer rshell]$ exit
exit

Script done on Sun 06 Mar 2016 10:19:54 PM PST
