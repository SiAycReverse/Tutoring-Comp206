# The C Programming Language

Online C IDE: <https://repl.it/@JiajunChen1/>
C code snippts: <https://www.sanfoundry.com/c-interview-questions-answers/>
RegularHalfDeletion

### C Basic

\--- skipped ---

### Pointers

Variables that stores the memory address of another variable

```C
#include <stdio.h>

int main() {

  // variable declarations
  int x = 1;
  int y = 2;
  int z[10];
  printf("%d\n", &x); // print the address of x
  printf("%d\n", &y); // print the address of y
  printf("%d\n", &z); // print the address of z
  printf("------\n");

    int *ip;             // decalre a pointer (int) called ip
    printf("%d\n", &ip); // print the address of pointer ip
    printf("------\n");

    ip = &x;             // points to the address of x
    printf("%d\n", ip);  // print the value of ip
    printf("%d\n", &x);  // print the address of x
    printf("%d\n", *ip); // print the value of pointer ip points
    printf("------\n");

    printf("%d\n", y);
    y = *ip; // assign the value of what ip points to y
    printf("%d\n", y);
    printf("------\n");

    // more in pointer.c **
}
```

### Strings in C

`char *p = "my name is bob"`

-   The p is a variable pointer
    -   The p points to the first character (in this case ‘m’)
-   The “my name is bob” is a static constant value
    -   cannot be edited
    -   cannot be written over
-   `<string.h>`
    -   string library for C
    -   Please know how to use them

```C
// Common string.h functions
strcmp()
strlen()
strncat()
strncpy()
```

```C
char array[100];
char *p, *q;
p = array;
printf("%s", p); // what is printed out?
printf("%s", (p+2)); // what is printed out?
q = &array[5]; // since we are not pointing to the first cell
printf("%s", q); // what is printed out?
```

```C
#include <stdio.h>
#include <string.h>

int main () {

   char str1[12] = "Hello";
   char str2[12] = "World";
   char str3[12];
   int  len ;

   /* copy str1 into str3 */
   strcpy(str3, str1);
   printf("strcpy( str3, str1) :  %s\n", str3 );

   /* concatenates str1 and str2 */
   strcat( str1, str2);
   printf("strcat( str1, str2):   %s\n", str1 );

   /* total lenghth of str1 after concatenation */
   len = strlen(str1);
   printf("strlen(str1) :  %d\n", len );

   return 0;
}
// **
```

### Struct and Union

-   like OOP in Java (well, not really)
-   Is it possible to do inheritance using struct?
    -   Yes, let us do it together

###### Code example

```C
#include <stdio.h>
#include <string.h>

struct Books {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};

int main( ) {

   struct Books Book1;        /* Declare Book1 of type Book */
   struct Books Book2;        /* Declare Book2 of type Book */

   /* book 1 specification */
   strcpy( Book1.title, "C Programming");
   strcpy( Book1.author, "Nuha Ali");
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;

   /* book 2 specification */
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Zara Ali");
   strcpy( Book2.subject, "Telecom Billing Tutorial");
   Book2.book_id = 6495700;

   /* print Book1 info */
   printf( "Book 1 title : %s\n", Book1.title);
   printf( "Book 1 author : %s\n", Book1.author);
   printf( "Book 1 subject : %s\n", Book1.subject);
   printf( "Book 1 book_id : %d\n", Book1.book_id);

   /* print Book2 info */
   printf( "Book 2 title : %s\n", Book2.title);
   printf( "Book 2 author : %s\n", Book2.author);
   printf( "Book 2 subject : %s\n", Book2.subject);
   printf( "Book 2 book_id : %d\n", Book2.book_id);

   return 0;
}
```

```C
#include <stdio.h>
#include <string.h>

struct Books {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};

/* function declaration */
void printBook( struct Books book );

int main( ) {

   struct Books Book1;        /* Declare Book1 of type Book */
   struct Books Book2;        /* Declare Book2 of type Book */

   /* book 1 specification */
   strcpy( Book1.title, "C Programming");
   strcpy( Book1.author, "Nuha Ali");
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;

   /* book 2 specification */
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Zara Ali");
   strcpy( Book2.subject, "Telecom Billing Tutorial");
   Book2.book_id = 6495700;

   /* print Book1 info */
   printBook( Book1 );

   /* Print Book2 info */
   printBook( Book2 );

   return 0;
}

// we use actual struct here
void printBook( struct Books book ) {

   printf( "Book title : %s\n", book.title);
   printf( "Book author : %s\n", book.author);
   printf( "Book subject : %s\n", book.subject);
   printf( "Book book_id : %d\n", book.book_id);
}
```

```C
#include <stdio.h>
#include <string.h>

struct Books {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};

/* function declaration */
void printBook( struct Books *book );
int main( ) {

   struct Books Book1;        /* Declare Book1 of type Book */
   struct Books Book2;        /* Declare Book2 of type Book */

   /* book 1 specification */
   strcpy( Book1.title, "C Programming");
   strcpy( Book1.author, "Nuha Ali");
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;

   /* book 2 specification */
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Zara Ali");
   strcpy( Book2.subject, "Telecom Billing Tutorial");
   Book2.book_id = 6495700;

   /* print Book1 info by passing address of Book1 */
   printBook( &Book1 );

   /* print Book2 info by passing address of Book2 */
   printBook( &Book2 );

   return 0;
}

// this time we use pointer
void printBook( struct Books *book ) {

   printf( "Book title : %s\n", book->title);
   printf( "Book author : %s\n", book->author);
   printf( "Book subject : %s\n", book->subject);
   printf( "Book book_id : %d\n", book->book_id);
}
// **
```

### Dynamic Memory

-   Create data structures on the fly (while program is running)
    1.  At compile-time define the data structure type
    2.  At run-time ask the system for memory formatted according to your defined data structure type
    3.  If the system returns NULL then it was not successful
    4.  When you are finished using the data structure return the memory back to the system


    #include <stdlib.h>
    void *malloc(int size);
      - Creates one data structure of ‘size’
    void *calloc(int multiples, int size)
      - Creates an array of data structures of type ‘size’
    free(void *)
      - Returns the data structure’s memory

### C Pre-processor and Modular Programming

##### Common C Pre-Processor

    #include
    #define
    #ifdef
    #else
    #endif
    #ifndef

```C
#include <stdio.h>

#define LOWER 32
#define UPPER 90
#define STEP 5

int main() {

  int fahr;
  for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
    printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
  }
  putchar(EOF);
  return 0;
}
```

### C file operations

    File handling functions
    Description
    fopen ()  function creates a new file or opens an existing file.
    fclose ()	function closes an opened file.
    getw ()	  function reads an integer from file.
    putw ()	functions writes an integer to file.
    fgetc ()	 function reads a character from file.
    fputc ()	functions write a character to file.
    gets ()	function reads line from keyboard.
    puts ()	function writes line to o/p screen.
    fgets() function reads string from a file, one line at a time.
    fputs ()	function writes string to a file.
    feof ()	 function finds end of file.
    fgetchar ()	function reads a character from keyboard.
    fprintf ()	function writes formatted data to a file.
    fscanf ()	 function reads formatted data from a file.
    fputchar ()	function writes a character onto the output screen from keyboard input.
    getc ()	 function reads character from file.
    getch ()	 function reads character from keyboard.
    getche ()	function reads character from keyboard and echoes to o/p screen.
    getchar ()	 function reads character from keyboard.
    putc ()	function writes a character to file.
    putchar ()	 function writes a character to screen.
    scanf() function reads formatted data from keyboard.
    remove ()	 function deletes a file.

### \* void pointer

-   Pointe which can literally points to anything (variables, structs, array, strings, functions, poitners....)
-   <https://www.geeksforgeeks.org/void-pointer-c-cpp/>
-   <http://www.circuitstoday.com/void-pointers-in-c>
-   <https://stackoverflow.com/questions/11626786/what-does-void-mean-and-how-to-use-it>
