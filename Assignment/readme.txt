Daniel Rourke 19386993

cc AssOne
./a.out


-----------------------------------------
build list function

make pointer previous equal Null 
initialise an index

loop
    make new list item
    make random vaule and set to base_pri
    make charfiller equal index as string
    make link point equal to previous
    make previous point to this list item

make a pointer Head equal previous

return Head

----------------------------------------

----------------------------------------
bubble sort list funtion

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
-----------------------------------------
swap pointers function

take two pointers a, b
make temp pointer c


make c = a
make a = b
make b = c

return a, b


-----------------------------------------
-----------------------------------------
print list funtion


for all element of list
	print to screen

-----------------------------------------

-----------------------------------------
test list sorted function

for all elements in list 
 	if next element value is less the current value
	return -1;

return 1;

-------------------------------------------



Test method
create unorded list
print list
apply sort function to list
check if each item is sorted


