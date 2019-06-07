#include <string.h>
#include <stdio.h>
#include <math.h>
#include <calculateFunction.h>

int main(int argc,char* argv[]) {
    char stringInput[255];
    for (int i = 1; i < 100; i++) {
	if (argv[i]) {
            strcat (stringInput, argv[i]);
        }
	else {
	    break;
	}
    }
   // printf("%s\n", stringInput);
    currencyExchange(stringInput);
}
