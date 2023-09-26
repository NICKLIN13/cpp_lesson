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

class GameError(Exception):
    pass

class Game:
    def __init__(self, num: int) -> None:
        self.num = num
        print(f"Game {self.num} start!")
        self.LOWER_BOUND = 1
        self.UPPER_BOUND = 20
        self.ANS = random.randint(self.LOWER_BOUND, self.UPPER_BOUND)

    def get_guess(self) -> int: 
        """get input and check it"""

        raw_str = input("Please enter your guess(1~20): ")

        if raw_str == "":
            raise ValueError("empty string!")

        guess = int(raw_str)

        if guess < self.LOWER_BOUND or guess > self.UPPER_BOUND: # no magic number!
            raise ValueError("out of range")

        return guess

    def check_ans(self, guess: int):
        result = ""

        self.msg_correct = 'Good job! ⸜(⸝⸝⸝´꒳`⸝⸝⸝)⸝'
        if guess == self.ANS:
            result = self.msg_correct
        elif guess > self.ANS:
            result = 'Too big (っಠ‿ಠ)っ'
        elif guess < self.ANS:
            result = 'Too small \(￣ﾊ￣)'

        print(result)
        return result


    def run(self) -> None:
        while True:
            try: # 把可能會出錯的情況抓出來，試試看他有沒有錯
                guess = self.get_guess()
            except ValueError as e: # 如果發生了預期的錯誤，就執行裡面的內容
                print(e)
                continue

            result = self.check_ans(guess)

            if result == self.msg_correct:
                break











newgame = Game(1) # initiate
newgame.run()