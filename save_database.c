#include "header.h"

int save_database(hash_t *arr, Flist *head){
    FILE *fp ;
    fp = fopen("database.txt","w");
    if(fp == NULL){
        printf("❌ Failed to open File !");
    }
    write_to_database(arr , fp) ;
    printf("✅ Saved to database Successfully !");
}