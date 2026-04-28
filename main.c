#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    for ( int i = 1; i < argc; i++){

        int counter = 0;
        int isInside = 0;
        int c;
        int charCounter = 0;
        int lineCounter = 0;


        FILE *file = fopen(argv[i], "r");

        if (file == NULL){
            printf("couldnt open file\n");
            continue;
        }

        while ((c = fgetc(file)) != EOF){
             if (c == '\n'){
                 lineCounter ++;
             }
             if (isspace(c)){
                 isInside = 0;
             
            } else {
                 charCounter ++;
                 if (isInside == 0){
                     counter ++;
                     isInside = 1;
                 }
        }
        }
        
        fclose(file); 
        printf("%s: %d words, %d characters, %d lines\n",argv[i], counter, charCounter, lineCounter);
    }
    return 0;
}
