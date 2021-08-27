/*
    Time complexity: O(N^2)
    Space complexity: O(N^2)

    Where ‘N’ is the number of rows/columns.
*/

struct Cell {
    int xCoordinate, yCoordinate;
    int stepCount;
    Cell() {}
    Cell(int x, int y, int step) {
        xCoordinate = x;
        yCoordinate = y;
        stepCount = step;
    }
};

// Utility method returns true if (x, y) lies inside Board.
bool isInside(int x, int y, int n) {
    if (x >= 1 && x <= n && y >= 1 && y <= n) {
        return true;
    }
    return false;
}

int minSteps(pair<int, int> knightPosition, pair<int, int> targetPosition, int size) {
    // x and y direction, where a knight can move.
    int directionX[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int directionY[] = {-1, -2, -2, -1, 1, 2, 2, 1};

    // Queue for storing states of knight in board.
    queue<Cell> q;

    q.push(Cell(knightPosition.first, knightPosition.second, 0));
    Cell temp;
    int x, y;
    bool visited[size + 1][size + 1];

    // Make all the cell unvisited.
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            visited[i][j] = false;
        }
    }

    visited[knightPosition.first][knightPosition.second] = true;
    while (!q.empty()) {
        temp = q.front();
        q.pop();

        // If current cell is equal to target cell, return its distance.
        if (temp.xCoordinate == targetPosition.first && temp.yCoordinate == targetPosition.second) {
            return temp.stepCount;
        }

        // Loop for all reachable states.
        for (int i = 0; i < 8; i++) {
            x = temp.xCoordinate + directionX[i];
            y = temp.yCoordinate + directionY[i];

            /* 
            	If reachable state is not yet visited and
               	inside board, push that state into queue.
            */
            if (isInside(x, y, size) && !visited[x][y]) {
                visited[x][y] = true;
                q.push(Cell(x, y, temp.stepCount + 1));
            }
        }
    }
}
