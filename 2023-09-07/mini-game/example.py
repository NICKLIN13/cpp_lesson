import random

class Game:
    def __init__(self, num: int) -> None:  # def 就是function
        self.num = num
        print(f"Game {self.num} starts!")
        self.ANS = random.randint(1, 20)
    
    def get_guess(self) -> int:
        raw_str = input('Please enter your guess (1~20): ')

        if raw_str == "":
            # something wrong
            print("error: empty string")
            return None
        
        guess = int(raw_str)
        
        if guess < 0 or guess > 20:
            print("error: out of range")
            return None

        return guess


    def run(self):  # 在class 裡面的function第一個參數都要餵給他吃self
        ANS = self.ANS
        while True:
            guess = self.get_guess()
            if guess is None:
                continue

            if guess == 0:
                # for debug
                print("debug")
                break

            if guess == ANS:
                break
            elif guess > ANS:
                print('Too big (っಠ‿ಠ)っ')
                print(' ')
                # guess = int(input('Please try again: '))
            elif guess < ANS:
                print('Too small \(￣ﾊ￣)')
                print(' ')

        print('Good job! ⸜(⸝⸝⸝´꒳`⸝⸝⸝)⸝')



# g1 = Game(1)
# g1.run()


all_games = list()
rounds = 3
for i in range(rounds):
    g = Game(i)
    g.run()
    all_games.append(g)
    # == vector.push_back

for game in all_games:
    print(game.ANS)