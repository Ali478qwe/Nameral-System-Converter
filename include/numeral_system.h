#ifndef _NUMERAL_SYS_H_
#define _NUMERAL_SYS_H_

#define HEX_CONVERTER_VERSION "V1.0-PROTOTYPE"
#define VERSION_DATE "2026-01-20"

#include <stdbool.h>

typedef enum {
     Sharp,
     Decimal,
     Binary,
     Octal,
     Hexadecimal
}codeflag_t;


//int hexCharToInt(char * character);
// char intToHexChar(int number);

unsigned long long hexToDecimal(char * hex);
void hexToBinary(char hex[],char * output);
void hexToOctal(char hex[],char * output);

void decimalToHex(unsigned int number,char * output);
void decimalToBinary(unsigned int number,char * output);
void decimalToOctal(unsigned int number,char * output);

unsigned long long binaryToDecimal(char binary[]);
void binaryToHex(char binary[],char * output);
void binaryToOctal(char binary[],char * output);



#endif

