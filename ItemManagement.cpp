#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct data{
	char nama[20];
	int harga;
	int qty;
	struct data *next, *prev;
}*head,*tail,*curr;

void insert_depan(char nama[],int harga,int qty){
	curr=(struct data *)malloc(sizeof(struct data));
	curr->harga=harga;
	curr->qty = qty;
	strcpy(curr->nama,nama);
	
	if(head==NULL){
		head=tail=curr;
	}
	else{
		curr->next=head;
		head=curr;
	}
	tail->next=NULL;
}

void pop_depan(){
	if(head!=NULL){
		curr=head;
		head=head->next;
		free(curr);
	}
}

void pop_tail(){
	if(tail!=NULL){
		curr=tail;
		tail= tail->prev;
		free(curr);
	}
}

void popSearching(char nama[20]){
	curr = head;
	if(strcmp(head->nama,nama)==0) pop_depan();
	else if(strcmp(tail->nama,nama)==0) pop_tail();
	while(curr!=NULL && strcmp(curr->nama, nama) != 0){
		curr = curr->next;
	}
	if(curr!=NULL){
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
		free(curr);
	}
}

void popall(){
	while(head!=NULL){
		pop_depan();
	}
}

int check(char nama[20]){
	curr = head;
	while(curr!=NULL && strcmp(curr->nama, nama) != 0){
		curr = curr->next;
	}
	if(curr==NULL){
		return 0;
	}
	return curr->qty;
}

//data *check(char nama[20]{
//	curr = head;
//	while(curr!=NULL && strcmp(curr->nama, nama) != 0){
//		curr = curr->next;
//	}
//	if(curr == NULL){
//		return NULL;
//	}else{
//		return curr;
//	}
//}

void minusQuantity(char nama [20], int qty){
	curr = head;
	while(curr!=NULL && strcmp(curr->nama, nama) != 0){
		curr = curr->next;
	}
	if(curr==NULL){
		printf("Tidak ditemukan\n");
	}
	curr->qty = curr->qty - qty;
	if(curr->qty == 0){
		popSearching(nama);
	}
}


void menu(){
	printf("Item Management\n");
	printf("1. Add Product\n");
	printf("2. Sale Product\n");
	printf("3. Exit\n");
	printf("Choice :");
}

void cls(){
	for(int i=0;i<25;i++)
		printf("\n");
}

void cetak(){
	if(head==NULL){
		return;
	}
	curr = head;
	int i=1;
	printf("No. 	Product Name		Product Price 		Quantitiy\n");
	while(curr!=NULL){
		printf("%d. %-20s Rp.%-15d %-10d\n",i,curr->nama, curr->harga, curr->qty);
		curr = curr->next;
		i++;
	}
}

void menu_1(){
	char item_name[20];
	int price, qty, flag=0;
	do{
		flag=0;
		printf("Input Item name [must start with 'Item ']:");
		gets(item_name);
		for(int r =5; r<strlen(item_name); r++){
			if(isupper(item_name[r])){
				flag++;
			}
		}
	}while(strncmp(item_name, "Item ", 5) != 0 || flag != 0);			
	do{
		printf("Input Price [more than or equals 10000]:");
		scanf("%d",&price);fflush(stdin);
	}while(price<10000);
	do{
		printf("Input Quantity [more than or equals 1]:");
		scanf("%d", &qty);fflush(stdin);
	}while(qty<1);
	insert_depan(item_name,price,qty);
}

void menu_2(){
	char item_name[20];
	int qty, Qty;
	printf("Input Item name :");
	gets(item_name);
	
	if(check(item_name)==0){
		printf("Tidak ketemu\n");
	}else{
		do{
			printf("Input Qty [1..1]:");
			scanf("%d", &qty);fflush(stdin);
		}while(!(qty<=check(item_name) && qty>0));
		minusQuantity(item_name,qty);
	}
}

int main(){
	int jawab;
	head=tail=NULL;
	do{
		cls();
		cetak();
		menu();
		scanf("%d",&jawab);fflush(stdin);
		switch(jawab){
		case 1:menu_1();break;	
		case 2:menu_2();break;
		}	
	}while(jawab!=3);
	return 0;
}
