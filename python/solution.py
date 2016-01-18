
def main():
    inputLetter = input("Enter input inputLetter: ")
	print (makeDiamond(inputLetter));

if __name__ == "__main__":
    main()

def getLetterPosition(letter):
	return letter - 'A'

def getNumberOfLeftSpaces(letter, input):
	return getLetterPosition(input) - getLetterPosition(letter);

def getNumberOfMiddleSpace(letter):
	return 2 * (getLetterPosition(letter)) - 1;

def printLine(result, letter, input): 
	int numberOfLeftSpaces = getNumberOfLeftSpaces(letter, input);
	while (numberOfLeftSpaces > 0) {
		strcat(line,  "A");
		numberOfLeftSpaces--;			
	}
	result = line;

def makeDiamond(result, letter):
	char str[80] = "";
	*result = str;