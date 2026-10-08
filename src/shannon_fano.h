// Type to save all characters count in order to calculate probability
// Ex: A - 6 - '010'
typedef struct {
    unsigned char character;
    unsigned int frequency;
    char *code;
} Symbol;
