# Initial Graph for chess game 3x4
chess = []
for i in range(4):
    row = []
    for j in range(3):
        row.append(0)
    chess.append(row)

# Initialize knights position on the board
chess[0][0] = 2
chess[0][1] = 2
chess[0][2] = 2
chess[3][1] = 1
chess[3][0] = 1
chess[3][2] = 1


# Visualizes the chess game
def visualize(chess):
    for row in chess:
        for col in row:
            if col == 0:
                print('| |', end=' ')
            elif col == 1:
                print('|W|', end=' ')
            elif col == 2:
                print('|B|', end=' ')
        print()


print("The game intial state : ")
visualize(chess)
print("\n")


# Defining the movement of knights
def moveKnight(chess, x, y):
    Knight = chess[x[0]][x[1]]
    chess[x[0]][x[1]] = 0
    chess[y[0]][y[1]] = Knight

    visualize(chess)
    print("\n")


# gets the floor division by 3 of the sent variable
def cal(x):
    x = x - 1
    return x // 3, x % 3


# checks the position of the knight whether its in the inner or outer graph of length 6 or 10
def find(chess, subgraph):
    # if it's the innerGraph which consists of 6 vertices then check the knight positions and return true
    if subgraph and len(subgraph) == 6:
        if chess[0][1] == 1 and chess[3][1] == 2:
            return 1
    # if it's the outerGraph which consists of 6 vertices then check the knight positions and return true
    elif subgraph and len(subgraph) == 10:
        if chess[0][0] == 1 and chess[0][2] == 1 and chess[3][0] == 2 and chess[3][2] == 2:
            return 1
    return 0


# solves the inner graph that consists of 1 white against 1 black
def chessGame(chess, innerGraph, outerGraph):
    # innerGraph consists of 2 knights against one another 1 black 1 white
    # outerGraph consists of 2 black knights against 2 white knights
    n = 0
    if innerGraph and outerGraph:
        chessGame(chess, innerGraph, None)  # sends divided partitions to solve either the inner graph and outer graph
        chessGame(chess, None, outerGraph)
        return

    # check which graph im using (inner or outer)
    board = innerGraph if innerGraph else outerGraph
    # create empty graph to add knights positions in it
    knights = []
    # loop in the given board to save knights position
    for node in board:
        if chess[cal(node)[0]][cal(node)[1]] in (1, 2):
            knights.append(node)

    for i, node in enumerate(knights):
        # Enumerate() method adds a counter to an iterable and returns it in a form of enumerating object. here it
        # Enumerates the knights
        node1 = board.index(node)
        node2 = board.index(knights[i + 1]) if i < len(knights) - 1 else board.index(knights[0])
        subgraph = board[node1:node2] if node2 > node1 else board[node1:] + board[:node2]  #

        # keeps moving the knights on the board vertices until the knights are in their target positions
        for j in range(len(subgraph) - 1):
            moveKnight(chess, cal(subgraph[j]), cal(subgraph[j + 1]))
    # moves the knights to their correct positions
    for i, node in enumerate(knights):
        nodex = board.index(node)
        nodey = nodex - 1 if nodex != 0 else len(board) - 1
        n += 1
        moveKnight(chess, cal(board[nodey]), cal(board[nodex]))

    # checks if the sent boards are the innerGraph or outerGraph
    if find(chess, innerGraph) and not outerGraph:
        return
    elif not outerGraph:
        chessGame(chess, innerGraph, None)
    elif find(chess, outerGraph) and not innerGraph:
        return
    elif not innerGraph:
        chessGame(chess, None, outerGraph)


print("Game starts NOW")
chessGame(chess, [6, 11, 4, 9, 2, 7], [1, 8, 3, 4, 9, 10, 5, 12, 7, 6])
# outer vertices for the outerGraph [1, 8, 3, 4, 9, 10, 5, 12, 7, 6]
# inner vertices for the innerGraph [6, 11, 4, 9, 2, 7]
