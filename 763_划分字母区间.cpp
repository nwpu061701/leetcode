/*
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。
示例 1：
输入：S = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-labels

提示：
S的长度在[1, 500]之间。
S只包含小写字母 'a' 到 'z' 。

*/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> result;
        for(int i=0;i<S.size();)
        {
            size_t pos = S.find_last_of(S[i]);//定位起点和终点
            if(pos != string::npos)
            {
                for(int j=i;j<pos;++j)//在起点和终点中，寻找是否有超越终点的字符，有的话，更新终点
                {
                    size_t pos_temp = S.find_last_of(S[j]);
                    if(pos_temp!=string::npos && pos_temp>pos)
                    {
                        pos = pos_temp;
                    }
                }
                result.push_back(pos-i+1);
                i = pos+1;
            }
            else
            {
                result.push_back(1);
                ++i;
            }
        }

        return result;
    }
};