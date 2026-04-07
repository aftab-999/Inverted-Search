#include "header.h" 

int main(int argc , char* argv[]){
    Flist *head = NULL ;
    int option ; 
    hash_t arr[27] ;
    for(int i=0;i<27;i++){
        arr[i].index = i ;
        arr[i].link = NULL ;
    }
    // check cla is passed or not 
    if(argc < 2){
        printf("❌ Error : You have not passed any file names !\n");
        return 0 ;
    }
    if(read_and_validate(argc , argv , &head) == SUCCESS) {
        // check for filename extension is ".txt" 
        // check for filename exist 
        // check for file is empty or not 
        // check for file is duplicate or not 
        printf("✅ Read & Validation Successfully Done !\n");
        //print_list(head) ;

        // Display menu 
        
        while(1){
        printf("1. create database\n2.Display database\n3.Search database\n4.Update database.\n5.Save database\n6.exit");
        printf("\n🔸Enter option - ");
        scanf("%d",&option);
        switch(option){
            case 1 :
              create_database(arr , head) ;
              printf("✅ Database created successfully !\n");
              break;
            case 2 :
              display_database(arr , head) ;
              break ;
            case 3 :
              search_database (arr , head) ;
              break ;
            case 4 : 
              update_database(arr , &head) ;
              break;
            case 5 :
              save_database(arr , head) ;
              break;
            case 6 :
            printf("\n") ;
            return 0 ;
            default : 
            printf("Invalid Option !\n") ;
            break ;
        }
    }
    }else{
        printf("❌ Read & validation Failure !\n");
    }
    
    
}