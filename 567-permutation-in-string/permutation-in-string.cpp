class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
        return false;
        vector <int> freq1(26,0);
        vector <int> freq2(26,0);
        int high=s1.size()-1;
        int low=0;
        for(char ch : s1)
        {
            freq1[ch-'a']++;
        }
        for(int i=low;i<=high;i++) //1st window
        {
            freq2[s2[i]-'a']++;
        }
        if(freq1==freq2)
        {
            return true;
        }
        // high++;
        // freq2[s2[low]-'a']--;
        // low++;
        while(high+1<s2.size())
        {
           
          high++;
          freq2[s2[high]-'a']++;

          freq2[s2[low]-'a']--;
          low++;
           if(freq1==freq2)
          {
            return true;
          } 
        }
        return false;
    }

};