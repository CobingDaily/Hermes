#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>


int main(void) {
    while (true) {
        printf("Hello, World!\n");
        sleep(1);
    }

    return 0;
}
