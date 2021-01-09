#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node node_t;

node_t *head;

void printList()
{
    node_t *ptr = head;                                    
    while(ptr != NULL)
    {
        printf("INDEX: %p DATA: %d NPTR: %p\n", ptr, ptr->data, ptr->next); 
        ptr = ptr->next;                                        
    }

    head == NULL ? puts("List is empty.") : puts("");
}

size_t getLLISize()
{
    int amount = 0;

    node_t *cur;

    for(cur = head; cur != NULL; cur = cur->next)
      amount++;
    return amount;
}

void insertNode(int data)
{
    ///printf("\n DATA-> %d\n", data);
    node_t *newNode = malloc(sizeof(node_t));

    newNode->data = data;
    newNode->next = head;

    head = newNode;
}

void deleteNodes(int amount)
{
    if(getLLISize() < amount)
    {
        puts("-> LLISize < amount");
        exit(1);
    }

    for(int i = 0; i < amount; i++)
    {
        head = head->next;
    }
}

int isEmpty()
{
    return head == NULL ? 0 : 1;
}

void checkInput(char input)
{
    int data = 0;
    switch(input)
    {
      case 'p':
        printList();
        break;

      case 'i':
        puts("insertNode(int data)");
        puts("               ^^^^");
        printf("->");
        scanf("%I", &data);
        insertNode(data);
        break;

      case 'd':
        puts("deleteNodes(int amount)");
        puts("                ^^^^^^");
        printf("->");
        scanf("%I", &data);
        deleteNodes(data);
        break;

      case 'c':
        printf("Current size: %d", getLLISize());
        break;

      case 'D':
        printf("\x1b[34mTEST\n");
        for(int i = 0; i < 100; i++)
          insertNode(i%0x20);

        for(int i = 0; i < 50; i++)
          insertNode(i%0x0A);

        printList();
        printf("SIZE: %d", getLLISize());
        deleteNodes(getLLISize());
        printf("\nSIZE: %d", getLLISize());

    }
}

int main(int argc, char* argv[])
{
    // Map functions to STDIN
    puts("->Enter the character inside of the () to select a mode.");
    puts("\n->Print (p)\n->Insert (i)\n->Delete (d)\n->Count (c)\n->Exit (e)\n->Debug (D)");

    char input;

    printf("\n");
    while(input != 'e')
    {
      input = getc(stdin);
      checkInput(input);
    }

    puts("EXIT");
}
