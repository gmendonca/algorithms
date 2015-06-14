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

int print_lcs( char *X, char *Y, int m, int n)
{
   int L[m+1][n+1];
   int i, j;

   for (i = 0; i <= m; i++)
   {
     for (j = 0; j <= n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }

   int index = L[m][n];
   int id = index; 
   char print_lcs[index+1];
   print_lcs[index] = 0;
 
   // Start from the right-most-bottom-most corner and
   // one by one store characters in lcs[]
   i = m;
   j = n;
   while (i > 0 && j > 0)
   {
      // If current character in X[] and Y are same, then
      // current character is part of LCS
      if (X[i-1] == Y[j-1])
      {
          print_lcs[index-1] = X[i-1]; // Put current character in result
          i--; j--; index--;     // reduce values of i, j and index
      }
 
      // If not same, then find the larger of two and
      // go in the direction of larger value
      else if (L[i-1][j] > L[i][j-1])
         i--;
      else
         j--;
   }

   printf("LCS = %d\n", id);

   for(j = 0; j < id; j++){
      printf("%c", print_lcs[j]);
   }
   printf("\n");

   return 0;

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

	print_lcs(x, y, n, m);

	free(x);
	free(y);

	return 0;
}

