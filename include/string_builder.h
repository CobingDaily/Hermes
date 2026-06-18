#ifndef STRING_BUILDER_H
#define STRING_BUILDER_H

#include <stddef.h>

typedef struct {
    char *text;
    size_t length;
} String_Builder;

String_Builder* SB_make(char *init);

/** Non-persistent append.
 * `left` becomes the final result.
 */
int SB_append(String_Builder* left,
              String_Builder* right);


#endif // !STRING_BUILDER_H
