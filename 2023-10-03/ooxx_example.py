class OOXX():
    def __init__(self) -> None:
        print("OOXX starts!")
        self.board = ['.'] * 9
        self.print_board()
        self.count = 1
        self.player = None

    def print_board(self):
        for i in range(0,9):
            print(self.board[i], end='')
            if i % 3 == 2:
                print()
    
    def get_input(self):
        if self.count % 2 == 0:
            self.player = 'X'
        else:
            self.player = 'O'

        data = input(f"Player {self.player}, please input a number: ")
        
        # throw an error if data is not a number
        data = int(data)
        
        # Real index starts from 0 instead of 1
        data -= 1

        # throw an error if data is not in range(0, 9)
        if data < 0 or data > 8:
            raise ValueError("The number is not in range(0, 9).")
        

        if self.board[data] != '.':
            raise ValueError("The block is not empty.")

        return data

    def put_stone(self, data):
        self.board[data] = self.player

    def check_winner(self):
        return any([
            self.check_line(0, 1, 2),
            self.check_line(3, 4, 5),
            self.check_line(6, 7, 8),
            
            self.check_line(0, 3, 6),
            self.check_line(1, 4, 7),
            self.check_line(2, 5, 8),
            
            self.check_line(0, 4, 8),
            self.check_line(2, 4, 6)
            ]
        )

    def check_line(self, a, b, c) -> bool:
        B = self.board
        p = self.player
        result = all([B[a] == p, B[b] == p, B[c] == p])
        # print(result)
        return result

    def run(self) -> None:

        while True:
            try:
                data = self.get_input()
            except ValueError as e:
                print(e)
                continue

            self.put_stone(data)
            self.print_board()

            if self.check_winner():
                print(f"The winner is {self.player}!")
                break
            
            
            if self.count == 9:
                print("It's a tie!")
                break

            self.count += 1

        print("end")

g1 = OOXX()
g1.run()

# Minimax algorithm