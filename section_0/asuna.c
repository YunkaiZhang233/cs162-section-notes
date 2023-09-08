#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char* a, int x, int y) {
    char t = a[x];
    a[x] = a[y];
    a[y] = t;
}

int partition(char* a, int l, int r) {
    int pivot;
    int i;
    int j;
    pivot = a[l];
    i = l;
    j = r+1;
    while (i < j) {
        do {
            ++i;
        } while (a[i] <= pivot && i <= r);
        do {
            --j;
        } while (a[j] > pivot && j > i);
        if (i >= j) {
            break;
        }
        swap(a, i, j);
    }
    swap(a, l, j);
    return j;
} 

void sort(char* a, int l, int r) {
    int j;
    if (l < r) {
        j = partition(a, l, r);
        sort(a, l, j-1);
        sort(a, j+1, r);
    }
}

int main(int argc, char** argv) {
    char* a = NULL;
    const char* asuna = "Asuna is the best char!";
    if (argc > 1) {
        a = malloc(strlen(argv[1]) + 1);
        strcpy(a, argv[1]);
    } else {
        a = malloc(strlen(asuna) + 1);
        strcpy(a, asuna);
    }
    printf("Unsorted \"%s\"\n", a);
    sort(a, 0, strlen(a) - 1);
    printf("Sorted \"%s\"\n", a);
    return 0;
}