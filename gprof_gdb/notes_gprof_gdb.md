# gprof and gdb

### gprof

More reference: https://www.thegeekstuff.com/2012/08/gprof-tutorial
###### Run program with gprof
```Bash
# add -pg flag to enable profiling
gcc -pg -o TestGprof TestGprof.c

# run gprof on profiling data
gprof -b TestGprof gmon.out > analysis.out

```

##### Sample profile and call graph
```
Flat profile:

Each sample counts as 0.01 seconds.
  %   cumulative   self               self     total
 time   seconds   seconds    calls   s/call   s/call  name
100.55     20.38    20.38      100     0.20     0.20  StaticFunc
  0.00     20.38     0.00        1     0.00    20.38  TestFunc

                        Call graph


granularity: each sample hit covers 2 byte(s) for 0.05% of 20.38 seconds

index % time    self  children    called          name
               20.38    0.00     100/100         TestFunc [2]
[1]    100.0   20.38    0.00     100             StaticFunc [1]
---------------------------------------------------------------
                0.00   20.38       1/1           main [3]
[2]    100.0    0.00   20.38       1             TestFunc [2]
               20.38    0.00     100/100         StaticFunc [1]
---------------------------------------------------------------

[3]    100.0    0.00   20.38                     main [3]
                0.00   20.38       1/1           TestFunc [2]
---------------------------------------------------------------

Index by function name

   [1] StaticFunc              [2] TestFunc
```

##### Profiler term explanation
- `% time` - percentage of the total execution time your program spent in this function. These should all add up to 100%.
- `cumulative seconds` - the cumulative total number of seconds the computer spent executing this functions, plus the time spent in all the functions above this one in this table.
- `self seconds` - the number of seconds accounted for by this function alone.
- `calls` - This is the total number of times the function was called, blank otherwise.
- `self ms/call` - This represents the average number of milliseconds spent in this function per call.
- `total ms/call` - Average number of milliseconds spent in this function and its descendants per call.
- `name` - This is the name of the function.



### gdb

##### Compile the program to use gdb
`gcc -g hello.cc -o hello`

##### Start the program in debugger mode
`gdb hello`

##### Common Command List

- print <variable>
- break

```
- list              show 10 lines
- step & next       step into or skip function, like Java
- print x           print the value stored in x
- quit              quit gdb
- break LINE_NO     interrupt at line number
- break FUNC_NAME   interrupt at function call
- continue          continue program execution after break
- watch EXPR        stop program as soon as expression is true
- ptype NAME        pretty print of structure n
```

##### Additional References
- online gdb debugger
  - https://www.onlinegdb.com
- tutorials
  - https://www.cs.cmu.edu/~gilpin/tutorial/
  - https://www.tutorialspoint.com/gnu_debugger
