#include "shannon_fano.h"
#include "stdio.h"
#include <stdlib.h>


Symbol simbolos[256];

char teste[20] = "ola meus amigos";

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


int add_new_symbol(Symbol *srs, char c, int count, char *code){
    for (int i = 0; i <= 256; i++){
        if (srs[i].character == c) return -1;
        Symbol newS;
        newS.character = c;
        newS.frequency = count;
        newS.code = code;
        return 0;
    }
}


int main() {
    int c = get_count_char('1', teste);
    printf("total: %d", c);
    return 0;
}
