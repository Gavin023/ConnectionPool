all: mytest

mytest: main.o Connection.o ConnectionPool.o
	g++ -o mytest main.o Connection.o ConnectionPool.o -lmysqlclient

main.o: main.cpp Connection.h public.h ConnectionPool.h
	g++ -c main.cpp

Connection.o: Connection.cpp Connection.h public.h
	g++ -c Connection.cpp
ConnectionPool.o:ConnectionPool.cpp ConnectionPool.h public.h
	g++ -c ConnectionPool.cpp 
clean:
	rm -f mytest *.o
