CPP_FLAGS = -std=c++11 -Wall -Wextra -Werror

#Linux
#CC = g++
#RM = rm -f

#Mac OS X
CC = g++
RM = rm -f

#Windows
#CC = c:\mingw\bin\g++
#RM = del # cmd.exe
#RM = rm -fo # PowerShell

test.exe: test.cpp bstree.hpp word.o
<<<<<<< HEAD
	$(CC) $(CPP_FLAGS) word.o test.cpp -o test.exe
	
word.o: word.h word.cpp 
	$(CC) $(CPP_FLAGS) -c word.cpp -o word.o
	
=======
	$(CC) $(CPP_FLAGS) test.cpp word.o -o test.exe

word.o: word.h word.cpp
	$(CC) $(CPP_FLAGS) -c word.cpp -o word.o

>>>>>>> 158fae2b22b5d261fd7f0ba368780bbb2bea9026
driver.exe: driver.cpp bstree.hpp word.o
	$(CC) $(CPP_FLAGS) driver.cpp word.o -o driver.exe

clean:
	$(RM) *.o

cleanall: clean
	$(RM) *.exe
