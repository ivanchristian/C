#include <stdio.h>
#include <string.h>
#include <algorithm>

struct Product{
	char namaProduk[25];
	int qty;
}supermarket[100];

void generate_data(){
	strcpy(supermarket[0].namaProduk,"Teh Semangka");
	supermarket[0].qty = 30;
	
	strcpy(supermarket[1].namaProduk,"Teh Jeruk");
	supermarket[1].qty = 10;
	
	strcpy(supermarket[2].namaProduk,"Susu Nangka");
	supermarket[2].qty = 1;
	
	strcpy(supermarket[3].namaProduk,"Kopi Pisang");
	supermarket[3].qty = 3;
}

int count_data;

void show_data(){
	for(int i=0;i<count_data;i++){
		printf("| %-15s | %-3d |\n",supermarket[i].namaProduk,
		supermarket[i].qty);
	}
}

void swap(Product *a, Product *b){
	struct Product c;
	c = *a;
	*a = *b;
	*b = c;
}

void bubble_sort(){

	for(int i=0;i<count_data-1;i++){
		for(int j=count_data-1;j>i;j--){

			if(strcmp(supermarket[j].namaProduk,
			supermarket[j-1].namaProduk) > 0){

				swap(&supermarket[j],&supermarket[j-1]);
			}
		}
	}

}

void selection_sort(){
	int iLow;
	for (int i=0;i<count_data-1;i++) {
		iLow = i;
	    for (int j=i+1;j<count_data;j++){
	    	if (supermarket[j].qty < supermarket[iLow].qty  ) iLow = j;
		}		
		if (iLow > i) swap(&supermarket[i], &supermarket[iLow]);
	}
}

void insertion_sort(){
	int temp; 
	for(int i=1; i < count_data; i++) {
		temp = supermarket[i].qty;
		for(int j=i-1; j >= 0 && temp < supermarket[j].qty; j--){
			swap(&supermarket[j+1],&supermarket[j]);	
		} 			
	}
}

void quick_sort(int L,int R) {
	int i,j;
	if(L < R){
		for(i = L, j = R+1; i <= j ;   )
		{
			do{ i++;} while(strcmp(supermarket[i].namaProduk, supermarket[L].namaProduk)>0);
			do{ j--;} while(strcmp(supermarket[j].namaProduk, supermarket[L].namaProduk)<0);

			if(i < j) swap(&supermarket[i],&supermarket[j]);
		}		
		swap(&supermarket[L],&supermarket[j]);
	    quick_sort(L,j-1);
	    quick_sort(j+1,R);
	}
}


void merge( int L, int m1, int m2, int R )
{
   struct Product temp[ count_data ];
   int Lidx,Cidx,Ridx;

   for(Lidx = L, Cidx = L, Ridx = m2; Lidx <= m1 && Ridx <= R ;   )
   {

      if ( supermarket[ Lidx ].qty >= supermarket[ Ridx ].qty )
         temp[ Cidx++ ] = supermarket[ Lidx++ ];
      else
         temp[ Cidx++ ] = supermarket[ Ridx++ ];
   }
   if ( Lidx == m2 ) {
      while ( Ridx <= R )
         temp[ Cidx++ ] = supermarket[ Ridx++ ];
   }
   else {
      while ( Lidx <= m1 )
         temp[ Cidx++ ] = supermarket[ Lidx++ ];
   }
   for (int i=L; i<=R; i++ )
      supermarket[ i ] = temp[ i ];
}


void merge_sort( int low, int high )
{
   int m1, m2;
   if (( high-low)>=1) {
      m1 = (low+high) / 2;
      m2 = m1+1;
      merge_sort( low, m1 );
      merge_sort( m2, high );
      merge( low, m1, m2, high );
   }
}

int linear_search(char namaItem[]){
	int valid = -1;
	for(int i=0;i<count_data;i++){

		if(strcmpi(namaItem,supermarket[i].namaProduk)==0){
			return i;
		}
	}	
	if(valid == -1){
		return -1;
	}
}

int binary_search(char namaItem[]){
	int low  = 0;
	int high = count_data;
	do{
		int mid  = (low+high)/2;
		if(strcmpi(supermarket[mid].namaProduk, namaItem) < 0){
			high = mid;
		}else if(strcmpi(supermarket[mid].namaProduk, namaItem) > 0){
			low  = mid;
		}else{
			return mid;
		}
	}while(low <= high);
	return -1;	
}

int interpolation_search(char namaItem[]) {
	int mid, min = 0, max = count_data-1;
	
	while(strcmpi(namaItem, supermarket[min].namaProduk)>0 && strcmpi(namaItem, supermarket[max].namaProduk)<0) { 
			
		
		if(strcmpi(supermarket[mid].namaProduk,namaItem)<0) 
   			min = mid + 1; 
		else if(strcmpi(supermarket[mid].namaProduk,namaItem)>0) 
			max = mid - 1;
		else return mid; 
		
		
   	}  
	if (strcmpi(supermarket[min].namaProduk, namaItem)==0) return min;
	else if(strcmpi(supermarket[max].namaProduk, namaItem)==0) return max; 
	
	return -1; 
}

int x[]={0,2,4,6,8,10,30};
int n=7;

int interpol_search(int key) {
	int mid, min = 0, max = n-1;
	while(x[min] < key && x[max] > key) { 
		mid = min + ((key-x[min])*(max-min)) / (x[max]-x[min]); 
		if(x[mid] < key) 
   			min = mid + 1; 
		else if(x[mid] > key) 
			max = mid - 1;
		else return mid; 
   	}  
	if (x[min] == key) return min;
	else if(x[max] == key) return max; 
	return -1; 
}



int main(){
	count_data = 4; 
	generate_data(); 
	bubble_sort();

	printf("%d\n",interpol_search(8));
			
	return 0;
}
