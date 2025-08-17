#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

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
          int remainder = intValue % 2;
          intBinaNum += remainder * place;
          place *= 10;
          intValue /= 2;
        }

        while (count <= 15) {
          float eachResult = fractionalValue * 2;
          int digit = (int)eachResult;
          fractionalValue = eachResult - digit;

          int len = strlen(fracBinaStr);
          fracBinaStr[len] = digit + '0';
          fracBinaStr[len + 1] = '\0';

          if (eachResult == 1.00) break;

          count++;
        }

        printf("Decimal: %s\n", deciNum);
        printf("Binary: %d.%s\n", intBinaNum, fracBinaStr);
    } else {
        int binaResult = 0;
        int place = 1;
        strcpy(integerPart, deciNum);
        fractionalPart[0] = '\0';

        int intValue = atoi(integerPart);

        while (intValue > 0) {
          int remainder = intValue % 2;
          binaResult += remainder * place;
          place *= 10;
          intValue /= 2;
        }

        printf("Decimal: %s\n", deciNum);
        printf("Binary: %d\n", binaResult);
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
        break;
      }

      printf("\n");
      switch (ch){
        case 'A':
        case 'a':
                char deciNum[50];

                printf("Enter decimal number: ");
                fgets(deciNum, sizeof(deciNum), stdin);

                size_t len = strlen(deciNum);
                if (len > 0 && deciNum[len - 1] == '\n') {
                    deciNum[len - 1] = '\0';
                }
                decimalToBinary(deciNum);
                break;
        default:
          printf("Invalid input...!\n");
          break;
      }
    }
    return 0;
}
void DecimalToOctal(char deciNum[50]) {
    char integerPart[20];
    char fractionalPart[20];

}