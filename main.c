#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "listfiles.h"

struct FileStats{
        int words;
        int chars;
        int lines;
    };

int main(int argc, char *argv[]) {
    int verbose = 0;
    for (int i =1; i < argc; i++){
    if (strcmp(argv[i], "--verbose") == 0){
        verbose = 1;
    }
    if (strcmp(argv[i], "--list") == 0){
        list_directory();
        return 0;
    } 


    struct FileStats totals = {0, 0, 0}; 
    
    for ( int i = 1; i < argc; i++){
        struct FileStats fileStats = {0,0,0};
 
        

        char buffer[100];
        int bufferIndex = 0;
        int isInside = 0;
        int c;
    

        FILE *file = fopen(argv[i], "r");

        if (file == NULL){
            printf("couldnt open file\n");
            continue;
        }

        while ((c = fgetc(file)) != EOF){
             if (c == '\n'){fileStats.lines ++;}

             if (isspace(c)){
                 if (isInside ==1 ){
                 buffer[bufferIndex] = '\0';
                 printf("word: %s\n", buffer);
                 bufferIndex = 0;
             }
             isInside = 0;
            } else {
                 fileStats.chars ++;
                 buffer[bufferIndex] = c;
                 bufferIndex ++;

                 if (isInside == 0){
                     fileStats.words ++;
                     isInside = 1;
                   }
             }
        }
        if (isInside == 1){
            buffer[bufferIndex] = '\0';
            printf("word: %s\n", buffer);
        }

        fclose(file);
        printf("%s: %d words, %d characters, %d lines\n",argv[i], fileStats.words, fileStats.chars, fileStats.lines);

        totals.words += fileStats.words;
        totals.chars += fileStats.chars;
        totals.lines += fileStats.lines;
    }

    printf("total: %d words, %d characters, %d lines\n", totals.words, totals.chars, totals.lines);
    return 0;
}
