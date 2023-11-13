pair<int, int> arestas[numArestas], pesos[numArestas];
int chefe[numVertices], grau[numVertices];

void UFinit(int numVertices)
{
    for(int i = 0; i < numVertices; i++)
    {
        chefe[i] = i;
        grau[i] = 1;
    }
}

int UFfind(int vertice)
{
    int ans = vertice;
    while(ans != chefe[ans])
        ans = chefe[ans];
    return ans;
}

void UFunion(int x, int y)
{
    if(grau[x] < grau[y])
    {
        chefe[x] = y;
        grau[y] += grau[x];
    }
    else
    {
        chefe[y] = x;
        grau[x] += grau[y];
    }
}

int MSTKruskal()
{
    int x, y, z, cont = 1, ans = 0;
    sort(pesos, pesos + numArestas);
        for(int i = 0; i < numArestas && cont < numVertices; i++)
        {
            z = pesos[i].second;
            x = UFfind(arestas[z].first);
            y = UFfind(arestas[z].second);
            if(x != y)
            {
                ans += pesos[i].first;
                cont++;
                UFunion(x, y);
            }
        }
        return ans;
}