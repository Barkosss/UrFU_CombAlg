def dfs(matrix: list, visited: list, vertex: int):
    if visited[vertex]:
        return "N", visited
    elif len(visited) >= vertex:
        return ("A",)

    visited[vertex] = True

    for i, is_connected in enumerate(matrix[vertex]):
        if is_connected:
            return dfs(matrix, visited, i)

def main():
    count = int(input("Enter counter: "))
    matrix = [list(map(int, input().split())) for _ in range(count)]
    visited = [False] * len(matrix)
    result = dfs(matrix, visited, 0)
    print(*result[0])
    if result[0] == "N":
        print(*result[1])

if __name__ == '__main__':
    main()
