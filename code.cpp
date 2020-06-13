#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	vector<pair<int,int> > product[n*m];
	bool f=0,f2=0;
	for(int i=0;i<n*m;i++)
	{
		int row=i/m,col=i%m;
		if(col+1==m)
		{
			if(row!=0)
				product[i].push_back(make_pair((row-1)*m,-1));
			else
				product[i].push_back(make_pair((n-1)*m,-1));
			if(row!=n-1)
				product[i].push_back(make_pair((row+1)*m,-1));
			else
				product[i].push_back(make_pair(0,-1));
		}
		else if(col+1!=m)
		{
			if(row!=0)
				product[i].push_back(make_pair((row-1)*m+col+1,-1));
			else
				product[i].push_back(make_pair((n-1)*m+col+1,-1));
			if(row!=n-1)
				product[i].push_back(make_pair((row+1)*m+col+1,-1));
			else
				product[i].push_back(make_pair(col+1,-1));
		}
		if(col==0)
		{
			if(row!=0)
				product[i].push_back(make_pair((row-1)*m+m-1,-1));
			else
				product[i].push_back(make_pair((n-1)*m+m-1,-1));
			if(row!=n-1)
				product[i].push_back(make_pair((row+1)*m+m-1,-1));
			else
				product[i].push_back(make_pair(m-1,-1));
		}
		else if(col!=0)
		{
			if(row!=0)
				product[i].push_back(make_pair((row-1)*m+col-1,-1));
			else
				product[i].push_back(make_pair((n-1)*m+col-1,-1));
			if(row!=n-1)
				product[i].push_back(make_pair((row+1)*m+col-1,-1));
			else
				product[i].push_back(make_pair(col-1,-1));
		}
	}
	/////////////////////////////////////////////////////
	for(int j=0;j<m;j++)
	{
		for(int i=0;i<n;i++)
		{
			int next,c;
			if(j==m-1)
			{
				if(i==n-1)
					break;
				if(i%2==0)
				{
					c=3;
				}
				else
				{
					c=1;
				}
				next=(i+1)*m;
			}
			else
			{
				if(j%2==0)
				{
					if(i==n-1)
						break;
					next=(i+1)*m+j+1;
					c=5;
				}
				else
				{
					if(i==0)
						continue;
					if(i%2==1)
					{
						c=1;
					}
					else
						c=3;
					next=(i-1)*m+j+1;
				}
			}
			for(int k=0;k<product[i*m+j].size();k++)
			{
				if(product[i*m+j][k].first==next)
				{
					product[i*m+j][k].second=c;
					break;
				}
			}
			for(int k=0;k<product[next].size();k++)
			{
				if(product[next][k].first==i*m+j)
				{
					product[next][k].second=c;
					break;
				}
			}
		}
	}
	for(int j=0;j<m;j++)
	{
		int c,next;
		if(j==m-1)
		{
			c=2;
			next=0;
			for(int k=0;k<product[(n-1)*m+j].size();k++)
			{
				if(product[(n-1)*m+j][k].first==next)
				{
					product[(n-1)*m+j][k].second=c;
					break;
				}
			}
			for(int k=0;k<product[next].size();k++)
			{
				if(product[next][k].first==(n-1)*m+j)
				{
					product[next][k].second=c;
					break;
				}
			}
		}
		else
		{
			if(j%2==0)
			{
				c=5;
				next=j+1;
				for(int k=0;k<product[(n-1)*m+j].size();k++)
				{
					if(product[(n-1)*m+j][k].first==next)
					{
						product[(n-1)*m+j][k].second=c;
						break;
					}
				}
				for(int k=0;k<product[next].size();k++)
				{
					if(product[next][k].first==(n-1)*m+j)
					{
						product[next][k].second=c;
						break;
					}
				}
			}
			else
			{
				c=3;
				next=(n-1)*m+j+1;
				for(int k=0;k<product[j].size();k++)
				{
					if(product[j][k].first==next)
					{
						product[j][k].second=c;
						break;
					}
				}
				for(int k=0;k<product[next].size();k++)
				{
					if(product[next][k].first==j)
					{
						product[next][k].second=c;
						break;
					}
				}
			}
		}
	}
	///////////////////////////////////////////
	for(int j=0;j<m;j++)
	{
		for(int i=1;i<n;i++)
		{
			int next,c;
			if(j==m-1)
			{
				if(i==0)
					break;
				if(i%2==0)
				{
					cout<<i*m+j<<" hi"<<endl;
					if(i==n-1)
					{
						c=1;
					}
					else
						c=2;	
				}
				else
				{
					c=4;
				}
				next=(i-1)*m;
			}
			else
			{
				if(j%2==0)
				{
					if(i==0)
						break;
					if(i%2==0)
						c=2;
					else
						c=4;
					next=(i-1)*m+j+1;
				}
				else
				{
					if(i==n-1)
						continue;
					if(i%2==1)
						c=4;
					else
						c=2;
					next=(i+1)*m+j+1;
				}
			}
			for(int k=0;k<product[i*m+j].size();k++)
			{
				if(product[i*m+j][k].first==next)
				{
					product[i*m+j][k].second=c;
					break;
				}
			}
			for(int k=0;k<product[next].size();k++)
			{
				if(product[next][k].first==i*m+j)
				{
					product[next][k].second=c;
					break;
				}
			}
		}
	}
	for(int j=0;j<m;j++)
	{
		int c,next;
		if(j==m-1)
		{
			c=4;
			next=(n-1)*m;
			for(int k=0;k<product[j].size();k++)
			{
				if(product[j][k].first==next)
				{
					product[j][k].second=c;
					break;
				}
			}
			for(int k=0;k<product[next].size();k++)
			{
				if(product[next][k].first==j)
				{
					product[next][k].second=c;
					break;
				}
			}
		}
		else
		{
			if(j%2==1)
			{
				c=2;
				next=j+1;
				for(int k=0;k<product[(n-1)*m+j].size();k++)
				{
					if(product[(n-1)*m+j][k].first==next)
					{
						product[(n-1)*m+j][k].second=c;
						break;
					}
				}
				for(int k=0;k<product[next].size();k++)
				{
					if(product[next][k].first==(n-1)*m+j)
					{
						product[next][k].second=c;
						break;
					}
				}
			}
			else
			{
				if((j+1)%3==0 || f==1)
					c=4;
				else
				{
					c=1;
					f=1;
				}	
				next=(n-1)*m+j+1;
				for(int k=0;k<product[j].size();k++)
				{
					if(product[j][k].first==next)
					{
						product[j][k].second=c;
						break;
					}
				}
				for(int k=0;k<product[next].size();k++)
				{
					if(product[next][k].first==j)
					{
						product[next][k].second=c;
						break;
					}
				}
			}
		}
	}
	///////////////////////////////////////////////
	for(int i=0;i<n*m;i++)
	{
		cout<<i<<"->";
		for(int j=0;j<product[i].size();j++)
		{
			cout<<product[i][j].first<<","<<product[i][j].second<<"->";
		}
		cout<<endl;
	}
	/////////////////////////////
	map<int,int> proper;
    for(int i=0;i<n*m;i++)
	{
        int w;
        cout<<i<<" ";
        for(int j=0;j<product[i].size();j++) 
        { 
            w = product[i][j].second; 
        	if(proper[w]!=0) 
			{
            	cout<<"not proper!";
            	break;
        	}
	        else
			{
            	proper[w]=1;
        	}
		}
		cout<<endl;
        proper.clear();
    }
	return 0;
}
