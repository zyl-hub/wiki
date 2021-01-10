#include <iostream>
#include <vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix);
//vector<vector<int>> matrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 10, 11, 12 } };
//vector<vector<int>> matrix = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
//vector<vector<int>> matrix = {};
vector<vector<int>> matrix = { { 1, 2, 3, 4, 5 }, { 6, 7, 8, 9, 10 }, { 11, 12, 13, 14, 15 }, { 16, 17, 18, 19, 20 }, { 21, 22, 23, 24, 25 } };

int main()
{
  spiralOrder(matrix);
  return 0;
}

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
  int iter = 0;
  int len = 0;
  int curRow = 0;
  int curCol = 0;
  vector<int> none;
  //cout << row << '\t' << col << '\t';
  if (matrix.size() == 0) {
    return none;
  }
  int row = matrix.size();
  int col = matrix[0].size();
  vector<int> temp(row * col);
  while (len < temp.size()) {
    //cout << 1 << endl;
    for (curCol; curCol < col; curCol++) {
      //cout << curRow << '\t' << curCol << endl;
      if (len == temp.size())
        break;
      temp[len] = matrix[curRow][curCol];
      len++;
    }
    curCol--;
    curRow++;

    //cout << 2 << endl;
    for (curRow; curRow < row; curRow++) {
      //cout << curRow << '\t' << curCol << endl;
      if (len == temp.size())
        break;
      temp[len] = matrix[curRow][curCol];
      len++;
    }
    curRow--;
    curCol--;

    //cout << 3 << endl;
    for (curCol; curCol >= iter; curCol--) {
      //cout << curRow << '\t' << curCol << endl;
      if (len == temp.size())
        break;
      temp[len] = matrix[curRow][curCol];
      len++;
    }
    curCol++;
    curRow--;

    //cout << 4 << endl;
    for (curRow; curRow > iter; curRow--) {
      //cout << curRow << '\t' << curCol << endl;
      if (len == temp.size())
        break;
      temp[len] = matrix[curRow][curCol];
      len++;
    }

    curCol = curCol + 1;
    curRow = curRow + 1;
    if (col - 1 > 0)
      col = col - 1;
    if (row - 2 > 0)
      row = row - 1;
    iter++;
  }
  for (int i = 0; i < len; i++)
    cout << temp[i] << '\t';
  return temp;
}
