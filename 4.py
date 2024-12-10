def validate_password(password):
    # Check if the password is at least 6 characters long
    if len(password) < 6:
        return "Password should be at least 6 characters long."
    
    # Check if the password contains at least one uppercase letter
    if not any(char.isupper() for char in password):
        return "Password should contain at least one uppercase letter."
    
    # Check if the password contains at least one lowercase letter
    if not any(char.islower() for char in password):
        return "Password should contain at least one lowercase letter."
    
    # Check if the password contains at least one digit
    if not any(char.isdigit() for char in password):
        return "Password should contain at least one digit."
    
    # If all checks pass
    return "Password is valid."

# Ask the user to input a password
password = input("Enter your password: ")

# Validate the password
result = validate_password(password)

# Display the result
print(result)