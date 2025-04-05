#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//strcmp ascending
int ascending(const char *a, const char *b) {
        return strcmp(a,b);
}

//void bubble(char **env_var, const int index, int (*compare)(char *, char *));
void swap(char **element1, char **element2) {
        char *hold = *element1;
        *element1 = *element2;
        *element2 = hold;
}
void bubble(char **env_var, const int index, int (*compare)(const char *, const char *)) {
        char delimeter[]="=";
        char *name1,*name2;
        for (int i = 0; i < index - 1; i++) {
                for (int j = 0; j < index - 1 - i; j++) {
                        //if (arr[j] > arr [j+1]){
                        //      swap(&arr[j],&arr[j+1]);
                        //      }
                        char n1 =*env_var[j];
                        char n2= *env_var[j+1];
                        name1=strtok(&n1,delimeter);
                        name2=strtok(&n2,delimeter);
                        //if(env_var[j],env_var[j+1])
                        if ((*compare)(name1,name2)>0) {
                                swap(&env_var[j], &env_var[j + 1]);
                        }
                }

        }
}

int main( int argc, char ** argv, char * envp[] )
{
        int index = 0;
        //counting number of variables
        while(envp[index]){
                index++;
        }

        printf("Number of environment vars = %d\n", index );

        char **env_var=(char **)malloc(index*sizeof(char*));

        // Sort in ascending order
        //
        for(int i=0;i<index;i++){
                env_var[i]=envp[i];
                //printf("env_var[%d] = \"%s\"\n", i, env_var[i]);
        }

        bubble(env_var, index, ascending);

        for (int i = 0; i < index; i++) {
        printf("%s\n",env_var[i]);
    }

        exit( 0 );
} 
