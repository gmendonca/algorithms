#include <cstdlib>
#include <stdio.h>


int main(){
	int n;
	printf("Sort a list\nEnter the size of the list:");
	scanf("%d", &n);
	
	if(n <= 0)
		return 0;
	
	int num[n], i, j, tmp;
	int last = n;
	int nnew = 0;

	for(i = 0; i < n; i++){
		num[i] = rand() % n;
		printf("%d ", num[i]);
	}
	printf("\n");

	for(i = 0; i < n; i++){
		nnew = last;
		for(j = 0; j < nnew; j++){
			if(num[j] > num[j+1]){
				tmp = num[j];
				num[j] = num[j+1];
				num[j+1] = tmp;
				// optmized version avoind everything beyond the last swap
				last = j;
			}
		}
	}

	printf("Sorted :\n");
	for(i = 0; i < n; i++){
		printf("%d ", num[i]);
	}
	printf("\n");
	return 0;

}