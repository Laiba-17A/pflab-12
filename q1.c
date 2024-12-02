#include<stdio.h>
void swap(int *x,int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
}
int main(){
	
	int x,y;
	printf("enter num 1: \n");
	scanf("%d",&x);
	printf("enter num 2: \n");
	scanf("%d",&y);
	swap(&x,&y);
	printf("x:%d\n",x);
	printf("y:%d\n",y);
	return 0;
}