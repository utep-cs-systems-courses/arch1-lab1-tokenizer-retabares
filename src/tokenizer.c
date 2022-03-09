#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"


int space_char(char c){
  if(c == ' ' || c == '\t'){
    return 1;
  }else{
    return 0;
  }
}

int non_space_char(char c){
  if(!space_char(c) && c != '\0'){
    return 1;
  }else{
    return 0;
  }
}

char *word_terminator(char *word){
  int i = 0;
  while((*(word+i))){
    if(space_char(*(word+i))){
      return word+i;
    }else{
      i++;
    }
    return word+i;
  }
}


char *word_start(char *s){

  char *temp = s;
  
  while(*temp){
    if(non_space_char(*temp)){
      temp++;
    }
    return temp;
  }
}


int count_words(char *str){
  int count = 1;

  while(*str++){
    if(*str == ' '){
      count++;
    }
  }
  return count;
}




char *copy_str(char *inStr, short len){
  char *p = malloc((sizeof(char)*len) + 1);
  char *temp = inStr;

  for(int i = 0; i < len; i++){
    *(p+i) = *temp;
    temp++;
  }

  *(p+len) = '\0';

  return p;
}

char** tokenize(char* str){
  
  int word_count = count_words(str);
  char** tokens = (char**)malloc((word_count+1) * (sizeof(char*)));
  char* temp = str;

  for (int i = 0; i < word_count; i++){

      temp = word_start(temp);

      tokens[i] = copy_str(temp, (word_terminator(temp)- temp));

      temp = word_terminator(temp);

    }
  tokens[word_count] = '\0';
  return tokens;
}


void print_tokens(char **tokens){
  char **temp = tokens;
  int i = 0;
  while(*temp != NULL){
    printf("tokens[%d] = %s\n", i++, *(temp++));
  }
}

void free_tokens(char **tokens){
  char** temp = tokens;
  
  while(*temp){
    free(*temp);
    temp++;
  }
  free(tokens);
}
