int ladderSum(
    int matrix[100][100],
    unsigned int rows,
    unsigned int columns,
    unsigned int startRow,
    unsigned int startColumn
)
{
    int sum = 0;

    for (
        int row = startRow, column = startColumn, i = 0;
        row < rows && column < columns;
        row += i % 2, column += (i + 1) % 2, i++
    )sum += matrix[row][column];

    return sum;
}