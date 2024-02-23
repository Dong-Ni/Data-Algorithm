#include <vector>
#include <iostream>


using namespace std;

vector<int> twoSum(vector<int>& nums, int target) 
{
    vector<int> vecRet;
    int nSize = nums.size();
    for(int i = 0; i < nSize; ++i)
    {
        for(int j = i+1; j < nSize; ++j)
        {
            if(nums[i]+ nums[j] == target)
            {
                vecRet.push_back(i);
                vecRet.push_back(j);
                return vecRet;
            }
        }
    }
        
    return vecRet;
}

void coutVecNums(vector<int> vecInput)
{
    for(auto it : vecInput)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vecInput1 = {2,7,11,15};
    int target1 = 9;
    vector<int> vecRet1 = twoSum(vecInput1, target1);
    cout << "input1 ret = ";
    coutVecNums(vecRet1);

    vector<int> vecInput2 = {3,2,4};
    int target2 = 6;
    vector<int> vecRet2 = twoSum(vecInput2, target2);
    cout << "input2 ret = ";
    coutVecNums(vecRet2);

    vector<int> vecInput3 = {3,3};
    int target3 = 6;
    vector<int> vecRet3 = twoSum(vecInput3, target3);
    cout << "input3 ret = ";
    coutVecNums(vecRet3);



    return 0;
}

