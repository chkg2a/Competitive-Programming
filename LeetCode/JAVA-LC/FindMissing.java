import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
      Map<Integer,Integer> map = new HashMap<>();
      int [] answer = new int[2];
      int missingNumber = 0;
      for(int i = 0; i < grid.length; i++){
        for(int j = 0; j < grid[0].length; j++){
          int num = grid[i][j];
          if(map.containsKey(num)){
            missingNumber = num;
          }
          map.put(num, 1);
        }
      }
      for(int i = 0; i <= (grid.length * grid.length); i++){
        if(!map.containsKey(i)){
          answer[0] = missingNumber;
          answer[1] = i;
        }
      }
      return answer;
    }
}

class FindMissing {
  public static void main(String [] args){
    int [][] matrix = {
      {9,1,7},
      {8,9,2},
      {3,4,6}
    };
    Solution sol = new Solution();
    for(int num : sol.findMissingAndRepeatedValues(matrix)){
      System.out.print(num + " ");
    }
  }
}
