#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next; // link
}node;

//Ham duyet DSLK
void duyet(node* head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

//Ham dem so node
int count(node* head){
    int cnt = 0;
    while(head != NULL){
        ++cnt;
        head = head->next;
    }
    return cnt;
}

// Ham tao node moi
node *makeNode(int x){
    //Xin cap phat dong
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

//Ham them node vao dau DSLK
void addfirst(node **head, int x){
    node *newNode = makeNode(x);
    newNode->next = (*head); //toan  tu giai tham chieu
    (*head) = newNode; // cap nhat newnode thanh node dau tien
}

//Ham them node vao cuoi DSLK
void pushBack(node **head, int x){
    node *newNode = makeNode(x);
    node *tmp = (*head);
    //DSLK rong
    if(tmp == NULL){
        (*head) = newNode;
        return;
    }
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

//Ham chen node vao vi tri k
void insert(node **head, int k, int x){
    int n = sizeof(*head);
        node *tmp = (*head);
    if(k < 1 || k > n + 1){
        printf("Vi tri chen khong hop le!");
        return;
    }
    else if(k == 1){
        addfirst(head, x);
    }
    else if(k == n + 1){
        pushBack(head, x);
    }
    else{
        for(int i = 1; i < k - 1; i++){
            tmp = tmp->next;
        }
    }
        node *newNode = makeNode(x);
        newNode->next = tmp->next;
        tmp->next = newNode;
}

int main(){
    node *head = NULL;
    printf("------------------------------------\n");
    printf("1. Them vao dau DS\n");
    printf("2. Them vao cuoi DS\n");
    printf("3. Them vao giua DS\n");
    printf("4. Duyet DS\n");
    printf("0. Thoat!\n");
    printf("------------------------------------\n");

    int choose;
    int x;
    int k;
    while(1){
        printf("Nhap lua chon: ");
        scanf("%d", &choose);
        switch(choose){
            case 1:
                scanf("%d", &x);
                addfirst(&head, x);
                break;
            case 2:
                scanf("%d", &x);
                pushBack(&head, x);
                break;
            case 3:
                printf("Vi tri can chen: ");
                scanf("%d", &k);
                printf("Gia tri can them: ");
                scanf("%d", &x);
                insert(&head, k, x);
                break;
            case 4:
                duyet(head);
                break;
            case 0:
                printf("Ket Thuc!");
                exit(0);
                break;
        }
    }

    return 0;
}