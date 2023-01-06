#include <stdio.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <bits/stdc++.h>
#include <algorithm>
#include <conio.h>
#include <windows.h>
#define rep(i, x, y) for(register int i = x; i <= y; i++)
#define wl(i) while(i)
using namespace std;
string listh[10000], mergels[1000][5], pswd;
bool op, atsv;
int num, mgnum = 0;

void init()
{
	ifstream finls("data/list.dat", ios::in);
	finls >> num;
	rep(i, 1, num) finls >> listh[i];
	ifstream finmg("data/merge.dat", ios::in);
	while (!mgnum || mergels[mgnum][1] != ".")
	{
		mgnum++;
		finmg >> mergels[mgnum][1] >> mergels[mgnum][2] >> mergels[mgnum][3];
	}
	mgnum--;
	ifstream findat("data/datas.dat", ios::in);
	findat >> op >> atsv >> pswd;
}

string ch(string s)
{
	if (s == "metal")
		return "金";
	if (s == "wood")
		return "木";
	if (s == "water")
		return "水";
	if (s == "fire")
		return "火";
	if (s == "soil")
		return "土";
	if (s == "tree")
		return "树";
	if (s == "Gold")
		return "金子";
	if (s == "Mud")
		return "泥";
	if (s == "dust")
		return "灰尘";
	if (s == "Air")
		return "空气";
	if (s == "forest")
		return "森林";
	if (s == "desert")
		return "沙漠";
	if (s == "Beach")
		return "沙滩";
	if (s == "paper")
		return "纸";
	if (s == "Map")
		return "地图";
	if (s == "book")
		return "书";
	if (s == "sun")
		return "太阳";
	if (s == "planet")
		return "星球";
	if (s == "Mercury")
		return "水星";
	if (s == "Mars")
		return "火星";
	if (s == "Saturn")
		return "土星";
	if (s == "Jupiter")
		return "木星";
	if (s == "Venus")
		return "金星";
	if (s == "lake")
		return "湖";
	if (s == "sea")
		return "海";
	if (s == "ocean")
		return "大洋";
	if (s == "city")
		return "城市";
	if (s == "country")
		return "国家";
	if (s == "land")
		return "大陆";
	if (s == "Earth")
		return "地球";
	if (s == "金")
		return "metal";
	if (s == "木")
		return "wood";
	if (s == "水")
		return "water";
	if (s == "火")
		return "fire";
	if (s == "土")
		return "soil";
	if (s == "树")
		return "tree";
	if (s == "金子")
		return "Gold";
	if (s == "泥")
		return "Mud";
	if (s == "灰尘")
		return "dust";
	if (s == "空气")
		return "Air";
	if (s == "森林")
		return "forest";
	if (s == "沙漠")
		return "desert";
	if (s == "沙滩")
		return "Beach";
	if (s == "纸")
		return "paper";
	if (s == "地图")
		return "Map";
	if (s == "书")
		return "book";
	if (s == "太阳")
		return "sun";
	if (s == "星球")
		return "planet";
	if (s == "水星")
		return "Mercury";
	if (s == "火星")
		return "Mars";
	if (s == "土星")
		return "Saturn";
	if (s == "木星")
		return "Jupiter";
	if (s == "金星")
		return "Venus";
	if (s == "湖")
		return "lake";
	if (s == "海")
		return "sea";
	if (s == "大洋")
		return "ocean";
	if (s == "城市")
		return "city";
	if (s == "国家")
		return "country";
	if (s == "大陆")
		return "land";
	if (s == "地球")
		return "Earth";
	return s;
}

void printit()
{
	cout << "元素箱：";
	if (!num)
	{
		cout << "(空).\n";
		return;
	}
	sort(listh + 1, listh + num + 1);
	rep(i, 1, num - 1) cout << ch(listh[i]) << " ";
	cout << ch(listh[num]) << ".\n";
}

void saveit()
{
	cout << "保存中...";
	ofstream foutls("data/list.dat", ios::out);
	foutls << num << endl;
	rep(i, 1, num) foutls << listh[i] << endl;
	ofstream foutdat("data/datas.dat", ios::out);
	foutdat << op << atsv << endl << pswd;
	cout << "完成!\n";
}

string getpsw()
{
	cout << "密码 - ";
	string psw;
	char ch;
	wl(1)
	{
		ch = getch();
		if (ch == 13)
			break;
		psw += ch;
		cout << "*";
	}
	cout << "\n";
	return psw;
}

void addit()
{
	if (op)
	{
		if (getpsw() != pswd)
		{
			cout << "密码错误! 请重试!\n";
			return;
		}
	}
	string mainobj[10] = {"", "metal", "wood", "water", "fire", "soil"};
	srand(time(0));
	int rdn = rand() % 5 + 1;
	listh[++num] = mainobj[rdn];
	cout << "获得: " << ch(mainobj[rdn]) << ".\n";
}

bool fdit(string s, int t = 1)
{
	int k = 0;
	rep(i, 1, num) if (s == listh[i])
	{
		k++;
		if (k == t)
			return 1;
	}
	return 0;
}

string mergefd(string it1, string it2)
{
	rep(i, 1, mgnum) if ((mergels[i][1] == it1 && mergels[i][2] == it2) || (mergels[i][2] == it1 && mergels[i][1] == it2))
		return mergels[i][3];
	return "empty";
}

void delit(string it)
{
	rep(i, 1, num) if (listh[i] == it)
	{
		rep(k, i, num - 1) listh[k] = listh[k + 1];
		num--;
		break;
	}
}

void mergeit()
{
	string it1, it2;
	cout << "元素1 - ";
	cin >> it1;
	cout << "元素2 - ";
	cin >> it2;
	it1 = ch(it1);
	it2 = ch(it2);
	if (it1 == it2 && !fdit(it1, 2))
	{
		cout << "没有足够的元素 " << ch(it1) << ".\n";
		return;
	}
	if (!fdit(it1))
	{
		cout << "没有足够的元素 " << ch(it1) << ".\n";
		return;
	}
	if (!fdit(it2))
	{
		cout << "没有足够的元素 " << ch(it2) << ".\n";
		return;
	}
	string fdres = mergefd(it1, it2);
	if (fdres == "empty")
	{
		cout << "无法合并 " << ch(it1) << " 和 " << ch(it2) << ".\n";
		return;
	}
	listh[++num] = fdres;
	delit(it1);
	delit(it2);
	cout << "获得: " << ch(fdres) << ".\n";
	if (fdres[0] >= 'A' && fdres[0] <= 'Z')
		cout << "获得终极元素!\n";
}

void sets()
{
	string t;
	cout << "操作 - ";
	cin >> t;
	if (t == "npsw")
	{
		if (op)
		{
			if (getpsw() != pswd)
			{
				cout << "密码错误! 请重试!\n";
				return;
			}
		}
		cout << "新";
		pswd = getpsw();
		cout << "设置新密码...";
		op = 1;
		cout << "完成!\n";
		return;
	}
	if (t == "cpsw")
	{
		if (op)
		{
			if (getpsw() != pswd)
			{
				cout << "密码错误! 请重试!\n";
				return;
			}
		}
		cout << "关闭密码...";
		op = 0;
		cout << "完成!\n";
		return;
	}
	if (t == "atsv")
	{
		if (!atsv)
			cout << "开启自动保存...";
		else
			cout << "关闭自动保存...";
		atsv = !atsv;
		cout << "成功!\n";
		return;
	}
	cout << "不明指令 '" << t << "'. 输入 'help' 以获取帮助.\n";
}

void clearscr()
{
	system("cls");
	cout << "欢迎来到 TY 的合并游戏!\n输入 'help' 以获取帮助.\n\n";
	printit();
}

void help()
{
	cout << "\n";
	cout << "  操作名称 |  功能\n";
	cout << " ----------|--------------------\n";
	cout << "  print    |  输出现有元素\n";
	cout << " ----------|--------------------\n";
	cout << "  save     |  存档\n";
	cout << " ----------|--------------------\n";
	cout << "  add      |  添加元素\n";
	cout << " ----------|--------------------\n";
	cout << "  merge    |  合成元素\n";
	cout << " ----------|--------------------\n";
	cout << "  sets     |  设置\n";
	cout << "    -npsw  |  设置密码\n";
	cout << "    -cpsw  |  关闭密码\n";
	cout << "    -atsv  |  开启/关闭自动保存\n";
	cout << " ----------|--------------------\n";
	cout << "  clear    |  清屏\n";
	cout << " ----------|--------------------\n";
	cout << "  break    |  退出（自动存档）\n";
	cout << "\n";
}

int main()
{
	cout << "欢迎来到 TY 的合并游戏!\n输入 'help' 以获取帮助.\n\n";
	init();
	printit();
	string s;
	wl(1)
	{
		cout << "- ";
		cin >> s;
		if (s == "break")
			break;
		else if (s == "print")
			printit();
		else if (s == "save")
			saveit();
		else if (s == "add")
		{
			addit();
			if (atsv)
				saveit();
		}
		else if (s == "merge")
		{
			mergeit();
			if (atsv)
				saveit();
		}
		else if (s == "sets")
		{
			sets();
			if (atsv)
				saveit();
		}
		else if (s == "clear")
			clearscr();
		else if (s == "help")
			help();
		else
			cout << "不明指令 '" << s << "'. 输入 'help' 以获取帮助.\n";
	}
	saveit();
	return 0;
}