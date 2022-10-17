#include <bits/stdc++.h>

using namespace std;

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution
{
public:
    int rand7()
    {
    }
    int rand10()
    {
        // func 1
        // 7和10的最小公倍数：70
        // 进行十次采样后进行叠加 最后对10取余+1  注意不是绝对的随机  但是可以通过测试
        vector<int> temp;
        for (int i = 0; i < 10; i++)
        {
            temp.push_back(rand7());
        }
        int sum = accumulate(temp.begin(), temp.end(), 0);
        int res = sum % 10 + 1;
        return res;

        // 注意在采样的时候必须保证等概率
        // func 2
        //拒绝采样的原理就是舍弃一部份数，使得所生成的数组正好是我们要的并且出现的概率相等
        int num;
        do{
            // 出现1,2,···10的概率相等
            // rand7():      1,2,3,4,5,6,7
            // rand7()-1:    0,1,2,3,4,5,6
            // rand7()-1*7:  0,7,14,21,28,35,42 乘7是为了在下一步加上rand7()以后出现的每一个数字正好是等概率
            num = (rand7() - 1) * 7 + rand7();
        } while (num > 10);//当不满足条件时 结束循环
        return num;
    }
};

int main()
{
    int i = 0;
    do{
        cout << i++ << endl;
    } while (i < 10);

    return 0;
}