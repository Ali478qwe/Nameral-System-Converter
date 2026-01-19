#include <stdio.h>
#include <stdint.h>
#include <stdalign.h>
#include <string.h>
#include "../include/numeral_system.h"

#define MAX_ITEM 128

int main(int argc,char * args[]){
    

   char hex[MAX_ITEM];

    if(argc == 2){
      strncpy(hex,args[1],100);
      hex[100] = '\0';
    }
    else{
      printf("Enter Hex:");
      scanf("%s",hex);
    }
    
    printf("hex: %s decimal: %lld\n",hex,hexToDecimal(hex));
    printf("strlen : %ld\n",strlen(hex));

    return 0;


}