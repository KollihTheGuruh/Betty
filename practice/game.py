import random

def select_word():
    words = ['apple', 'banana', 'cherry', 'orange', 'grape', 'kiwi', 'lemon', 'lime', 'mango', 'melon', 'peach', 'pear', 'pineapple', 'plum', 'strawberry', 'watermelon']
    return random.choice(words)

def jumble_word(word):
    jumbled = list(word)
    random.shuffle(jumbled)
    return ''.join(jumbled)

def play_game(stage):
    word = select_word()
    jumbled = jumble_word(word)
    attempts = 0
    max_attempts = 0
    
    if stage == 'simple':
        max_attempts = 3
    elif stage == 'hard':
        max_attempts = 5
    elif stage == 'difficult':
        max_attempts = 7
    
    while attempts < max_attempts:
        print(f'Jumbled word: {jumbled}')
        guess = input('Guess the word: ')
        attempts += 1
        
        if guess.lower() == word:
            print('Congratulations! You guessed the word.')
            return
        
        print('Incorrect guess.')
    
    print(f'You ran out of attempts. The word was {word}.')

# Main program
print('Welcome to the word puzzle game!')
stage = input('Select a stage (simple/hard/difficult): ')

play_game(stage)

