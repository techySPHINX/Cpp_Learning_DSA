map<int, int> mapInsert(int arr[], int n)
{
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]] = i; // mp[key] = value
    }
    return mp;
}

void mapDisplay(map<int, int> mp)
{
    // map<int, int>::iterator it;
    // for (it = mp.begin(); it != mp.end(); it++)
    // {
    //      cout << it -> first << " " << it -> second << endl;
    // }
    for (auto x : mp)
    {
        cout << x.first << " " << x.second << endl;
    }
}

void mapErase(map<int, int> &mp, int x)
{
    auto it = mp.find(x);
    if (it != mp.end())
    {
        mp.erase(it);
        cout << "erased" << x;
    }
    else
    {
        cout << "not found";
    }
}
