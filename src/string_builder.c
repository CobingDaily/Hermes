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

    char* old_text;
    strcpy(old_text, sb->text);

    sb->text = realloc(sb->text, length + 1);

    if (!sb->text) {
        free(sb);
        return 1;
    }

    memcpy(sb->text + sb->length, more, add + 1);

    sb->length = length;
    return 0;
}

int SB_concat(String_Builder* left, String_Builder* right) {
    return SB_append(left, right->text);
}

