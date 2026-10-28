
class Solution {
public:
    long long kadaneMax(vector<int>& array)
    {
        long long sum = 0;
        long long best_ending = 0;

        for(int i = 0; i < array.size(); i++)
        {
            long long choice1 = array[i];
            long long choice2 = best_ending + array[i];

            best_ending = max(choice1, choice2);
            sum = max(sum, best_ending);
        }

        return sum;
    }

    int kConcatenationMaxSum(vector<int>& arr, int k)
    {
        const int mod = 1e9 + 7;

        if(arr.size() == 0)
        {
            return 0;
        }

        vector<int> array;

        for(int i = 0; i < min(k, 2); i++)
        {
            for(int num : arr)
            {
                array.push_back(num);
            }
        }

        long long sum = kadaneMax(array);

        long long totalSum = 0;
        for(int num : arr)
        {
            totalSum += num;
        }

        if(k > 2 && totalSum > 0)
        {
            sum += (long long)(k - 2) * totalSum;
        }

        return sum % mod;
    }
};
