CC = gcc
CFLAGS = -ansi -Wall
all: daysCalculatorA.c daysCalculatorB.c daysCalculatorC.c daysCalculatorD.c daysCalculatorE.c
	$(CC) $(CFLAGS) -o daysCalculatorA daysCalculatorA.c
	$(CC) $(CFLAGS) -o daysCalculatorB daysCalculatorB.c
	$(CC) $(CFLAGS) -o daysCalculatorC daysCalculatorC.c
	$(CC) $(CFLAGS) -o daysCalculatorD daysCalculatorD.c
	$(CC) $(CFLAGS) -o daysCalculatorE daysCalculatorE.c

daysCalculatorA: daysCalculatorA.c
	$(CC) $(CFLAGS) -o daysCalculatorA daysCalculatorA.c

daysCalculatorB: daysCalculatorB.c
	$(CC) $(CFLAGS) -o daysCalculatorB daysCalculatorB.c

daysCalculatorC: daysCalculatorC.c
	$(CC) $(CFLAGS) -o daysCalculatorC daysCalculatorC.c

daysCalculatorD: daysCalculatorD.c
	$(CC) $(CFLAGS) -o daysCalculatorD daysCalculatorD.c

daysCalculatorE: daysCalculatorE.c
	$(CC) $(CFLAGS) -o daysCalculatorE daysCalculatorE.c

clean:
	-rm daysCalculatorA daysCalculatorB daysCalculatorC daysCalculatorD daysCalculatorE
