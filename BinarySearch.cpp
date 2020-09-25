#include <stdio.h>
#include <stdlib.h>

struct node{
	int key;
	struct node *left, *right;	
}*root = NULL;

struct node * insert(struct node * curr, int insertedKey){
	if(curr == NULL){
		curr = (struct node *) malloc(sizeof(struct node));
		curr->key = insertedKey;
		curr->left = curr->right = NULL;
	}
	else{
		if( insertedKey < curr->key){
			curr->left = insert(curr->left, insertedKey);
		}
		else{
			curr->right = insert(curr->right, insertedKey);
		}
	}
	return curr;
}

struct node * deleteValue(struct node * curr, int deletedKey){

	if( curr == NULL ) return NULL;
	else if(deletedKey < curr->key){
		curr->left = deleteValue(curr->left, deletedKey);		
	}
	else if(deletedKey > curr->key){
		curr->right = deleteValue(curr->right, deletedKey);
	}
	else{ 		

		if(curr->left == NULL || curr->right == NULL){
			struct node * temp = NULL;
			
			if(curr->left != NULL) temp = curr->left;
			else temp = curr->right;
			

			if(temp == NULL){
				temp = curr;
				curr = NULL;
			}

			else{
				*curr = *temp;
			}
			free(temp);
		}
		
		else{

			struct node * temp = curr->left;
			while(temp->right != NULL){
				temp = temp->right;
			}

			curr->key = temp->key;
		
			curr->left = deleteValue(curr->left, temp->key);

		}
	}
	return curr;
}

void inorder(struct node * curr){
	if(curr==NULL) return;
	printf("%d ", curr->key);
	inorder(curr->left);
	inorder(curr->right);
}

struct node * popAll(struct node * curr){
	if(curr == NULL) return NULL;
	curr->left = popAll(curr->left);
	curr->right = popAll(curr->right);
	free(curr);
	return NULL;
}

int main(){
	int choice = 0, insertedKey = 0, deletedKey = 0; 
	do{
		printf("1. Insert Data\n");
		printf("2. View Data\n");
		printf("3. Delete Data\n");
		printf("4. Exit\n");
		printf("Choice : ");
		scanf("%d", &choice); fflush(stdin);
		
		switch(choice){
			case 1:
				printf("Masukkan key : ");
				scanf("%d", &insertedKey);
				fflush(stdin);
				
				root = insert(root, insertedKey);
				break;
			case 2:
				inorder(root);
				getchar();
				break;
			case 3:
				printf("Masukkan key : ");
				scanf("%d", &deletedKey);
				fflush(stdin);
				
				root = deleteValue(root, deletedKey);
				break;
		}		
	}while(choice != 4);
	root = popAll(root);
	return 0;
}
