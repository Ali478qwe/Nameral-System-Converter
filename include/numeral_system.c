/** HEX TO DECIMAL CONVERTER - PROTOTYPE V1.0
 * 
 * Features:
 * Supports # and 0x prefixes
 * Invalid character error detection
 * 
 * Limitations:
 * Overflow in large numbers (without overflow management)
 * 
 * Date : 2026/01/20
 * Author : ALI478QWE
 * Status : Primary Model-For Development and Testing
 * 
 * Tips: 
 * Auxiliary functions are limited to static
 * Simple interface for concept testing
 * 
 */
#include "numeral_system.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>


//find flag : #-0b-0x-0b
static codeflag_t findCodeFlag(char character[]){
   int len = strlen(character);

   if(character[0] == '#')
     return Sharp;
   else if(len>= 2 && character[0] == '0' && tolower(character[1]) == 'x')
     return Hexadecimal;
   else if(len>= 2 && character[0] == '0' && tolower(character[1]) == 'b')
     return Binary;
   else if(len>= 2 && character[0] == '0' && tolower(character[1]) == 'o')
     return Octal;
}

static int startCodeIndex(codeflag_t flag){
     switch (flag)
     {
     case Sharp:
          return 1;
          break;
     case Hexadecimal:
          return 2;
          break;
     case Binary:
          return 2;
          break;
     case Octal:
          return 2;
          break;
     default:
          return 0;
          break;
     }
}

static int hexCharToInt(char * character){
    if(*character >= '0' && *character <= '9') 
         return *character - '0';
    else if(*character >= 'A' && *character <= 'F') 
         return *character - 'A' + 10;
    else if(*character >= 'a' && *character <= 'f') 
         return *character - 'a' + 10; 
    else
         return -1;
}

char intToHexChar(int number){
     if(number >= 0 && number <= 9) 
         return (char)(number + 48);
    else if(number >= 10 && number <= 15) 
         return (char)(number + 55);
    else
         return -1;

}

unsigned long long hexToDecimal(char hex[]){

   int len = strlen(hex);
   int start = startCodeIndex(findCodeFlag(hex));
   

    unsigned long long result = 0;
    int digit = 0;

    //convert type
    for(int i = start;i < len;i++){
        
      if(isxdigit(hex[i])){

          digit = hexCharToInt(&hex[i]);
          result = (result * 16) + digit;//Horners Law

      }else
          return -1;

      if(result < 0){
        printf("Error: Number is very big");
        return -1;
      }    
      
    }
    return result;
}

void hexToBinary(char hex[],char * output){
     __u_int len = strlen(hex);
     __u_int start = startCodeIndex(findCodeFlag(hex));
     __u_int out_index = 2;

     output[0] = '0';
     output[1] = 'b';

     for(__u_int i = start;i < len;i++){

          if(isxdigit(hex[i])){

               __u_int value = hexCharToInt(&hex[i]);

               for(__uint8_t bit = 3; bit < 4;bit--){
                    output[out_index++] = ((value >> bit) & 1)?'1':'0';
               }

               // if(i < len - 1){
               //      output[out_index++] = ' ';
               // }
          }
     }
     
     output[out_index] = '\0';

}

void hexToOctal(char hex[],char * output){
     unsigned long long Decimal = hexToDecimal(hex);
     decimalToOctal(Decimal,output);
}

void decimalToHex(unsigned int number,char * output){
     char temp[20];
     int i = 0;

     if(number == 0){
       output[0] = '0';
       output[1] = 'x';
       output[2] = '0';
       output[3] = '\0';
       return;
     }

     while(number > 0){
       int remainder = number % 16;
       temp[i] = intToHexChar(remainder);
       number = number / 16;
       i++;
     }

     output[0] = '0';
     output[1] = 'x';

     for(int j = 0; j < i;j++){
       output[j+2] = temp[i-j-1];
     }

     output[i+2] = '\0';
     
}

void decimalToBinary(unsigned int number,char * output){
     char temp[33]; // 32 bit + nullbit
     int i = 0;

     if(number == 0){
       strcpy(output,"0b0");
       return;
     }

     while(number > 0){
       temp[i++] = (number % 2) + '0' ;
       number /= 2;
     }

     output[0] = '0';
     output[1] = 'b';

     for(int j = 0; j < i;j++){
       output[j+2] = temp[i-j-1];
     }

     output[i+2] = '\0';
     
}

void decimalToOctal(unsigned int number,char * output){
     char temp[60];
     int i = 0;

     if(number == 0){
       strcpy(output,"0o0");
       return;
     }

     while(number > 0){
       temp[i++] = (number % 8) + '0' ;
       number /= 8;
     }

     output[0] = '0';
     output[1] = 'o';

     for(int j = 0; j < i;j++){
       output[j+2] = temp[i-j-1];
     }

     output[i+2] = '\0';
}

unsigned long long binaryToDecimal(char binary[]){
     int len = strlen(binary);
     int start = startCodeIndex(findCodeFlag(binary));
     unsigned long long result = 0;

     for(int i = start; i < len;i++){

          if(binary[i] == ' ') continue;

          result <<= 1;

          if(binary[i] == '1'){
               result |= 1;
          }else if(binary[i] == '0'){

          }else{
               return -1;
          }
     }
     return result;
}

void binaryToHex(char binary[],char * output){
     char clean_bit[100];
     int len = strlen(binary);

     __uint8_t start = startCodeIndex(findCodeFlag(binary));    
     __uint8_t clean_start = 0;  
     __uint8_t padding = 0;
     __uint8_t hex_index = 2;

     for(__uint8_t i = start; i < len;i++){
          // if(binary[i] == ' ')continue;
          clean_bit[clean_start++] = binary[i];
     }

     clean_bit[clean_start] = '\0';

     __uint8_t clean_len = strlen(clean_bit);


     padding = (4 - (clean_len % 4)) % 4;
     
     output[0] = '0';
     output[1] = 'x';

     for(__uint8_t i= 0; i< clean_len + padding;i += 4){
          __uint8_t  value = 0; 

          for(__uint8_t j = 0; j < 4;j++){
               __int8_t bit_pos = i + j - padding;
               char bit_char;

               bit_char  = (bit_pos < 0)?'0':clean_bit[bit_pos];

               value = (value << 1) | (bit_char - '0');
          }

          output[hex_index++] = intToHexChar(value);
     }
     output[hex_index] = '\0';
}

void binaryToOctal(char binary[],char * output){
     char clean_bit[100];
     int len = strlen(binary);

     __uint8_t start = startCodeIndex(findCodeFlag(binary));    
     __uint8_t clean_start = 0;  
     __uint8_t padding = 0;
     __uint8_t hex_index = 2;

     for(__uint8_t i = start; i < len;i++){
          // if(binary[i] == ' ')continue;
          clean_bit[clean_start++] = binary[i];
     }

     clean_bit[clean_start] = '\0';

     __uint8_t clean_len = strlen(clean_bit);


     padding = (3 - (clean_len % 3)) % 3;
     
     output[0] = '0';
     output[1] = 'o';

     for(__uint8_t i= 0; i< clean_len + padding;i += 3){
          __uint8_t  value = 0; 

          for(__uint8_t j = 0; j < 3;j++){
               __int8_t bit_pos = i + j - padding;
               char bit_char;

               bit_char  = (bit_pos < 0)?'0':clean_bit[bit_pos];

               value = (value << 1) | (bit_char - '0');
          }

          output[hex_index++] = intToHexChar(value);
     }
     output[hex_index] = '\0';
}



