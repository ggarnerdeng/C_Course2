// Garner Deng
// 2048.cpp

#include <algorithm>
#include <array>
#include <iostream>
#include <random>
#include <vector>

const int N = 4;

using Grid = std::array<std::array<int, N>, N>;
Grid rotate(const Grid &grid);
bool move(Grid &grid, int direction);
void add_tile(Grid &grid);

int main()
{
    bool game_over = false;
    int direction;
    int counter = 0;
    char d1;
    Grid grid{}; // Initialize grid to all zeros.
    add_tile(grid);
    add_tile(grid);

    while (!game_over)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                std::cout.width(3);

                std::cout << grid[i][j] << ' ';
            }
            std::cout << '\n';
        }

        // Check if game is over.
        game_over = true;
        counter++;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j] == 0)
                {
                    game_over = false;
                    break;
                }
                if (i > 0 && grid[i][j] == grid[i - 1][j])
                {
                    game_over = false;
                    break;
                }
                if (j > 0 && grid[i][j] == grid[i][j - 1])
                {
                    game_over = false;
                    break;
                }
            }
            if (!game_over)
            {
                break;
            }
        }
        if (game_over)
        {
            std::cout << "Game over\n";
            int highestTile = 0;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (highestTile < grid[i][j])
                    {
                        highestTile = grid[i][j];
                    }
                }
            }
            std::cout << '\n'
                      << "Highest tile: " << highestTile << ", Moves: " << counter;
            break;
        }

        std::cout << "Enter a direction (w-a-s-d): ";

        if (!(std::cin >> d1) || (!(d1 == 'w') && !(d1 == 'a') && !(d1 == 's') && !(d1 == 'd')))
        {
            std::cout << "Invalid input\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::vector<char> d = {'a', 's', 'd', 'w'};
        for (int i = 0; i < d.size(); i++)
        {
            if (d1 == d[i])
                direction = i;
        }

        if (move(grid, direction))
        {
            add_tile(grid);
        }
        else
        {
            std::cout << "Invalid move\n";
        }
    }
    return 0;
}

// Rotate the grid 90 degrees clockwise.
Grid rotate(const Grid &grid)
{
    Grid result;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            result[i][j] = grid[N - j - 1][i];
        }
    }
    return result;
}

// Move all tiles in the specified direction, combining adjacent tiles with the same value. Returns true if the grid was modified, false otherwise.
bool move(Grid &grid, int direction)
{
    bool modified = false;
    // Rotate the grid so that moving up is equivalent to moving left.
    for (int i = 0; i < direction; i++)
    {
        grid = rotate(grid);
    }

    for (int i = 0; i < N; i++)
    {
        // Combine tiles and shift them as far left as possible.
        int pos = 0;
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] != 0)
            {
                if (pos > 0 && grid[i][pos - 1] == grid[i][j])
                {
                    grid[i][pos - 1] *= 2;
                    grid[i][j] = 0;
                    modified = true;
                }
                else
                {
                    grid[i][pos++] = grid[i][j];
                    if (pos != j + 1)
                    {
                        modified = true;
                    }
                }
            }
        }
        // Fill in remaining spaces with zeros.
        while (pos < N)
        {
            grid[i][pos++] = 0;
        }
    }

    // Rotate the grid back to its original orientation.
    for (int i = 0; i < (4 - direction) % 4; i++)
    {
        grid = rotate(grid);
    }

    return modified;
}

// Add a new tile to the grid.
void add_tile(Grid &grid)
{
    std::vector<std::pair<int, int>> empty;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
            {
                empty.emplace_back(i, j);
            }
        }
    }
    if (empty.empty())
    {
        return;
    }

    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<std::size_t> dist{0, empty.size() - 1};
    std::pair<int, int> coord = empty[dist(rng)];
    int i = coord.first;
    int j = coord.second;
    grid[i][j] = (std::uniform_int_distribution<>(0, 9)(rng) == 0) ? 4 : 2;
}
