#include <algorithm>
#include <chrono>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

bool isValidSudoku(vector<vector<char>> &board) {
  vector<unordered_set<char>> rows(9);
  vector<unordered_set<char>> cols(9);
  vector<unordered_set<char>> squares(9);

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      char num = board[i][j];
      if (num == '.') {
        continue;
      }
      int squareIndex = (i / 3) * 3 + (j / 3);
      if (rows[i].count(num) || cols[j].count(num) ||
          squares[squareIndex].count(num)) {
        return false;
      }
      rows[i].insert(num);
      cols[j].insert(num);
      squares[squareIndex].insert(num);
    }
  }
  return true;
}

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();
  cout << "Output : ";
  srand(time(0));

  vector<vector<char>> board = {{'1', '2', '.', '.', '3', '.', '.', '.', '.'},
                                {'4', '.', '.', '5', '.', '.', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '.', '3'},
                                {'5', '.', '.', '.', '6', '.', '.', '.', '4'},
                                {'.', '.', '.', '8', '.', '3', '.', '.', '5'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '.', '.', '.', '.', '.', '2', '.', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '8'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  cout << isValidSudoku(board);

  std::cout << std::endl;
  auto end = std::chrono::high_resolution_clock::now();
  auto duration_s =
      std::chrono::duration_cast<std::chrono::seconds>(end - start);
  std::cout << "Execution time: " << duration_s.count() << " seconds "
            << std::endl;
  auto duration_ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "Execution time: " << duration_ms.count() << " milliseconds "
            << std::endl;
  auto duration_ns =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
  std::cout << "Execution time: " << duration_ns.count() << " nanoseconds ";

  return 0;
}
