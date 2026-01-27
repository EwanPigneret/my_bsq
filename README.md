# Welcome to My Bsq
***

## Task
The task is to process a map, written in a file. The map is made of characters, that are '.' and 'o'. The 'o' are obstacles and the '.' are free spaces. The goal is to find the first biggest square that you can make in this map.
The square is represented by the characters 'x'. The function doesn't return anything.

Exemple :
```
./my_bsq map5x5.txt
```

Content of map5x5.txt
```
.o...
o.o..
.o...
..oo.
..o.o
```

Output
```
.o.xx
o.oxx
.o...
..oo.
..o.o
```

## Description
The program firstly reads the content of the file given, and save it in a string. Then, the string is converted as an array of integer. If the character is a '.', the value is 1, if the character is a 'o', the value is 0.
Afterwards, the newly created array goes throught a recursive program that converts each number, to know were the biggest square is. The number are converted depending on the minimum of the previous number,
the one in diagonal up left and the one up the current number, plus one.

Exemple :
```
11
01
```
The value of the bottom right number is 1, because the value of its surronding is 1 in the diagonal, 1 up and 0 to the left.

## Installation
I didn't have any installation to do.

## Usage
In order to use the program, you need to call it with a file. The format of the name of the file needs to be "mapXxY.txt", were X and Y are the dimension of the map.

If you need to compile the code, you can do so by using the following command :
```
$>make
``` 

Exemple :
```
$>./my_bsq map10x10.txt
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
