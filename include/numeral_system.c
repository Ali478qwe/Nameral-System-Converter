#include "numeral_system.h"
#include <ctype.h>
#include <string.h>

int hexCharToInt(char * character){
    if(*character >= '0' && *character <= '9') 
         return *character - '0';
    else if(*character >= 'A' && *character <= 'F') 
         return *character - 'A' + 10;
    else if(*character >= 'a' && *character <= 'f') 
         return *character - 'a' + 10; 
    else
         return -1;
}




int hexToDecimal(char * character[]){
   int len = strlen(character);
   if(isxdigit(*character)){
    return hexCharToInt(character);
    }
}