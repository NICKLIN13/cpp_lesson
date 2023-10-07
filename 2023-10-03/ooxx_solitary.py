# class OOXX():
#     def __init__(self) -> None:
#         print("Game start!")
#         self.board = ["."] * 9
#         self.print_board()
#         self.count = 1
#         self.player = None


#     def print_board(self) -> None:
#         for i in range(0, 9):
#             print(self.board[i], end = " ")
#             if i % 3 == 2:
#                 print()

#     def get_input(self) -> int:
#         if self.count % 2 == 0:
#             self.player = 'X'
#         else:
#             self.player = 'O'

#         data = input(f"Player {self.player}, please enter the number: ")
#         data = int(data) - 1
#         return data


#     def validity(self, data) -> None:

#         if data < 0 or data > 8:
#             raise ValueError("Invalid input!")
        
#         if self.board[data] != '.':
#             raise ValueError("Forbidden point!")
        

#     def check_line(self, a, b, c) -> bool:
#         BOARD = self.board
#         PLAYER = self.player
#         # all of the following conditions are true -> return true
#         result = all([BOARD[a] == PLAYER, BOARD[b] == PLAYER, BOARD[c] == PLAYER])
#         return result


#     def check_winner(self) -> bool:
#         # any of the following conditions is true -> return true
#         return any([
#             self.check_line(0, 1, 2),
#             self.check_line(3, 4, 5),
#             self.check_line(6, 7, 8),

#             self.check_line(0, 3, 6),
#             self.check_line(1, 4, 7),
#             self.check_line(2, 5, 8),
            
#             self.check_line(0, 4, 8),
#             self.check_line(2, 4, 6),
#         ])



#     def put_stone(self, data) -> None:
#         self.board[data] = self.player
#         self.print_board()


#     def run(self) -> None:
#         while True:
#             try:
#                 data = self.get_input()
#                 self.validity(data)
#             except ValueError as e:
#                 print(e)
#                 self.print_board()
#                 continue
            
#             self.put_stone(data)

#             if self.check_winner():
#                 print(f"The winner is {self.player}!")
#                 break # 忘れがち

#             if self.count == 9:
#                 print("It's a tie!")
#                 break # 忘れがち


#             self.count += 1
        


# g1 = OOXX()
# g1.run()





class OOXX():
    def __init__(self) -> None:
        print("OOXX start!")
        self.count = 1
        self.board = ['.'] * 9
        self.print_board()
        self.player = None

    def print_board(self) -> None:
        for i in range(0, 9):
            print(self.board[i], end = ' ')
            if i % 3 == 2:
                print()

    def get_input(self) -> int:
        if self.count % 2 == 0:
            self.player = 'X'
        else:
            self.player = 'O'

        data = input(f"Player {self.player}, it's your turn: ")
        data = int(data) - 1

        self.validity(data)
        
        return data

    def validity(self, data) -> None:
        if data < 0 or data > 8:
            raise ValueError("Invalid value!")
        if self.board[data] != '.':
            raise ValueError("Forbidden point!")
        

    def check_line(self, a, b, c) -> bool:
        BOARD = self.board
        PLAYER = self.player
        return all([BOARD[a] == PLAYER, BOARD[b] == PLAYER, BOARD[c] == PLAYER])


    def check_winner(self) -> bool:
        return any([
            self.check_line(0, 1, 2),
            self.check_line(3, 4, 5),
            self.check_line(6, 7, 8),

            self.check_line(0, 3, 6),
            self.check_line(1, 4, 7),
            self.check_line(2, 5, 8),

            self.check_line(0, 4, 8),
            self.check_line(2, 4, 6),
        ])


    def put_stone(self) -> None:
        data = self.get_input()
        self.board[data] = self.player


    def run(self) -> None:
        while True:
            try: 
                self.put_stone()
            except ValueError as e:
                print(e)
                self.print_board()
                continue
            
            self.print_board()
            if self.check_winner():
                print(f"Player {self.player} win!")
                break
            if self.count == 9:
                print("It's a tie!")
                break

            self.count += 1


g1 = OOXX()
g1.run()