#include <stdio.h>

#define size 10

//function to find the largest number in arr
int largest(int arr[],int n){
	int largest=arr[0],i=0;

	for(i=1;i<n;i++){
	if(arr[i]>largest)
		largest=arr[i];
}

return largest;
}

//function implementing radix sort 
void radix_sort(int arr[],int n){
	int buckets[size][size],buckets_count[size];
	int NOP =0,largest_num=0,i=0,pass=0,divisor=1,remainder=0,k=0,j=0;
	largest_num= largest(arr,n);
	while(largest_num > 0){
		NOP++;
		largest_num /=10;
	}

	for(pass=0;pass < NOP;pass++){

		for(i=0;i<size;i++)
			buckets_count[i]=0;
		for(i=0;i< n ;i++)
		{	//sort the numbers into buckets according to digit at passth place
			remainder = (arr[i]/divisor)%size;
			buckets[remainder][buckets_count[remainder]]=arr[i];
			buckets_count[remainder]+=1;
		}

	i=0;
	//picking up from the buckets after sorting 
	for(k=0;k<size;k++)
	{	
		for(j=0;j<buckets_count[k];j++)
		{
			arr[i]=buckets[k][j];
			i++;	
		}	
	
	}
	divisor*=size;
}

}

//function to display arr elements 
void display(int arr[],int n){
	int i =0;
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

void main(){
	int arr[]={100,34,65,55,255};
	int n=5;
	display(arr,n);
	radix_sort(arr,n);
	display(arr,n);
}
