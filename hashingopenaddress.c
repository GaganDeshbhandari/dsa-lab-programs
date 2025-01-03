#include<stdio.h>
#include<stdlib.h>

int main() {
    int a[100], a1[100], i, j, result, n, cnt = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Initialize hash table with -1
    for(i = 0; i < 10; i++)
        a1[i] = -1;

    // Hashing with open addressing
    for(i = 0; i < n; i++) {
        result = a[i] % 10;
        if(a1[result] == -1) {
            a1[result] = a[i];
            printf("Location: a1[%d], Value: %d\n", result, a1[result]);
        } else {
            j = result + 1;
            while(1) {
                if(a1[j] == -1) {
                    a1[j] = a[i];
                    printf("Location: a1[%d], Value: %d\n", j, a1[j]);
                    break;
                }
                if(j > n - 1)
                    j = 0;
                if(cnt == n)
                    break;
                cnt++;
                j++;
            }
        }
        result = 0;
    }

    // Print hash table
    printf("Hash table using open addressing mode:\n");
    for(i = 0; i < 10; i++) {
        if(a1[i] != -1)
            printf("%d ", a1[i]);
    }
    return 0;
}