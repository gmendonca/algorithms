import java.util.*;

public class FibMemoization {

    public static int fibonacci(int n, int[] memory) {
        // Complete the function.
        if (n <= 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (memory[n] != 0) {
            return memory[n];
        }
        int f = fibonacci(n - 1, memory) + fibonacci(n - 2, memory);
        memory[n] = f;
        return f;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int [] memory = new int[n+1];
        scanner.close();
        System.out.println(fibonacci(n, memory));
    }
}
