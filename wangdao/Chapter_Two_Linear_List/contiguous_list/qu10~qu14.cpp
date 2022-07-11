#include<bits/stdc++.h>
using namespace std;


//qu10
//设将n（n>1）个整数存放到一维数组R中。将R中保存的序列循环左移p（0<p<n）个位置
bool rorate_left(vector<int> arr, int pos)
{
    int len1 = pos;
    int len2 = arr.size() - pos;
    for(int i = 0; i < (len1 + len2) / 2; i++)
        swap(arr[i], arr[len1 + len2 - 1 - i]);
    for(int i = 0; i < len2 / 2; i ++)
        swap(arr[i], arr[len2 - i - 1]);
    for(int i = 0; i < len1 / 2; i ++)
        swap(arr[i + len2], arr[len2 + len1 - i - 1]);
    return 1;
}

//qu11
//现在有两个等长升序序列A和B，找出两个序列 A和B的中位数。
float get_middle_of_two_arr(vector<int> arr1, vector<int> arr2)
{
    int last;
    int pos = 0;
    int len1 = arr1.size();
    int len2 = arr2.size();
    int pos1 = 0, pos2 = 0;
    int flag = (len1 + len2) % 2;
    int limit = len2 + (len1 - len2) / 2;
    while(pos1 < len1 && pos2 < len2)
    {
        if(pos1 + pos2 + (!flag) > limit)
        {
            int cur = arr1[pos1] < arr2[pos2] ? arr1[pos1]: arr2[pos2];
            return flag? last: (float)last + ((float)cur - (float)last) / 2;
        }
        last = arr1[pos1] < arr2[pos2] ? arr1[pos1++]: arr2[pos2++];
    }
    while(pos1 < len1)
    {
        if(pos1 + pos2 > limit)
        {
            int cur = arr1[pos1];
            return flag? last: (float)last + ((float)cur - (float)last) / 2;
        }
        last = arr1[pos1++];
    }
    while(pos2 < len2)
    {
        if(pos1 + pos2 > limit)
        {
            int cur = arr1[pos2];
            return flag? last: (float)last + ((float)cur - (float)last) / 2;
        }
        last = arr1[pos2++];
    }
}

//qu12
//寻找数组中的主元素，不存在则返回-1
int find_mian_element(vector<int> arr)
{
    unordered_map<int, int> count;
    int len = arr.size();
    for(int i = 0; i < len; i++)
        count[arr[i]] ++;
    int mostAmount = -1;
    int mostNum;
    for(int i = 0; i < len; i++)
        if(count[arr[i]] > mostAmount)
        {
            mostAmount = count[arr[i]];
            mostNum = arr[i];
        }
    if(mostAmount <= len / 2)
        return -1;
    return mostNum;
}

//qu13
//找出数组中未出现的最小正整数
int smallest_positive_integer_not_arrpear(vector<int> arr)
{
    int len = arr.size();
    vector<int> check(len + 1, 0);
    for(int i = 0; i <= len ; i ++)
        if(arr[i] > 0 && arr[i] <= len)
            check[arr[i]] = 1;
    for(int i = 1; i <= len; i++)
        if(check[i] == 0)
            return i; 
    return len + 1;
}

//qu14
//
int findMinofTrip(vector<int> arr1, vector<int> arr2, vector<int> arr3)
{
    int i = 0, j = 0, k = 0;
    int minDis = 0x3f3f3f3f;
    while(i < arr1.size() && j < arr2.size() && k < arr3.size() && minDis >= 0)
    {
        int tpdis = abs(arr1[i] - arr2[j]) + abs(arr2[j] - arr3[k]) + abs(arr3[k] - arr1[i]);
        if(arr1[i] < arr2[j] && arr1[i] < arr3[k])
            i++;
        else if(arr2[j] < arr1[i] && arr2[j] < arr3[k])
            j++;
        else
            k++;
    }
    return minDis;
}



int main()
{
    vector<int> arr1 = {1, 2, 3, 7, 8};
    vector<int> arr2 = {4, 5, 6, 9, 10};
    cout << get_middle_of_two_arr(arr1, arr2) << endl;
    return 0;
}