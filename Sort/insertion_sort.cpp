#include <cstdlib>
#include <stdio.h>

int insertion_sort(int * numbers, int n){
	for(int j = 2; j <= n; j++){
		int key = numbers[j];
		int i = j - 1;
		// mantain stability, don't change when equals
		while(i > 0 && numbers[i] > key){
			numbers[i + 1] = numbers[i];
			i--;
		}
		numbers[i+1] = key;
	}
	return 0;
}

int main(){
	int n;
	printf("Insertion Sort a list\nEnter the size of the list:");
	scanf("%d", &n);
	
	if(n <= 0)
		return 0;
	
	int numbers[n];

	for(int i = 1; i <= n; i++){
		numbers[i] = rand() % n;
		printf("%d ", numbers[i]);
	}
	printf("\n");

	insertion_sort(numbers, n);

	for(int i = 1; i <= n; i++){
		printf("%d ", numbers[i]);
	}
	printf("\n");
	return 0;

}