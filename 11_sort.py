def bucket_sort(arr):
    # Step 1: Create empty buckets
    min_value = min(arr)
    max_value = max(arr)
    bucket_count = 10  # Can adjust this based on desired granularity
    range_per_bucket = (max_value - min_value) / bucket_count

    buckets = [[] for i in range(bucket_count)]

    # Step 2: Insert elements into buckets
    for num in arr:
        index = int((num - min_value) // range_per_bucket)
        if index == bucket_count:
            index -= 1  # Ensure the max value is placed in the last bucket
        buckets[index].append(num)

    # Step 3: Sort individual buckets and concatenate the result
    sorted_arr = []
    for bucket in buckets:
        sorted_arr.extend(sorted(bucket))
    return sorted_arr

def display_top_five(arr):
    sorted_arr = arr[::-1]  # Display in descending order
    return sorted_arr[:5]

percentages = [76.5, 82.3, 91.4, 68.9, 87.2, 95.1, 78.4, 85.0, 79.5, 88.0, 92.3, 74.8]  # Example percentages
print("Bucket Sort Method:")

sorted_arr = bucket_sort(percentages)
print("Sorted Array (Bucket Sort):", sorted_arr)
print("Top Five Scores:", display_top_five(sorted_arr))