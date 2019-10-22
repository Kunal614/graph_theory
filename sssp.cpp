/*
 * C++ Program to find SSSP(Single Source Shortest Path) 
 * in DAG(Directed Acyclic Graphs)
 */

#define INFINITY 999
struct node
{
   int from;
}p[7];
int c = 0;
void djikstras(int *a,int b[][7],int *dv)
{
    int i = 0,j,min,temp;
    a[i] = 1;
    dv[i] = 0;
    p[i].from = 0;
    for (i = 0; i < 7;i++)
    {
        if (b[0][i] == 0)
        {
            continue;
        }
        else
        {
            dv[i] = b[0][i];
            p[i].from = 0;
        }
    }
    while (c < 6)
    {
        min = INFINITY;
        for (i = 0; i < 7; i++)
        {
            if (min <= dv[i] || dv[i] == 0 || a[i] == 1)
            {
                continue;
            }
            else if (min > dv[i])
            {
                min = dv[i];
            }
        }
        for (int k = 0; k < 7; k++)
        {
            if (min == dv[k])
            {
                temp = k;
                break;
            }
            else
            {
                continue;
    	    }
        }
        a[temp] = 1;
        for (j = 0; j < 7; j++)
        {
            if (a[j] == 1 || b[temp][j] == 0)
            {
                continue;
            }
            else if (a[j] != 1)
            {
                if (dv[j] > (dv[temp] + b[temp][j]))
                {
                    dv[j] = dv[temp] + b[temp][j];
                    p[i].from = temp;
                }
            }
        }
        c++;
    }  
    for (int i = 0; i < 7; i++)
    {
        cout<<"from node "<<p[i].from<<" cost is:"<<dv[i]<<endl;
    } 
}       
int main()
{
    int a[7];
    int dv[7];
    for(int k = 0; k < 7; k++)
    {
        dv[k] = INFINITY;
    }
    for (int i = 0; i < 7; i++)
    {
        a[i] = 0;
    }
    int b[7][7];
    for (int i = 0;i < 7;i++)
    {
        cout<<"enter values for "<<(i+1)<<" row"<<endl;
        for(int j = 0;j < 7;j++)
        {
            cin>>b[i][j];
        }
    }
    djikstras(a,b,dv);
    getch();
}
