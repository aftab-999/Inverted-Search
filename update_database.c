#include "header.h"

int update_database(hash_t *arr , Flist **head){
    char word[20] ;
   printf("🔸Enter the file name : ");
   scanf("%s",word);
   
   Flist *node = malloc(sizeof(Flist));
   strcpy(node->filename , word);
   node->link = NULL ;

   if(*head == NULL){
     *head = node ;
   }else{
    Flist *travelptr = *head ;
    while(travelptr->link != NULL){  // we just added node to Flist which is a list of filenames .
        travelptr = travelptr->link;
    }
    travelptr->link = node ;
   }

   create_database(arr , node) ;         // but we passed only address holded by node .
   printf("✅ Database Update Successfull");
}