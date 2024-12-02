#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	int *arr;
	int sum=0;
	printf("enter size of array ");
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	if(arr==NULL){
		printf("memory allocation for array failed");
	}
	printf("enter values: \n");
	for(int i=0;i<n;i++){
		printf("enter element %d: ",i+1);
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<n;i++){
	   sum=sum+arr[i];
   }
   printf("sum: %d\n",sum);
   
   arr=realloc(arr,2*n*sizeof(int));
   printf("enter %d more values: \n",n);
	for(int i=n;i<2*n;i++){
		printf("enter element %d: ",i+1);
		scanf("%d",&arr[i]);
	}
	for(int i=n;i<2*n;i++){
	   sum=sum+arr[i];
   }
   printf("\n new sum: %d",sum);
   free(arr);
   
}