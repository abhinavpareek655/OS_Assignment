#include <stdio.h>

int main() {
    for (int i = 0; i < 10; i++) {
        if (i == 3) printf("abc\n"); // Intentionally invalid data
        else printf("%d\n", i);
    }
    return 0;
}