#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

//void free_historyR(Item *node); //This serves as a forward declaration of free_history()

int id_tracker = 1;

List *init_history(){
  List *history = (List*)malloc(sizeof(List*));
  history->root = NULL;
  return history;
}

void add_history(List *list, char *str)

{

  Item* current;

  current = list -> root;



  if (list->root == NULL)

    {

      list-> root = (Item*)malloc(sizeof(Item));

      list-> root -> id = id_tracker++;

      list-> root -> str = str;

      list-> root-> next = NULL;

    }

  else

    {

      while (current->next != NULL)

	{

	  current = current->next;

	}

      current->next = (Item*)malloc(sizeof(Item));

      current->next->id = id_tracker;

      current->next->str = str;

      current->next->next = NULL;

    }

}



char *get_history(List *list, int id){
  Item *temp = list->root;

  while(temp->next != NULL){
    temp = temp->next;
    id--;
    
  }
  return temp->str;
}

//void print_history(List *list){
  //Item *node = list->root;
  //int i = 1;
  // while(node != NULL){
    // printf("%d. %s\n", i++, node->str);
    // node = node->next;
    // }
  //}

void print_history(List *list){
  Item *node = list->root;
  while(node->next !=NULL){
    printf("%d.) %s\n", node->id, node->str);
    node = node->next;
  }
}


//void free_history(List *list){
//if(list->root->next != NULL){
//  free_historyR(list->root->next);
//  free(list->root);
//}else{
//  free(list->root);
//}
//free(list);
//}

void free_history(List *list){
  Item *temp = list->root;
  while(temp != NULL){
    free(temp);
  }
  free(list);
}
