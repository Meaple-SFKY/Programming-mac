#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

class Record {
    char name[20];
    char *addr;
    char tel[20];
public:
    Record();
    Record(char a[],char *b,char c[]);
    Record(Record &s);
    ~Record();
    void insert(char a[],char *b,char c[]);
    int find(char *a);
    void print(void);
    void modify(char a[],char *b,char c[]);
    char* getname(void);
    char* getaddr(void);
    char *gettel(void);
};

class Book {
    Record list[80];
    int size;
public:
    Book(int s=0)
    {
        size=s;
    }
    int insert(void);
    void printList(void);
    void find(void);
    void modify(void);
    void sortBook(void);
    void delList(void);
    void menu(void);
};

Record::Record(void) {
    addr=new char[20];
}

Record::Record(char a[],char *b,char c[]) {
    addr=new char[20];
    strcpy(name,a);
    strcpy(addr,b);
    strcpy(tel,c);
}

Record::Record(Record &s) {
    strcpy(name,s.name);
    strcpy(addr,s.addr);
    strcpy(tel,s.tel);
}

Record::~Record() {
    delete []addr;
}

void Record::insert(char a[],char *b,char c[]) {
    strcpy(name,a);
    strcpy(addr,b);
    strcpy(tel,c);
}

int Record::find(char *a) {
    if(strcmp(this->name,a)==0)
        return 1;
    return 0;
}

void  Record::print(void) {
    cout<<name<<' '<<addr<<' '<<tel<<endl;
}

void Record::modify(char a[],char *b,char c[]) {
    strcpy(name,a);
    strcpy(addr,b);
    strcpy(tel,c);
}

char* Record::getname(void) {
    return name;
}

char *Record::getaddr(void) {
    return addr;
}

char* Record::gettel(void) {
    return tel;
}

int Book::insert(void) {
    cout<<"插入一条新纪录，请输入:";
    char name[20];
    char addr[20];
    char tel[20];
    cin>>name>>addr>>tel;
    list[size++].insert(name,addr,tel);
    return size;
}

void Book::printList(void) {
    cout<<"通讯录信息："<<endl;
    cout<<"姓名 地址 号码"<<endl;
    for(int i=0; i<size; i++)
        list[i].print();
}

void Book::find(void) {
    char name[20];
    cout<<"请输入所需查找人的姓名：";
    cin>>name;
    for (int i=0; i<size; i++) {

        int flag=list[i].find(name);
        if (flag) {
            cout<<"该联系人住址及电话：";
            cout<<list[i].getaddr()<<' '<<list[i].gettel()<<endl;
            break;
        }
    }
}

void Book::modify(void) {
    char name[20],tel[20];
    cout<<"请输入所需修改号码的联系人姓名极其新号码：";
    cin>>name>>tel;
    for (int i=0; i<size; i++) {
        if (strcmp(name,list[i].getname())==0) {
            list[i].modify(name,list[i].getaddr(),tel);
        }
    }
}

void Book::sortBook(void) {
    for (int i=0; i<size; i++) {
        for (int j=0; j<size-1-i; j++) {
            if (strcmp(list[j].getname(),list[j+1].getname())>0) {
                Record r(list[j].getname(),list[j].getaddr(),list[j].gettel());
                list[j]=list[j+1];
                list[j+1]=r;
            }
        }
    }
}

void Book::delList(void) {
    char name[20];
    cout<<"请输入所需删除记录的人的姓名：";
    cin>>name;
    for (int i=0; i<size; i++) {
        if (strcmp(name,list[i].getname())==0) {
            for(int j=i; j<size; j++) {
                list[j]=list[j+1];
            }
            size--;
            break;
        }
    }
}

void Book::menu(void) {
    for (int i = 0; i < 50; i++) {
        cout << "*";
    }
    cout << endl;

    cout << "*";
    for (int i = 0; i < 48; i++) {
        cout << " ";
    }
    cout << "*" << endl;

    cout << "*              ---   我的通讯录   ---            *" << endl;

    cout << "*";
    for (int i = 0; i < 48; i++) {
        cout << " ";
    }
    cout << "*" << endl;

    cout << "*            -----   请选择功能   -----          *" << endl;

    cout << "*";
    for (int i = 0; i < 48; i++) {
        cout << " ";
    }
    cout << "*" << endl;

    cout << "*               1. 插入新纪录                    *" << endl;

    cout << "*";
    for (int i = 0; i < 48; i++) {
        cout << " ";
    }
    cout << "*" << endl;

    cout << "*               2. 删除指定记录                  *" << endl;

    cout << "*";
    for (int i = 0; i < 48; i++) {
        cout << " ";
    }
    cout << "*" << endl;

    cout << "*               3. 修改某人的电话号码            *" << endl;

    cout << "*";
    for (int i = 0; i < 48; i++) {
        cout << " ";
    }
    cout << "*" << endl;

    cout << "*               4. 查找记录                      *" << endl;

    cout << "*";
    for (int i = 0; i < 48; i++) {
        cout << " ";
    }
    cout << "*" << endl;

    cout << "*               5. 查看记录条数                  *" << endl;

    cout << "*";
    for (int i = 0; i < 48; i++) {
        cout << " ";
    }
    cout << "*" << endl;

    cout << "*               6. 按姓名进行排序                *" << endl;

    cout << "*";
    for (int i = 0; i < 48; i++) {
        cout << " ";
    }
    cout << "*" << endl;

    cout << "*               7. 查看所有记录                  *" << endl;

    cout << "*";
    for (int i = 0; i < 48; i++) {
        cout << " ";
    }
    cout << "*" << endl;

    cout << "*               8. 退出                          *" << endl;

    cout << "*";
    for (int i = 0; i < 48; i++) {
        cout << " ";
    }
    cout << "*" << endl;

    for (int i = 0; i < 50; i++) {
        cout << "*";
    }
    cout << endl;
}

int main(void) {
    Book teleBook;
    int len = 0, key = 0;
    /* //插入3条新记录
    for(int i=0; i<3; i++) {
        teleBook.insert();
    }
    teleBook.printList();
    teleBook.find();
    len=teleBook.insert();   //插入1条新记录
    cout<<"记录条数="<<len<<endl;
    teleBook.modify();   //修改1条记录
    teleBook.printList();
    teleBook.delList(); //  删除
    teleBook.printList();
    teleBook.sortBook();  //排序
    teleBook.printList(); */

    teleBook.menu();

    cout << endl << "请输入功能所对应的标号： ";
    cin >> key;
    //system("cls");
    cout << "------------------------------------" << endl;

    while (key != 8) {
        switch (key) {
            case 1: {
                teleBook.insert();
                break;
            }
            case 2: {
                teleBook.delList();
                break;
            }
            case 3: {
                teleBook.modify();
                break;
            }
            case 4: {
                teleBook.find();
                break;
            }
            case 5: {
                cout << "一共有 " << len << " 条记录" << endl;
                break;
            }
            case 6: {
                teleBook.sortBook();
                break;
            }
            case 7: {
                teleBook.printList();
                break;
            }
            default: {
                cout << "请输入正确的标号!" << endl;
                break;
            }
        }
        cout << endl << "请输入功能所对应的标号： ";
        cin >> key;
        //system("cls");
        cout << "-------------------------------" << endl;
    }
    
    return 0;
}