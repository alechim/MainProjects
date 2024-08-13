# Alec Him
# Python Project - Slot Machine
import random
import data

## Check Functions
def check_winnings(columns, bet, values, paylines):
    """Checks if user won."""
    winnings = 0
    winning_lines = []
    for payline in paylines:
        symbol = columns[payline[0] // data.ROWS][payline[0] % data.COLS]
        for reel in payline:
            if symbol != columns[reel // data.ROWS][reel % data.COLS] and columns[reel // data.ROWS][reel % data.COLS] != data.WILD_SYMBOL:
                break
        else:
            winnings += values[symbol] * bet
            winning_lines.append(payline)

    return winnings, winning_lines

def check_valid_bets(balance):
    """Check if user has enough to bet."""
    while True:
        bet = get_bet()
        if bet > balance:
            print(f"You do not have enough to bet that amount, your current balance is: ${balance}")
        else:
            break
    print(f"You are betting ${bet}.")
    return bet

def check_valid_rounds(balance, bet):
    """Check if user is able to play requested amount of rounds."""
    while True:
        rounds = get_rounds()
        if rounds * bet > balance:
            print(f"You do not have enough to play that many rounds, your current balance is: ${balance}")
        else:
            break
    print(f"You are playing {rounds} rounds.")
    return rounds

## Getter Functions
def get_slot_machine_spin(rows, cols, symbols):
    """Generates a 5x5 matrix of symbols."""
    all_symbols = []
    for symbol, symbol_count in symbols.items():
        for _ in range(symbol_count):
            all_symbols.append(symbol)

    # List Comprehension
    # [expression for item in iterable if condition]
    columns = []
    for _ in range(cols):
        column = []
        current_symbols = all_symbols[:]
        for _ in range(rows):
            value = random.choice(current_symbols)
            current_symbols.remove(value)
            column.append(value)
        columns.append(column)

    return columns

def get_bet():
    """Allows user to place a bet."""
    while True:
        amount = input("How much would you like to bet? $")
        if amount.isdigit():
            amount = int(amount)
            if data.MIN_BET <= amount <= data.MAX_BET:
                break
            else:
                print(f"Amount must be between ${data.MIN_BET} - ${data.MAX_BET}.")
        else:
            print("Please enter a number.")

    return amount

def get_rounds():
    """Allows user to decide how many rounds they want to play."""
    while True:
        rounds = input("How many rounds would you like to play? ")
        if rounds.isdigit():
            rounds = int(rounds)
            if rounds > 0:
                break
            else:
                print("Rounds must be greater than 0.")
        else:
            print("Please enter a number.")

    return rounds