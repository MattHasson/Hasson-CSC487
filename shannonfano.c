#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convertToInt(char inChar){
	switch(inChar) {
		case 'A':
			return 0;
		case 'B':
			return 1;
		case 'C':
			return 2;
		case 'D':
			return 3;
		case 'E':
			return 4;
		case 'F':
			return 5;
		default:	
			return -1;
	}
}

int main() {
	char inString[] = "ABCDEF";
	char encoder[6][5] = {"00", "01", "10", "110", "1110", "1111"};
	char outString[64] = "";
	outString[0] = '\0';


	for (int i = 0; i < sizeof(inString)-1; i++) {
		strcat(outString, encoder[convertToInt(inString[i])]);
	} 

	printf("%s\n", outString);

	return 0;
}
