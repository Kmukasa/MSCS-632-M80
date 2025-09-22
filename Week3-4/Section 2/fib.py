def fibonacci_iterative(n):
    """Calculate Fibonacci number using iteration (more efficient)"""
    if n <= 1:
        return n
    
    a, b = 0, 1
    for _ in range(2, n + 1):
        a, b = b, a + b
    return b

def main():
    print("Python Fibonacci:")
    print(f"Iterative fib(10): {fibonacci_iterative(10)}")
        

if __name__ == "__main__":
    main()