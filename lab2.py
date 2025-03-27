
def BFS(matrix: list[int]):
    n = len(matrix)


    visited = 0


    return visited == n


def main():
    count = int(input("Enter counter: "))
    matrix = [x for x in range(count)]
    BFS(matrix)


if __name__ == '__main__':
    main()