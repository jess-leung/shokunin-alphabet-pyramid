#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void makeDiamond(char** result, char letter) { 
	char str[80] = "";
	*result = str; 
}

int getLetterPosition(char letter) {
	return letter - 'A';
}

int getNumberOfLeftSpaces(char letter, char input) {
	return getLetterPosition(input) - getLetterPosition(letter);
}

int getNumberOfMiddleSpace(char letter, char input) {
	return 0;
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

// MAIN
int main(int argc, char **argv){
	if (strcmp(argv[1], "test") == 0) {
		shouldReturnZeroNumberOfSpacesForCGivenC();
		shouldReturnOneNumberOfSpacesForCGivenB();
		shouldReturnTwoNumberOfSpacesForCGivenA();
	} else {
		char *result;
		makeDiamond(&result, argv[1][0]);
    	printf("%s", result);
	}
    return 0;
}

