#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    int counter = 0;
    int isInside = 0;
    int c;
    int charCounter = 0;
    int lineCounter = 0;


    FILE *file = fopen(argv[1], "r");

    if (file == NULL){
        printf("couldnt open file\n");
        return 1;
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
    printf("%d words\n", counter);
    printf("%d characters\n", charCounter);
    printf("%d Lines\n", lineCounter);
    fclose(file); 
    return 0;
}
