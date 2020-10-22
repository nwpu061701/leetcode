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