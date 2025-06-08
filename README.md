# Maze-Solver-BFS-Approach-
This is a simple C++ program that finds the shortest path through a maze using Breadth-First Search (BFS). I wrote this to practice pathfinding logic and grid-based algorithms.

    The maze is represented as a grid of characters:

        'x' = wall (you can't move here)

        'S' = start point

        'G' = goal point

        ' ' (space) = open path

    The program reads in the maze and figures out the shortest path from S to G using a BFS traversal.

    Once the path is found, it backtracks from the goal to the start and marks the path using '*' on the maze.

Features

    Finds the shortest path (if it exists).

    If no path exists, prints "No Path".

    Marks the path visually using '*'.

    Pretty clean and readable logic.

Directions the BFS explores:

    Down

    Left

    Up

    Right

Each move keeps track of:

    How far it has gone (distance array)

    Where it came from (parent array)
