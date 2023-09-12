import random

ans = random.randint(1, 20)
guess = 0

guess = int(input('Please enter your guess: '))
    
while guess != ans:
  # guess = int(input('Please try again: '))
  if guess > ans:
    print('Too big (っಠ‿ಠ)っ')
    print(' ')
    # guess = int(input('Please try again: '))
  elif guess < ans:
    print('Too small \(￣ﾊ￣)')
    print(' ')
  guess = int(input('Please try again: '))

print('Good job! ⸜(⸝⸝⸝´꒳`⸝⸝⸝)⸝')