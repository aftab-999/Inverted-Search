#include "header.h"

int read_and_validate(int argc , char* argv[] , Flist **head){
    // read and validate 
    for(int i=1; i<argc ;i++){
       if(strstr(argv[i] , ".txt") != NULL){
         FILE *fp ;
         fp = fopen( argv[i] , "r");
         if(fp != NULL){
            fseek(fp , 0 , SEEK_END) ;
            if(ftell(fp)!=0){
              if(insert_at_last(head , argv[i]) == SUCCESS){
              printf("✅ %s filename successfully added in list!\n",argv[i]) ;
              }else{
                printf("❌ Duplicate File insertion FOUND !\n");
              }
            }else{
                printf("❌ %s file is empty !\n",argv[i]);
            }
         }
         else if(fp == NULL){
            printf("❌ File does not Exist ! \n");
         }
       }else{
        printf("❌ File is not .txt file !\n");
       }
    }
    return SUCCESS ;
}

int insert_at_last(Flist **head ,char *fname) {
    Flist *temp = malloc(sizeof(Flist)) ;
    strcpy(temp->filename , fname) ;
    temp->link = NULL ;
    if(*head == NULL){
      *head = temp ;
      return SUCCESS ;
    }else{
        Flist *travelptr = *head ;
        
        while(travelptr->link != NULL){
         if(strstr(travelptr->filename , temp->filename) == NULL){
            travelptr = travelptr->link ;
        }else{
            return FAILURE; 
        }
    }
        travelptr->link = temp ;
        return SUCCESS ;
    }
}