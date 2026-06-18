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

/** Non-persistent append.
 * `left` becomes the final result.
 */
int SB_append(String_Builder* left,
              String_Builder* right);

