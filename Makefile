make: src/yash.c src/child.c src/childchild.c src/jobCtrl.c
	gcc src/yash.c src/child.c src/childchild.c src/jobCtrl.c -o yash
	./yas\h

debug: src/yash.c src/child.c src/childchild.c
	gcc -g src/yash.c src/child.c src/childchild.c src/jobCtrl.c -o yash
	gdb -tui -q ./yash

clean:
	rm yash file*.txt
