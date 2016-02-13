Script started on Fri 12 Feb 2016 08:30:31 PM PST
]0;struo006@hammer:~/CS100/rshell[?1034h[struo006@hammer rshell]$ make
rm -rf bin
mkdir bi
g++ -ansi -pedantic -Wall -Werror src/rshell.cpp -o bin/rshell
]0;struo006@hammer:~/CS100/rshell[struo006@hammer rshell]$ ls
[0m[38;5;27mbin[0m  LICENSE  makefile  makefile~  README.md  [38;5;27msrc[0m  [38;5;27mtests[0m
[m]0;struo006@hammer:~/CS100/rshell[struo006@hammer rshell]$ bin/rshell
[struo006@hammer.cs.ucr.edu]$ls
bin  LICENSE  makefile	makefile~  README.md  src  tests
[struo006@hammer.cs.ucr.edu]$ls -a
.  ..  bin  .git  LICENSE  makefile  makefile~	.makefile.un~  README.md  src  tests
[struo006@hammer.cs.ucr.edu]$  ls
bin  LICENSE  makefile	makefile~  README.md  src  tests
[struo006@hammer.cs.ucr.edu]$   ls  -a
.  ..  bin  .git  LICENSE  makefile  makefile~	.makefile.un~  README.md  src  tests
[struo006@hammer.cs.ucr.edu]$echo "A&B"
"A&B"
[struo006@hammer.cs.ucr.edu]$echo AB
AB
[struo006@hammer.cs.ucr.edu]$mkdir TestDIR
[struo006@hammer.cs.ucr.edu]$ls -a
.  ..  bin  .git  LICENSE  makefile  makefile~	.makefile.un~  README.md  src  TestDIR	tests
[struo006@hammer.cs.ucr.edu]$meeep
execvp failed: No such file or directory
[struo006@hammer.cs.ucr.edu]$ls ls -a
ls: cannot access ls: No such file or directory
[struo006@hammer.cs.ucr.edu]$ls la
ls: cannot access la: No such file or directory
[struo006@hammer.cs.ucr.edu]$ls ls
ls: cannot access ls: No such file or directory
[struo006@hammer.cs.ucr.edu]$ls --a
ls: option '--a' is ambiguous
Try `ls --help' for more information.
[struo006@hammer.cs.ucr.edu]$exit
]0;struo006@hammer:~/CS100/rshell[struo006@hammer rshell]$ exit
exit

Script done on Fri 12 Feb 2016 08:32:33 PM PST
