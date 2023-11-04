import itertools
import pandas as pd

# Define the number of games
number_of_games = 17

# Create all possible combinations of W and L
outcomes = list(itertools.product('WL', repeat=number_of_games))

# Convert the outcomes to a list of strings
outcomes_as_strings = [''.join(outcome) for outcome in outcomes]

# Convert the list to a DataFrame
df = pd.DataFrame(outcomes_as_strings, columns=['Outcomes'])

# Save the DataFrame to an Excel file
df.to_excel('sports_game_outcomes.xlsx', index=False)
