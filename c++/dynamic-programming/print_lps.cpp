#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <string.h>

int gen_random(char *s, int len) {
    const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZZYXWVUTSRQPONMLKJIHGFEDCBA";
    for (int i = 0; i <= len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
        printf("%c", s[i]);
    }
    s[len] = 0;

    return 0;
}

void printSubStr( char* str, int low, int high )
{
    for( int i = low; i <= high; ++i )
        printf("%c", str[i]);
}
 

int print_lps( char *str )
{
    int n = strlen( str );
 

    bool table[n][n];
    memset(table, 0, sizeof(table));
 
    int maxLength = 1;
    for (int i = 0; i < n; ++i)
        table[i][i] = true;
 
    int start = 0;
    for (int i = 0; i < n-1; ++i)
    {
        if (str[i] == str[i+1])
        {
            table[i][i+1] = true;
            start = i;
            maxLength = 2;
        }
    }
 

    for (int k = 3; k <= n; ++k)
    {
        for (int i = 0; i < n-k+1 ; ++i)
        {
            int j = i + k - 1;
 
            if (table[i+1][j-1] && str[i] == str[j])
            {
                table[i][j] = true;
 
                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
 
    printf("Longest palindrome substring is: ");

    for( int i = start; i <= start + maxLength - 1; ++i )
        printf("%c", str[i]);
 
    return maxLength;
}

int main(){
	
	srand(time(0));
	int n = rand() % 30 + 1;
	char *x = (char*)malloc(n * sizeof (int));
	printf("X = ");
	gen_random(x, n);
	printf("\n");

  //char x[] = "xabbibba";
  printf("\nLength is: %d\n", print_lps(x));  

	free(x);

	return 0;
}