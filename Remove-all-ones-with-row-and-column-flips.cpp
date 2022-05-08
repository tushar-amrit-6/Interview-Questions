solution I can think of is, each row is either the same as the next row or a complement of the next row.
  So by simply check if all rows is equal or complement of the next row, we can return True else the solution would be false.
    
 Try it out with any example, you will see the pattern :)

Time complexity: O(m*n)
Space complexity: O(1)

The code would look something like this

 public static boolean flipForZeros(int[][] arr) {
     
     // edge cases
     if (arr.length < 2 ) {
         return arr != null && arr.length == 1 && arr[0]!= null && arr[0].length > 0;
     }
     
    for(int i = 0; i < arr.length-1; i++) {
        int complement = (arr[i][0] == arr[i+1][0]? 0: 1);
        for (int j = 0; j < arr[i].length; j++) {
            if ((arr[i][j] ^ complement) != arr[i+1][j]) {
                return false;
            }
        }
    }

    return true;
}
