#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    int totalWords = 0;
    int totalChars = 0;
    int totalLines = 0;

    for ( int i = 1; i < argc; i++){
        
        

        char buffer[100];
        int bufferIndex = 0;
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
             if (c == '\n'){lineCounter ++;}

             if (isspace(c)){
                 if (isInside ==1 ){
                 buffer[bufferIndex] = '\0';
                 printf("word: %s\n", buffer);
                 bufferIndex = 0;
             }
             isInside = 0;
            } else {
                 charCounter ++;
                 buffer[bufferIndex] = c;
                 bufferIndex ++;

                 if (isInside == 0){
                     counter ++;
                     isInside = 1;
                   }
             }
        }
        if (isInside == 1){
            buffer[bufferIndex] = '\0';
            printf("word: %s\n", buffer);
        }

        fclose(file); 
        printf("%s: %d words, %d characters, %d lines\n",argv[i], counter, charCounter, lineCounter);
        totalWords += counter;
        totalChars += charCounter;
        totalLines += lineCounter;
    }
    printf("total: %d words, %d characters, %d lines\n", totalWords, totalChars, totalLines);
    return 0;
}
