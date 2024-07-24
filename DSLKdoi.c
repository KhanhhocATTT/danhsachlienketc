#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Khai bao node
typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}node;

//Ham tao node moi
node *makeNode(int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

//Ham them mot node vao dau
void pushFront(node **head, int x){
    node *newNode = makeNode(x);
    newNode->next = (*head);
    if(*head != NULL){
        (*head)->prev = newNode;
    }
    *head = newNode;
}

//Ham them mot node vao cuoi
void pushBack(node **head, int x){
    node *newNode = makeNode(x);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    node *tmp = (*head);
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode;
    newNode->prev = tmp;
}

//Ham them vao vi tri k
void pushK(node **head, int k, int x){
    int n = sizeof(*head);
    node *tmp = (*head);
    if(k < 1 || k > n + 1){
        printf("Vi tri khong hop le!");
        return;
    }
    else if(k == 1){
        pushFront(head, x);
    }
    else if(k == n + 1){
        pushBack(head, x);
    }
    else{
        for(int i = 1; i < k - 1; i++){
            tmp = tmp->next;
        }
        node *newNode = makeNode(x);
        newNode->next = tmp->next;
        tmp->next->prev = newNode;
        tmp->next = newNode;
        newNode->prev = tmp;
    }
}

//Ham xoa node dau
void popFront(node **head){
    if(*head == NULL){
        return;
    }
    node *tmp = (*head);
    *head = tmp->next;
    if(*head != NULL){
        tmp->next->prev = NULL;
    }
    free(tmp);
}

//Ham xoa node cuoi
void popBack(node **head){
    if(*head == NULL){
        return;
    }
    node *tmp = (*head);
    if(tmp->next == NULL){
        *head = NULL;
        free(tmp);
        return;
    }
    while(tmp->next != NULL){
        tmp = tmp->next; // duyet den node sat cuoi
    }
    node *last = tmp->next; // node last la node cuoi
    tmp->prev->next = NULL; // 
    free(last);
}

//Ham xoa node o vi tri k
void popK(node **head, int k){
    int n = sizeof(*head);
    node *tmp = (*head);
    if(k < 1 || k > n + 1){
        printf("Vi tri khong hop le!\n");
        return;
    }
    if(k == 1){
        popFront(head);
    }
    else{
        for(int i = 1; i <= k - 1; i++){
            tmp = tmp->next; // duyet den node k
        }
    }
    tmp->prev->next = tmp->next; // link node k - 1 voi node k + 1
    if(tmp->next != NULL){
        tmp->next->prev = tmp->prev; // link node k + 1 voi node k - 1
    }
    free(tmp); // giai phong node k
}

//Ham duyet danh sach
void duyet(node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

//Ham duyet nguoc danh sach
void reverseduyet(node *head){
    if(head == NULL) return;
    node *tmp = head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    while(tmp != NULL){
        printf("%d ", tmp->data);
        tmp = tmp->prev;
    }
    printf("\n");
}

//Ham sap xep node tu lon den be
void sort(node **head){
    for(node *i = (*head); i != NULL; i = i->next){
        node *min = i;
        for(node *j = i->next; j != NULL; j = j->next){
            if(min->data > j->data){
                min = j;
            }
        }
    int tmp = min->data;
    min->data = i->data;
    i->data = tmp;
    }
}

int main(){
    node *head = NULL;
    printf("------------------------Danh Sach Quan Ly------------------------\n");
    printf("1. Them node vao dau DS,\n");
    printf("2. Them node vao vi tri K.\n");
    printf("3. Them node vao cuoi DS.\n");
    printf("4. Xoa node dau.\n");
    printf("5. Xoa node o vi tri K.\n");
    printf("6. Xoa node cuoi.\n");
    printf("7. Duyet DS.\n");
    printf("8. Duyet nguoc DS.\n");
    printf("9. Sap xep node.\n");
    printf("0. Ket Thuc DS.\n");
    printf("------------------------------------------------------------------\n");

    int choose, k, x;
    while(1){
        printf("Moi nhap lua chon: ");
        scanf("%d", &choose);
        switch(choose){
            case 1:
                printf("Gia tri can them: ");
                scanf("%d", &x);
                pushFront(&head, x);
                break;
            case 2:
                printf("Vi tri can them: ");
                scanf("%d", &k);
                printf("Gia tri can them: ");
                scanf("%d", &x);
                pushK(&head, k, x);
                break;
            case 3:
                printf("Gia tri can them: ");
                scanf("%d", &x);
                pushBack(&head, x);
                break;
            case 4: 
                popFront(&head);
                break;
            case 5:
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &k);
                popK(&head, k);
                break;
            case 6:
                popBack(&head);
                break;
            case 7:
                printf("Danh sach la: \n");
                duyet(head);
                break;
            case 8:
                printf("Danh sach la: \n");
                reverseduyet(head);
                break;
            case 9:
                printf("Danh sach sau khi sap xep: \n");
                sort(&head);
                duyet(head);
                break;
            case 0:
                printf("Ket thuc Danh Sach\n");
                exit(0);
                break;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        
        }
    }
}