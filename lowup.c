#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <argp.h>
#include <getopt.h>


int to_lower(char* ass);
int to_upper(char* ass);
int CheckArgumentCount(int argc);
int ussage();

int main(int argc,char *argv[],char **envp)
{

if (!CheckArgumentCount(argc))
    exit(1);    

int option;
int flag=0;
while ((option = getopt(argc, argv, "l:u:")) !=-1){
    switch (option){
        case 'l' :
            to_lower(optarg);
            flag++;
            break;

        case 'u' :
            to_upper(optarg);
            flag++;
            break;

        default :
            printf("\nprovide a tag noob \n");
            ussage();
            flag++;
            break;
    }
    }

if (flag == 0){
        printf("provide an option and a file noob \n");
        ussage();
   return 0;
}

}
 

int to_lower(char* ass){
   FILE* ptr;
   char ch;

   ptr = fopen(ass, "r");

   if (NULL == ptr) {
        printf("dude file does not exist \n");
    }

    do {
        ch = tolower(fgetc(ptr));
        printf("%c", ch);
    } while (ch != EOF);


   return 0;
}

int to_upper(char* ass){
   FILE* ptr;
   char ch;

   ptr = fopen(ass, "r");

   if (NULL == ptr) {
        printf("dude file does not exist \n");
    }

    do {
        ch = toupper(fgetc(ptr));
        printf("%c", ch);
    } while (ch != EOF);


   return 0;
}

int ussage(){
    printf("ussage: lowup [option] [filename] \n -l to convert to to lowercase \n -u to convert to uppercase");
    exit(0);
}

int CheckArgumentCount(int argc)
{
   if (argc != 3)   
  {
    puts("Wrong number of arguments\n");
    ussage();
    return 0;
  }

  return 1;
}