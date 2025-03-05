#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int stack[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &stack[i]);
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (stack[j] < stack[j + 1]) {
                int temp = stack[j];
                stack[j] = stack[j + 1];
                stack[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", stack[i]);
    }

    return 0;
}
