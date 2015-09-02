CC = g++
CFLAGS = -c -Wall -g
LDFLAGS = -g

All: Time Date

Time: Time.o main_Time.o  
	$(CC) $(LDFLAGS) Time.o main_Time.o -o Time

Time.o: Time.c Time.h
	$(CC) $(CFLAGS) Time.c

main_Time.o: main_Time.c Time.h
	$(CC) $(CFLAGS) main_Time.c 

Date: Date.o main_Date.o Date_Implementation.o
	$(CC) $(LDFLAGS) Date.o main_Date.o Date_Implementation.o -o Date 

Date.o: Date.c Date.h Date_Implementation.h
	$(CC) $(CFLAGS) Date.c

Date_Implementation.o: Date_Implementation.c Date_Implementation.h
	$(CC) $(CFLAGS) Date_Implementation.c

main_Date.o: main_Date.c Date.h
	$(CC) $(CFLAGS) main_Date.c
