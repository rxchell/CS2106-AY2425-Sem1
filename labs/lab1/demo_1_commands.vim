Demo1 	L01/part1 	flex_reduce
* srun gcc testr.c queue.c -o testr
* srun ./testr 


Demo2 	L01/part3	valgrind		llist.c
* srun gcc -g lab1p3c.c -o lab1p3c
* srun ./lab1p3c
* srun valgrind ./lab1p3c

* gcc -o testlist testlist.c llist.c
* valgrind ./testlist


Demo3	L01/part 4 	testdir.c
* gcc -g -o testdir testdir.c llist.c dir.c
* valgrind ./testdir
