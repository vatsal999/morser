/**
* MORSE CODE GENERATOR
* TODO: add decoder
* TODO: add more chars support
* TODO: add sound 
*
**/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MESSAGE_BUFSIZE 1024

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

void encode(){
    char c;
    int position = 0;
    int message_size = MESSAGE_BUFSIZE;
    char *message = malloc(sizeof(char) * message_size);

    if (!message) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }


    while(1){
        c = getchar();

        if (c == EOF || c == '\n') {
          message[position] = '\0';
          for(int j = 0; j < position; j++){
              if((int)message[j] > 90){
                  message[j] = message[j] - 32;
              }
              if(message[j] == 32){
                  printf(" /");
              }else{
                  printf("%s/", letters[(int)message[j] - 65]);
              }
          }
          printf("\n");
          return;
          // return message;
        } else {
          message[position] = c;
        }
        position++;
    }
}

void help(char** programname){
    printf("Morse code generator/translator \n");
    printf("USAGE: %s [OPTION] [FILE]\n", *programname);
}

int main (int argc, char *argv[]){

    if (argc < 2) {
        fprintf(stderr, "Arguments not provided!\n");
        help(argv);
        return 1;
    }

    if ( !strcmp(argv[1], "encode") ) {
        encode();
    }else if ( !strcmp(argv[1], "decode") ) {
        printf("decode\n");
    }

    return 0;
}
