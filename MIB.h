#pragma once
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class goods
{
public:
    long G_id;
    string G_name;
    string G_type;
    goods(string name, string type, long id)
    {
        G_id = id;
        G_type = type;
        G_name = name;
    }
};
class wareHouseMIB
{
private:
    
    map<string, string> Findgoods_type()//������Ʒ����
    {
        map<string, string> typ;
        int a = 0;
        for (vector<goods>::iterator i = goods_.begin(); i != goods_.end(); i++)
        {
            typ[i->G_type] = i->G_type;
            a++;
        }
        return typ;
    }

public:
    vector<goods> goods_;
    int Input(string name, string type, long id)
    {
        if (Findgoods(id) == -1)
            goods_.push_back(goods(name, type, id));
        else
            cout << "����ʧ��" << endl << "ID��ָ��Ļ������ڼܣ�����ID����" << endl;
        return 0;
    }
    int Findgoods(string name, string type)
    {
        int count_ = 0;
        for (int i = 0; i < goods_.size(); i++)
        {
            if (goods_[i].G_name == name && goods_[i].G_type == type)
            {
                cout <<"   "<< goods_[i].G_id<<endl;
                count_++;
            }
                
        }
        cout << "��Ѱ��Ʒ�ڼ�" << count_ << "��" << endl;
        return count_;
    }
    int Findgoods()
    {
        return goods_.size();
    }
    int Findgoods(long id)
    {
        for (int i = 0; i < goods_.size(); i++)
        {
            if (goods_[i].G_id == id)
                return i;
        }
        return -1;
    }
    int outWare(long id)
    {
        int i = Findgoods(id);
        if (i >= 0)
        {
            goods_.erase(goods_.begin() + i);
            return 1;
        }
        return 0;
    }
    void OutgoodsList()
    {
        map<string, string> typ = Findgoods_type();
        for (map<string, string>::iterator i = typ.begin()++; i != typ.end(); i++)
        {
            cout << i->first << endl;
            for (vector<goods>::iterator j = goods_.begin(); j != goods_.end(); j++)
            {
                if (i->first == j->G_type)
                {
                    cout << "    " << j->G_name << "   " << j->G_id << endl;
                }
            }
        }

    }
};
