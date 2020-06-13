#include<bits/stdc++.h>
using namespace std;

int isCyclicConntected(vector<int> adj[],int s,int V,vector<bool>& visited) 
{ 
    vector<int> parent(V,-1); 
    queue<int> q; 
    visited[s]=true; 
    q.push(s); 
    while(!q.empty()) 
	{ 
        int u=q.front(); 
        q.pop(); 
        for(int i=0;i<adj[u].size();i++) 
		{ 
        	int v=adj[u][i];
            if(!visited[v]) 
			{ 
                visited[v]=true; 
                q.push(v); 
                parent[v]=u; 
            } 
            else if(parent[u]!=v) 
                return 1; 
        } 
    } 
    return 0; 
} 
int isCyclicDisconntected(vector<int> adj[],int V) 
{ 
    // Mark all the vertices as not visited 
    vector<bool> visited(V,false);  
    for (int i=0;i<V;i++) 
    	if (!visited[i] && isCyclicConntected(adj,i,V,visited)==1) 
    		return 1; 
    return 0; 
}       
int main()
{
	int n,m;
	cout<<"Enter n and m:";
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
					c=3;
				else
					c=1;
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
						c=1;
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
					//cout<<i*m+j<<" hi"<<endl;
					if(i==n-1)
						c=1;
					else
						c=2;	
				}
				else
					c=4;
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
			if(product[i][j].second==-1)
				product[i][j].second=2;
			cout<<product[i][j].first<<","<<product[i][j].second<<"->";
		}
		cout<<endl;
	}
	/////////////////////////////
	map<int,int> proper;
	int missing[6]={0};
	bool c1=0,c2=0,c3=0,c4=0,c5=0;
	bool p=0;
    for(int i=0;i<n*m;i++)
	{
        int w;
        //cout<<i<<" ";
        c1=0;c2=0;c3=0;c4=0;c5=0;
        for(int j=0;j<product[i].size();j++) 
        { 
            w = product[i][j].second; 
            if(w==1)
            	c1=1;
            else if(w==2)
            	c2=1;
            else if(w==3)
            	c3=1;
            else if(w==4)
            	c4=1;
            else
            	c5=1;
        	if(proper[w]!=0) 
			{
            	cout<<"not proper!";
            	p=1;
            	break;
        	}
	        else
            	proper[w]=1;
		}
		//cout<<endl;
		if(c5==0)
			missing[5]++;
		else if(c4==0)
			missing[4]++;
		else if(c3==0)
			missing[3]++;
		else if(c2==0)
			missing[2]++;
		else
			missing[1]++;
        proper.clear();
    }
    if(p==0)
	    cout<<"proper!"<<endl;
	for(int i=1;i<=5;i++)
		cout<<i<<" "<<missing[i]<<endl;
    vector<int> g12[n*m];
	vector<int> g13[n*m];
	vector<int> g14[n*m];
	vector<int> g15[n*m];
	vector<int> g23[n*m];
	vector<int> g24[n*m];
	vector<int> g25[n*m];
	vector<int> g34[n*m];
	vector<int> g35[n*m];
	vector<int> g45[n*m];
	
	for(int i=0;i<n*m;i++)
	{
		for(int j=0;j<product[i].size();j++)
		{
			if(product[i][j].second == 1 || product[i][j].second == 2)
			    g12[i].push_back(product[i][j].first);
			if(product[i][j].second == 1 || product[i][j].second == 3)
			    g13[i].push_back(product[i][j].first);
			if(product[i][j].second == 1 || product[i][j].second == 4)
			    g14[i].push_back(product[i][j].first);
			if(product[i][j].second == 1 || product[i][j].second == 5)
			    g15[i].push_back(product[i][j].first);
			if(product[i][j].second == 2 || product[i][j].second == 3)
			    g23[i].push_back(product[i][j].first);
			if(product[i][j].second == 2 || product[i][j].second == 4)
			    g24[i].push_back(product[i][j].first);
			if(product[i][j].second == 2 || product[i][j].second == 5)
			    g25[i].push_back(product[i][j].first);
			if(product[i][j].second == 3 || product[i][j].second == 4)
			    g34[i].push_back(product[i][j].first);
			if(product[i][j].second == 3 || product[i][j].second == 5)
			    g35[i].push_back(product[i][j].first);
			if(product[i][j].second == 4 || product[i][j].second == 5)
			    g45[i].push_back(product[i][j].first);
		}
	}
	/*for(int i=0;i<n*m;i++)
	{
		cout<<i<<" ";
		for(int j=0;j<g12[i].size();j++)
		{
			cout<<g12[i][j]<<" ";
		}
		cout<<endl;
	}*/
	int a12=isCyclicDisconntected(g12,n*m);
	int a13=isCyclicDisconntected(g13,n*m);
	int a14=isCyclicDisconntected(g14,n*m);
	int a15=isCyclicDisconntected(g15,n*m);
	int a23=isCyclicDisconntected(g23,n*m);
	int a24=isCyclicDisconntected(g24,n*m);
	int a25=isCyclicDisconntected(g25,n*m);
	int a34=isCyclicDisconntected(g34,n*m);
	int a35=isCyclicDisconntected(g35,n*m);
	int a45=isCyclicDisconntected(g45,n*m);
	
	if(a12==1 || a13==1 || a13==1 || a14==1 || a15==1 || a23==1 || a24==1 || a25==1 || a34==1 || a35==1 || a45==1)
	    cout<<"There is a cycle"<<endl;
	else
	    cout<<"Acyclic"<<endl;
	return 0;
}
