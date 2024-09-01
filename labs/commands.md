### Compile and run files
#### On slurm
```vim
srun gcc -g lab1p3c.c -o lab1p3c
```
```vim
srun ./lab1p3c
```
#### On normal Linux machine
```vim
gcc -g lab1p3c.c -o lab1p3c
```
```vim
./lab1p3c
```
### Then run valgrind 
https://bytes.usc.edu/cs104/wiki/valgrind/#valgrind-cheat-sheet
```vim
srun valgrind ./lab1p3b
```
```vim
srun valgrind --leak-check=full ./lab1p3c
```

##### Compile `testlist.c` and `llist.c` into an executable called `testlist` and make it ready for analysis by Valgrind
```vim
gcc -o testlist testlist.c llist.c
```
- `gcc` is the GNU Compiler Collection, which compiles the C code.
- `-o testlist` specifies the name of the output executable file, which is testlist.
- `testlist.c` and `llist.c` are the source files to be compiled and linked.
```vim
valgrind ./testlist
```
