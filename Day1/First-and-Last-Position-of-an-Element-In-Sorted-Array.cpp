// In time complexity O(log(n)) and space complexity O(1)

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    
    int first = -1;
    int last = -1;

    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k) {
            first = mid;
            high = mid - 1; 
        } else if (arr[mid] < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k) {
            last = mid;
            low = mid + 1; 
        } else if (arr[mid] < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return std::make_pair(first, last);
}

// In time complexity O(n) and space complexity O(1)

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int first = -1;
    int last = -1;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == k)
        {
            if(first == -1)
            {
                first = i;
                last = i;
            }
            else
            {
                last = i;
            }
        }
    }

    return make_pair(first, last);
}
