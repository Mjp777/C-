Wildcard Matching

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

class Solution {
 public:
  bool isMatch(string s, string p) {
    const int m = s.length();
    const int n = p.length();
    // dp[i][j] := true if s[0..i) matches p[0..j)
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
    dp[0][0] = true;

    auto isMatch = [&](int i, int j) -> bool {
      return j >= 0 && p[j] == '?' || s[i] == p[j];
    };

    for (int j = 0; j < p.length(); ++j)
      if (p[j] == '*')
        dp[0][j + 1] = dp[0][j];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (p[j] == '*') {
          const bool matchEmpty = dp[i + 1][j];
          const bool matchSome = dp[i][j + 1];
          dp[i + 1][j + 1] = matchEmpty || matchSome;
        } else if (isMatch(i, j)) {
          dp[i + 1][j + 1] = dp[i][j];
        }

    return dp[m][n];
  }
};
