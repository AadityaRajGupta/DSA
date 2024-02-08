// Introduction to C++ STL | STL |   Vector, Pair, Queue

#include<iostream>
#include<vector>
using namespace std;

int vector_stl();
int main()
{
    vector<int> v;
    cout <<"capacity:" << v.capacity()<<endl;
    v.push_back(1);
    cout <<"capacity:" << v.capacity()<<endl;
    v.push_back(2);
    cout <<"capacity:" << v.capacity()<<endl;
    v.push_back(3);
    cout <<"capacity:" << v.capacity()<<endl;
    v.push_back(4);
    cout <<"capacity:" << v.capacity()<<endl;
    v.push_back(5);
    cout <<"capacity:" << v.capacity()<<endl;

    cout << v.size();
    for(auto i:v)
    {
        cout << i << " ";
    }

    vector<int> v2(10,5);     // intialize the vector of size 10 and it contain the 5 in each place
    v2.push_back(11);
    cout << endl <<"capacity:" << v2.capacity() << endl;
    cout << "size:" << v2.size() << endl;
    cout << endl;
    for(auto i:v2)
    {
        cout << i << " ";
    }
    v2.pop_back();
    cout << endl;
    for(auto i:v2)
    {
        cout << i << " ";
    }

    v2.erase(v2.begin(),v2.begin()+4);
    cout<<"\n\n\n";
    for(auto i:v2)
    {
        cout << i << " ";
    }

    vector<int> v3[5]; // array of vector
    /*
    v3[0]: 1 2 3
    v3[1]: 10 20 30 40
    v3[2]: 11 22 33 33 33
    v3[3]: 89 38
    v3[4]: 73 49 39
    */
    v3[0].push_back(1);
    v3[0].push_back(2);
    v3[0].push_back(3);

    v3[1].push_back(10);
    v3[1].push_back(20);
    v3[1].push_back(30);
    v3[1].push_back(40);

    v3[2].push_back(11);
    v3[2].push_back(22);
    v3[2].push_back(33);
    v3[2].push_back(33);
    v3[2].push_back(33);

    v3[3].push_back(89);
    v3[3].push_back(38);

    v3[4].push_back(73);
    v3[4].push_back(49);
    v3[4].push_back(39);

    cout<<"\n\n";
    for(int i=0;i<5;i++)
    {
        cout << "size: "<< v3[i].size() << endl;
        cout << "v3[" << i << "]: ";
        for(int j=0;j<v3[i].size();j++)
        {
            cout << v3[i][j] << " ";
        }
        cout << endl << endl;
    }
    return 0;
}




int queue_stl()
{
    return 0;
}