# HexTrim

**Hextrim use stdin as input and copy it to stdout cutting out every matches of the bynary string given as parameter.**

Hextrim is a simple tool I wrote in 2008 that executes a simple task curiosly not performed by any unix standard tool.
Hextrim use stdin as input and copy it to stdout cutting out every matches of the bynary string given as 
parameter with a syntax clearer than sed.

You can do

    cat foo.dat | hextrim 1CAFFE >> bar.dat

which is better than

    cat foo.dat | sed 's/\x1C\xAF\xFE/g' >> bar.dat

Here a better example:

	thedarshan: ~/Documents/hextrim $ hexdump AUTHORS 
	0000000 6956 636e 6e65 6f7a 4c20 2061 7053 7365
	0000010 0a61 6956 636e 6e65 6f7a 616c 7073 7365
	0000020 4061 6d67 6961 2e6c 6f63 0a6d          
	000002c
	thedarshan: ~/Documents/hextrim $ cat AUTHORS | ./hextrim 0A >> bar.txt
	thedarshan: ~/Documents/hextrim $ hexdump bar.txt 
	0000000 6956 636e 6e65 6f7a 4c20 2061 7053 7365
	0000010 5661 6e69 6563 7a6e 6c6f 7361 6570 6173
	0000020 6740 616d 6c69 632e 6d6f               
	000002a

It works using the Knuth-Morris-Pratt search.

## Compiling

Just 

	make all

You'll need g++ of course.

Hextrim uses old BorlandCpp pragmas ( as I originally wrote it for WindowsXP ) but gcc will simply ignore it.

## Dependencies

None. It's just plain standard Cpp.


## License
Hextrim is given under the Gnu GPL license.


