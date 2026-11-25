# Grid Robot Route with Charging Priorities  [Hard]

https://www.fastprep.io/problems/uber-grid-robot-charging-priorities

A robot travels through a rectangular `grid` from its unique `S` cell to its unique `T` cell. A cell is one of `S`, `T`, `.` (ordinary open space), `C` (a charging cell), or `#` (a wall).

Each move goes up, down, left, or right to a non-wall cell and consumes one unit of battery. There are no diagonal moves. The robot starts with a full battery of a capacity that you must determine.

Whenever it enters a `C` cell, it automatically refills to that capacity and the number of charging visits increases by one. Refilling is mandatory on entry, even on a repeated visit. The move into a charger still costs one unit, but arriving with exactly zero battery is allowed before refilling.

For a route, the required battery capacity is the largest number of moves in any segment from the start or a charging visit to the next charging visit or the target. The initial full battery is not a charging visit. Revisiting `S` does not refill the battery. The journey ends immediately on reaching `T`.

Compare routes by these priorities, in order:

1. Minimize the number of charging visits.
2. Among routes with that minimum, minimize the required battery capacity.
3. Among routes tied on both preceding values, minimize the total number of moves.

Return these three optimal values as `[chargingVisits, requiredCapacity, totalMoves]`. Return `[-1, -1, -1]` if no route reaches the target. Return the values only, not the route's coordinates. Cells may be revisited, but every charger entry is counted; there is no free option to pass through a charger without refilling.

### Example 1

```text
Input: grid = ["SCT", "..."]
Output: [0,4,4]

Explanation: The direct two-move route enters the charger, giving [1,1,2]. Going around the bottom uses no charger and gives [0,4,4], which wins because charging visits have first priority.
```

### Example 2

```text
Input: grid = ["SC...", ".###.", ".###T", ".C..."]
Output: [1,4,8]

Explanation: Both the top-and-right corridor and the left-and-bottom corridor use one charger. The left-and-bottom route has the smaller required capacity, so [1,4,8] is preferred.
```

### Constraints

- The grid has from `1` through `10` rows and from `1` through `10` columns, with at least `2` cells in total.
- Every row has the same length and contains only `S`, `T`, `.`, `C`, and `#`.
- There is exactly one `S` and one `T`; they are distinct cells.
- There are at most `8` charging cells.
- The robot cannot leave the grid or enter walls.
