Script started on Fri 12 Feb 2016 08:37:49 PM PST
]0;struo006@hammer:~/CS100/rshell[?1034h[struo006@hammer rshell]$ make
rm -rf bin
mkdir bin
g++ -ansi -pedantic -Wall -Werror src/rshell.cpp -o bin/rshell
]0;struo006@hammer:~/CS100/rshell[struo006@hammer rshell]$ bin/rshell
[struo006@hammer.cs.ucr.edu]$ls -a#testing Comments
.  ..  bin  .git  LICENSE  makefile  makefile~	.makefile.un~  README.md  src  tests
[struo006@hammer.cs.ucr.edu]$ls #more comments
execvp failed: No such file or directory
[struo006@hammer.cs.ucr.edu]$ls#more comments
bin  LICENSE  makefile	makefile~  README.md  src  tests
[struo006@hammer.cs.ucr.edu]$echo "MEEP"#eho comments
"MEEP"
[struo006@hammer.cs.ucr.edu]$echo "#meep"#meeep
[struo006@hammer.cs.ucr.edu]$mkdir TestDIR #making direcory
[struo006@hammer.cs.ucr.edu]$ls -a
.  ..  bin  .git  LICENSE  makefile  makefile~	.makefile.un~  README.md  src  TestDI  tests
[struo006@hammer.cs.ucr.edu]$:cat TestDI
cat: TestDI: Is a directory
[struo006@hammer.cs.ucr.edu]$exit
]0;struo006@hammer:~/CS100/rshell[struo006@hammer rshell]$ exit
Script done on Fri 12 Feb 2016 08:39:51 PM PST
