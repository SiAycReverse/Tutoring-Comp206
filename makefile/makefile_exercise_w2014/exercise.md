### Exercise 1
A programmer has the following project she wants to compile using make, the final executable name is `program`

- `main.c` and `main.h` where `main.c` includes `library.h`, `menu.h`, `order.h`, `report.h`
- `library.c `and `library.h`
- `menu.c` and menu.h
- `order.c` and `order.h` where `order.c` includes `menu.h` and `library.h`
- `report.c` and `report.h` where `report.c` includes `library.h`

She also wants to back up all .c files and .h files into a directory inside the project called `backup`, if the directory does not exist, she needs to create it

There is also a clean command which removes all executable and .o files
