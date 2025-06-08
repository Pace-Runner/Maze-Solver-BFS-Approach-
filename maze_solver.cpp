#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

void solveMaze(vector<vector<char>>& maze, int height, int width, pair<int, int> start, pair<int, int> goal) {
    // Initialise an empty queue
    queue<pair<int, int>> q;

    // Initialise distance and parent arrays
    vector<vector<int>> distance(height, vector<int>(width, INT_MAX)); //Grid that will store the distance from start
    vector<vector<pair<int, int>>> parent(height, vector<pair<int, int>>(width, {-2, -2})); //stores the block that came before current block

    // goal and start
    q.push(start);
    distance[start.first][start.second] = 0;

    vector<pair<int, int>> directions = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

    // Loop until the queue is empty and the goal is visited
    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();

        // If the goal is reached, we can exit the loop early
        if (curr == goal)
        {
            break;;
        }



        // Foreach neighbor (down, left, up, right)
        for (const auto& dir : directions)//Adding path for all directions to the que- This is fine though because each of those co-ordinated knows where its parent is
        {   
            //Moving
            int newRow = curr.first + dir.first;
            int newCol = curr.second + dir.second;

            // Check if the neighbor is a valid move and unvisited
            if (newRow >= 0 && newRow < height   && newCol >= 0 && newCol < width && maze[newRow][newCol] != 'x' && distance[newRow][newCol] == INT_MAX)
            {
                distance[newRow][newCol] = distance[curr.first][curr.second] + 1; //Current distance at that block plus 1
                parent[newRow][newCol] = curr; //New new blocks parent is the last block it came from(currently curr)
                q.push({newRow, newCol}); //Adding new co-ordinates to the que
            }
        }
    }


    if (distance[goal.first][goal.second] == INT_MAX) //When everything is tried but the goal still hasnt been reched
    {
        cout << "No Path" << endl;
        return;
    }
    
    // Backtrack to find the path from goal to start
    vector<pair<int, int>> output;
    pair<int, int> curr = goal;
    while (curr != start)
    {
        output.insert(output.begin(), curr); // Add current to the front of the output
        curr = parent[curr.first][curr.second];//Going back
    }
    output.insert(output.begin(), start); // Add start to the front of the output

    // Output the path
    for (const auto& step : output) {
        if (maze[step.first][step.second] != 'G' && maze[step.first][step.second] != 'S')
        {
            maze[step.first][step.second] = '*';
        }
    }

    // Printing
    cout << endl;
    for (const auto& row : maze)
    {
        for (char cell : row)
        {
            cout << cell;
        }
        cout << endl;
    }


}

int main()
{
    //input
    int height, width;
    cin >> height >> width;
    cin.ignore();

    pair<int, int> start, goal;
    vector<vector<char>> maze(height, vector<char>(width));

    for (int i = 0; i < height; ++i)
    {
        string row;
        getline(cin, row);
        for (int j = 0; j < width; ++j)
        {
            maze[i][j] = row[j];
            if (maze[i][j] == 'S') start = {i, j};
            if (maze[i][j] == 'G') goal = {i, j};
        }
    }

    solveMaze(maze, height, width, start, goal);
    return 0;
}
