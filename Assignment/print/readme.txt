Daniel Rourke 19386993

to run program
compile and link:
	cc -c -g iorb.c
	cc -c -g main.c
	cc -o main main.o iorb.o
to run:
	./main
OR
	./main (insert Posative IntgerHere, Must be less than 10000)

Note: larger numbers require longer running times



-----------------------------------------
build list function
-----------------------------------------
make pointer previous equal Null 
initialise an index

loop
    make new list item
    make random vaule and set to base_pri
    make random charfiller with size equal index or maxSize as a string
    make link point equal to previous
    make previous point to this list item

make a pointer Head equal previous

return Head



----------------------------------------
bubble sort list funtion
----------------------------------------
take a pointer head

while list is not sorted loop
    make pointer previous equal to Head
 

    while two does not equal NULL loop
	make pointer one point to what previous points to
    	make pointer two point to what one points to
        

	if one value > two value
	    swap what one and two points too
	    set list to not sorted
	
	make pointer previous equal to one
 

-----------------------------------------
swap pointers function
-----------------------------------------
take three pointer pointers A, B, C

assign value to temp pointers a b c


make C = a
make A = b
make B = c



-----------------------------------------
print list funtion
-----------------------------------------
for all element of list
	print to screen



-----------------------------------------
test list sorted function
-----------------------------------------
for all elements in list 
 	if next element value is less the current value
	return -1;

return 1;

-----------------------------------------
Test sort function method
-----------------------------------------
create unorded list
print list
apply sort function to list
check if each item is sorted
print list


-----------------------------------------
Test input validation method
-----------------------------------------


run program with non numeric characters
run program with negative intergers
run program with float
run program with Posative intergers above 10000
run program with Posative intergers below 10000
run program with no extra parrameters


-----------------------------------------
Test Output
-----------------------------------------


-bash-4.1$ cc -c -g iorb.c
-bash-4.1$ cc -c -g main.c
-bash-4.1$ cc -o main main.o iorb.o
-bash-4.1$ ./main gggg
Usage: ./main or ./main integer-bash-4.1$ 
-bash-4.1$ clear
-bash-4.1$ cc -c -g iorb.c
-bash-4.1$ cc -c -g main.c
-bash-4.1$ cc -o main main.o iorb.o
-bash-4.1$ ./main gggg
Usage: ./main or ./main integer
-bash-4.1$ ./main -2
Usage: ./main or ./main integer
-bash-4.1$ ./main 2.5
Usage: ./main or ./main integer
-bash-4.1$ ./main 10001
Integer must be less than 10000
Usage: ./main or ./main integer
-bash-4.1$ ./main 5
Insert element front 2 (nil) WS
Insert element front 5 0x107b010 TYUPX
Insert element front 2 0x107b090 PE
Insert element front 4 0x107b110 JIPT
Insert element front 2 0x107b190 BA
Start printing the List ...
 | 2 - BA | 
 | 4 - JIPT | 
 | 2 - PE | 
 | 5 - TYUPX | 
 | 2 - WS | 
 
Start testing the list ...
 ...The List is sorted
 
Start printing the List ...
 | 2 - BA | 
 | 2 - PE | 
 | 2 - WS | 
 | 4 - JIPT | 
 | 5 - TYUPX | 
 
-bash-4.1$ ./main
Insert element front 13 (nil) ZWOSGRIVWMUJX
Insert element front 16 0xbc5010 FLMPPWIBLQCMQUGE
Insert element front 1 0xbc5090 H
Insert element front 1 0xbc5110 D
Insert element front 10 0xbc5190 HUJCTWYETG
Insert element front 17 0xbc5210 EUBVQLWBDAQTUWAJF
Insert element front 15 0xbc5290 OFHIQMDMMKHSWNO
Insert element front 14 0xbc5310 IEMGIPIYLDWLOB
Insert element front 14 0xbc5390 CIVMZHQNVCXOYM
Insert element front 17 0xbc5410 XXJJFTAOTNTRAHUMJ
Insert element front 8 0xbc5490 JVESNTNP
Insert element front 15 0xbc5510 DPHIOETZJOAZHPS
Insert element front 17 0xbc5590 QBUEKXNIDHXXUPRAE
Insert element front 17 0xbc5610 ITEDUQRWPAMKACLUG
Insert element front 19 0xbc5690 UVGXCDWYSOYZOIUTLOJ
Insert element front 19 0xbc5710 LYEXIEBUBJSVEYUIDRG
Insert element front 9 0xbc5790 HHVVPRODF
Insert element front 18 0xbc5810 HSYMPISSETBWOHWJPA
Insert element front 13 0xbc5890 YWJHTGWKXZRWH
Insert element front 5 0xbc5910 WVBFN
Start printing the List ...
 | 5 - WVBFN | 
 | 13 - YWJHTGWKXZRWH | 
 | 18 - HSYMPISSETBWOHWJPA | 
 | 9 - HHVVPRODF | 
 | 19 - LYEXIEBUBJSVEYUIDRG | 
 | 19 - UVGXCDWYSOYZOIUTLOJ | 
 | 17 - ITEDUQRWPAMKACLUG | 
 | 17 - QBUEKXNIDHXXUPRAE | 
 | 15 - DPHIOETZJOAZHPS | 
 | 8 - JVESNTNP | 
 | 17 - XXJJFTAOTNTRAHUMJ | 
 | 14 - CIVMZHQNVCXOYM | 
 | 14 - IEMGIPIYLDWLOB | 
 | 15 - OFHIQMDMMKHSWNO | 
 | 17 - EUBVQLWBDAQTUWAJF | 
 | 10 - HUJCTWYETG | 
 | 1 - D | 
 | 1 - H | 
 | 16 - FLMPPWIBLQCMQUGE | 
 | 13 - ZWOSGRIVWMUJX | 
 
Start testing the list ...
 ...The List is sorted
 
Start printing the List ...
 | 1 - D | 
 | 1 - H | 
 | 5 - WVBFN | 
 | 8 - JVESNTNP | 
 | 9 - HHVVPRODF | 
 | 10 - HUJCTWYETG | 
 | 13 - YWJHTGWKXZRWH | 
 | 13 - ZWOSGRIVWMUJX | 
 | 14 - CIVMZHQNVCXOYM | 
 | 14 - IEMGIPIYLDWLOB | 
 | 15 - DPHIOETZJOAZHPS | 
 | 15 - OFHIQMDMMKHSWNO | 
 | 16 - FLMPPWIBLQCMQUGE | 
 | 17 - ITEDUQRWPAMKACLUG | 
 | 17 - QBUEKXNIDHXXUPRAE | 
 | 17 - XXJJFTAOTNTRAHUMJ | 
 | 17 - EUBVQLWBDAQTUWAJF | 
 | 18 - HSYMPISSETBWOHWJPA | 
 | 19 - LYEXIEBUBJSVEYUIDRG | 
 | 19 - UVGXCDWYSOYZOIUTLOJ | 




