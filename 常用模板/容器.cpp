#include<bits/stdc++.h>
using namespace std;

    set<int>sets;
    map<int,int>maps;
    vector<int>vectors;
    deque<int>deques;//ûɶ��.....
    string strings;
    queue<int>queues;
    priority_queue<int>priority_queues;
    stack<int>stacks;
    //ȫ��֧�ֵȺŲ�����������Ԫ�ظ�ֵ��
int main()
{
    /*����������
    empty():�ж������Ƿ�Ϊ��
    size():����������С
    swap():��������������ֵ
    ����stack��queue:
    begin():���������ʼ�ĵ�����
    end():��Χ������ĩ�˵ĵ�����
    rbegin():���ط�ת�������Ŀ�ʼ
    rend():���ط�ת��������ĩβ
    */
    /*vector*/
    //Capacity(����):
    vectors.size();//�����Ĵ�С
    vectors.max_size();//������С�����ֵ
    vectors.capacity();//����sizeС��max_size�Ĵ�С
    vectors.reserve(x);//��������С����Ϊx
    vectors.resize(x,y);//��������С����Ϊx��ÿ��Ԫ�ص�ֵΪy
    //Element access(Ԫ�ط���):
    vectors[i];//���ʵ�i��Ԫ��
    vectors.at(i);//���ʵ�i��Ԫ��
    vectors.front();//��һ��Ԫ��
    vectors.back();//�������һ��Ԫ��
    int *p=vectors.data();//������pֱ�Ӷ�vector���в�����������ǰָ����С��
    //Modifiers(�޸�):
     vectors.assign(x,y);//���x,yΪ���֣���x��y��������;���x,yΪ��һ�������ķ�Χ���ͽ���������ڵ�ֵ��Ϊ��Χ���ֵ
     vectors.push_back(6);//����
     vectors.pop_back();//����ĩβԪ��
     vectors.insert(s,x,y);//��s��ǰ�����x��y������ֵ�ǵ�����
     vectors.erase(x);//��ȥx��ֵ��x������ֵ�ĵ�����
     vector1.swap(vector2);//�������������ڵ�Ԫ��
     vectors.clear();//��������ڵ�Ԫ��
     vectors.emplace(s,x,y);//��s��ǰ�����x��y������ֵ�ǵ�����
     vectors.emplace_back(x);//�������в���x��emplace�ĺô����ڸ�ֵ������û���м�����Ĳ�����

     /*map*/
     //Capacity:(size(),empty(),max_size())
     //Element access:(֧��[]����,at())
     //Modifiers:(insert(),earse(),swap(),clear(),emplace())
     maps.emplace_hint(s,x,y);//��s��ǰ������first=x,second=y
     maps.key.comp();//����һ��ͬ���͵��������е�һ��key�ıȽ�
     maps.value.comp();//����һ��ͬ���͵��������еڶ���key�ıȽ�
     maps.find('a')->second;//Ѱ��maps['a']��ֵ�����û�з���������ĩβ��ֵ
     maps.count('x');//�����������м���'x'
     maps.lower_bound('x');//����'x'��ǰһ������
     maps.upper_bound('x');//����'x'�ĺ�һ������
     maps.equal_range('x');//��������ֵ��һ����'x'��λ�ã��ڶ�����'x'����һ��λ��

     /*set*/
     //���룬ɾ�������ҵĸ��ӶȾ�Ϊo(logn)���ʺ�����ʹ��Ƶ�������
     //����������mapһ��

     /*stack*/
     //Member functions:
     //empty(),size(),top()
     stacks.pop()��//������һ��Ԫ��
     stacks.push(x);//ѹ��x
     stacks.emplace(x);//ѹ��x
     x.swap(y)==swap(y,x);//������������������

     /*queue*/
     //Member functions:
     //empty(),size().front().push().emplace(),pop().swap().
     queues.back();//���������һ��Ԫ��

     /*priority_queues*/
     //���ʶ���Ԫ����top();
     //empty(),size(),pop(),back().push(x),emplace(),swap()

     /*string*/
     //Capacity:size,length,max_size,resize,capacity,reserve,clear,empty
     //Element access:[],at()
     strings.back()='x';//�����һ��Ԫ���޸�Ϊx
     strings.front()='x';//����һ��Ԫ���޸�Ϊx
     //Modifiers:֧��+=,����һ��append��������ı���
     strings.pop_back();//�������һ��Ԫ��
     strings.push_back();//��������ı�
     strings.erase(x,y);//��ȥ��x��ʼ�ĺ����y��Ԫ��
     x.swap(y);//��������x��y
     //String operations:
     strings.find(x);//����x�������е�λ��

    return 0;
}
