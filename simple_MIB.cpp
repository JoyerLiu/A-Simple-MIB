
#include <iostream>
#include <vector>
#include <map>
#include "MIB.h"
using namespace std;

int main()
{
    wareHouseMIB MIB;
    

    string name, type;
    long id;
    int a = 0;
    while (true)
    {
        cout << "---------------------------------------------" << endl;
        cout << "目前在架共:"<<MIB.Findgoods() << endl;
        cout << "1、入库" << endl << "2、出库" << endl << "3、列表" <<endl<<"4、查找物品"<<endl<<"5、查找ID"<< endl;
        cout << "---------------------------------------------" << endl;
        cout << "个人制作\n" << "刘旅诚 @JoyerLiu为本程序著作权持有者\n" << "本程序以学习为主，按照GPL开源免费\n";
        cout << "---------------------------------------------" << endl;
        cout << "输入选项：";
        cin >> a;
        cout << "---------------------------------------------" << endl;
        switch (a)
        {
        case 1:
            cout << "入库" << endl;
            cout << "请输入 name type id（空格隔开" << endl;
            cin >> name >> type >> id;
            MIB.Input(name, type, id);
            cout << "完成输入 " << name << " " << type << " " << id << endl;
            break;
        case 2:
            cout << "出库/删除" << endl;
            cout << "请输入 id:" ;
            cin >> id;
            MIB.outWare(id);
            break;
        case 3:
            cout << "列表" << endl;
            MIB.OutgoodsList();
            break;
        case 4:
            cout << "查询物品" << endl;
            cin >> type >> name;
            MIB.Findgoods(type,name);
            break;
        case 5:
            cout << "查询ID" << endl;
            cin >> id;
            if (MIB.Findgoods(id) != -1)
                cout << MIB.goods_[MIB.Findgoods(id)].G_name<<" "<< MIB.goods_[MIB.Findgoods(id)].G_type << endl;
            else
                cout << "未找到该物品或该物品未上架" << endl;
            break;
        }
    }
    
}