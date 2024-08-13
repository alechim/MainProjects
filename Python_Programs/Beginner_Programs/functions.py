# Alec Him
# Python Exercise 4 - Functions
# - Do Not Repeat Yourself (DRY) principle

# def -> defines a function
def ask_name():
    name = input("What is your name? ").capitalize()
    return name

# pass a parameter to a function
def calculate_expenses(expenses):
    # sum(parameter) -> adds up all the values in the list
    sum_total = sum(expenses)
    return sum_total

## Work on creating functions: calculate_savings, simple_interest, compound_interest
def calculate_savings(income, expenses):
    # Convention / Good practice to use this format of string to explain what the function does
    """ Subtracts expenses from income to calculate savings. """
    savings = income - expenses
    # f<string> -> format string
    # ${variable} -> format variable
    # <variable>:.2f -> round to 2 decimal places
    return f"Total savings: ${savings:.2f}"

def simple_interest(principal, rate, time):
    """ Calculates simple interest on a principal over time at a given rate. """
    interest = (principal * (rate / 100) * time)
    return f"Simple interest: ${interest:.2f}"

def compound_interest(principal, rate, times_compounded, years):
    """ Calculates compound interest. """
    amount = principal * (1 + (rate / 100) / times_compounded) ** (times_compounded * years)
    interest = amount - principal
    return f"Compound interest: ${interest:.2f}"

exp = [20.3, 50.3, 70.1, 86.3]

# print(ask_name())
# print(calculate_expenses(exp))

command = input("Which command would you like to run? Options: expenses, ask_name, savings, ")

# Exercise 5 - Control Flow + Type Casting + For Loops
# - Traceback - an error that occurs when running a python program
if command == "expenses":
    num_expenses = int(input("How many expenses do you have? "))
    expenses = []
    for i in range(num_expenses):
        expense = float(input(f"Enter expense {i + 1}: "))
        expenses.append(expense)
    print(f"Total expenses: ${calculate_expenses(expenses):.2f}")

elif command == "ask_name":
    print(f"Hello, {ask_name()}!")

elif command == "savings":
    # Typecasting to float
    income = float(input("What is your income? "))
    # Typecasting to int
    num_expenses = int(input("How many expenses do you have? "))
    expenses = []
    # For loop to get expenses
    for i in range(num_expenses):
        expense = float(input(f"Enter expense {i + 1}: "))
        # Append to list
        expenses.append(expense)
    total_expenses = calculate_expenses(expenses)
    print(calculate_savings(income, total_expenses))

elif command == "simple_interest":
    principal = float(input("What is the principal amount? "))
    rate = float(input("What is the interest rate (in %)? "))
    time = float(input("For how many years? "))
    print(simple_interest(principal, rate, time))

elif command == "compound_interest":
    principal = float(input("What is the principal amount? "))
    rate = float(input("What is the interest rate (in %)? "))
    times_compounded = float(input("How many times is the interest compounded per year? "))
    years = float(input("For how many years? "))
    print(compound_interest(principal, rate, times_compounded, years))

else:
    print("Invalid command")