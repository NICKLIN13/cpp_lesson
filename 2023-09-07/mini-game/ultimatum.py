# import random

# ans = random.randint(1, 20)
# guess = 0
# # 123
# guess = int(input('Please enter your guess: '))
    
# while guess != ans:
#   # guess = int(input('Please try again: '))
#   if guess > ans:
#     print('Too big (っಠ‿ಠ)っ')
#     print(' ')
#     # guess = int(input('Please try again: '))
#   elif guess < ans:
#     print('Too small \(￣ﾊ￣)')
#     print(' ')
#   guess = int(input('Please try again: '))

# print('Good job! ⸜(⸝⸝⸝´꒳`⸝⸝⸝)⸝')



import random

class Game:
  def __init__(self, num: int) -> None:
    self.num = num
    print(f"Game {self.num} start!")
    self.ANS = random.randint(1, 20)

  def get_guess(self) -> int:
    raw_str = input("Please enter your guess(1~20): ")

    if raw_str == "":
      print("empty string!")
      return None # try except throw
    
    guess = int(raw_str)

    if guess < 0 or guess > 20:
      print("out of range")
      return None
    
    return guess
  
  def run(self) -> None:
    while True:
      guess = self.get_guess()

      if guess is None:
        continue

      if guess == self.ANS:
        print('Good job! ⸜(⸝⸝⸝´꒳`⸝⸝⸝)⸝')
        break
      elif guess > self.ANS:
        print('Too big (っಠ‿ಠ)っ')
      elif guess < self.ANS:
        print('Too small \(￣ﾊ￣)')










newgame = Game(1) # initiate
newgame.run()