#include <stdio.h>
#include <cstdlib>
#include <ctime>

int gen_random(char *s, int len) {
    const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i <= len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
        printf("%c", s[i]);
    }
    s[len] = 0;

    return 0;
}

int max(int i, int j){
	if (i > j) return i;
	return j;
}

int lcs(char* X, char* Y, int i, int j){
	if(i == 0 || j == 0) return 0;
	if(X[i-1] == Y[j-1]) return 1 + lcs(X, Y, i-1, j-1);
	return max(lcs(X,Y,i,j-1), lcs(X,Y,i-1,j));
}

int main(){
	
	srand(time(0));
	int n = rand() % 30 + 1;
	char *x = (char*)malloc(n * sizeof (int));
	printf("X = ");
	gen_random(x, n);
	printf("\n");
	
	srand(time(0)+1);
	printf("Y = ");
	int m = rand() % 30 + 1;
	char *y = (char*)malloc(m * sizeof (int));
	gen_random(y, m);
	printf("\n");

	printf("LCS = %d\n", lcs(x, y, n, m));

	free(x);
	free(y);

	return 0;
}

