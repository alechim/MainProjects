/*
 * Alec Him
 * CS 135 - Lab 9
 * Description: Fibonacci Sequence numbers based on passed inputs from user
 * Input: Fibonacci number and Max Fibonacci Value
 * Output: Fibonacci Sequence based on prior inputs
 */
#include <iostream>

// Function Prototypes
int fibonacci(int);
void print_fib(int);

// Function Definitions
int fibonacci(int n)
{
    if(n <= 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 1;
    
    // Variables
    int fib[500];
    fib[0] = 0;
    fib[1] = 1;

    for(int i = 2; i < n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    return fib[n - 1];
}

void print_fib(int n)
{
    if(n <= 0)
    {
        std::cout << "No Fibonacci sequence exists for non-positive integers.\n";
        return;
    }
    
    int fib[500];
    fib[0] = 0;
    fib[1] = 1;

    std::cout << fib[0] << " " << fib[1] << " ";
    for(int i = 2; i < n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
        if(fib[i] > n) break;
        std::cout << fib[i] << " ";
    }

    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    if(argc != 3)
    {
        std::cout << "Error: invalid command line arguments.\n";
        std::cout << "Usage: ./lab9 <nth_fibonacci> <max_fib_value>\n";
        return 1;
    }
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    if(x <= 0 || y <= 0)
    {
        std::cout << "Error: arguments must be positive integers.\n";
        return 1;
    }

    std::cout << "The " << x << "th number in the Fibonacci Sequence is: " << fibonacci(x) << std::endl;
    std::cout << "The Fibonacci sequence up to " << y << " is:\n";
    print_fib(y);

    return 0;
}