#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

//Ham tao node moi
node *makeNode(int x){
    //Xin cap phat node moi
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data =  x;
    newNode->next = NULL;
    
    return newNode;
}

//Ham duyet DSLK
void duyet(node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

//Ham them node vao dau
void pushFront(node **head, int x){
    node *newNode = makeNode(x);
    newNode->next = (*head);
    (*head) = newNode;
}

//Ham them node vao cuoi
void pushBack(node **head, int x){
    node *newNode = makeNode(x);
    if(*head == NULL){
        (*head) = newNode;
        return;
    }
    node *tmp = (*head);
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode; 
}
//Ham them node vao giua
void pushMid(node **head, int k, int x){
    int n = sizeof(*head);
    node *tmp = (*head);
    if(k < 1 || k > (n + 1)){
        printf("Vi tri khong hop le!\n");
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
        tmp->next = newNode;

    }
}

//Ham xoa node dau tien
void popFront(node **head){
    if(*head == NULL){
        return;
    }
    node *tmp = (*head);
    *head = (*head)->next;
    free(tmp);
}

//Ham xoa node cuoi cung
void popBack(node **head){
    if(*head == NULL){
        return;
    }
    node *tmp = (*head);
    if(tmp->next == NULL){
        (*head) = NULL;
        free(tmp);
        return;
    }
    while(tmp->next->next != NULL){
        tmp =  tmp->next; // node thu 2 tu duoi len
    }
    node *last = tmp->next; // node can xoa
    tmp->next = NULL;
    free(last);
}

//Ham xoa node thu k
void popK(node **head, int k){
    node *tmp = (*head);
    if(k < 1 || k > sizeof(*head)){
        printf("Vi tri khong hop le!\n");
        return;
    }
    else if(k == 1){
        popFront(head);
    }
    else{
        for(int i = 1; i < k - 1; i++){
            tmp = tmp->next; // node k - 1
        }
        node *del = tmp->next;
        tmp->next = del->next;
        free(del);
    }
}

//Ham tim kiem node thu k
void sreachK(node *head, int k){
    int n = sizeof(head);
    node *tmp = head;
    if(k < 1 || k > n + 1){
        printf("Vi tri khong hop le!\n");
        printf("Vui long chon gia tri khac!\n");
        return;
    }
    else{
        for(int i = 1; i < k - 1; i++){
            tmp = tmp->next;
        }
        printf("Gia tri can tim la: ");
        printf("%d\n", tmp->data);
    }
}

//Ham tim kiem node co gia tri lon nhat
void maxNode(node *head){
    int res = -1e9;
    while(head != NULL){
        res = fmax(res, head->data);
        head = head->next;
    }
    printf("%d\n", res);
}

//Ham sap xep cac node tu be -> lon
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

    printf("<------------------------------------------------------------------------------>\n");
    printf("1. Them node vao dau.\n");
    printf("2. Them node vao vi tri k.\n");
    printf("3. Them node vao cuoi.\n");
    printf("4. Xoa node dau tien.\n");
    printf("5. Xoa node thu k.\n");
    printf("6. Xoa node cuoi cung.\n");
    printf("7. Tim kiem node thu k.\n");
    printf("8. Tim node co gia tri lon nhat.\n");
    printf("9. Sap xep DS.\n");
    printf("10. Duyet DS.\n");
    printf("0. Thoat DS.\n");
    printf("<------------------------------------------------------------------------------>\n");

    int choose, x, k;
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
                printf("Gia tri can nhap: ");
                scanf("%d", &x);
                pushBack(&head, x);
                break;
            case 3:
                printf("Vi tri can chen: ");
                scanf("%d", &k);
                printf("Gia tri can them: ");
                scanf("%d", &x);
                pushMid(&head, k, x);
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
                printf("Vi tri can tim kiem: ");
                scanf("%d", &k);
                sreachK(head, k);
                break;
            case 8:
                printf("Node co gia tri lon nhat la: ");
                maxNode(head);
                break;
            case 9:
                sort(&head);
                break;
            case 10:
                duyet(head);
                printf("\n");
                break;
            case 0:
                printf("Ket Thuc!");
                exit(0);
                break;
            default:
                printf("Gia tri khong hop le! Dit Me May!\n");
                break;
        }    
    }

    return 0;
}