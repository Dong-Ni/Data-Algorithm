#include <vector>
#include <iostream>
#include <set>

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
    auto it = (first++);
    int currentTotal = 2;
    for(;it != setNums.end(); it++)
    {
        if(*it != nlast+1)
        {
            //do not step increase
            nRet = nRet > nCurrent ? nRet : nCurrent;
            //if(nRet > (setNums.size() - currentTotal))
            {
            //    return nRet;
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

int main()
{
    vector<int> input1 = {100,4,200,1,3,2};
    //int nRet1 = longestConsecutive(input1);
    //cout << "nRet1 = " << nRet1 << endl;

    vector<int> input2 = {0,3,7,2,5,8,4,6,0,1};
    int nRet2 = longestConsecutive(input2);
    cout << "nRet2 = " << nRet2 << endl;

    vector<int> input3 = {0,-1};
    int nRet3 = longestConsecutive(input3);
    cout << "nRet3 = " << nRet3 << endl;

    return 0;
}