#include <stdio.h>
#include <cstdlib>
#include <ctime>

int gen_random(char *s, int len) {
    const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZZYXWVUTSRQPONMLKJIHGFEDCBA";
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

int lps( char *x, int i, int j)
{
   if (i == j) return 1;
   if (x[i] == x[j] && i + 1 == j) return 2;
   if (x[i] == x[j]) return 2 + lps(x, i+1, j-1);
   return max( lps(x, i, j-1), lps(x, i+1, j) );
}

int main(){
	
	srand(time(0));
	int n = rand() % 30 + 1;
	char *x = (char*)malloc(n * sizeof (int));
	printf("X = ");
	gen_random(x, n);
	printf("\n");

	printf("LPS = %d\n", lps(x, 0, 8));

	free(x);

	return 0;
}

