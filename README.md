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
The program starts by reading the first 10 characters of the file. Then it goes through it to identify the first new line character, and saves all the one before in a temporary variable.
The variable is then cast as an int, this gives us the dimension of the map. The rest of the characters read are copied in a an array, that is the size of the map given in the map.
Then, the rest of the map is copied and string is converted as an array of integer. If the character is a '.', the value is 1, if the character is a 'o', the value is 0.
Afterwards, the newly created array goes throught a recursive program that converts each number, to know were the biggest square is. The number are converted depending on the minimum of the previous number,
the one in diagonal up left and the one up the current number, plus one.

Exemple :
```
11
01
```
The value of the bottom right number is 1, because the value of its surronding is 1 in the diagonal, 1 up and 0 to the left.

The array is transformed one last time to write where the square will be with -1. The biggest number is the transform array is found. It symbolise the bottom right corner of the square.
The square is then filed, starting from the bottom right all the way to the top left.

Finally, the array is printed in the terminal. The -1 is a 'x' character, to show where the square, the 0 is a 'o' character,that shows the obstacles and any number above 0 is a '.' character,
that shows the other free spaces left. 

## Installation
I didn't have any installation to do.

## Usage
In order to use the program, you need to call it with a file. The format of the name of the file needs to be "mapXxY.txt", were X and Y are the dimension of the map.

Exemple :
```
./my_bsq map10x10.txt
```

If you need to compile the code, you can do so by using the following command :
```
make
``` 
