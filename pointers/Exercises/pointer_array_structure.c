#include <stdio.h>
#include <stdlib.h>

int main(void){

    struct numchars{
        int num;
        char character;
    } *numchar[26];

    for(int i = 0; i < 26; i++){
        numchar[i] = malloc(sizeof(struct numchars));

        if(numchar[i] == NULL){
            puts("Error: could not allocate memory");
            return 1;
        }

        numchar[i]->num = i;
        numchar[i]->character = 'A'+i;

        printf("%d + %c\n",
            numchar[i]->num,
            numchar[i]->character
        );
    }

    for(int i = 0; i < 26; i++){
    free(numchar[i]);
    }
    return 0;
}