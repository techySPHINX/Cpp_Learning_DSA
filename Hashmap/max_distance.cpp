class Solution
{
public:
    int maxDistance(int arr[], int n)
    {
        unordered_map<int, pair<int, int>> mp; // store element and its first and last occurrence

        int max_dist = 0;

        for (int i = 0; i < n; i++)
        {
            if (mp.find(arr[i]) == mp.end())
            {
                mp[arr[i]] = {i, i}; // store both first and last occurrence as the same index
            }
            else
            {
                mp[arr[i]].second = i;                          // update last occurrence
                max_dist = max(max_dist, i - mp[arr[i]].first); // calculate max distance
            }
        }

        // Additional concept: Find the element with the maximum distance
        int element_with_max_dist = -1;
        for (const auto &entry : mp)
        {
            int dist = entry.second.second - entry.second.first;
            if (dist == max_dist)
            {
                element_with_max_dist = entry.first;
                break;
            }
        }

        cout << "Element with maximum distance: " << element_with_max_dist << endl;
        return max_dist;
    }
};
{ // maximum distance between same elements
public:
    int maxDistance(int arr[], int n)
    {
        unordered_map<int, int> mp;

        int max_dist = 0;

        for (int i = 0; i < n; i++)
        { // check if element is present or not
            if (mp.find(arr[i]) == mp.end())
            {
                mp[arr[i]] = i;
            }
            else
            {
                // if element is found change max distance
                max_dist = max(max_dist, i - mp[arr[i]]);
            }
        }
        return max_dist;
    }
}
