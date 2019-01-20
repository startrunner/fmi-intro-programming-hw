#include <cstring>
#include <iostream>
bool checkBounds(int rowCount, int columnCount, int row, int column)
{
    return row >= 0 && column >= 0 && row < rowCount && column < columnCount;
}

bool tryMatchWordInGrid(
    const char *word, size_t wordLength,
    char grid[100][100], unsigned rowCount, unsigned columnCount,
    int atRow, int atColumn,
    int rowDeltaPerStep, int columnDeltaPerStep
)
{
    bool isMatching = true;

    int currentRow = atRow;
    int currentColumn = atColumn;
    for (size_t i = 0; i < wordLength && isMatching; i++)
    {
        if (!checkBounds(rowCount, columnCount, currentRow, currentColumn))isMatching = false;
        else isMatching &= (grid[currentRow][currentColumn] == word[i]);

        currentRow += rowDeltaPerStep;
        currentColumn += columnDeltaPerStep;
    }

    return isMatching;
}

bool tryMatchWordInGrid(
    const char *word, size_t wordLength,
    char grid[100][100], unsigned rowCount, unsigned columnCount,
    int atRow, int atColumn
)
{
    return(
        tryMatchWordInGrid(word, wordLength, grid, rowCount, columnCount, atRow, atColumn, 0, 1) ||
        tryMatchWordInGrid(word, wordLength, grid, rowCount, columnCount, atRow, atColumn, 1, 0)
    );
}

bool tryMatchWordInGrid(
    const char *word,
    char grid[100][100],
    unsigned rowCount,
    unsigned columnCount
)
{
    size_t wordLength = strlen(word);
    bool success = false;

    for (size_t row = 0; row < rowCount && !success; row++)
    {
        for (size_t column = 0; column < columnCount && !success; column++)
        {
            success |= tryMatchWordInGrid(
                word, wordLength,
                grid, rowCount, columnCount,
                row, column
            );
        }
    }

    return success;
}

unsigned int countWords(
    char words[50][101], unsigned int numWords,
    char grid[100][100], unsigned int gridRows, unsigned int gridColumns
)
{
    unsigned matchedWordCount = 0;

    for (size_t i = 0; i < numWords; i++)
    {
        char *word = words[i];
        bool matched = tryMatchWordInGrid(word, grid, gridRows, gridColumns);
        if (matched)matchedWordCount++;
    }

    return matchedWordCount;
}