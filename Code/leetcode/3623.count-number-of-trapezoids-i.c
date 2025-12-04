// @leet start
#define D 100000000
#define N 1000000007
int countTrapezoids(int** points, int pointsSize, int* pointsColSize) {
  long long sum = 0,sum_sq = 0,ans = 0;
  int cnt = 0;
  int* y_value = (int*)calloc(pointsSize,sizeof(int));
  int* hash = (int*)calloc(2 * D + 1,sizeof(int));
  for(int i = 0;i < pointsSize;i++){
    hash[points[i][1] + D]++;
    if(hash[points[i][1] + D] == 1){
      y_value[cnt] = points[i][1];
      cnt++;
    }
  }
  for(int i = 0;i < cnt;i++){
    int y = y_value[i];
    long long n = hash[y + D];
    if(n < 2) continue;
    long long s = n * (n - 1) / 2;
    sum += s;
    sum_sq += s * s;
  }
  ans = (sum * sum - sum_sq) / 2;
  ans = ans % N;
  free(y_value);
  free(hash);
  return ans;
}
// @leet end
