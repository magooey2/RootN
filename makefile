
all : test_rt3                    # test_rt2   

test_rt3: test_rt3.o rtN_int.o
	g++ test_rt3.o rtN_int.o -o test_rt3

test_rt2: test_rt2.o rtN_int.o
	g++ test_rt2.o rtN_int.o -o test_rt2

test_rt2.o: test_rt2.cpp rtN_int.h
	g++ -c test_rt2.cpp
	
rtN_int.o : rtN_int.cpp rtN_int.h
	g++ -c rtN_int.cpp

test_rt3.o : test_rt3.cpp rtN_int.h
	g++ -c test_rt3.cpp

clean:
	rm -f *.o test_rt2 test_rt3 a.out *~ *.bak 
	
