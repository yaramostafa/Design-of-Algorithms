import numpy as np
import random

# Initial Graph
graph = {(x, y): ' ' for x in range(1, 5) for y in range(1, 4)}
graph[(1, 1)] = 'B'
graph[(1, 2)] = 'B'
graph[(1, 3)] = 'B'

graph[(4, 1)] = 'W'
graph[(4, 2)] = 'W'
graph[(4, 3)] = 'W'

# Target Graph
target = {(x, y): ' ' for x in range(1, 5) for y in range(1, 4)}
target[(1, 1)] = 'W'
target[(1, 2)] = 'W'
target[(1, 3)] = 'W'

target[(4, 1)] = 'B'
target[(4, 2)] = 'B'
target[(4, 3)] = 'B'


# Visualizing the graph
def visualize(graph):
    row = 0

    print(end="\t********")
    for node in graph:
        if node[0] != row:
            if row == 0:
                print(end="\n\t| ")
            else:
                print(end="| \n\t| ")
            row += 1

        print(graph[node], end=" ")
    print(end="|\n\t|*******|\n\n")


# Getting Distance from two nodes

def get_distance(node1, node2):
    dist = np.sqrt(np.sum(np.square(np.subtract(node1, node2))))
    return dist


choices = {(x, y): set() for x in range(1, 5) for y in range(1, 4)}

for node1 in graph:
    for node2 in graph:
        if get_distance(node1, node2) == np.sqrt(5):
            choices[node1].add(node2)
            choices[node2].add(node1)


def restart(graph):
    print("restarting....")
    graph = {(x, y): ' ' for x in range(1, 5) for y in range(1, 4)}
    graph[(1, 1)] = 'B'
    graph[(1, 2)] = 'B'
    graph[(1, 3)] = 'B'

    graph[(4, 1)] = 'W'
    graph[(4, 2)] = 'W'
    graph[(4, 3)] = 'W'

def main():
    print("Beginning of the graph:\n")
    visualize(graph)
    print("Target graph:\n")
    visualize(target)

    is_white = True

    num_try = 1
    is_restart = True

    while graph != target:
        if is_restart:
            print("Restarting...")

            # Initialize graph

            for node in graph:
                graph[node] = ' '
            graph[(1, 1)] = 'B'
            graph[(1, 2)] = 'B'
            graph[(1, 3)] = 'B'

            graph[(4, 1)] = 'W'
            graph[(4, 2)] = 'W'
            graph[(4, 3)] = 'W'
            is_white = True

            # Save horse positions

            whites = []
            blacks = []

            for node in graph:
                if graph[node] == 'W':
                    whites.append(node)
                elif graph[node] == 'B':
                    blacks.append(node)

            num_try += 1
            num_turn = 0
            is_restart = False

            print("Try: " + str(num_try))
            print("Beginning: \n")

        is_played = False
        visualize(graph)

        if is_white:
            while not is_played:
                is_available = False

                for horse in whites:
                    for choice in choices[horse]:
                        if graph[choice] == ' ':
                            is_available = True

                if not is_available:
                    is_restart = True
                    break

                white = random.choice(whites)

                move = random.sample(choices[white], 1)[0]

                if graph[move] == ' ':
                    graph[white] = ' '
                    graph[move] = 'W'

                    whites.remove(white)
                    whites.append(move)

                    is_played = True

            is_white = False
        else:
            while not is_played:
                is_available = False

                for horse in blacks:
                    for choice in choices[horse]:
                        if graph[choice] == ' ':
                            is_available = True

                if not is_available:
                    restart(graph)
                    break

                black = random.choice(blacks)

                move = random.sample(choices[black], 1)[0]

                if graph[move] == ' ':
                    graph[black] = ' '
                    graph[move] = 'B'

                    blacks.remove(black)
                    blacks.append(move)

                    is_played = True
            is_white = True

        num_turn += 1

    print("Final graph (" + str(num_try) + ")(" + str(num_turn) + "): \n")
    visualize(graph)


if __name__ == "__main__":
    main()
