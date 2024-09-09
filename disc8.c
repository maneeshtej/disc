#include<stdio.h>
#include<string.h>
#include<conio.h>
#define MAX 500

int t[MAX];

void shifttable(char p[]) {
    int i, j, m;
    m = strlen(p);
    for(i = 0; i < MAX; i++)
        t[i] = m;
    for(j = 0; j < m - 1; j++)
        t[(int)p[j]] = m - 1 - j;  // Cast p[j] to int for proper indexing
}

int horspool(char src[], char p[]) {
    int i, k, m, n;
    n = strlen(src);
    m = strlen(p);
    printf("\nLength of text = %d", n);
    printf("\nLength of pattern = %d", m);
    i = m - 1;
    
    while(i < n) {
        k = 0;
        while((k < m) && (p[m - 1 - k] == src[i - k]))
            k++;
        if(k == m)
            return (i - m + 1);  // Return starting index
        else
            i += t[(int)src[i]];  // Cast src[i] to int for proper indexing
    }
    return -1;
}

void main() {
    char src[100], p[100];
    int pos;
    
    printf("Enter the text in which pattern is to be searched:\n");
    gets(src);  // gets is unsafe, but as per the instruction, we will not change it
    printf("Enter the pattern to be searched:\n");
    gets(p);
    
    shifttable(p);
    pos = horspool(src, p);
    
    if(pos >= 0)
        printf("\nThe desired pattern was found starting from position %d", pos + 1);
    else
        printf("\nThe pattern was not found in the given text");
    
    getch();  // For pausing the output on screen
}

INPUT:
Enter the text in which pattern is to be searched:
abcababcabca
Enter the pattern to be searched:
abca
