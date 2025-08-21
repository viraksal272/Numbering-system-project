#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <math.h>

void getDecimalInput(char *buf, size_t size) {
  printf("Enter decimal number: ");
  fgets(buf, size, stdin);

  size_t len = strlen(buf);
  if (len > 0 && buf[len - 1] == '\n') {
    buf[len - 1] = '\0';
  }
}

void reverse(char hexResult[]) {
  int i, j;
  char temp;
  for (i = 0, j = strlen(hexResult) - 1; i < j; i++, j--) {
    temp = hexResult[i];
    hexResult[i] = hexResult[j];
    hexResult[j] = temp;
  }
}

void decimalToBinary(char deciNum[50]) {
    char integerPart[20];
    char fractionalPart[20];
    char fractionalFloatStr[25];
    char *dotPosition = strchr(deciNum, '.');

    if (dotPosition != NULL) {
        size_t intLen = dotPosition - deciNum;
        strncpy(integerPart, deciNum, intLen);
        integerPart[intLen] = '\0';
        int place = 1;
        int intBinaNum = 0;
        int count = 0;
        int len = 0;
        char fracBinaStr[50] = "";

        strcpy(fractionalPart, dotPosition + 1);
        int intValue = atoi(integerPart);

        snprintf(fractionalFloatStr, sizeof(fractionalFloatStr), "0.%s", fractionalPart);
        float fractionalValue = atof(fractionalFloatStr);

        while (intValue > 0) {
          const int remainder = intValue % 2;
          intBinaNum += remainder * place;
          place *= 10;
          intValue /= 2;
        }

        while (count <= 15) {
          float eachResult = fractionalValue * 2;
          const int digit = (int)eachResult;
          fractionalValue = eachResult - digit;

          int len = strlen(fracBinaStr);
          fracBinaStr[len] = digit + '0';
          fracBinaStr[len + 1] = '\0';

          if (eachResult == 1.00) break;

          count++;
        }

        printf("===================================\n");
        printf("| Decimal: %s\n", deciNum);
        printf("| Binary : %d.%s\n", intBinaNum, fracBinaStr);
        printf("===================================\n");
    } else {
        int binaResult = 0;
        int place = 1;
        strcpy(integerPart, deciNum);
        fractionalPart[0] = '\0';

        long intValue = atoi(integerPart);
        if (intValue == 0) {
          printf("===================================\n");
          printf("| Decimal: %s\n", deciNum);
          printf("| Binary : 0\n");
          printf("===================================\n");
          return;
        }

        while (intValue > 0) {
          const int remainder = intValue % 2;
          binaResult += remainder * place;
          place *= 10;
          intValue /= 2;
        }

        printf("===================================\n");
        printf("| Decimal: %s\n", deciNum);
        printf("| Binary : %d\n", binaResult);
        printf("===================================\n");
    }
}

void decimalToOctal(char decimalNum[50]) {
  char intPart[20];
  char fracPart[20];
  char fracFloatStr[25];
  char *dotPost = strchr(decimalNum, '.');

  if (dotPost == NULL) {
    long int octalResult = 0;
    int place = 1;
    strcpy(intPart, decimalNum);
    fracPart[0] = '\0';

    long intDeci = atoi(intPart);
    if (intDeci == 0) {
      printf("===================================\n");
      printf("| Decimal: %s\n", decimalNum);
      printf("| Octal  : 0\n");
      printf("===================================\n");
      return;
    }

    while (intDeci > 0) {
      int remainder = intDeci % 8;
      octalResult += remainder * place;
      place *= 10;
      intDeci /= 8;
    }

    printf("===================================\n");
    printf("| Decimal: %s\n", decimalNum);
    printf("| Octal  : %d\n", octalResult);
    printf("===================================\n");
  }
  else {
    size_t intLen = dotPost - decimalNum;
    strncpy(intPart, decimalNum, intLen);
    intPart[intLen] = '\0';
    int place = 1;
    long int intOctalResult = 0;

    strcpy(fracPart, dotPost + 1);
    long integerPart = atoi(intPart);

    while (integerPart > 0) {
      int r = integerPart % 8; // r stands for remainder 
      intOctalResult += r * place;
      place *= 10;
      integerPart /= 8;
    }

    snprintf(fracFloatStr, sizeof(fracFloatStr), "0.%s", fracPart);
    float fractionalPart = atof(fracFloatStr);
    int count = 0;
    int len = 0;
    char fracOctStr[50] = "";

    while (count <= 15) {
      fractionalPart *= 8;
      int digit = (int)fractionalPart;
      fractionalPart -= digit;

      int len = strlen(fracOctStr);
      fracOctStr[len] = digit + '0';
      fracOctStr[len + 1] = '\0';

      if (fractionalPart == 0.00) break;

      count++;
    }

    printf("===================================\n");
    printf("| Decimal: %s\n", decimalNum);
    printf("| Octal  : %d.%s\n", intOctalResult, fracOctStr);
    printf("===================================\n");
  }
}

void decimalToHexa(char decimalNumber[50]) {
  char intPart[20];
  char fracPart[20];
  char fracStr[25];
  char *dotPost = strchr(decimalNumber, '.');

  if (dotPost == NULL) {
    char hexResult[50] = "";
    strcpy(intPart, decimalNumber);
    fracPart[0] = '\0';

    long deciNum = atoi(intPart);
    if (deciNum == 0) {
      printf("===================================\n");
      printf("| Decimal    : %s\n", decimalNumber);
      printf("| Hexadecimal: 0\n");
      printf("===================================\n");
      return;
    }

    while (deciNum > 0) {
      int remainder = deciNum % 16;
      char digit = (remainder < 10) ? (remainder + '0') : ('A' + (remainder - 10));
      int len = strlen(hexResult);
      hexResult[len] = digit;
      hexResult[len + 1] = '\0';
      deciNum /= 16;
    }

    reverse(hexResult);
    printf("===================================\n");
    printf("| Decimal    : %s\n", decimalNumber);
    printf("| Hexadecimal: %s\n", hexResult);
    printf("===================================\n");
  }
  else {
    size_t intLen = dotPost - decimalNumber;
    strncpy(intPart, decimalNumber, intLen);
    intPart[intLen] = '\0';
    char intPartResult[50] = "";
    strcpy(fracPart, dotPost + 1);
    long intDeci = atoi(intPart);

    while (intDeci > 0) {
      int remainder = intDeci % 16;
      char digit = (remainder < 10) ? (remainder + '0') : ('A' + (remainder - 10));
      int len = strlen(intPartResult);
      intPartResult[len] = digit;
      intPartResult[len + 1] = '\0';
      intDeci /= 16;
    }

    snprintf(fracStr, sizeof(fracStr), "0.%s", fracPart);
    double fracDeci = atof(fracStr);
    int count = 0;
    int len = 0;
    char fracPartResult[50] = "";


    while (count <= 15) {
      fracDeci *= 16;
      int eachDigit = (int)fracDeci;
      char digit = (eachDigit < 10) ? (eachDigit + '0') : ('A' + (eachDigit - 10));
      int len = strlen(fracPartResult);
      fracPartResult[len] = digit;
      fracPartResult[len + 1] = '\0';
      fracDeci -= eachDigit;

      if (fabs(fracDeci) < 1e-12) break;
      count++;
    }

    reverse(intPartResult);
    if (strlen(intPartResult) == 0) {
      strcpy(intPartResult, "0");
    }
    printf("===================================\n");
    printf("| Decimal    : %s\n", decimalNumber);
    printf("| Hexadecimal: %s.%s\n", intPartResult, fracPartResult);
    printf("===================================\n");
  }
}
int main() {

    while (true) {
      printf("=========================================\n");
      printf("| A -> Decimal to Binary\t\t|\n");
      printf("| B -> Decimal to Octal\t\t\t|\n");
      printf("| C -> Decimal to Hexadecimal\t\t|\n");
      printf("| Press ESC key to exit!\t\t|\n");
      printf("=========================================\n");
      char ch; // get choice from the user
      printf("Enter your choice: ");
      
      ch = getch();

      printf("\n");
      if (ch == 27) {
        printf("Exiting program...!\n");
        printf("Program exited!");
        break;
      }

      char deciInput[50];

      printf("\n");
      switch (ch){
        case 'A':
        case 'a':
                getDecimalInput(deciInput, sizeof(deciInput));
                decimalToBinary(deciInput);
                break;
        case 'B':
        case 'b':
                getDecimalInput(deciInput, sizeof(deciInput));
                decimalToOctal(deciInput);
                break;
        case 'C':
        case 'c':
                getDecimalInput(deciInput, sizeof(deciInput));
                decimalToHexa(deciInput);
                break;
        default:
          printf("Invalid input...!\n");
          break;
      }
    }
    return 0;
}
