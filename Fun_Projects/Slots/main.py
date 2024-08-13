# Alec Him
# Python Project - Slot Machine
# Tutorial Video followed (Tech with Tim): https://youtu.be/th4OBktqK1I?si=g4uXQz_yRZ_949zs
import data
import func
import time
import threading
import msvcrt

## Display Functions
def print_slot_machine(columns):
    """Prints the 5x5 matrix of symbols."""
    print("+---+---+---+---+---+")
    for row in range(len(columns[0])):
        for i, column in enumerate(columns):
            if i != len(columns) - 1:
                print(end="| " + column[row] + " ")
            else:
                print(end="| " + column[row] + " | ")
        print()
    print("+---+---+---+---+---+")

def print_instructions(balance):
    """Prints the instructions for the game."""
    print("*=============================*")
    print(f"| Current balance is: ${balance}")
    print("*=============================*")
    print("| 1. Press Enter to play      |")
    print("| 2. Press q to quit          |")
    print("| 3. Press a to play auto     |")
    print("| 4. Press d to deposit money |")
    print("*=============================*")

## Game Functions
def deposit():
    """Allows user to deposit money."""
    print("*=============================*")
    while True:
        amount = input("What would you like to deposit? $")
        # <variable>.isdigit() -> checks if variable is a number
        if amount.isdigit():
            amount = int(amount)
            if amount > 0:
                break
            else:
                print("Amount must be greater than 0.")
        else:
            print("Please enter a number.")
    return amount

def auto_play(balance, bet, rounds):
    """Allows user to play automatically."""
    # Create a new thread to wait for user input
    stop_auto_play = threading.Event()
    def wait_for_user_input():
        while not stop_auto_play.is_set():
            # Check if user has pressed any key
            if msvcrt.kbhit():
                # Read the key that was pressed without echoing it
                msvcrt.getch()
                # Set the stop_auto_play event
                stop_auto_play.set()
    
    # Start the wait_for_user_input thread
    thread = threading.Thread(target=wait_for_user_input)
    thread.daemon = True  # Set as daemon thread so it exits when main thread exits
    thread.start()
    
    # Game Logic
    for i in range(rounds):
        balance += game(bet)
        print(f"Round {i + 1}: Balance = ${balance}")
        time.sleep(1) # Wait for 1 second before playing the next round
        if stop_auto_play.is_set():
            break

    return balance

def game(bet):
    """Runs the game."""
    slots = func.get_slot_machine_spin(data.ROWS, data.COLS, data.symbol_count)
    print_slot_machine(slots)
    winnings, winning_lines = func.check_winnings(slots, bet, data.symbol_value, data.paylines)
    print(f"You won ${winnings}.")
    # *<variable> - splat/unpack operator - unpacks the list into separate arguments
    # print(f"You won on lines: ", *winning_lines)
    for i, line in enumerate(data.paylines):
        if line in winning_lines:
            if i < 5:
                print(f"You won on Row {i+1}.")
            elif i < 10:
                print(f"You won on Column {i-4}.")
            elif i == 10:
                print(f"You won on Diagonal 1.")
            else:
                print(f"You won on Diagonal 2.")
    
    return winnings - bet

## DONE:
## - Auto Play
## - Base 5x5 Grid
## - Randomize / Base Game

## TODO:
## - Change Win Conditions + Add Symbols
## - Add free spins/bonus
## - Check performance of overall gameplay
## - Front End Work (Website)
#### > Images + Sounds

## Win Lines
## - Rows
## - Diagonals
## - Zig Zags
## - Min 3 Symbols & Max 5 Symbols

# Main
def main():
    balance = deposit()
    print_instructions(balance)
    while True:
        choice = input("Choose an option (Select m to display instructions): ").lower()
        if choice == "q":
            break
        elif choice == "a":
            bet = func.check_valid_bets(balance)
            rounds = func.check_valid_rounds(balance, bet)
            balance = auto_play(balance, bet, rounds)
        elif choice == "d":
            balance = deposit()
        elif choice == "m":
            print_instructions(balance)
        else:
            # Check if user has enough to bet
            bet = func.check_valid_bets(balance)
            balance += game(bet)
    
    # Display final balance
    if balance > 0:
        print(f"You left with ${balance}.")
    else:
        print("Take the L nerd.")

if __name__ == "__main__":
    main()