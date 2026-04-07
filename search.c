#include"header.h" 
#include<stdio.h>
 
int search_database(hash_t *arr , Flist *head){
    printf("🔸Enter the word you have to search - ");
    char word[20] ;
    scanf("%s",word);

    int index ;
    if(islower(word[0])){
     index = word[0] - 97 ;
    }
     else if(isupper(word[0])){
     index = word[0] - 65 ;
     }
     
     m_node *travelptr = arr[index].link ;
     while(travelptr != NULL){
        if(strcmp(travelptr->word , word) == 0){
            printf("✅ String (%s) is present in %d file(s) :\n",word , travelptr->filecount);
            s_node *travelsub = travelptr->slink ;
            while(travelsub != NULL){
                printf("☑️ In File: %s %d time(s).\n",travelsub->filename , travelsub->wordcount);
                travelsub = travelsub->slink ;
            }
            return 0;
        }
        travelptr = travelptr->mlink ;
     }
     printf("❌ Your entered word is not present in Files .");
     return 0 ;

}