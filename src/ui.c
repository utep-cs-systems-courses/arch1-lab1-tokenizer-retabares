#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

int main(){
  char input[100];
  List *history = init_history();
  char **tokens;
  int history_index;

  while(1){
    printf("Hello, welcome to tokenizer! Please enter a string to tokenize\n");
    printf("\nEnter '!' followed by one of these characters for the following options:\n");
    printf("\n'h' for full input history, any number for a specific item in history, or 'q; to quit:\n\n");

    putchar('$');
    fgets(input, 100, stdin);
    tokens = tokenize(input);

    if(**tokens == '!'){
      if(*(*tokens + 1) == '!'){
	break;
      }else if(*(*tokens + 1) == 'h'){
	printf("Printing all user input history....\n\n");
	print_history(history);
      }else{
	history_index = atoi(input+1);
	printf("Here are your results!: %d) %s", history_index, get_history(history, history_index));
      }
    }else{
      add_history(history, input);
      printf("Printing your string tokens!\n");
      print_tokens(tokens);
    }
    printf("Your input: %s\n", input);
    free(tokens);
  }
  free_history(history);
  return 0;
}
