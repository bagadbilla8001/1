def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j+1] = key
    return arr

def shell_sort(arr):
    n = len(arr)
    gap = n // 2  # Start with a large gap and reduce it
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2  # Reduce the gap
    return arr

def display_top_five(scores):
    print("Top 5 Scores (Highest to Lowest):")
    for i, score in enumerate(scores[-1:-6:-1], 1):  # Access last 5 elements in reverse order
        print(f"{i}. {score:.2f}%")

# Input: Second year percentages
percentages = [82.3, 94.5, 78.6, 85.7, 91.4, 88.3, 76.8, 92.5, 79.1, 84.4, 90.2, 87.3]

print("Original Percentages:")
print(percentages)

# Sorting using Insertion Sort
sorted_percentages_insertion = insertion_sort(percentages.copy())

print("\nSorted Percentages using Insertion Sort (Ascending Order):")
print(sorted_percentages_insertion)

# Display the top five scores after Insertion Sort
display_top_five(sorted_percentages_insertion)

# Sorting using Shell Sort
sorted_percentages_shell = shell_sort(percentages.copy())

print("\nSorted Percentages using Shell Sort (Ascending Order):")
print(sorted_percentages_shell)

# Display the top five scores after Shell Sort
display_top_five(sorted_percentages_shell)