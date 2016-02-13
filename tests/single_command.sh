Script started on Fri 12 Feb 2016 07:43:44 PM PST
]0;struo006@hammer:~/CS100/rshell[?1034h[struo006@hammer rshell]$ make
rm -rf bin
mkdir bin
g++ -ansi -pedantic -Wall -Werror src/rshell.cpp -o bin/rshell
]0;struo006@hammer:~/CS100/rshell[struo006@hammer rshell]$ bin/rshell
[struo006@hammer.cs.ucr.edu]$ls
bin  LICENSE  makefile	makefile~  README.md  src  tests
[struo006@hammer.cs.ucr.edu]$ls -a
.  ..  bin  .git  LICENSE  makefile  makefile~	.makefile.un~  README.md  src  tests
[struo006@hammer.cs.ucr.edu]$  ls
terminate called after throwing an instance of 'std::out_of_range'
  what():  basic_string::at
Aborted
]0;struo006@hammer:~/CS100/rshell[struo006@hammer rshell]$    ls
[0m[38;5;27mbin[0m  LICENSE  makefile  makefile~  README.md  [38;5;27msrc[0m  [38;5;27mtests[0m
[m]0;struo006@hammer:~/CS100/rshell[struo006@hammer rshell]$   ls
[0m[38;5;27mbin[0m  LICENSE  makefile  makefile~  README.md  [38;5;27msrc[0m  [38;5;27mtests[0m
[m]0;struo006@hammer:~/CS100/rshell[struo006@hammer rshell]$  ls
[0m[38;5;27mbin[0m  LICENSE  makefile  makefile~  README.md  [38;5;27msrc[0m  [38;5;27mtests[0m
[m]0;struo006@hammer:~/CS100/rshell[struo006@hammer rshell]$    ls
[0m[38;5;27mbin[0m  LICENSE  makefile  makefile~  README.md  [38;5;27msrc[0m  [38;5;27mtests[0m
[m]0;struo006@hammer:~/CS100/rshell[struo006@hammer rshell]$ eho[K[Kcho "A"
A
]0;struo006@hammer:~/CS100/rshell[struo006@hammer rshell]$ echo "A && B"
A && B
]0;struo006@hammer:~/CS100/rshell[struo006@hammer rshell]$ mkdir testDIR
]0;struo006@hammer:~/CS100/rshell[struo006@hammer rshell]$ ls
[0m[38;5;27mbin[0m  LICENSE  makefile  makefile~  README.md  [38;5;27msrc[0m  [38;5;27mtestDIR[0m  [38;5;27mtests[0m
[m]0;struo006@hammer:~/CS100/rshell[struo006@hammer rshell]$ ls -a
[0m[38;5;27m.[0m  [38;5;27m..[0m  [38;5;27mbin[0m  [38;5;27m.git[0m  LICENSE  makefile  makefile~  .makefile.un~  README.md  [38;5;27msrc[0m  [38;5;27mtestDIR[0m  [38;5;27mtests[0m
[m]0;struo006@hammer:~/CS100/rshell[struo006@hammer rshell]$ exit
exit

Script done on Fri 12 Feb 2016 07:44:58 PM PST
