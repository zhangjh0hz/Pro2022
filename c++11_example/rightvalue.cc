#include<iostream>
#include<string>
#include<vector>
#include<string.h>

using namespace std;

class Dog {
public:
    Dog(string name):_name(name) {
        cout<< "construct" << endl;
        _childs.clear();
    }

    Dog(Dog& d) {
        cout<< "copy construct" << endl;
        _name = d._name;
        for (int i = 0; i < d._childs.size(); i++) {
            char *c = new char(sizeof(d._childs[i]));
            strcpy(c,d._childs[i]);
            _childs.push_back(c);
        }
    }

    Dog(Dog&& rd) {
        cout<< "right copy construt" << endl;
        _name = rd._name;
        _childs = rd._childs;
    }

    
    ~Dog() {
        while(!_childs.empty()) {
            delete [] _childs.back();
            _childs.pop_back();
        }
    }

public:
    string _name;
    vector<char*> _childs;

};

void callfunc(Dog g) {
    cout << g._name << endl;
}
int main()
{
    Dog d("dog dad");
    char *c1 = new char(sizeof("child1"));
    memcpy(c1, "child1", sizeof("child1"));
    char *c2 = new char(sizeof("child2"));
    memcpy(c2, "child2", sizeof("child2"));
    d._childs.push_back(c1);
    d._childs.push_back(c2);
    callfunc(std::move(d));
    callfunc(Dog("dog mom"));
    return 0;
}
