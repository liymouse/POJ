# include <iostream>
# include <queue>
using namespace std;
	
bool map[100][100];
int w,h;

struct point
{
	int x;
	int y;
};
queue<point> refer;
class sub_graph
{
public:
    bool data[100][100],use;
	sub_graph *next;
	int width,height,total;
	sub_graph(int width,int height)
	{
		total=0;
		use=false;
		this->width=width;
		this->height=height;
        memset(data,0,sizeof(data));
	}
	void add(int x,int y)
	{
		data[x][y]=true;
		total++;
	}
};



class graph
{
public:
	sub_graph *start,*end;
	int len,total;
	graph()
	{
		start=end=NULL;
		total=0;
	}
	void add(sub_graph* temp)
	{
		if(start==NULL) 
		{
			start=end=temp;
			temp->next=NULL;
		}
		else
		{
			end->next=temp;
			end=end->next;
			end->next=NULL;
		}
	}


	void cul()
	{
		len=0;
		for(sub_graph* temp=start;temp!=NULL;temp=temp->next) 
		{
			len++;
			total+=temp->total;
		}
	}
	bool cmp(sub_graph *g1,sub_graph *g2)
	{
		if(g1->total!=g2->total) return false;
		queue<int> q1,q2t;
		for(int i=0;i<g2->width;i++)
			 for(int j=0;j<g2->height;j++)
				 q2t.push(g2->data[i][j]);
		bool flag;
		int tlen=q2t.size();
		int *q2=new int[tlen+1];
		for(int i=1;i<=tlen;i++)
		{
			q2[i]=q2t.front();
			q2t.pop();
		}
		
		//----------直接对比---------------
		flag=true;
		if(g1->height==g2->height&&g1->width==g2->width)
		{
			for(int i=0;i<g1->width;i++)
			{
				for(int j=0;j<g1->height;j++)
					if(g1->data[i][j]!=g2->data[i][j]) 
					{
						flag=false;
						break;
					}
				if(!flag) break;
			}
			if(flag) return true;
		}
		//----------水平翻转对比---------------------
		flag=true;
		if(g1->height==g2->height&&g1->width==g2->width)
		{
			for(int i=0;i<g1->width;i++)
			{
				for(int j=0;j<g1->height;j++)
					if(g1->data[g1->width-i-1][j]!=g2->data[i][j]) 
					{
						flag=false;
						break;
					}
				if(!flag) break;
			}
			if(flag) return true;
		}
		//---------垂直翻转对比-------------------------
		flag=true;
		if(g1->height==g2->height&&g1->width==g2->width)
		{
			for(int i=0;i<g1->width;i++)
			{
				for(int j=0;j<g1->height;j++)
					if(g1->data[i][g1->height-1-j]!=g2->data[i][j]) 
					{
						flag=false;
						break;
					}
				if(!flag) break;
			}
			if(flag) return true;
		}
		//-------90度转对比----------------------------
		flag=true;
		if(g1->height==g2->width&&g1->width==g2->height)
		{
		  for(int j=0;j<g1->height;j++)
			for(int i=g1->width-1;i>=0;i--)
				q1.push(g1->data[i][j]);


		  for(int i=1;i<=tlen;i++)
		  {
			  if(flag)
			  {
			  int t1=q1.front();
			  int t2=q2[i];
			  if(t1!=t2) flag=false;
			  }
			  q1.pop();

			 
		  }
		  if(flag) return true;
		}
		//------------------180度旋转对比--------------------------------
		flag=true;
		if(g1->height==g2->height&&g1->width==g2->width)
		{
		  for(int i=g1->width-1;i>=0;i--)
			for(int j=g1->height-1;j>=0;j--)
				q1.push(g1->data[i][j]);

		  for(int i=1;i<=tlen;i++)
		  {
				if(flag)
			  {
			  int t1=q1.front();
			  int t2=q2[i];
			  if(t1!=t2) flag=false;
			  }
			  q1.pop();

		  }
		  if(flag) return true;
		}
		//------------270度对比-----------------------------------------------
		flag=true;
		if(g1->height==g2->width&&g1->width==g2->height)
		{
		  for(int j=g1->height-1;j>=0;j--)
			for(int i=g1->width-1;i>=0;i--)
				q1.push(g1->data[i][j]);

		  for(int i=1;i<=tlen;i++)
		  {
				if(flag)
			  {
			  int t1=q1.front();
			  int t2=q2[i];
			  if(t1!=t2) flag=false;
			  }
			  q1.pop();

		  }
		  if(flag) return true;
		}
		//-------90度转对比+水平翻转----------------------------
		flag=true;
		if(g1->height==g2->width&&g1->width==g2->height)
		{
		 for(int j=g1->height-1;j>=0;j--)
			for(int i=g1->width-1;i>=0;i--)
				q1.push(g1->data[i][j]);

		  for(int i=1;i<=tlen;i++)
		  {
			  if(flag)
			  {
			  int t1=q1.front();
			  int t2=q2[i];
			  if(t1!=t2) flag=false;
			  }
			  q1.pop();

			 
		  }
		  if(flag) return true;
		}
		//------------------180度旋转对比+水平翻转---------------------------
		flag=true;
		if(g1->height==g2->height&&g1->width==g2->width)
		{
		 for(int i=0;i<g1->width;i++)
			for(int j=g1->height-1;j>=0;j--)
				q1.push(g1->data[i][j]);


		  for(int i=1;i<=tlen;i++)
		  {
				if(flag)
			  {
			  int t1=q1.front();
			  int t2=q2[i];
			  if(t1!=t2) flag=false;
			  }
			  q1.pop();

		  }
		  if(flag) return true;
		}
		//------------270度对比+水平翻转------------------------------------------
		flag=true;
		if(g1->height==g2->width&&g1->width==g2->height)
		{
		 for(int j=0;j<g1->height;j++)
			for(int i=g1->width-1;i>=0;i--)
				q1.push(g1->data[i][j]);


		  for(int i=1;i<=tlen;i++)
		  {
				if(flag)
			  {
			  int t1=q1.front();
			  int t2=q2[i];
			  if(t1!=t2) flag=false;
			  }
			  q1.pop();

		  }
		  if(flag) return true;
		}
		//-------90度转对比+垂直翻转-----------------------
		flag=true;
		if(g1->height==g2->width&&g1->width==g2->height)
		{
		  for(int j=0;j<g1->height;j++)
			for(int i=0;i<=g1->width-1;i++)
				q1.push(g1->data[i][j]);


		  for(int i=1;i<=tlen;i++)
		  {
			  if(flag)
			  {
			  int t1=q1.front();
			  int t2=q2[i];
			  if(t1!=t2) flag=false;
			  }
			  q1.pop();

			 
		  }
		  if(flag) return true;
		}
		//------------------180度旋转对比+垂直翻转---------------------------
		flag=true;
		if(g1->height==g2->height&&g1->width==g2->width)
		{
		  for(int i=g1->width-1;i>=0;i--)
			for(int j=0;j<=g1->height-1;j++)
				q1.push(g1->data[i][j]);

	
		  for(int i=1;i<=tlen;i++)
		  {
				if(flag)
			  {
			  int t1=q1.front();
			  int t2=q2[i];
			  if(t1!=t2) flag=false;
			  }
			  q1.pop();

		  }
		  if(flag) return true;
		}
		//------------270度对比+垂直翻转------------------------------------------
		flag=true;
		if(g1->height==g2->width&&g1->width==g2->height)
		{
		  for(int j=g1->height-1;j>=0;j--)
			for(int i=0;i<=g1->width-1;i++)
				q1.push(g1->data[i][j]);


		  for(int i=1;i<=tlen;i++)
		  {
				if(flag)
			  {
			  int t1=q1.front();
			  int t2=q2[i];
			  if(t1!=t2) flag=false;
			  }
			  q1.pop();
			
		  }
		  if(flag) return true;
		}
		delete[] q2;
		return false;
	}
	bool compare(graph& g2)
	{
		if(len!=g2.len||total!=g2.total) return false;
		else
		{
			for(sub_graph *t1=g2.start;t1!=NULL;t1=t1->next)
			{
			  bool flag=false;
              for(sub_graph *t2=start;t2!=NULL;t2=t2->next)
			  {
				  if(t1->use==false&&t2->use==false)
				     if(cmp(t2,t1))
					 {
					    t2->use=t1->use=true;
						flag=true;
						break;
					 }	  
			  }
			  if(!flag) return false;
			}
			return true;
		}
	}
	~graph()
	{
		for(sub_graph *temp=start;temp!=NULL;)
		{
			sub_graph* t=temp;
			temp=temp->next;
			delete t;
		}
	}
};
	
void detect(int x,int y)
{
	if(x<0||x>w||y<0||y>h) return;
	else if(map[x][y]==false) return;
	else
	{
		point temp;
		temp.x=x;
		temp.y=y;
		map[x][y]=false;
		refer.push(temp);
		detect(x+1,y);
		detect(x-1,y);
		detect(x,y+1);
		detect(x,y-1);
	}
}

int main()
{
	int test_num;

	cin>>test_num;
	for(int i=1;i<=test_num;i++)
	{
		int num;
		graph g1,g2;
		cin>>w>>h>>num;
		//--------------graph 1------------------------------------------------
		memset(map,0,sizeof(map));
		for(int j=1;j<=num;j++)
		{
			int t1,t2;
			cin>>t1>>t2;
			map[t1][t2]=true;
		}
		for(int j=0;j<w;j++)
		  for(int k=0;k<h;k++)
			  if(map[j][k])
			  {
				  int t1=j,t2=k;
				  int leftx=9999,rightx=-1,undery=99999,topy=-1;
				  detect(t1,t2);
				  int len=refer.size();
				  point *temp=new point[len+1];
				  for(int l=1;l<=len;l++)
				  {
					  point t=refer.front();
					  refer.pop();
					  temp[l]=t;
				  }
				  for(int l=1;l<=len;l++)
				  {
					  if(temp[l].x<leftx) leftx=temp[l].x;
					  if(temp[l].x>rightx) rightx=temp[l].x;
					  if(temp[l].y<undery) undery=temp[l].y;
					  if(temp[l].y>topy) topy=temp[l].y;
				  }
				  sub_graph *t_g=new sub_graph(rightx-leftx+1,topy-undery+1);
				  for(int l=1;l<=len;l++) 
				  {
					  temp[l].x-=leftx;
					  temp[l].y-=undery;
					  t_g->add(temp[l].x,temp[l].y);
				  }
				  delete[] temp;
				  g1.add(t_g);
			  }
			  //-----------------graph2-------------------------------------------------
			  memset(map,0,sizeof(map));
		for(int j=1;j<=num;j++)
		{
			int t1,t2;
			cin>>t1>>t2;
			map[t1][t2]=true;
		}
		for(int j=0;j<w;j++)
		  for(int k=0;k<h;k++)
			  if(map[j][k])
			  {
				  int t1=j,t2=k;
				  int leftx=9999,rightx=-1,undery=99999,topy=-1;
				  detect(t1,t2);
				  int len=refer.size();
				  point *temp=new point[len+1];
				  for(int l=1;l<=len;l++)
				  {
					  point t=refer.front();
					  refer.pop();
					  temp[l]=t;
				  }
				  for(int l=1;l<=len;l++)
				  {
					  if(temp[l].x<leftx) leftx=temp[l].x;
					  if(temp[l].x>rightx) rightx=temp[l].x;
					  if(temp[l].y<undery) undery=temp[l].y;
					  if(temp[l].y>topy) topy=temp[l].y;
				  }
				  sub_graph *t_g=new sub_graph(rightx-leftx+1,topy-undery+1);
				  for(int l=1;l<=len;l++) 
				  {
					  temp[l].x-=leftx;
					  temp[l].y-=undery;
					  t_g->add(temp[l].x,temp[l].y);
				  }
				  delete[] temp;
				  g2.add(t_g);
			  }
			  g1.cul();
			  g2.cul();
			  if(g1.compare(g2)) cout<<"YES"<<endl;
			  else cout<<"NO"<<endl;
		
	}
	return 0;
}
