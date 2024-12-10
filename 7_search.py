# Function to perform linear search
def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

# Function to perform sentinel search
def sentinel_search(arr, target):
    n = len(arr)
    last = arr[n-1]
    arr[n-1] = target
    i = 0
    while arr[i] != target:
        i += 1
    arr[n-1] = last
    if i < n-1 or arr[n-1] == target:
        return i
    return -1

# Function to perform binary search (requires sorted array)
def binary_search(arr, target):
    low = 0
    high = len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return -1

# Function to perform Fibonacci search (requires sorted array)
def fibonacci_search(arr, target):
    n = len(arr)
    fib_m_2 = 0  # (m-2)'th Fibonacci No.
    fib_m_1 = 1  # (m-1)'th Fibonacci No.
    fib = fib_m_1 + fib_m_2  # m'th Fibonacci

    # Fibonacci number greater than or equal to n
    while fib < n:
        fib_m_2 = fib_m_1
        fib_m_1 = fib
        fib = fib_m_1 + fib_m_2

    # Comparing the element with Fibonacci numbers
    offset = -1
    while fib > 1:
        i = min(offset + fib_m_2, n - 1)

        if arr[i] < target:
            fib = fib_m_1
            fib_m_1 = fib_m_2
            fib_m_2 = fib - fib_m_1
            offset = i
        elif arr[i] > target:
            fib = fib_m_2
            fib_m_1 = fib_m_1 - fib_m_2
            fib_m_2 = fib - fib_m_1
        else:
            return i

    if fib_m_1 and arr[offset + 1] == target:
        return offset + 1

    return -1

# Sample list of roll numbers (unsorted for some searches)
roll_numbers = [102, 110, 101, 105, 108, 103, 107, 106]

# Sort the roll numbers for binary and Fibonacci search
sorted_roll_numbers = sorted(roll_numbers)

target = int(input("Enter the roll number to search: "))

# Linear search
result = linear_search(roll_numbers, target)
if result != -1:
    print(f"Linear Search: Roll number {target} found at index {result}")
else:
    print("Linear Search: Roll number not found")

# Sentinel search
result = sentinel_search(roll_numbers, target)
if result != -1:
    print(f"Sentinel Search: Roll number {target} found at index {result}")
else:
    print("Sentinel Search: Roll number not found")

# Binary search (requires sorted array)
result = binary_search(sorted_roll_numbers, target)
if result != -1:
    print(f"Binary Search: Roll number {target} found at index {result}")
else:
    print("Binary Search: Roll number not found")

# Fibonacci search (requires sorted array)
result = fibonacci_search(sorted_roll_numbers, target)
if result != -1:
    print(f"Fibonacci Search: Roll number {target} found at index {result}")
else:
    print("Fibonacci Search: Roll number not found")