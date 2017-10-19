#include<bits/stdc++.h>
using namespace std;

    set<int>sets;
    map<int,int>maps;
    vector<int>vectors;
    deque<int>deques;//没啥用.....
    string strings;
    queue<int>queues;
    priority_queue<int>priority_queues;
    stack<int>stacks;
    //全部支持等号操作（将所有元素赋值）
int main()
{
    /*公共操作：
    empty():判断容器是否为空
    size():返回容器大小
    swap():交换两个容器的值
    除了stack和queue:
    begin():返回容器最开始的迭代器
    end():范围容器最末端的迭代器
    rbegin():返回反转迭代器的开始
    rend():返回反转迭代器的末尾
    */
    /*vector*/
    //Capacity(容量):
    vectors.size();//容器的大小
    vectors.max_size();//容器大小的最大值
    vectors.capacity();//大于size小于max_size的大小
    vectors.reserve(x);//将容器大小调整为x
    vectors.resize(x,y);//将容器大小调整为x，每个元素的值为y
    //Element access(元素访问):
    vectors[i];//访问第i个元素
    vectors.at(i);//访问第i个元素
    vectors.front();//第一个元素
    vectors.back();//访问最后一个元素
    int *p=vectors.data();//可以用p直接对vector进行操作（必须提前指定大小）
    //Modifiers(修改):
     vectors.assign(x,y);//如果x,y为数字，将x个y赋给容器;如果x,y为另一个容器的范围，就将这个容器内的值变为范围里的值
     vectors.push_back(6);//插入
     vectors.pop_back();//弹出末尾元素
     vectors.insert(s,x,y);//在s的前面插入x个y，返回值是迭代器
     vectors.erase(x);//除去x的值，x必须是值的迭代器
     vector1.swap(vector2);//交换两个容器内的元素
     vectors.clear();//清除容器内的元素
     vectors.emplace(s,x,y);//在s的前面插入x个y，返回值是迭代器
     vectors.emplace_back(x);//在容器中插入x（emplace的好处是在赋值过程中没有中间变量的产生）

     /*map*/
     //Capacity:(size(),empty(),max_size())
     //Element access:(支持[]操作,at())
     //Modifiers:(insert(),earse(),swap(),clear(),emplace())
     maps.emplace_hint(s,x,y);//在s的前面输入first=x,second=y
     maps.key.comp();//与另一个同类型的容器进行第一个key的比较
     maps.value.comp();//与另一个同类型的容器进行第二个key的比较
     maps.find('a')->second;//寻找maps['a']的值，如果没有返回容器做末尾的值
     maps.count('x');//返回容器中有几个'x'
     maps.lower_bound('x');//返回'x'的前一个容器
     maps.upper_bound('x');//返回'x'的后一个容器
     maps.equal_range('x');//返回两个值，一个是'x'的位置，第二个是'x'的下一个位置

     /*set*/
     //插入，删除，查找的复杂度均为o(logn)，适合三者使用频繁的情况
     //基本函数和map一样

     /*stack*/
     //Member functions:
     //empty(),size(),top()
     stacks.pop()；//弹出第一个元素
     stacks.push(x);//压入x
     stacks.emplace(x);//压入x
     x.swap(y)==swap(y,x);//交换两个容器的内容

     /*queue*/
     //Member functions:
     //empty(),size().front().push().emplace(),pop().swap().
     queues.back();//容器的最后一个元素

     /*priority_queues*/
     //访问队首元素是top();
     //empty(),size(),pop(),back().push(x),emplace(),swap()

     /*string*/
     //Capacity:size,length,max_size,resize,capacity,reserve,clear,empty
     //Element access:[],at()
     strings.back()='x';//将最后一个元素修改为x
     strings.front()='x';//将第一个元素修改为x
     //Modifiers:支持+=,还有一个append用来添加文本，
     strings.pop_back();//弹出最后一个元素
     strings.push_back();//用来添加文本
     strings.erase(x,y);//擦去第x开始的后面的y个元素
     x.swap(y);//交换容器x和y
     //String operations:
     strings.find(x);//返回x在容器中的位置

    return 0;
}
