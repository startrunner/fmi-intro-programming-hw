#include <map>
#include <sstream>
#include <vector>
#include <string>
using namespace std;


int getWordId(map<string, int> &idMap, string word)
{
    auto found = idMap.find(word);
    if (found == idMap.end()) 
    {
        idMap.emplace(word, idMap.size() + 1);
        return idMap.size();
    }
    else return found->second;
}

void minifyData(
    const char grid[30][30][101], int gridRows, int gridColumns,
    char* sentence,
    vector<vector<int>> &minifiedGrid,
    vector<int> &minifiedSentence
)
{
    minifiedSentence.clear();
    minifiedGrid.resize(gridRows, vector<int>(gridColumns));

    map<string, int> idMap;

    stringstream wordStream{ sentence };
    for (string word; !wordStream.eof();)
    {
        wordStream >> word;
        minifiedSentence.push_back(getWordId(idMap, word));
    }
    for (int i = 0; i < gridRows; i++)
    {
        for (int j = 0; j < gridColumns; j++)
        {
            minifiedGrid[i][j] = getWordId(idMap, grid[i][j]);
        }
    }
}

int countReads(
    const vector<vector<int>> &grid,
    const vector<int> &sequence,
    int currentRow, int currentColumn,
    int wordIndex
)
{
    if (currentRow < 0 || currentColumn < 0)return 0;
    if (currentRow >= grid.size())return 0;
    if (currentColumn >= grid.front().size())return 0;
    if (grid[currentRow][currentColumn] != sequence[wordIndex])return 0;

    if (wordIndex + 1 == sequence.size())return 1;

    return(
        countReads(grid, sequence, currentRow + 0, currentColumn + 1, wordIndex + 1) +
        countReads(grid, sequence, currentRow + 0, currentColumn - 1, wordIndex + 1) +
        countReads(grid, sequence, currentRow + 1, currentColumn + 0, wordIndex + 1) +
        countReads(grid, sequence, currentRow - 1, currentColumn + 0, wordIndex + 1)
    );
}

int countReads(const vector<vector<int>> &grid, const vector<int> &sequence)
{
    int count = 0;

    for (int atRow = 0; atRow < grid.size(); atRow++)
    {
        for (int atColumn = 0; atColumn < grid.front().size(); atColumn++)
        {
            count += countReads(grid, sequence, atRow, atColumn, 0);
        }
    }

    return count;
}

int countReads(char grid[30][30][101], int gridRows, int gridColumns, char sentence[90901])
{
    vector<int> minifiedSentence;
    vector<vector<int>> minifiedGrid;
    minifyData(grid, gridRows, gridColumns, sentence, minifiedGrid, minifiedSentence);
    ;
    return countReads(minifiedGrid, minifiedSentence);
}