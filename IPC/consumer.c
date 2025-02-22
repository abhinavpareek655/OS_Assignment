#include <stdio.h>
#include <stdlib.h>

int main() {
    int sum = 0, num;
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        if (sscanf(buffer, "%d", &num) == 1) sum += num;
        else fprintf(stderr, "Invalid input: %s", buffer);
    }
    printf("Total: %d\n", sum);
    return 0;
}