#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

int longestConsecutive(vector<int>& nums) 
{
    set<int> setNums(nums.begin(), nums.end());
    if(setNums.empty())
    {
        return 0;
    }

    int nRet = 1;
    int nCurrent = 1;
    auto first = setNums.begin();
    int nlast = *first;
    int currentTotal = 1;
    for(auto it = setNums.begin(); it != setNums.end(); it++)
    {
        if(*it != nlast+1)
        {
            //do not step increase
            nRet = nRet > nCurrent ? nRet : nCurrent;
            if(nRet > (setNums.size() - currentTotal))
            {
                return nRet;
            }
            nCurrent = 1;
        }
        else
        {
            nCurrent++;
        }
        nlast = *it;
        currentTotal++;
    }

    return nRet > nCurrent ? nRet : nCurrent;
}

int longestConsecutive2(vector<int>& nums)
{
    unordered_set<int> setNums(nums.begin(), nums.end());

    if(setNums.empty())
    {
        return 0;
    }

    auto it = setNums.begin();
    int nRet = 1;
    for( ; it != setNums.end(); ++it)
    {
    
        int nTmpRet = 1;
        int nTmp = *it;
        if(setNums.find(nTmp+1) != setNums.end())
        {
            continue;
        }

        nTmp--;
        while(setNums.find(nTmp) != setNums.end())
        {
            nTmpRet++;
            nTmp--;
        }

       nRet = nTmpRet > nRet ? nTmpRet : nRet;
    }

    return nRet;
}

int main()
{
    vector<int> input1 = {100,4,200,1,3,2};
    int nRet1 = longestConsecutive2(input1);
    cout << "nRet1 = " << nRet1 << endl;

    vector<int> input2 = {0,3,7,2,5,8,4,6,0,1};
    int nRet2 = longestConsecutive2(input2);
    cout << "nRet2 = " << nRet2 << endl;

    vector<int> input3 = {0,-1};
    int nRet3 = longestConsecutive2(input3);
    cout << "nRet3 = " << nRet3 << endl;

    return 0;
}