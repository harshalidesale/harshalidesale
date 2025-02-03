#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *next;
};

struct node *first, *cur, *prev;

void init() {
    first = NULL;
}

void add_node() {
    struct node *temp;
    int t, ch, pos, st, found;

    while (1) {
        printf("\n\tAdd Menu \n1. Add at start\n2. Add at End\n3. Add at intermediate position\n4. Exit submenu\nEnter choice : ");
        scanf("%d", &ch);

        switch (ch) {
        case 1://Add at Start
            temp = (struct node *)malloc(sizeof(struct node));
            printf("\n Enter data : ");
            scanf("%d", &t);
            temp->num = t;
            temp->next = first;
            first = temp;
            break;

        case 2://Add at End
            temp = (struct node *)malloc(sizeof(struct node));
            printf("\n Enter data : ");
            scanf("%d", &t);
            temp->num = t;
            temp->next = NULL;

            if (first == NULL) {
                first = temp;
            } else {
                cur = first;
                while (cur->next != NULL) {
                    cur = cur->next;
                }
                cur->next = temp;
            }
            break;

        case 3://Add at Specific Position
            printf("\n Enter the position after which you want to enter data : ");
            scanf("%d", &pos);
            st = 1;
            found = 0;
            cur = first;

            while (cur != NULL) {
                if (st == pos) {
                    found = 1;
                    break;
                }
                cur = cur->next;
                st++;
            }

            if (found) {
                temp = (struct node *)malloc(sizeof(struct node));
                printf("\n Enter data : ");
                scanf("%d", &t);
                temp->num = t;
                temp->next = cur->next;
                cur->next = temp;
            } else {
                printf("\nPosition out of range");
            }
            break;

        case 4:
            return;

        default:
            printf("\n\n Wrong choice\n\n");
        }
    }
}

#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *next;
};

struct node *first, *cur, *prev;

void init() {
    first = NULL;
}

void add_node() {
    struct node *temp;
    int t, ch, pos, st, found;

    while (1) {
        printf("\n\tAdd Menu \n1. Add at start\n2. Add at End\n3. Add at intermediate position\n4. Exit submenu\nEnter choice : ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            temp = (struct node *)malloc(sizeof(struct node));
            printf("\n Enter data : ");
            scanf("%d", &t);
            temp->num = t;
            temp->next = first;
            first = temp;
            break;

        case 2:
            temp = (struct node *)malloc(sizeof(struct node));
            printf("\n Enter data : ");
            scanf("%d", &t);
            temp->num = t;
            temp->next = NULL;

            if (first == NULL) {
                first = temp;
            } else {
                cur = first;
                while (cur->next != NULL) {
                    cur = cur->next;
                }
                cur->next = temp;
            }
            break;

        case 3:
            printf("\n Enter the position after which you want to enter data : ");
            scanf("%d", &pos);
            st = 1;
            found = 0;
            cur = first;

            while (cur != NULL) {
                if (st == pos) {
                    found = 1;
                    break;
                }
                cur = cur->next;
                st++;
            }

            if (found) {
                temp = (struct node *)malloc(sizeof(struct node));
                printf("\n Enter data : ");
                scanf("%d", &t);
                temp->num = t;
                temp->next = cur->next;
                cur->next = temp;
            } else {
                printf("\nPosition out of range");
            }
            break;

        case 4:
            return;

        default:
            printf("\n\n Wrong choice\n\n");
        }
    }
}

void del_node() {
    struct node *temp;
    int ch, pos, st, found;

    while (1) {
        printf("\n\tDelete Menu \n1. Delete starting node\n2. Delete End node\n3. Delete an intermediate node\n4. Exit submenu\nEnter choice : ");
        scanf("%d", &ch);

        switch (ch) {
        case 1://Delete First
            if (first == NULL) {
                printf("\n Empty list : nothing deleted");
            } else {
                temp = first;
                first = first->next;
                printf("\nNode deleted");
                free(temp);
            }
            break;

        case 2: //Delete Last
            if (first == NULL) {
                printf("\n Empty list : nothing deleted");
            } else if (first->next == NULL) {
                free(first);
                first = NULL;
                printf("\nNode deleted");
            } else {
                cur = first;
                while (cur->next->next != NULL) {
                    cur = cur->next;
                }
                temp = cur->next;
                cur->next = NULL;
                printf("\nNode deleted");
                free(temp);
            }
            break;

        case 3: //Delete Specific Position
            printf("\n Enter the position after which you want to delete node : ");
            scanf("%d", &pos);
            st = 1;
            found = 0;
            cur = first;

            while (cur != NULL && cur->next != NULL) {
                if (st == pos) {
                    found = 1;
                    break;
                }
                cur = cur->next;
                st++;
            }

            if (found) {
                temp = cur->next;
                cur->next = temp->next;
                printf("\nNode deleted");
                free(temp);
            } else {
                printf("\nPosition out of range");
            }
            break;

        case 4:
            return;

        default:
            printf("\n\n Wrong choice\n\n");
        }
    }
}

void display() {
    cur = first;

    if (cur == NULL) {
        printf("\nEmpty List!");
        return;
    }

    printf("\nLink List contents are :\n");
    while (cur != NULL) {
        printf("%d\n", cur->num);
        cur = cur->next;
    }
}

int main() {
    int ch;

    init();

    while (1) {
        printf("\n\tMain Menu \n1. Add element\n2. Delete element\n3. Display elements \n4. Exit\nEnter choice : ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            add_node();
            break;

        case 2:
            del_node();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("\n\n Wrong choice\n\n");
        }
    }
}





