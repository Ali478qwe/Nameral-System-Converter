#include <stdio.h>
#include <stdint.h>
#include "include/numeral_system.c"
#define MAX_ITEM 131

int main(){
    
   char input_hex[MAX_ITEM];
   int hex[MAX_ITEM];

//    char hex_code[] = {'A','B','C','D','E','F'};
    
    printf("Enter Hex:");

    scanf("%s",&input_hex);

 printf("This Your Code : %s\n",input_hex);

    if(input_hex[0] == '0' && input_hex[1] == 'x'){
        for(int i = 0 ; i <= 6;i++){
            hex[i] = (int)input_hex[i+2];
            if(input_hex[i+2] == '\0'){
                break;
            }

        }
        printf("This Your Hex Code :");
        for(int i = 0; i <= 10;i++){

         printf("%d ",hex[i]);

        }
    }


    

    return 0;


}