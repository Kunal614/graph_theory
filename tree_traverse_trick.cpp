#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int val;
    node *left,*right;
};
node *root = NULL;
unordered_map<node* ,int> cnt;
stack<node*>s;
void traversal_trick()
{
    s.push(root);
    while(!s.empty())
    {
        node *cur=s.top();
        if(cur==NULL)
        {
            s.pop();continue;
        }
        if(cnt[cur]==0){s.push(cur->left);}
        else if(cnt[cur]==1){s.push(cur->right);}
        else if(cnt[cur]==2){cout<<cur->val<<" ";}
        else
        {
            s.pop();
        }
        cnt[cur]++;
        
    
    }
}
