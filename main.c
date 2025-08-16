#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char text[]="\033[1mNUMBER CONVERTER\033[0m";
    int width = 120;
    int space = (width - strlen(text)) / 2;
    int choice;
    for (int i = 0; i < space; i++) {
        printf(" ");
    }
    printf("%s\n\n", text);
    printf("Please select the type of conversion you want to do\n\n");
    printf("1.Decimal to Binary\n\n");
    printf("2.Decimal to Octal\n\n");
    printf("3.Decimal to Hexadecimal\n\n");
    printf("4.Binary to Decimal\n\n");
    printf("Enter your choice(number only) : ");
    scanf("%d",&choice);

    //to seperate all the tasks to different part

    switch (choice) {
        case 1:
            printf("Decimal to Binary\n\n");
            DecToBin();
            break;
        case 2:
            printf("Decimal to Octal\n\n");
            DecToOctal();
            break;
        case 3:
            printf("Decimal to Hexadecimal\n\n");
            DecToHex();
            break;
        case 4:
            printf("Binary to Decimal\n\n");
            BinToDec();
            break;
        default:
            printf("Invalid Choice\n\n");
            break;
    }
    system("pause");
    return 0;
}

//to write the code that make the program works

void DecToBin() {
    int num;
    int binary[32];
    int i = 0;
    char text[]="\033[1mHere you can convert Decimal to Binary\033[0m";
    int width = 120;
    int space = (width - strlen(text)) / 2;
    int choice;
    for (int i = 0; i < space; i++) {
        printf(" ");
    }
    printf("%s\n\n",text);
    printf("Please enter your Decimal number : ");
    scanf("%llu",&num);
    if (num == 0) {
        printf("Binary = 0\n");
        return;
    }
    printf("\n");
    while (num > 0) {
        binary[i] = num % 2;
        num = num / 2;
        i++;
    }
    printf("Binary = ");
    for (int j = 0; j < i; j++) {
        printf("%d", binary[j]);
    }
    printf("\n\n");
}
void DecToOctal() {
    int num;
    int octal[32];
    int i = 0;
    char text[]="\033[1mHere you can convert Decimal to OctalDecimal\033[0m";
    int width = 120;
    int space = (width - strlen(text)) / 2;
    int choice;
    for (int i = 0; i < space; i++) {
        printf(" ");
    }
    printf("%s\n\n",text);
    printf("Please enter your Decimal Number : ");
    scanf("%llu",&num);


}
void DecToHex() {
    int num;
    int decimal[32];
    int i = 0;
    char text[]="\033[1mHere you can convert Decimal to HexaDecimal\033[0m";
    int width = 120;
    int space = (width - strlen(text)) / 2;
    int choice;
    for (int i = 0; i < space; i++) {
        printf(" ");
    }
    printf("%s\n\n",text);
    printf("Please enter your Decimal number : ");
    scanf("%llu",&num);
    //Please write the algorithm here
}

void BinToDec() {
    unsigned long long binary;
    int Decimal = 0;
    int base = 1;
    int remainder;
    char text[] = "\033[1mHere you can convert Binary to Decimal\033[0m";
    int width = 120;
    int space = (width - strlen(text)) / 2;
    int choice;
    for (int i = 0; i < space; i++) {
        printf(" ");
    }
    printf("%s\n\n", text);
    printf("Please enter your Binary number : ");
    scanf("%llu", &binary);
    unsigned long long temp = binary;   //start to check if the binary is valid
    int valid = 1;
    while (temp > 0) {
        int digit = temp % 10;
        if (digit !=0 && digit != 1) {
            valid = 0;
            break;
        }
        temp /= 10;
    }
    if (!valid){
        printf("\n\nInvalid Binary Number, Please try again\n\n");
        return;
    }
        while (binary > 0) {           //conversion
            remainder = binary % 10;
            Decimal += remainder * base;
            base *= 2;
            binary /= 10;
        }
        printf("Decimal = %d\n ", Decimal);
    }