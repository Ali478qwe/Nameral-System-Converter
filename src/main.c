#include <stdio.h>
#include <stdint.h>
#include <stdalign.h>
#include <string.h>
#include "../include/numeral_system.h"

#define MAX_ITEM 128

int main(int argc,char * args[]){
    
//  char  input_hex;
   char * hex[MAX_ITEM];

//  char * hex_code[] = {'A','B','C','D','E','F'};
    if(argc == 2){
      strncpy(hex,args[1],100);
      hex[100] = '\0';
    }
    else{
      printf("Enter Hex:");
      scanf("%s",hex);
    }

    // scanf("%c",&input_hex);

//  printf("This Your Code : %s\n",input_hex);

//     if(input_hex[0] == '0' && input_hex[1] == 'x'){
//         for(int i = 0 ; i <= 6;i++){
//             hex[i] = (int)input_hex[i+2];
//             if(input_hex[i+2] == '\0'){
//                 break;
//             }

//         }
//         printf("This Your Hex Code :");
//         for(int i = 0; i <= 10;i++){

//          printf("%d ",hex_str_to_decimal(&hex[i]));

//         }
//     }

//   printf("%zu\n",alignof(char*));
//   printf("%zu\n",sizeof(input_hex));
//   printf("%s\n",input_hex);
//      for(int i = 0; i < 128;i++){
    // int value = hexToDecimal(&hex[2]);
    //  if(value != -1)
        //   printf("%d\n",value);
        printf("strlen : %d\n",strlen(hex));
//    }

  
    

    return 0;


}