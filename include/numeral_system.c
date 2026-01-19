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


unsigned long long hexToDecimal(char character[]){

   int len = strlen(character);
   int start = 0;
   
   //find flag
   if(character[0] == '#')
      start = 1;
   else if(len> 2 && character[0] == '0' && tolower(character[1]) == 'x')
      start = 2;
      

    unsigned long long result = 0;
    int digit = 0;

    //convert type
    for(int i = start;i < len;i++){
        
      if(isxdigit(character[i])){

          digit = hexCharToInt(&character[i]);
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