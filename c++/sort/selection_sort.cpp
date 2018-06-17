#include <cstdlib>
#include <stdio.h>

int selection_sort(int * numbers, int n){
	
	int i, j, iMin, tmp;

	for(j = 1; j < n; j++){
		iMin = j;
		for(i = j+1; i <= n; i++)
			if(numbers[i] < numbers[iMin])
				iMin = i;

		if(iMin != j){
			tmp = numbers[j];
			numbers[j] = numbers[iMin];
			numbers[iMin] = tmp;
		}
	}

	return 0;
}

int main(){
	int n;
	printf("Selection Sort a list\nEnter the size of the list:");
	scanf("%d", &n);
	
	if(n <= 0)
		return 0;
	
	int numbers[n];

	for(int i = 1; i <= n; i++){
		numbers[i] = rand() % n;
		printf("%d ", numbers[i]);
	}
	printf("\n");

	selection_sort(numbers, n);

	for(int i = 1; i <= n; i++){
		printf("%d ", numbers[i]);
	}
	printf("\n");
	return 0;

}