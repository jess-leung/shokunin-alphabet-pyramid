#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <regex.h> 

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
	char line[200] = "";
	int position = 0;
	int numberOfLeftSpaces = getNumberOfLeftSpaces(letter, input);
	for (int i = 0; i < numberOfLeftSpaces; i++) {
		line[position++] = ' ';
	}
	line[position++] = letter;
	int numberOfMiddleSpace = getNumberOfMiddleSpace(letter);
	if (numberOfMiddleSpace > 0) {
		numberOfLeftSpaces++;
		for (int i = 0; i < numberOfMiddleSpace; i++) {
			line[position++] = ' ';
		}
		line[position++] = letter; 
	}
	line[position++] = '\n';
	*result = line;
}

void makeDiamond(char** result, char* letters) { 
	char str[10000] = "";
	char *line;
	regex_t regex;
	regcomp(&regex, "^[a-zA-Z]{1,1}$", REG_EXTENDED);
	int regexMatchResult = regexec(&regex, letters, 0, NULL, 0);
	if (regexMatchResult == 1) {
		*result = "Invalid character";
		return;
	}

	char letter = toupper(letters[0]);
	for (int i = 'A'; i < letter; i++) {
		printLine(&line, i, letter);
		strcat(str, line);
	}

	for (int i = letter; i >= 'A'; i--) {
		printLine(&line, i, letter);
		strcat(str, line);
	}

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
	
	assert(strcmp(result, " A\n") == 0);
}

void shouldReturnBSpaceBGivenBForB() {
	char *result;

	printLine(&result, 'B', 'B');
	
	assert(strcmp(result, "B B\n") == 0);
}

void shouldReturnCSpaceSpaceSpaceCGivenDForC() {
	char *result; 

	printLine(&result, 'C', 'D');

	assert(strcmp(result, " C   C\n") == 0);
}

void shouldMakeADimamondGivenA() {
	char *result;

	makeDiamond(&result, "A");

	assert(strcmp(result, "A\n") == 0);
}

void shouldMakeADimamondGivenD() {
	char *result;

	makeDiamond(&result, "D");

	// printf("%s", result);
	assert(strcmp(result, "   A\n  B B\n C   C\nD     D\n C   C\n  B B\n   A\n") == 0);
}

void shouldMakeADimamondGivend() {
	char *result;

	makeDiamond(&result, "d");

	assert(strcmp(result, "   A\n  B B\n C   C\nD     D\n C   C\n  B B\n   A\n") == 0);
}

void shouldNotMakeADimamondGivenSpecialCharacter() {
	char *result;

	makeDiamond(&result, "*");

	assert(strcmp(result, "Invalid character") == 0);
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
		shouldReturnCSpaceSpaceSpaceCGivenDForC();
		shouldMakeADimamondGivenA();
		shouldMakeADimamondGivenD();
		shouldMakeADimamondGivend();
		shouldNotMakeADimamondGivenSpecialCharacter();
	} else {
		char *result;
		makeDiamond(&result, argv[1]);
    	printf("%s", result);
	}
    return 0;
}

