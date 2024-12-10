def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr

def display_top_five(arr):
    print("Top 5 Scores (Highest to Lowest):")
    for i in range(0,5) :
        print(arr[i])

# Input: First year percentages
percentages = [80.5, 91.7, 78.2, 85.6, 90.3, 87.1, 79.5, 88.4, 92.1, 86.3, 83.7, 95.2]

print("Original Percentages:")
print(percentages)

# Sorting using Selection Sort
sorted_percentages_selection = selection_sort(percentages.copy())

print("\nSorted Percentages using Selection Sort (Ascending Order):")
print(sorted_percentages_selection)

# Display the top five scores after Selection Sort
display_top_five(sorted_percentages_selection)

# Sorting using Bubble Sort
sorted_percentages_bubble = bubble_sort(percentages.copy())

print("\nSorted Percentages using Bubble Sort (Ascending Order):")
print(sorted_percentages_bubble)

# Display the top five scores after Bubble Sort
display_top_five(sorted_percentages_bubble)