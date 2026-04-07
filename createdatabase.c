#include "header.h" 
#include<stdio.h>
#include<stdlib.h>
int islower(int element){
    if(element>=97 && element<=122)
    return 1 ;
    else
    return 0 ;
}
int isupper(int element){
    if(element>=65 && element<=90)
    return 1;
    else
    return 0 ;
}
int create_database(hash_t *arr , Flist *head){
 
    int index ; 
    Flist *temp = head ;
    char input_word[20] ;

    while(temp != NULL){
        FILE *fp = fopen(temp->filename , "r" ) ;

        while(fscanf(fp , "%s" , input_word)!= -1){
            // find index
            if(islower(input_word[0]))
            index = input_word[0] - 97;

            else if(isupper(input_word[0]))
            index = input_word[0] - 65 ;

            else
            index = 26 ;

            if(arr[index].link==NULL){
                //create mainnode , create subnode , update the values
                
                m_node *mnode = malloc(sizeof(m_node));
                mnode->filecount = 1 ;
                strcpy(mnode->word , input_word) ;
                mnode->slink = NULL ;
                mnode->mlink = NULL ;

                s_node *snode = malloc(sizeof(s_node));
                snode->wordcount = 1 ;
                strcpy(snode->filename , temp->filename) ;
                snode->slink = NULL ;

                mnode->slink = snode ;
                arr[index].link = mnode ;
            }else{
        
                m_node *travelptr = arr[index].link;
                m_node *prev = NULL ;
                while(travelptr != NULL){
                if(strcmp(travelptr->word , input_word)==0){

                    s_node *travelsub = travelptr->slink ;
                    s_node *sprev = NULL ;
                    while(travelsub != NULL){
                        if(strcmp(travelsub->filename , temp->filename)==0){
                            (travelsub->wordcount)++ ;
                            break ;
                        }else{
                            sprev = travelsub ;
                            travelsub = travelsub->slink ;
                        }
                    }
                    // file is different
                    if(travelsub == NULL){
                    s_node *snode = malloc(sizeof(s_node));
                    strcpy(snode->filename, temp->filename) ;
                    snode->slink = NULL ;
                    snode->wordcount = 1 ;

                    sprev->slink = snode ;
                    (travelptr->filecount)++ ;
                }
                    break ; 
                }else{
                    prev = travelptr ;
                    travelptr = travelptr->mlink ;
                }
               }
            // If word is different
            // create mainnode 
            // create subnode 
            // update details
            if(travelptr == NULL){
            m_node *mnode = malloc(sizeof(m_node));
                 mnode->filecount = 1 ;
                 strcpy(mnode->word , input_word) ;
                 mnode->mlink = NULL ;
                 mnode->slink = NULL ;

                 s_node *snode = malloc(sizeof(s_node));
                 strcpy(snode->filename, temp->filename) ;
                 snode->slink = NULL ;
                 snode->wordcount = 1 ;
                 
                 mnode->slink = snode;
                 prev->mlink = mnode ;
                }
              }
            }
            temp = temp->link ;
            fclose(fp) ;
        }
    }


