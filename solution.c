#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int getLetterPosition(char letter) {
	return letter - 'A';
}

int getNumberOfLeftSpaces(char letter, char input) {
	return getLetterPosition(input) - getLetterPosition(letter);
}

int getNumberOfMiddleSpace(char letter) {
	return 2 * (getLetterPosition(letter)) - 1;
}

void printLine(char** result, char letter, char input) { 
	char line[100] = "";
	int numberOfLeftSpaces = getNumberOfLeftSpaces(letter, input);
	for (int i = 0; i < numberOfLeftSpaces; i++) {
		line[i] = ' ';
	}
	line[numberOfLeftSpaces] = letter;
	int numberOfMiddleSpace = getNumberOfMiddleSpace(letter);
	if (numberOfMiddleSpace > 0) {
		numberOfLeftSpaces++;
		for (int i = 0; i < numberOfMiddleSpace; i++) {
			line[numberOfLeftSpaces + i] = ' ';
		}
		line[numberOfLeftSpaces + numberOfMiddleSpace] = letter; 
	}
	*result = line;
}

void makeDiamond(char** result, char letter) { 
	char str[80] = "";
	*result = str; 
}

// TESTS
void shouldReturnZeroNumberOfSpacesForCGivenC() {
	int result = getNumberOfLeftSpaces('C', 'C');

	assert(result == 0);
}

void shouldReturnOneNumberOfSpacesForCGivenB() {
	int result = getNumberOfLeftSpaces('B', 'C');

	assert(result == 1);
}

void shouldReturnTwoNumberOfSpacesForCGivenA() {
	int result = getNumberOfLeftSpaces('A', 'C');

	assert(result == 2);
}

void shouldReturnThreeNumberOfMiddleSpacesForC() {
	int result = getNumberOfMiddleSpace('C');

	assert(result == 3);
}

void shouldReturnOneNumberOfMiddleSpacesForB() {
	int result = getNumberOfMiddleSpace('B');
	
	assert(result == 1);
}

void shouldReturnSingleAGivenAForA() {
	char *result;

	printLine(&result, 'A', 'B');
	
	assert(strcmp(result, " A") == 0);
}

void shouldReturnBSpaceBGivenBForB() {
	char *result;

	printLine(&result, 'B', 'B');
	
	assert(strcmp(result, "B B") == 0);
}

// MAIN
int main(int argc, char **argv){
	if (strcmp(argv[1], "test") == 0) {
		shouldReturnZeroNumberOfSpacesForCGivenC();
		shouldReturnOneNumberOfSpacesForCGivenB();
		shouldReturnTwoNumberOfSpacesForCGivenA();
		shouldReturnThreeNumberOfMiddleSpacesForC();
		shouldReturnOneNumberOfMiddleSpacesForB();
		shouldReturnSingleAGivenAForA();
		shouldReturnBSpaceBGivenBForB();
	} else {
		char *result;
		makeDiamond(&result, argv[1][0]);
    	printf("%s", result);
	}
    return 0;
}

