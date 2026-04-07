#include "header.h"
#include<stdio.h>

int display_database(hash_t *arr ,Flist *head){
    for(int i=0;i<27;i++){
        
        if(arr[i].link != NULL){
        printf("[%d]\t",i);
        m_node *travelptr = arr[i].link ;
        while(travelptr != NULL){
            printf("[%s]\t",travelptr->word);
            printf("%d\t",travelptr->filecount) ;

            s_node *travelsub = travelptr->slink ;
            while(travelsub != NULL){
                printf("[%s]\t",travelsub->filename);
                printf("%d\t",travelsub->wordcount);
                travelsub = travelsub->slink ;
            }
            
            travelptr = travelptr->mlink ;
        }
      printf("\n");
    }
    }
}

int write_to_database(hash_t *arr ,FILE *fp){
    for(int i=0;i<27;i++){
        
        if(arr[i].link != NULL){
        fprintf(fp,"[%d]\t",i);
        m_node *travelptr = arr[i].link ;
        while(travelptr != NULL){
            fprintf(fp,"[%s]\t",travelptr->word);
            fprintf(fp,"%d\t",travelptr->filecount) ;

            s_node *travelsub = travelptr->slink ;
            while(travelsub != NULL){
                fprintf(fp,"[%s]\t",travelsub->filename);
                fprintf(fp,"%d\t",travelsub->wordcount);
                travelsub = travelsub->slink ;
            }
            
            travelptr = travelptr->mlink ;
        }
      fprintf(fp,"\n");
    }
    }
}