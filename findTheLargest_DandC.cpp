#include <cstdlib>
#include <stdio.h>

int findTheLargest(int *num, int h, int t){
	if ( t - h == 1) {
		return num[h];
	} else {
	   	int half = (h+t)/2;
	    int lower = findTheLargest(num, h, half);
	    int upper = findTheLargest(num, half, t);
	    return (lower > upper) ? lower : upper;
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

	int x = findTheLargest(num, 0, n);

	printf("Largest element : %d\n", x);
	return 0;

}