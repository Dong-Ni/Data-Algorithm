#include <vector>
#include <iostream>
#include <unordered_set>



using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
    vector<unordered_multiset<char>> vecSetGroupPams;
    int nSize = strs.size();
    vector<vector<string>> vecVecRet;
    for(int i = 0; i < nSize; ++i)
    {
        // get current set chars
        unordered_multiset<char> setCurrent;
        for(int j = 0; j < strs[i].size(); ++j)
        {
            setCurrent.emplace(strs[i][j]);
        }
       
       // find exit sets if contains it
       int iIndex = vecSetGroupPams.size();
       bool bFind = false;
       for(int k = 0; k < iIndex; ++k)
       {
            if(vecSetGroupPams[k] == setCurrent)
            {
                vecVecRet[k].emplace_back(strs[i]);
                bFind = true;
                break;
            }
       }
       if(!bFind)
       {
            vecSetGroupPams.emplace_back(setCurrent);
            vecVecRet.emplace_back(vector<string>{strs[i]});
       }
    }

    return  vecVecRet;
}

void OutPutRet(vector<vector<string>>& vecVecStrs)
{
    for(auto it : vecVecStrs)
    {
        for(auto it1 : it)
        {
            cout << it1 << " ";
        }

        cout << endl;
    }
}

int main()
{
    vector<string> vecVecInput1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> vecVecRet1 = groupAnagrams(vecVecInput1);
    cout << "ret1 = " << endl;
    OutPutRet(vecVecRet1);

    vector<string> vecVecInput2 = {""};
    vector<vector<string>> vecVecRet2 = groupAnagrams(vecVecInput2);
    cout << "ret2 = " << endl;
    OutPutRet(vecVecRet2);

    vector<string> vecVecInput3 = {"a"};
    vector<vector<string>> vecVecRet3 = groupAnagrams(vecVecInput3);
    cout << "ret3 = " << endl;
    OutPutRet(vecVecRet3);

    vector<string> vecVecInput4 = {"ddddddddddg","dgggggggggg", "ddddddddgdd", "ggdgggggggg"};
    vector<vector<string>> vecVecRet4 = groupAnagrams(vecVecInput4);
    cout << "ret4 = " << endl;
    OutPutRet(vecVecRet4);

    return 0;
}