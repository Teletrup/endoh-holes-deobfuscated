.PHONY: test clean



test: prog.gif prog_deob.gif
	diff -s prog.gif prog_deob.gif

clean:
	@rm prog prog_deob prog.gif prog_deob.gif



prog: prog.c
	gcc prog.c -o prog

prog_deob: prog_deob.c
	gcc prog_deob.c -o prog_deob

prog.gif: prog
	./prog < sample.txt > prog.gif

prog_deob.gif: prog_deob
	./prog_deob < sample.txt > prog_deob.gif
