#include <stdio.h>
#include <stdlib.h>

typedef struct listNode {
    int data;
    struct listNode* link;
} listNode;

typedef struct linkedList_h {
    listNode* head;
} linkedList_h;

linkedList_h *createLinkedList_h(void);
void freeLinkedList_h(linkedList_h *L);
void addLastNode(linkedList_h *L, int data);
int getLength(linkedList_h *L);
void printAll(linkedList_h *L);

linkedList_h *createLinkedList_h(void)
{
    linkedList_h* L;
    L = (linkedList_h*)malloc(sizeof(linkedList_h));
    L->head = NULL;
    return L;
}

void freeLinkedList_h(linkedList_h *L)
{
    listNode *p;
    while (L->head != NULL)
    {
        p = L->head;
        L->head = L->head->link;
        free(p);
        p = NULL;
    }
}

void addLastNode(linkedList_h* L, int data) {
    listNode* newNode;
    listNode* p;
    newNode = (listNode *)malloc(sizeof(listNode));
    newNode->data = data;
    newNode->link = NULL;
    if (L->head == NULL) {
        L->head = newNode;
        return;
    }
    p = L->head;
    while (p->link != NULL) {
        p = p->link;
    }
    p->link = newNode;
}

int getLength(linkedList_h* L) {
    int length = 0;
    listNode* p;
    p = L->head;
    if (p == NULL) {
        printf("빈리스트입니다.");
    }
    while (p != NULL) {
        length++;
        p = p->link;
    }
    return length;
}

void printAll(linkedList_h* L) {
    listNode* p;
    if (L->head == NULL) {
        return;
    }
    p = L->head;
    while (p != NULL) {
        printf("%d", p->data);
        p = p->link;
        if (p != NULL) {
            printf(", ", p->data);
        }
    }
    printf("\n");
}

int main() {
    linkedList_h* L;
    L = createLinkedList_h();
    addLastNode(L, 1);
    addLastNode(L, 2);
    addLastNode(L, 3);
    // 예상 길이 3
    printf("length = %d\n", getLength(L));
    printAll(L);
    freeLinkedList_h(L);
}