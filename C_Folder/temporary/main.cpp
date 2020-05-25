#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
class record
{
    char name[20];
    char *addr;
    char tel[20];
public:
    record();
    record(char a[],char *b,char c[]);
    record(record &s);
    ~record();
    void insert(char a[],char *b,char c[]);
    int find(char *a);
    void print();
    void modify(char a[],char *b,char c[]);
    char* getname();
    char* getaddr();
    char *gettel();
};
class Book
{
    record list[80];
    int size;
public:
    Book(int s=0)
    {
        size=s;
    }
    int insert();
    void printlist();
    void find();
    void modify();
    void zdlist();
    void dellist();
};
record::record()
{
    addr=new char[20];
}
record::record(char a[],char *b,char c[])
{
    addr=new char[20];
    strcpy(name,a);
    strcpy(addr,b);
    strcpy(tel,c);
}
record::record(record &s)
{
    strcpy(name,s.name);
    strcpy(addr,s.addr);
    strcpy(tel,s.tel);
}
record::~record()
{
    delete []addr;
}
void record::insert(char a[],char *b,char c[])
{
    strcpy(name,a);
    strcpy(addr,b);
    strcpy(tel,c);
}
int record::find(char *a)
{
    if(strcmp(this->name,a)==0)
        return 1;
    return 0;
}
void  record::print()
{
    cout<<name<<' '<<addr<<' '<<tel<<endl;
}
void record::modify(char a[],char *b,char c[])
{
    strcpy(name,a);
    strcpy(addr,b);
    strcpy(tel,c);
}
char* record::getname()
{
    return name;
}
char *record::getaddr()
{
    return addr;
}
char* record::gettel()
{
    return tel;
}
int Book::insert()
{
    cout<<"插入一条新纪录，请输入:";
    char name[20];
    char addr[20];
    char tel[20];
    cin>>name>>addr>>tel;
    list[size++].insert(name,addr,tel);
    return size;
}
void Book::printlist()
{
    cout<<"通讯录信息："<<endl;
    cout<<"姓名 地址 号码"<<endl;
    for(int i=0; i<size; i++)
        list[i].print();
}
void Book::find()
{
    char name[20];
    cout<<"请输入所需查找人的姓名：";
    cin>>name;
    for(int i=0; i<size; i++)
    {

        int flag=list[i].find(name);
        if(flag)
        {
            cout<<"该联系人住址及电话：";
            cout<<list[i].getaddr()<<' '<<list[i].gettel()<<endl;
            break;
        }

    }
}
void Book::modify()
{
    char name[20],tel[20];
    cout<<"请输入所需修改号码的联系人姓名极其新号码：";
    cin>>name>>tel;
    for(int i=0; i<size; i++)
        if(strcmp(name,list[i].getname())==0)
        {
            list[i].modify(name,list[i].getaddr(),tel);
        }
}
void Book::zdlist()
{
    for(int i=0; i<size; i++)
        for(int j=0; j<size-1-i; j++)
            if(strcmp(list[j].getname(),list[j+1].getname())>0)
            {
                record r(list[j].getname(),list[j].getaddr(),list[j].gettel());
                list[j]=list[j+1];
                list[j+1]=r;
            }
}
void Book::dellist()
{
    char name[20];
    cout<<"请输入所需删除记录的人的姓名：";
    cin>>name;
    for(int i=0; i<size; i++)
    {
        if(strcmp(name,list[i].getname())==0)
        {
            for(int j=i; j<size; j++)
                list[j]=list[j+1];
            size--;
            break;
        }

    }
}
int  main()
{
    Book telebook;
    int len;
    for(int i=0; i<3; i++) //插入3条新记录
    {
        telebook.insert();
    }
    telebook.printlist();
    telebook.find();
    len=telebook.insert();   //插入1条新记录
    cout<<"记录条数="<<len<<endl;
    telebook.modify();   //修改1条记录
    telebook.printlist();
    telebook.dellist(); //  删除
    telebook.printlist();
    telebook.zdlist();  //排序
    telebook.printlist();
    return 0;
}