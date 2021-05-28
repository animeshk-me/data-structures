
// Without DP
int LCS(char * str1, char * str2, int idx1, int idx2) {
  if (idx1 == strlen(str1) || (idx2 == strlen(str2)))
    return 0;
  else if (str1[idx1] == str2[idx2]) {
    // printf("good\n");
    return (1 + LCS(str1, str2, idx1 + 1, idx2 + 1));
  }
  else {
    int skip1 = LCS(str1, str2, idx1 + 1, idx2);
    int skip2 = LCS(str1, str2, idx1, idx2 + 1);
    return maximum(skip1, skip2);
  }
}

// With bottom-up DP
int LCS_DP(char * str1, char * str2) {
  int Cache[len1 + 1][len2 + 1];
  memset(Cache, -1, sizeof(Cache));
  Initialize(Cache);
  for(int i = len1 - 1; i >= 0; i--) {
    for(int j = len2 - 1; j >= 0; j--) {
      if(str1[i] == str2[j])
        Cache[i][j] = 1 + Cache[i + 1][j + 1];
      else
        Cache[i][j] = maximum(Cache[i + 1][j], Cache[i][j + 1]);
    }
  }
  return Cache[0][0];
}
