Script started on Sun 06 Mar 2016 10:13:41 PM PST
]0;struo006@hammer:~/CS100_new/rshell[?1034h[struo006@hammer rshell]$ make
rm -rf bin
mkdir bin
g++ -ansi -pedantic -Wall -Werror src/rshell.cpp -o bin/rshell
]0;struo006@hammer:~/CS100_new/rshell[struo006@hammer rshell]$ bin/rshell
[struo006@hammer.cs.ucr.edu]$ls
bin  LICENSE  makefile	README.md  src	tests
[struo006@hammer.cs.ucr.edu]$test -e a.out
(False)
[struo006@hammer.cs.ucr.edu]$ls
bin  LICENSE  makefile	README.md  src	tests
[struo006@hammer.cs.ucr.edu]$test -e bin
(True)
[struo006@hammer.cs.ucr.edu]$test      -e     bin
(True)
[struo006@hammer.cs.ucr.edu]$test    -f   bin
(False)
[struo006@hammer.cs.ucr.edu]$test          -d      bin
(True)
[struo006@hammer.cs.ucr.edu]$echo A
A
[struo006@hammer.cs.ucr.edu]$[    -e    bin  ]
(True)
[struo006@hammer.cs.ucr.edu]$[       f  ]
Error, missing flag
[struo006@hammer.cs.ucr.edu]$[-e a.out]
Need a space after [
[struo006@hammer.cs.ucr.edu]$[ -e a.out ]
(False)
[struo006@hammer.cs.ucr.edu]$ls
bin  LICENSE  makefile	README.md  src	tests
[struo006@hammer.cs.ucr.edu]$test  -   bin
(True)
[struo006@hammer.cs.ucr.edu]$[    -    src
Missing ]
[struo006@hammer.cs.ucr.edu]$[    -   src  ]
(True)
[struo006@hammer.cs.ucr.edu]$exit
]0;struo006@hammer:~/CS100_new/rshell[struo006@hammer rshell]$ exit
exit

Script done on Sun 06 Mar 2016 10:15:21 PM PST
