/**
* MORSE CODE GENERATOR
* TODO: add decoder
* TODO: add more chars support
* TODO: add sound 
*
**/

#include <stdio.h>
#include <string.h>

char* letters[26] = {
    "._",   //A
    "_...", //B
    "_._.", //C
    "_..",  //D
    ".",    //E
    ".._.", //F
    "__.",  //G
    "....", //H
    "..",   //I
    ".___", //J
    "_._",  //K
    "._..", //L
    "__",   //M
    "_.",   //N
    "___",  //O
    ".__.", //P
    "__._", //Q
    "._.",  //R
    "...",  //S
    "_",    //T
    ".._",  //U
    "..._", //V
    ".__",  //W
    "_.._", //X
    "_.__", //Y
    "__.."  //Z
};

void help(char** programname){
    printf("Morse code generator/translator \n");
    printf("USAGE: %s [OPTION] [FILE]\n", *programname);
}

int main (int argc, char *argv[]){

    if (argc < 2) {
        help(argv);
        return -1;
    }

    if ( !strcmp(argv[1], "code") ) {

        char string[10];
        for(int i = 0; i < 10; i++){
            scanf(" %c", &string[i]);
        }
        for(int i = 0; i < 10; i++){
            if((int)string[i] > 90){
                string[i] = string[i] - 32;
            }
            printf("%s/", letters[(int)string[i] - 65]);
        }
        printf("\n");

    }else if ( !strcmp(argv[1], "decode") ) {
        printf("bruh\n");
    }

    return 0;
}
