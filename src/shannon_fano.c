#include "shannon_fano.h"
#include "stdio.h"
#include <stdlib.h>


Symbol simbolos[256];

char teste[20] = "ola meus amigos";

/*Checks the length of a string*/
int strlent(char * str){
    int i=0;
    for(;str[i]!='\0';i++);
    return i;
}

int get_count_char(char target, char *str){
    if (str == NULL) return 0;
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (str[i] == target) {
            j++;
        }
        i++;
    }
    return j;
}

int add_new_symbol(Symbol *srs, char c){
    for (int i = 0; i <= 256; i++){
        if (srs[i].character == c) {
            srs[i].frequency++;
        }
        else {
            Symbol newS;
            newS.character = c;
            newS.frequency = 0;
            srs[i] = newS;
        }
        return 0;
    }
}


int symb_sort(Symbol *srs, int size) {
    int i, j;
    int s;
    for (i = 0; i < size - 1; i++) {
        s = 0;
        for (j = 0; j < size - i - 1; j++) {
            if (srs[j].frequency < srs[j + 1].frequency) {
                Symbol temp = srs[j+1];
                srs[j+1] = srs[j];
                srs[j] = temp;
                s = 1;
            }
        }

        if (s == 0)
            break;
    }
}


int print_symb(Symbol *srs) {
    for (int i = 0; i < 256; i++) {
        if (srs[i].character != NULL) {
            printf("char %c |" " freq %d | \n", srs[i].character, srs[i].frequency);
        }
    }
}

int main() {
    for (int i = 0; i < strlent(teste); i++){
        add_new_symbol(simbolos, teste[i]);
    }
    print_symb(simbolos);
    return 0;
}
