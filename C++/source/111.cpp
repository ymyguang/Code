for (int t = 0 ; t < n; t++) {
// n 是列   m 是行
    for (int j = t ;j < n - t; j++)
        push -> a[t][j]
    for (int i = t+1; i < m - t;i++ )
        push -> a[i][n - t];
    for (int j = n - t; j > t;j--)
        push -> a[m-t][j];
    for (int i = m - t; i > t;i--)
        push -> a[i][t];
}

