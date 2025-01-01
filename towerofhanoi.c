//program for towerofhanoi in C
#include<stdio.h>

void tower(int n, char source, char dest, char temp) {
    if(n > 0) {
        tower(n-1, source, temp, dest);
        printf("Move disk %d from %c to %c\n", n, source, dest);
        tower(n-1, temp, dest, source);
    }
}

int main() {
    int n;
    printf("Enter the number of disks\n");
    scanf("%d", &n);
    tower(n, 'Source ', 'Destination', 'Temp');
    return 0;
}