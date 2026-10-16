// Type to save all characters count in order to calculate probability
typedef struct {
    unsigned char character;
    unsigned int frequency;
    char code[256];
} Symbol;

typedef struct {
    Symbol simbolos[256];
    int len;
} Simbolos;
