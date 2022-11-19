#include<stdio.h>
#include<iostream>
#include<cstring>
#include<fstream>
#include<bits/stdc++.h>
#include<algorithm>
#include<conio.h>
#define rep(i, x, y) for(register int i = x; i <= y; i++)
#define wl(i) while(i)
using namespace std;
string listh[10000], mergels[1000][5], pswd;
bool op;
int num, mgnum = 0;

void init()
{
	ifstream finls("data/list.dat", ios::in);
	finls>>num;
	rep(i, 1, num) finls>>listh[i];
	ifstream finmg("data/merge.dat", ios::in);
	while(!mgnum || mergels[mgnum][1] != ".")
	{
		mgnum++;
		finmg>>mergels[mgnum][1]>>mergels[mgnum][2]>>mergels[mgnum][3];
	} 
	mgnum--;
	ifstream findat("data/datas.dat", ios::in);
	findat>>op>>pswd;
}
void printit()
{
	cout<<"Now you have: ";
	if(!num)
	{
		cout<<"(empty).\n";
		return;
	}
	sort(listh + 1, listh + num + 1);
	rep(i, 1, num - 1) cout<<listh[i]<<" ";
	cout<<listh[num]<<".\n";
}
void saveit()
{
	cout<<"Saving...";
	ofstream foutls("data/list.dat", ios::out);
	foutls<<num<<endl;
	rep(i, 1, num) foutls<<listh[i]<<endl;
	ofstream foutdat("data/datas.dat", ios::out);
	foutdat<<op<<endl<<pswd;
	cout<<"done!\n";
}
void addit()
{
	if(op)
	{
		cout<<"Password: ";
		string psw = "";
		char ch;
		wl(1)
		{
			ch = getch();
			if(ch == 13) break;
			psw += ch;
			cout<<"*";
		}
		cout<<"\n";
		if(psw != pswd)
		{
			cout<<"Wrong password! Try again!\n";
			return;
		}
	}
	string mainobj[10] = {"", "metal", "wood", "water", "fire", "soil"};
	srand(time(0));
	int rdn = rand() % 5 + 1;
	listh[++num] = mainobj[rdn];
	cout<<"Add: "<<mainobj[rdn]<<".\n"; 
}
bool fdit(string s, int t = 1)
{
	int k = 0;
	rep(i, 1, num) if(s == listh[i])
	{
		k++;
		if(k == t) return 1;
	}
	return 0;
}
string mergefd(string it1, string it2)
{
	rep(i, 1, mgnum) if((mergels[i][1] == it1 && mergels[i][2] == it2) || (mergels[i][2] == it1 && mergels[i][1] == it2)) return mergels[i][3];
	return "empty";
}
void delit(string it)
{
	rep(i, 1, num) if(listh[i] == it)
	{
		rep(k, i, num - 1) listh[k] = listh[k + 1];
		num--;
		break;
	}
}
void mergeit()
{
	string it1, it2;
	cout<<"Item1: ";
	cin>>it1;
	cout<<"Item2: ";
	cin>>it2;
	if(it1 == it2 && !fdit(it1, 2))
	{
		cout<<"Don't have enough item '"<<it1<<"'.\n";
		return;
	}
	if(!fdit(it1))
	{
		cout<<"Don't have any item '"<<it1<<"'.\n";
		return;
	}
	if(!fdit(it2))
	{
		cout<<"Don't have any item '"<<it2<<"'.\n";
		return;
	}
	string fdres = mergefd(it1, it2);
	if(fdres == "empty")
	{
		cout<<"Can't merge '"<<it1<<"' and '"<<it2<<"'.\n";
		return;
	}
	listh[++num] = fdres;
	delit(it1);
	delit(it2);
	cout<<"Add: '"<<fdres<<"'.\n";
	if(fdres[0] >= 'A' && fdres[0] <= 'Z') cout<<"Get final item!\n";
}
void sets()
{
	string t;
	cout<<"Type: ";
	cin>>t;
	if(t == "npsw")
	{
		cout<<"New password: ";
		cin>>pswd;
		cout<<"Setting new password ('"<<pswd<<"')...";
		op = 1;
		cout<<"done!\n";
		return; 
	}
	if(t == "cpsw")
	{
		cout<<"Closing password...";
		op = 0;
		cout<<"done!\n";
		return;
	}
	cout<<"Command '"<<t<<"' not found. Type 'help' for help.\n";
} 
void clearscr()
{
	system("cls");
	cout<<"Hello! This is TY's game world!\nType 'help' for help.\n\n";
}
void help()
{
	cout<<"\n";
	cout<<"  操作名称  |  功能\n";
	cout<<" -----------|------------------\n";
	cout<<"  print     |  输出现有元素\n";
	cout<<" -----------|------------------\n";
	cout<<"  save      |  存档\n";
	cout<<" -----------|------------------\n";
	cout<<"  add       |  添加随机元素\n";
	cout<<" -----------|------------------\n";
	cout<<"  merge     |  尝试合成元素\n";
	cout<<" -----------|------------------\n";
	cout<<"  settings  |  设置\n";
	cout<<"    -npsw   |  设置新密码\n";
	cout<<"    -cpsw   |  关闭密码\n";
	cout<<" -----------|------------------\n";
	cout<<"  clear     |  清屏\n";
	cout<<" -----------|------------------\n";
	cout<<"  break     |  退出（自动存档）\n";
	cout<<"\n";
}
int main()
{
	cout<<"Hello! This is TY's game world!\nType 'help' for help.\n\n";
	init();
	printit();
	string s;
	wl(1)
	{
		cout<<"- ";
		cin>>s;
		if(s == "break") break;
		if(s == "print")
		{
			printit();
			continue;
		}
		if(s == "save")
		{
			saveit();
			continue;
		}
		if(s == "add")
		{
			addit();
			continue;
		}
		if(s == "merge")
		{
			mergeit();
			continue;
		}
		if(s == "settings")
		{
			sets();
			continue;
		}
		if(s == "clear")
		{
			clearscr();
			continue;
		}
		if(s == "help")
		{
			help();
			continue;
		} 
		cout<<"Command '"<<s<<"' not found. Type 'help' for help.\n";
	}
	saveit();
	return 0;
}

