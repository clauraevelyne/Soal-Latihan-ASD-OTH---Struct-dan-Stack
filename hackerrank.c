#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100005

int twoStacks(int maxSum, int a[], int n, int b[], int m) {
    int stackA[MAX_SIZE], stackB[MAX_SIZE];
    int topA = -1, topB = -1;
    int sum = 0, count = 0;
    int i = 0, j = 0;

    while (i < n && sum + a[i] <= maxSum) {
        sum += a[i];
        stackA[++topA] = a[i++];
    }

    count = topA + 1;

    while (j < m && i >= 0) {
        sum += b[j];
        stackB[++topB] = b[j++];

        while (sum > maxSum && topA >= 0) {
            sum -= stackA[topA--];
        }

        if (sum <= maxSum && topA + topB + 2 > count) {
            count = topA + topB + 2;
        }
    }

    return count;
}

int main() {
    int g;
    scanf("%d", &g);
    while (g--) {
        int n, m, maxSum;
        scanf("%d%d%d", &n, &m, &maxSum);
        int a[n], b[m];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }
        printf("%d\n", twoStacks(maxSum, a, n, b, m));
    }
    return 0;
}

