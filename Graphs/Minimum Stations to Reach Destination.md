# Minimum Stations to Reach Destination  [Hard]

Not a LeetCode problem — an OA-style question with no LeetCode equivalent. Statement and
constraints below are a faithful formalization of the original wording; the ambiguous
points in the original (whether repeat station visits are counted, what happens when
`source == destination`, whether `destination` may hold a station) are pinned down
explicitly here.

You are given `n` cities numbered from `0` to `n - 1`, and an array `roads` where `roads[i] = [x, y]` means a bidirectional road directly connects city `x` and city `y`. No road connects a city to itself, and there is at most one road between any pair of cities.

Your car starts in city `source` with exactly `p` kg of fuel in its tank. Driving along one road consumes exactly `1` kg of fuel. Your fuel level must never become negative, so you cannot begin driving along a road while the tank is empty.

The array `stations` lists the cities that contain a refueling station. Every time you arrive in a city that contains a refueling station you **must** refuel — the tank is immediately topped back up to exactly `p` kg. Refueling is not optional. City `source` never contains a refueling station, but `destination` may.

You may drive along the same road any number of times and visit the same city any number of times. Every drive counts separately: using one road 5 times contributes 5 to the number of roads used. Likewise, every arrival in a city that contains a refueling station counts separately toward the number of stations visited.

Return a 2-element array `[stations_visited, roads_used]` describing the best trip from `source` to `destination`, where "best" is decided in this priority order:

1. The fuel level must never become negative.
2. The number of refueling stations visited is as small as possible.
3. Among the trips tied on rule 2, the number of roads driven is as small as possible.

If no trip from `source` to `destination` exists under these rules, return `[-1, -1]`. If `source == destination`, the trip is empty, so the answer is `[0, 0]`.

### Example 1

```text
Input: n = 5, roads = [[0,1],[1,2],[2,3],[3,4]], stations = [2], source = 0, destination = 4, p = 2
Output: [1,4]
Explanation: 0 -> 1 (1kg left) -> 2, which refuels the tank to 2kg -> 3 (1kg left) -> 4 (0kg left).
One station visited, four roads driven. With only 2kg of fuel, city 4 cannot be reached at all
without the refuel in city 2.
```

### Example 2

```text
Input: n = 3, roads = [[0,1],[1,2]], stations = [], source = 0, destination = 2, p = 5
Output: [0,2]
Explanation: 0 -> 1 -> 2 uses two roads and the tank never empties.
```

### Example 3

```text
Input: n = 3, roads = [[0,1],[1,2]], stations = [], source = 0, destination = 2, p = 1
Output: [-1,-1]
Explanation: after driving 0 -> 1 the tank is empty, and city 1 has no refueling station,
so the car is stranded.
```

### Constraints

- `1 <= n <= 1000`
- `0 <= roads.length <= min(2000, n * (n - 1) / 2)`
- `roads[i].length == 2`
- `0 <= x, y < n`, `x != y`
- No duplicate roads
- `0 <= stations.length <= n`
- All values in `stations` are distinct and in `[0, n)`
- `source` is not in `stations`
- `0 <= source, destination < n`
- `1 <= p <= 1000`
