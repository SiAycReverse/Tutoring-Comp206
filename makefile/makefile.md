# Makefile

### What is a Makefile
A text file which defines set of tasks to be executed

### Basic Examples

```bash
all: say_hello generate

say_hello:
	@echo "Hello World"

generate:
	@echo "Creating empty text files..."
	touch file-{1..10}.txt

clean:
	@echo "Cleaning up..."
	rm *.txt
```




### Rule


##### Syntax for a typical Rule

```bash
target: prerequisites
  recipe
```
**target**
- a binary file that depends on prerequisites

**prerequisites**
- necessary stuff for the target
- can be files, binaries, targets
- **if prerequisites changes, that means we need to rebuild the target**

**recipe**
- uses *prerequisites* to make a *target*
- the body of the recipe is actually just a regular bash command
  - `rm -f *.o  *.out` simple clean up
  - `echo HELLO_WORLD`
  - `curl https://www.google.ca`

### Notes
- The first rule will be the default rule
- To execute a specific rule: `make <target>`
  - `make clean`
- Usually, the first rule's target name is the same as the final executable

### A basic C make file
Here is a straightforward makefile that describes the way an executable file called edit depends on eight object files which, in turn, depend on __eight C source__ and __three header files__.

In this example, all the C files include `defs.h`, but only those defining editing commands include `command.h`, and only low level files that change the editor buffer include `buffer.h`.
```bash
edit : main.o kbd.o command.o display.o \
       insert.o search.o files.o utils.o
        cc -o edit main.o kbd.o command.o display.o \
                   insert.o search.o files.o utils.o

main.o : main.c defs.h
        cc -c main.c
kbd.o : kbd.c defs.h command.h
        cc -c kbd.c
command.o : command.c defs.h command.h
        cc -c command.c
display.o : display.c defs.h buffer.h
        cc -c display.c
insert.o : insert.c defs.h buffer.h
        cc -c insert.c
search.o : search.c defs.h buffer.h
        cc -c search.c
files.o : files.c defs.h buffer.h command.h
        cc -c files.c
utils.o : utils.c defs.h
        cc -c utils.c
clean :
        rm edit main.o kbd.o command.o display.o \
           insert.o search.o files.o utils.o
```
