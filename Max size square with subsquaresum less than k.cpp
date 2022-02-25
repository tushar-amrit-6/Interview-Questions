void preProcess(int mat[N][M],
                     int aux[N][M])
{
    // Loop to copy the first row
    // of the matrix into the aux matrix
    for (int i = 0; i < M; i++)
        aux[0][i] = mat[0][i];
 
    // Computing the sum column-wise
    for (int i = 1; i < N; i++)
        for (int j = 0; j < M; j++)
            aux[i][j] = mat[i][j] +
                       aux[i - 1][j];
 
    // Computing row wise sum
    for (int i = 0; i < N; i++)
        for (int j = 1; j < M; j++)
            aux[i][j] += aux[i][j - 1];
}
 
// Function to find the sum of a
// submatrix with the given indices
int sumQuery(int aux[N][M], int tli,
          int tlj, int rbi, int rbj)
{
    // Overall sum from the top to
    // right corner of matrix
    int res = aux[rbi][rbj];
 
    // Removing the sum from the top
    // corer of the matrix
    if (tli > 0)
        res = res - aux[tli - 1][rbj];
 
    // Remove the overlapping sum
    if (tlj > 0)
        res = res - aux[rbi][tlj - 1];
 
    // Add the sum of top corner
    // which is subtracted twice
    if (tli > 0 && tlj > 0)
        res = res + aux[tli - 1][tlj - 1];
 
    return res;
}
 
// Function to check whether square
// sub matrices of size mid satisfy
// the condition or not
bool check(int mid, int aux[N][M],
                           int K)
{
 
    bool satisfies = true;
     
    // Iterating through all possible
    // submatrices of given size
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (x + mid - 1 <= N - 1 &&
                  y + mid - 1 <= M - 1) {
                if (sumQuery(aux, x, y,
          x + mid - 1, y + mid - 1) > K)
                    satisfies = false;
            }
        }
    }
    return (satisfies == true);
}
// Function to find the maximum
// square size possible with the
// such that every submatrix have
// sum less than the given sum
int maximumSquareSize(int mat[N][M],
                              int K)
{
    int aux[N][M];
 
    preProcess(mat, aux);
     
    // Search space
    int low = 1, high = min(N, M);
    int mid;
     
    // Binary search for size
    while (high - low > 1) {
        mid = (low + high) / 2;
         
        // Check if the mid satisfies
        // the given condition
        if (check(mid, aux, K)) {
            low = mid;
        }
        else
            high = mid;
    }
    if (check(high, aux, K))
        return high;
    return low;
}
 
