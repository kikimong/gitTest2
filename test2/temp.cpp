#include <iostream>
#include <vector>
using namespace std;

#include <string>
#include <algorithm>

#include <set>

int num =0;
int check=0;
vector<vector<int>> vv;
vector<int> re;

void fuc(int _i, int _j)
{
	vv[_i][_j] = 0;
	++check;

	if((_i-1>=0) && (vv[_i-1][_j] == 1))
		fuc(_i-1,_j);

	if((_i+1<num) && (vv[_i+1][_j] == 1))
		fuc(_i+1,_j);

	if((_j-1>=0) && (vv[_i][_j-1] == 1))
		fuc(_i,_j-1);

	if((_j+1<num) && (vv[_i][_j+1] == 1))
		fuc(_i,_j+1);
}

int main()
{
	cin>> num;

	for(int i=0;i<num; ++i)
	{
			vector<int> v;
			v.resize(num);
			vv.push_back(v);
	}

	for(int i=0;i<num; ++i)
	{
		string num2;
		cin>>num2;

		for(int j=0; j<num; ++j)
		{
// 			int num2;
// 			cin>>num2;
// 			vv[i][j] = num2;


			vv[i][j] = num2[j] - 48;
		}
	}

	for(int i=0;i<num; ++i)
	{
		for(int j=0; j<num; ++j)
		{
			if(vv[i][j] == 1)
			{
				fuc(i,j);
				re.push_back(check);
				check =0;
			}
		}
	}

	sort(re.begin(),re.begin() + re.size());

	cout<< re.size()<<endl;

	for(int i=0;i<re.size(); ++i)
	{
		cout<<re[i]<<endl;
	}

	if(re.size() ==0)
		cout<< re.size()<<endl;
	return 0;
}
