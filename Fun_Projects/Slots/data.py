# Alec Him
# Python Project - Slot Machine

# Global Variables
MAX_BET = 1000
MIN_BET = 1
ROWS = 5
COLS = 5
WILD_SYMBOL = "W"

# Dictionaries and Libraries
# symbol_count: Appearance Values for each symbol
symbol_count = {
    "A": 5,
    "B": 8,
    "C": 11,
    "D": 14,
    WILD_SYMBOL: 8
}
# symbol_value: Multiplier Values for each symbol
symbol_value = {
    "A": 5,
    "B": 3,
    "C": 2,
    "D": 1
}
# paylines: List of winning lines
paylines = [
    [0, 5, 10, 15, 20],     # Horizontal 1
    [1, 6, 11, 16, 21],     # Horizontal 2
    [2, 7, 12, 17, 22],     # Horizontal 3
    [3, 8, 13, 18, 23],     # Horizontal 4
    [4, 9, 14, 19, 24],     # Horizontal 5
    [0, 1, 2, 3, 4],        # Vertical 1
    [5, 6, 7, 8, 9],        # Vertical 2
    [10, 11, 12, 13, 14],   # Vertical 3
    [15, 16, 17, 18, 19],   # Vertical 4
    [20, 21, 22, 23, 24],   # Vertical 5
    [0, 6, 12, 18, 24],     # Diagonal 1
    [4, 8, 12, 16, 20],     # Diagonal 2
]