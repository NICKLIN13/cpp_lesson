class Game:
    def __init__(self, num: int) -> None:  # def 就是function
        self.num = num
        print(f"Game {self.num} starts!")

    def run(self):  # 在class 裡面的function第一個參數都要餵給他吃self
        guess = int(input('Please enter your guess (1~20): '))
        print(f"Game {self.num}: Your guess is {guess}")




# # class "object" instance

g1 = Game(1)
g1.run()
# g2 = Game(212312)
# g3 = Game(3)

# all_games = list()
# for i in range(3):
#     g = Game(i)
#     all_games.append(g)

# all_games[0].run
