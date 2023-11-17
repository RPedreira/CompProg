const int MAX = 30100;
vector <int> A[MAX], B[MAX];
vector <int> NA[MAX], NB[MAX];
int n;
bool comp(const vector <int>& a, const vector <int>& b)
{
    if(a.size() != b.size())
        return a.size() < b.size();
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] != b[i])
            return a[i] < b[i];
    }
    return false;
}
bool eq(const vector <int>& a, const vector <int>& b)
{
    if(a.size() != b.size())
        return false;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] != b[i])
            return false;
    }
    return true;
}
bool treeIsomorphism ()
{
    memset(NA, 0, sizeof NA);
    memset(NB, 0, sizeof NB);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < A[i].size(); j++)
            NA[i].push_back(A[A[i][j]].size());
        sort(NA[i].begin(), NA[i].end());
        for(int j = 0; j < B[i].size(); j++)
            NB[i].push_back(B[B[i][j]].size());
        sort(NB[i].begin(), NB[i].end());
    }
    sort(NA+1, NA+n+1, comp);
    sort(NB+1, NB+n+1, comp);
    bool equals = true;
    for(int i = 1; i <= n; i++)
        equals &= eq(NA[i], NB[i]);
    return equals;
}