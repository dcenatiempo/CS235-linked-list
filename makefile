###############################################################
# Program:
#     Assignment 06, NODE
#     Brother JonesL, CS235
# Author:
#     Devin Cenatiempo
# Summary:
#     Linked List implementation
###############################################################

##############################################################
# The main rule
##############################################################
a.out: node.h assignment06.o 
	g++ -o a.out assignment06.o  -g
	tar -cf assignment06.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment06.o      : the driver program
#      <anything else?>
##############################################################
assignment06.o: node.h assignment06.cpp sortInsertion.h
	g++ -c assignment06.cpp -g
