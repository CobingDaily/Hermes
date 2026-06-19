#include "string_builder.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

String_Builder* SB_make(char *init) {
    if (!init) return NULL;

    String_Builder* sb = malloc(sizeof(*sb));
    if (!sb) return NULL;

    size_t length = strlen(init);
    sb->length = length;
    sb->text = malloc(length + 1);
    
    if (!sb->text) {
        free(sb);
        return NULL;
    }

    strcpy(sb->text, init);    

    return sb;
}

int SB_append(String_Builder* sb, char* more) {
    size_t add = strlen(more);
    size_t length = sb->length + add;

    char *new_text = realloc(sb->text, length + 1);

    if (!new_text) {
        return 1;
    }

    sb->length = length;
    sb->text = new_text;
    memcpy(sb->text + sb->length, more, add + 1);

    return 0;
}

int SB_concat(String_Builder* left, String_Builder* right) {
    return SB_append(left, right->text);
}

