/*
    
    Template Double Linked List

    Nama    : Ammar Alifian F
    NRP     : 05111840000007
    Matkul  : Struktur Data - B

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node* next;
    struct node* prev;
} node_t;

typedef struct linklist{
    node_t* head;
    node_t* tail;
} linkedlist_t;

void insert_front(int value, linkedlist_t* ll){
	node_t* box = (node_t*) malloc(sizeof(node_t));
	box->val = value;
	box->next = NULL;
	box->prev = NULL;

	if(ll->head == NULL){
		ll->head = box;
		ll->tail = box;
	}else{
        ll->head->prev = box;
		box->next = ll->head;
		ll->head = box;
	}
}

void insert_back(int value, linkedlist_t* ll){
	node_t* box = (node_t*) malloc(sizeof(node_t));

	box->val = value;
	box->next = NULL;
	box->prev = NULL;

	if(ll->head == NULL){
		ll->head = box;
		ll->tail = box;
	}else{
		ll->tail->next = box;
		box->prev = ll->tail;
		ll->tail = box;
	}
}

void insert_middle(int value, int pos, linkedlist_t* ll){
    if(pos == -1){
        insert_front(value, ll);
        return;
    }

    node_t* box = (node_t*) malloc(sizeof(node_t));
    node_t* tmp = ll->head;

	box->val = value;
	box->next = NULL;
	box->prev = NULL;

	int i;
	for(i = 0; i < pos; i++){
        tmp = tmp->next;

        if(tmp == NULL){
            insert_back(value, ll);
            return;
        }
	}

    box->next = tmp->next;
    box->prev = tmp;
    tmp->next = box;
    tmp->next->prev = box;
}

void delete_front(linkedlist_t* ll){
    if(ll->head != NULL){
        ll->head = ll->head->next;
        ll->head->prev = NULL;
        free(ll->head->prev);
    }
}

void delete_back(linkedlist_t* ll){
    if(ll->head != NULL){
        ll->tail = ll->tail->prev;
        ll->tail->next = NULL;
        free(ll->tail->next);
    }
}

void delete_middle(int pos, linkedlist_t* ll){
    if(pos == 0){
        delete_front(ll);
    }

    pos--;
    node_t* tmp = ll->head;

    int i;
    for(i = 0; i < pos; i++){
        tmp = tmp->next;

        if(tmp == NULL){
            return;
        }
    }
    if(tmp->next == NULL){
        delete_back(ll);
    }else if(tmp->next->next == NULL){
        ll->tail->prev = tmp->prev;
    }else{
        tmp->next->next->prev = tmp;
        tmp->next = tmp->next->next;
    }
}

void print_ll(linkedlist_t* ll){
    node_t* tmp = ll->head;
    while(tmp != NULL){
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
}

void print_reverse_ll(linkedlist_t* ll){
    node_t* tmp = ll->tail;
    while(tmp != NULL){
        printf("%d ", tmp->val);
        tmp = tmp->prev;
    }
    printf("\n");
}

int main(){
	linkedlist_t list;
	list.head = NULL;
    //Insert 15 from the front
	insert_front(15, &list);
    //Insert 25 from the front
	insert_front(25, &list);
    //Insert 30 from the back
	insert_back(30, &list);
    //Insert 40 from the back
	insert_back(40, &list);
    //Insert 10 after the 2nd node
	insert_middle(10, 2, &list);
    //Insert 10 after the 10th node (last node)
	insert_middle(10, 10, &list);
    //Insert 22 after the 7th node
	insert_middle(22, 7, &list);
    //Delete the 0th node
	delete_middle(0, &list);
    //Print the linked list
	print_reverse_ll(&list);
}
