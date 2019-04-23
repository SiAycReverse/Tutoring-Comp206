# Bash Notes

### Bash Basic

Variable:  $<Variable_Name>

```Bash
TEST=MyTest#testBinarySearch
echo $TEST
#output: MyTest#testBinarySearch
```

WildCards

-   **\*** any pattern
-   **?** any single char
-   **\[]** or

### Bash Command List

-   `ls`
-   `cp`
-   `cd`
-   `grep`
    -   used to search for the patterns in output
    -   some common options
        ```Bash
        -i: ignore case
        -c: report only a count of the number of lines that do not match
        -v: invert the search, displaying only lines that do not match
        -n: display the line number along with the line on which a match was found
        -l: list filenames, but not lines, in which matches were found
        ```
-   `>`: redirection, create a new file or overwrite existing file
-   `>>`: redirection, create a new file or append to existing file
-   `tar`
    ```Bash
    -c : create a new tar archive
    -r : update the tar archive
    -x : extract from the tar archive
    -f: specifies the archive file name.
    -v: activates verbose mode, which means the tar command will output lots of information.
    -z: allows you to compress the archive (the archive is compress/decompressed using gzip).
    ```
-   `chmod`

### Bash Scripts Snippets

<https://devhints.io/bash>

###### make your script self-executable

`#!/bin/bash`

###### String quotes

```Bash
NAME="John"
echo "Hi $NAME"  #=> Hi John
echo 'Hi $NAME'  #=> Hi $NAME
```

###### read from STDIN

```Bash
echo "What is your name?"
read name
echo "Your name is $name."  # output: bob
echo 'Your name is $name.'  # output: $name
```

###### Basic math operation

<https://bash.cyberciti.biz/guide/Perform_arithmetic_operations>

```Bash
#!/bin/bash
x=5
y=10
ans=$(( x + y ))
echo "$x + $y = $ans"
# output: 5 + 10 = 15
```

###### Bash if statements

```Bash
if [[ -z "$string" ]];
then
  echo "String is empty"
elif [[ -n "$string" ]];
then
  echo "String is not empty"
else
  echo "i am an else statement"
fi
```

###### Bash Conditions

```Bash
[[ -z STRING ]]	         Empty string
[[ -n STRING ]]	         Not empty string
[[ STRING == STRING ]]	 Equal
[[ STRING != STRING ]]	 Not Equal
[[ NUM -eq NUM ]]	       Equal
[[ NUM -ne NUM ]]	       Not equal
[[ NUM -lt NUM ]]	       Less than
[[ NUM -le NUM ]]	       Less than or equal
[[ NUM -gt NUM ]]	       Greater than
[[ NUM -ge NUM ]]	       Greater than or equal
[[ STRING =~ STRING ]]	 Regexp
(( NUM < NUM ))	         Numeric conditions
[[ ! EXPR ]]	           Not
[[ X ]] && [[ Y ]]	     And
[[ X ]] || [[ Y ]]	     Or
[[ -e FILE ]]	           Exists
[[ -r FILE ]]	           Readable
[[ -d FILE ]]	           Directory
[[ -w FILE ]]	           Writable
[[ -f FILE ]]	           File
[[ FILE1 -ef FILE2 ]]	   Same files
```

###### Bash Conditions Example
```Bash
if ping -c 1 google.com; then
  echo "It appears you have a working internet connection"
fi
if grep -q 'foo' ~/.bash_history; then
  echo "You appear to have typed 'foo' in the past"
fi
# String
if [[ -z "$string" ]]; then
  echo "String is empty"
elif [[ -n "$string" ]]; then
  echo "String is not empty"
fi
# Combinations
if [[ X ]] && [[ Y ]]; then
  ...
fi
# Equal
if [[ "$A" == "$B" ]]
# Regex
if [[ "A" =~ "." ]]
if (( $a < $b )); then
   echo "$a is smaller than $b"
fi
if [[ -e "file.txt" ]]; then
  echo "file exists"
fi
```

###### Bash loops
```Bash
for ((i = 0 ; i < 100 ; i++)); do
  echo $i
done

for i in /etc/rc.*; do
  echo $i
done

for i in {1..5}; do
    echo "Welcome $i"
done

#!/usr/bin/sh
for i in ‘ls $1‘ do
  file $i;
done

while true; do
  ···
  [continue]
  [break]
done
```

###### Bash Functions
```Bash
myfunc() {
    echo "hello $1"
}
# Same as above (alternate syntax)
function myfunc() {
    echo "hello $1"
}
myfunc "John"

myfunc() {
    local myresult='some value'
    echo $myresult
}
result="$(myfunc)"


myfunc() {
  return 1
}
if myfunc; then
  echo "success"
else
  echo "failure"
fi
```

###### Bash Arguments
```Bash
$#	Number of arguments
$*	All arguments
$@	All arguments, starting from first
$1	First argument
```
