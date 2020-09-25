#include<stdio.h>
#include<string.h>
#include<Windows.h>

struct data{
	char code[10];
	char name[50];
	int qty;
	float price;
}arr[5];
int n_data = 4;

void init(){
	strcpy(arr[0].code,"CK001");
	strcpy(arr[0].name,"Blueberry Cake");
	arr[0].qty=13;
	arr[0].price=25000;
	
	strcpy(arr[1].code,"CK009");
	strcpy(arr[1].name,"Chocochip Cake");
	arr[1].qty=5;
	arr[1].price=20000;
	
	strcpy(arr[2].code,"CK017");
	strcpy(arr[2].name,"Mayonaise Cake");
	arr[2].qty=24;
	arr[2].price=30000;
	
	strcpy(arr[3].code,"CK023");
	strcpy(arr[3].name,"Strawberyy ShortCake");
	arr[3].qty=7;
	arr[3].price=17500;
}

void cetak(){
	printf("BLUE CAKE SHOP CASHIER\n");
	printf("======================\n");
	printf("No.	| Cake Code	| Cake Name				| Available | Price\n");
	printf("----------------------------------------------------------------\n");
	for(int i=0;i<n_data;i++){
		printf("%2d.	| %4s		| %20s |		%2d | Rp. %5.0f,-\n",i+1,arr[i].code,arr[i].name,arr[i].qty,arr[i].price);
	}
	printf("----------------------------------------------------------------\n");
}

void menu(){
	printf("Menu :\n");
	printf("1. Sell\n");
	printf("2. Add Stock\n");
	printf("3. Exit\n");
	printf("Input Choice :");
}

void sell(){
	char input_code[5];
	int idx=-1;
	do{
		printf("Input Cake Code [5 chars]:");
		gets(input_code);
		
		for(int i=0;i<n_data;i++){
			if(strcmp(arr[i].code,input_code)==0)
			idx=i;
		}
		if(idx==-1)
		printf(" --- The Cake Code doesn't exist ---\n");
	}while(idx==-1);
	
	int input_qty;
	do{
		printf(" Input Quantity [0..%d]:",arr[idx].qty);
		scanf("%d",&input_qty);
		fflush(stdin);
	}while(input_qty<0||input_qty>arr[idx].qty);
	
	printf("\n\nTotal Price is : Rp. %0f,- x %d = Rp. %.0f,-\n\n",arr[idx].price,input_qty,arr[idx].price*input_qty);
	printf("--- Thank You ---\n\n");
	
	arr[idx].qty-=input_qty;
	getchar();
}

void add(){
	char input_code[5];
	int idx=-1;
	do{
		printf("Input Cake Code [5 chars]:");
		gets(input_code);
		
		for(int i=0;i<n_data;i++){
			if(strcmp(arr[i].code,input_code)==0)
			idx=i;
		}
		if(idx==-1)
		printf(" --- The Cake Code doesn't exist ---\n");
	}while(idx==-1);
	
	int input_qty;
	do{
		printf(" Input Quantity [0..%d]:");
		scanf("%d",&input_qty);
		fflush(stdin);
	}while(input_qty<0||input_qty>10);
	
	arr[idx].qty+=input_qty;
	getchar();
}

int main(){
	
	init();
	int pilih=0;
	do{
		system("cls");
		cetak();
		menu();
		scanf("%d",&pilih);
		fflush(stdin);
		switch(pilih){
			case 1: sell();break;
			case 2: add();break;
		}
	}while(pilih!=3);
	
	return 0;
}


