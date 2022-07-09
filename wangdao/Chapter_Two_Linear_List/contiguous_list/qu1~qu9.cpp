#include<bits/stdc++.h>
using namespace std;


//qu.1
//从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值。空出的位置由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行。
int del_min(vector<int>& arr)
{
    if(arr.size() == 0)
    {
        cout << "arr is empty" << endl;
        return -1; 
    }
    int minNum = arr[0];
    int minPos = 0;
    for(int i = 1; i < arr.size(); i++)
        if(minNum > arr[i])
        {
            minNum = arr[i];
            minPos = i;
        }
    arr[minPos] = arr[arr.size() - 1];
    arr.pop_back();
    return minNum;
}

//qu.2
//设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O（1）。
bool arr_reverse(vector<int>& arr)
{
    int len = arr.size();
    if(len == 0)
        return 0;
    int limit = len / 2;
    for(int i = 0; i < limit; i++)
    {
        int a = i, b = len - i - 1;
        arr[a] = arr[a] ^ arr[b];
        arr[b] = arr[a] ^ arr[b];
        arr[a] = arr[a] ^ arr[b];
    }
    return 1;
}

//qu.3
//对长度为n的顺序表L，编写一个时间复杂度为O（n）、空间复杂度为O（1）的算法、该算法删除线性表中所有值为x的数据元素。
bool arr_del_x(vector<int>& arr, int x)
{
    int len = arr.size();
    if(len == 0)
        return 0;
    int offset = 0;
    for(int i = 0; i < len - offset; i++)
        if(arr[i] == x)
        {
            arr[i] = arr[len - 1 - offset];
            arr.pop_back();
            offset++;
        }
    return 1;
}

//qu.4 & qu.5
//从有序顺序表中删除其值在给定值s和t之间（要求s<t）的所有元素，若s或t不合理 或顺序表为空，则显示出错信息并退出运行。
bool arr_del_s_to_t(vector<int> arr, int s, int t)
{
    if(s>=t) 
        return 0;
    if(arr.size() == 0)
        return 0;
    int len = arr.size();
    int offset = 0;
    for(int i = 0; i < len - offset; i++)
        if(arr[i] > s && arr[i] < t)
        {
            arr[i] = arr[len - 1 - offset];
            arr.pop_back();
            offset++;
        }
    return 1;
}

//qu.6
//有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。
bool del_common_ele(vector<int>& arr)
{
    unordered_set<int> check;
    int len = arr.size();
    if(len == 0)
        return 0;
    int fast = 1;
    int slow = 0;
    while(fast < len)
    {
        if(arr[fast] != arr[slow])
            arr[++slow] = arr[fast];
        fast++;
    }
    for(int i = 0; i < fast - slow - 1; i++)
        arr.pop_back();
    return 1;
}

//qu.7
//两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表。
vector<int> merge_two_ordered_arr(vector<int> arr1, vector<int> arr2)
{
    int len1 = arr1.size();
    int len2 = arr2.size();
    vector<int> arr(len1 + len2);
    int pos1 = 0;
    int pos2 = 0;
    int pos = 0;
    while(pos1 < len1 && pos2 < len2)
        arr[pos++] = arr1[pos1] < arr2[pos2] ? arr1[pos1++]: arr2[pos2++];
    while (pos1 < len1)
        arr[pos++] = arr1[pos1++];
    while (pos2 < len2)
        arr[pos++] = arr2[pos2++];
    return arr;
}

//qu8
//已知在一维数组A[m+n]中依次存放两个线性表（a1,a2,⋯，an）和（b1，b2，b3 ⋯，bm）编写一 个函数，将数组中两个顺序表的位置互换，即将（b1，b2，b3.⋯，bm）放在（a，a2，a3.⋯，an）的前面。
bool arr_part_swap(vector<int>& arr, int n, int m)
{
    int len = n + m;
    for(int i = 0; i < len / 2; i++)
        swap(arr[i], arr[len - i - 1]);
    for(int i = 0; i < m / 2; i ++)
        swap(arr[i], arr[m - i - 1]);
    for(int i = 0; i < n / 2; i ++)
        swap(arr[i + m], arr[len - i - 1]);
    return 1;
}

//qu9
//线性表（a1，a2，a3，⋯，an）中的元素递增有序且按顺序存储于计算机内。要求设计一个算法，完成用最少时间在表中查找数值为x的元素，若找到，则将其与后继元素位置相交换,若找不到,则将其插入表中并使表中元素仍递增有序。
bool ordered_insert(vector<int> arr, int x)
{
    int l = 0;
    int r = arr.size() - 1;
    while(l <= r)
    {
        int mid = l + (r - l) / 2;
        if(arr[mid] == x)
        {
            if(mid != arr.size() - 1)
                swap(arr[mid], arr[mid + 1]);
            break;
        }
        else if(arr[mid] > x)
            r = mid - 1;
        else
            l = mid + 1; 
    }
    if(l > r)
    {
        int pos = l;
        int last = x;
        while(pos < arr.size())
        {
            int cur = arr[pos];
            arr[pos] = last;
            last = cur;
            pos ++;
        }
        arr.push_back(last);
    }
    return 1;
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 7, 8};
    vector<int> arr2 = {4, 5, 6, 9, 10};
    ordered_insert(arr1, 4);
    return 0;
}