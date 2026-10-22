
from itertools import permutations

def travelling_salesman(distance, start=0):
    n = len(distance)
    cities = list(range(n))
    cities.remove(start)

    min_cost = float('inf')
    best_path = []

    for path in permutations(cities):
        route = (start,) + path + (start,)
        cost = 0

        for i in range(len(route) - 1):
            cost += distance[route[i]][route[i + 1]]

        if cost < min_cost:
            min_cost = cost
            best_path = route

    return best_path, min_cost


# Distance matrix between 4 cities
distance = [
    [0, 10, 15, 20],
    [10, 0, 35, 25],
    [15, 35, 0, 30],
    [20, 25, 30, 0]
]

path, cost = travelling_salesman(distance)

print("Shortest Path:", " -> ".join(map(str, path)))
print("Minimum Cost:", cost)
