# HexTrim

**Hextrim use stdin as input and copy it to stdout cutting out every matches of the bynary string given as parameter.**

Hextrim is a simple tool I wrote in 2008 that executes a simple task curiosly not performed by any unix standard tool.
Hextrim use stdin as input and copy it to stdout cutting out every matches of the bynary string given as 
parameter with a syntax clearer than sed.

You can do

    cat foo.dat | hextrim 1CAFFE >> bar.dat

which is better than

    cat foo.dat | sed 's/\x1C\xAF\xFE/g' >> bar.dat


Hextrim is given under the Gnu GPL license.


