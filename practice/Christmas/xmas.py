from colorama import init, Fore, Back, Style
import numpy as np
import shutil

init()
size = 30

lst = np.array(["'"]*30 + ['♡', '♧'])

# Get the terminal width
terminal_width, _ = shutil.get_terminal_size(fallback=(80, 24))

for i in range(0, size):
    if i == 0:
        print(Fore.YELLOW + "★".center(terminal_width, " "))
    elif i % 2 == 0 and i > 0:
        print(Fore.GREEN + ''.join(np.random.choice(lst, size=i)).center(terminal_width, " "))
    else:
        print(Fore.RED + ("'"*(i+1)).center(terminal_width, " "))

for i in range(5):
    print(Fore.GREEN + "■".center(terminal_width, " "))

init(autoreset=True)
print()
print(Back.RED + "Merry Christmas...!!".center(terminal_width+2, " "))
print()
