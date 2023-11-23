vector<long long int> degree(MAX), total(MAX);

int lower(int ini, int fim, int val){
    int meio = (ini + fim) / 2;
    if(ini == fim && degree[ini] < val)
        return fim - 1;
    else if(ini == fim)
        return ini;
    else if(degree[meio] >= val)
        return lower(meio + 1, fim, val);
    else
        return lower(ini, meio, val);
}

bool ErdosGallai (int n)
{
    long long int aux, cont = 0;
    bool possible = true;
    for(int i = 0; i < n; i++)
    {
        scanf("%lld", &degree[i]);
        if(degree[i] >= n || degree[i] < 0)
            possible = false;
        cont += degree[i];
        cont %= 2;
    }
    if(n == 1)
    {
        if(degree[0] != 0)
            possible = false;
    }
    else
    {
        if(cont % 2)
            possible = false;
        else
        {
            sort(degree.begin(), degree.begin() + n, greater<int>());
            for(int i = 0; i < n; i++)
            {
                if(i == 0)
                    total[i] = degree[i];
                else
                    total[i] = total[i - 1] + degree[i];
            }
            for(long long int i = 0; i < n - 1 && possible; i++)
            {
                cont = 0;
                int index = lower(i + 1, n - 1, i + 1);
                if(index != i)
                    cont += (index - i) * (i + 1);
                cont += (total[n - 1] - total[index]);
                if(total[i] > i * (i + 1) + cont)
                    possible = false;
            }
        }
    }
    return possible;
}