#include <iostream>
#include <vector>
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix);

int main()
{
    vector<vector<char>> matrix = { { '1', '0', '1', '0', '0' }, { '1', '0', '1', '1', '1' }, { '1', '1', '1', '1', '1' }, { '1', '0', '0', '1', '0' } };

    return 0;
}

int maximalRectangle(vector<vector<char>>& matrix)
{
    int row = 0;
    int col = 0;
    int size = 0;
    row = matrix.size();
    col = matrix[0].size();
    struct node {
        char data = 't';
        node* next = NULL;
    };
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
        }
    }
    return size;
}
