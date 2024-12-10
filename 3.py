def longest_word(s):
    words = s.split()
    longest = max(words, key=len)
    return longest

def character_frequency(s, char):
    return s.count(char)

def is_palindrome(s):
    s = s.replace(" ", "").lower()
    return s == s[::-1]

def first_substring_index(s, substring):
    return s.find(substring)

def word_frequency(s):
    words = s.split()
    freq = {}
    for i in words:
        i = i.lower()
        freq[i] = freq.get(i, 0) + 1
    return freq


input_string = "Madam Arora teaches Malayalam and Algebra."

# a
longest = longest_word(input_string)
print(f"The longest word: {longest}")

# b
char = 'a'
freq_char = character_frequency(input_string, char)
print(f"Frequency of '{char}': {freq_char}")

# c
palindrome_status = is_palindrome(input_string)
print(f"Is the string a palindrome? {'Yes' if palindrome_status else 'No'}")

# d
substring = "teaches"
index = first_substring_index(input_string, substring)
print(f"Index of first appearance of '{substring}': {index}")

# e
word_freq = word_frequency(input_string)
print("Word frequencies:")
for word, freq in word_freq.items():
    print(f"'{word}': {freq}")