#include <cstdlib>
#include <stdio.h>

int merge(int * numbers, int p, int q, int r){

	int *merged = (int*)malloc(r * sizeof (int));
	//printf("p = %d\n", p);
	//printf("q = %d\n", q);
	//printf("r = %d\n\n", r);
	int i = p;
	int j = q+1;
	int k = 0;

	while(i <= q && j <= r){
		if (numbers[i] <= numbers[j]) {
			//printf("i[%d] = %d\n",i, numbers[i]);
			//printf("j[%d] = %d\n\n",j, numbers[j]);
			merged[k] = numbers[i];
			i++;
		} else {
			//printf("2i[%d] = %d\n",i, numbers[i]);
			//printf("2j[%d] = %d\n\n",j, numbers[j]);
			merged[k] = numbers[j];
			j++;
		}
		k++;
	}

	while(i <= q){
		merged[k] = numbers[i];
		k++;
		i++;
	}

	while(j <= r){
		merged[k] = numbers[j];
		k++;
		j++;
	}

	k--;
	while (k >= 0) {
        numbers[p + k] = merged[k];
        k--;
    }

    free(merged);

    return 0;

}

int merge_sort(int * numbers, int p, int r){
	
	if(p < r){
		int q = (p+r)/2;
		merge_sort(numbers, p, q);
		merge_sort(numbers, q+1, r);
		merge(numbers, p, q, r);
	}

	return 0;
	
}

int main(){
	int n;
	printf("Merge Sort a list\nEnter the size of the list: ");
	scanf("%d", &n);
	
	if(n <= 0)
		return 0;
	
	int numbers[n];

	for(int i = 0; i < n; i++){
		numbers[i] = rand() % n;
		printf("%d ", numbers[i]);
	}
	printf("\n");

	merge_sort(numbers, 0, n);

	for(int i = 0; i < n; i++){
		printf("%d ", numbers[i]);
	}
	printf("\n");

	return 0;


}