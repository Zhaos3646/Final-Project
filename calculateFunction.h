#include <stdio.h>
#include <math.h>
#include <string.h>

float convert (char FromCurrency[255], char ToCurrency[255], float start) {
  char currencyArray[][255] = {"euro", "pound", "rupee", "dollar"};
  float rateExchange[] = {0.885597, 0.786504, 69.190658};
  if (strcmp(FromCurrency, "dollar") == 0) {
    for (int i = 0; i < 3; i++) {
	if (strcmp(ToCurrency, currencyArray[i]) == 0) {
	    start = start * rateExchange[i];
	    return(start);
	}
    }
  }
  else if (strcmp(ToCurrency, "dollar") == 0) {
    for (int i = 0; i < 3; i++) {
	if (strcmp(FromCurrency, currencyArray[i]) == 0) {
	    start = start / rateExchange[i];
	    return(start);
	}
    }
  }
  else {
    for (int i = 0; i < 3; i++) {
	if (strcmp(ToCurrency, currencyArray[i]) == 0) {
	    start = start * rateExchange[i];
	}
    }
    for (int i = 0; i < 3; i++) {
	if (strcmp(FromCurrency, currencyArray[i]) == 0) {
	    start = start / rateExchange[i];
	    return(start);
	}
    }
  }
}

void currencyExchange (char inputString[255]) {
    int count = 0;
    int* pos1;
    int* pos2;
    int index;
    char currencyArray[][255] = {"euro", "pound", "rupee", "dollar"};
    char currencyFrom[255];
    char currencyTo[255];
    char currencyTemp[255];
    for(int i = 0; i<4; i++) {
	if (strstr(inputString, currencyArray[i])) {
	    count++;
	    if (count == 1) {
	      pos1 = strstr(inputString, currencyArray[i]);
		    strcpy(currencyFrom, currencyArray[i]);
	    }
	    else if (count == 2) {
		    pos2 = strstr(inputString, currencyArray[i]);
    		strcpy(currencyTo, currencyArray[i]);
	    }
	    else {
		printf("Too many currencies\n");
		break;
	    }
	}
    }
    if (count < 2) {
	printf("Input 2 distinct currencies\n");
	return;
    }
    if (pos1 > pos2) {
	//printf("To %s From %s\n", currencyTo, currencyFrom);
	strcpy(currencyTemp, currencyFrom);
	strcpy(currencyFrom, currencyTo);
	strcpy(currencyTo, currencyTemp);
	//printf("To %s From %s\n", currencyTo, currencyFrom);
    }
    for (int i = 0; i < strlen(inputString); i++) {
	if (inputString[i] == currencyFrom[0]) {
	    index = i;
	    break;
	}
    }
  char money[255];
  float fromValue;
  memcpy(money, &inputString[0], index);
  //printf("%s\n", money);
  sscanf(money, "%f", &fromValue);
  //printf("%f\n", fromValue);
  float toValue = convert(currencyFrom, currencyTo, fromValue);
  //printf("%f\n", toValue);
  printf("%f %ss is equal to %f %ss\n", fromValue, currencyFrom, toValue, currencyTo);
}
