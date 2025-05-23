#ifndef bintre_h
#define bintre_h

typedef struct bin_t{
    int value;
    struct bin_t * left;
    struct bin_t * right;
}bin_t;

void inibin(bin_t bin[], int size);

#endif