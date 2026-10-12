#include "shannon_fano.h"
#include "stdio.h"
#include <stdlib.h>



char teste[20] = "isabeli";

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

int add_new_symbol(Simbolos *srs, char c){
    for (int i = 0; i <= srs->len; i++){
        if (srs->simbolos[i].character == c) {
            srs->simbolos[i].frequency++;
            return 0;
        }
    }

    Symbol s = {0};
    s.character = c;
    s.frequency = 1;
    srs->simbolos[srs->len] = s;
    srs->len++;

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


int print_symb(Symbol *srs, int len) {
    printf("---------------\n");
    for (int i = 0; i < len; i++) {
        printf("char %c |" " freq %d | \n", srs[i].character, srs[i].frequency);
    }
    printf("---------------\n");
}

int get_total(Symbol *srs, int len) {
    int total = 0;
    for(int i = 0; i < len; i++) {
        total += srs[i].frequency;
    }
    return total;
}

int shannon_fano(Simbolos *s){
    symb_sort(s->simbolos, s->len);
    int total = get_total(s->simbolos, s->len);

    


}



int main() {

    Simbolos s = {0};

    for (int i = 0; i < strlent(teste); i++){
        add_new_symbol(&s, teste[i]);
    }
    symb_sort(s.simbolos, s.len);
    print_symb(s.simbolos, s.len);
    printf("%d", get_total(s.simbolos, s.len));
    return 0;
}
