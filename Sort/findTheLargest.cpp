#include <cstdlib>
#include <stdio.h>


int findTheLargest(int *num, int n){
	if (n == 1) {
        return num[0];

    } else {
        int max = findTheLargest(num, n-1);
        //printf("Largest element : %d\n", max);
        return num[n-1] > max ? num[n-1] : max;
    }
}

int main(){
	int n;
	printf("Find the Greatest number in a list\nEnter the size of the list:");
	scanf("%d", &n);
	
	if(n <= 0)
		return 0;
	
	int num[n];

	for(int i = 0; i < n; i++){
		num[i] = rand() % n;
		printf("%d ", num[i]);
	}
	printf("\n");

	int x = findTheLargest(num, n);

	printf("Largest element : %d\n", x);
	return 0;

}