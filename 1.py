def averagemarks(marks, N, absent):
    sum = 0
    for i in marks:
        if i != -1:
            sum += i
    if (N - absent) == 0:  # Check for division by zero
        print("Average = Cannot calculate average (all students absent)")
    else:
        avg = sum / (N - absent)
        print("Average = ", avg)

def minmaxmarks(marks, N, absent):
    valid_marks = [mark for mark in marks if mark != -1]  # Filter out absent students
    if not valid_marks:  # Check if there are no valid marks
        print("Min = Cannot determine (all students absent)")
        print("Max = Cannot determine (all students absent)")
    else:
        min_mark = min(valid_marks)
        max_mark = max(valid_marks)
        print("Min = ", min_mark, "Max = ", max_mark)

def absentstudents(marks):
    count = 0
    for i in marks:
        if i == -1:
            count += 1
    return count

def modemarks(marks):
    from collections import Counter
    valid_marks = [mark for mark in marks if mark != -1]  # Filter out absent students
    if not valid_marks:  # Check if there are no valid marks
        print("Mode = Cannot determine (all students absent)")
    else:
        count = Counter(valid_marks)
        mode = count.most_common(1)[0]  # Get the most common mark
        print(mode[0], "occurred", mode[1], "times.")

def convert_to_grades(marks):
    for i in marks:
        if i == -1:
            print("Absent")
        elif i >= 90:
            print("Grade: O")
        elif i >= 80:
            print("Grade: A+")
        elif i >= 70:
            print("Grade: A")
        elif i >= 60:
            print("Grade: B")
        elif i >= 50:
            print("Grade: C")
        elif i >= 40:
            print("Grade: D")
        else:
            print("Grade: Fail")

N = int(input("Enter no. of students: "))
marks = []
print("Enter marks of student, for absent enter -1 ")
for i in range(N):
    element = int(input())
    marks.append(element)

absent = absentstudents(marks)

while True:
    print("\nMenu:")
    print("1. Calculate Average Marks")
    print("2. Find Min and Max Marks")
    print("3. Count Absent Students")
    print("4. Find Mode of Marks")
    print("5. Convert Marks to Grades")
    print("6. Exit")
    
    choice = int(input("Enter your choice: "))
    if choice == 1:
        averagemarks(marks, N, absent)
    elif choice == 2:
        minmaxmarks(marks, N, absent)
    elif choice == 3:
        print("No. of absent students = ", absentstudents(marks))
    elif choice == 4:
        modemarks(marks)
    elif choice == 5:
        convert_to_grades(marks)
    elif choice == 6:
        break
    else:
        print("Invalid choice. Please try again.")