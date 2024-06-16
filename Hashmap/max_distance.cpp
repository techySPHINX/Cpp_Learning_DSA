class Solution
{ // maximum distance between same elements
public:
    int maxDistance(int arr[], int n)
    {
        unordered_map<int, int> mp;

        int max_dist = 0;

        for (int i = 0; i < n; i++)
        {  //check if element is present or not
            if (mp.find(arr[i]) == mp.end())
            {
                mp[arr[i]] = i;
            }else{
                //if element is found change max distance
                max_dist = max(max_dist,i - mp[arr[i]]);
            }
        }
        return max_dist;
    }
}