#include <stdio.h>
#include <string.h>

#define MAX_RNDS 40

struct Link {
    char content;
    struct Link *ptr_next;
};

int main()
{
    struct Link a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12;
    
    a1.content = 'H';
    a1.ptr_next = &a2;
    
    a2.content = 'e';
    a2.ptr_next = &a3;
    
    a3.content = 'l';
    a3.ptr_next = &a4;
    
    a4.content = 'l';
    a4.ptr_next = &a5;
    
    a5.content = 'o';
    a5.ptr_next = &a6;
    
    a6.content = ' ';
    a6.ptr_next = &a7;
    
    a7.content = 'W';
    a7.ptr_next = &a8;
    
    a8.content = 'o';
    a8.ptr_next = &a9;
    
    a9.content = 'r';
    a9.ptr_next = &a10;
    
    a10.content = 'l';
    a10.ptr_next = &a11;
    
    a11.content = 'd';
    a11.ptr_next = &a12;
    
    a12.content = '!';
    a12.ptr_next = &a3;
    
    a13.content = ' ';
    a13.ptr_next = &a1; // Try changing this value to create/remove loop
    
    struct Link *cur = &a1;
    int i = 0;
    
    do {
        printf("%c", cur->content);
        cur = cur->ptr_next;
        i++;
    } while (cur && i < MAX_RNDS);
    
    struct Link *cur1 = &a1;
    struct Link *cur2 = &a1;
    int j = 0;
    printf("\n");
    
    do {
        if (cur2->ptr_next == NULL || cur2->ptr_next->ptr_next == NULL) {
            // No loop if null found in next or next of next
            cur1 = NULL;
            break;
        }
        cur1 = cur1->ptr_next;
        cur2 = cur2->ptr_next->ptr_next;
        j++;
        printf("%d - cur1 %p: %c / cur2 %p: %c\n", j, cur1, cur1->content, cur2, cur2->content);
    } while (cur1 != cur2 && j < MAX_RNDS);
    
    if (cur1 != NULL) {
        printf("LOOP DETECTED!");
    } else {
        printf("NO LOOP!");
    }

    return 0;
}
