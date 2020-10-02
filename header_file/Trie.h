class TrieNode
{
	public:
		char data;
		TrieNode** children; // dynamic aary to store the address of its children;
		bool isTerminal; // For if some word is ending at this node or not;
		
		TrieNode(char data)
		{
			this->data=data;
			// we make a dynamic array to store the address of children which is type of TrieNode and at max a to z so we write 26;
			children=new TrieNode*[26];
			isTerminal=false; // By defaule we make it false;
			// We should initialize to null also;
			for(int i=0;i<26;i++)
			{
				children[i]=NULL;
			}
		}
};
// We make a complete Trie class as like we made a stack and queue and BST class;
class Trie
{
	// We should maintain root of each trie object then all things handled properly;
	TrieNode* root;
		void insertWord(TrieNode* root,string word)
		{
			// We should add this word to our trie;
			// We can think like tree we work on root and call recursion to do next;
			// Base case;
			if(word.size()==0) // When size becames 0 then we stop and mark isterminal is true as word end at this point;
			{
				root->isTerminal=true;
				return;
			}
			// Small Calculation
			int index=word[0]-'a';
			TrieNode* child;
			if(root->children[index]!=NULL) // Means ther is already a node present with word[0];
			{
				child=root->children[index];
			}
			else
			{
				// We have to create a root node with character word[0];
				child=new TrieNode(word[0]);
				// Update the array of root node;
				root->children[index]=child;
			}
			// recursive call;
			// We now call recursively to its child to insert next remaing word;
			insertWord(child,word.substr(1));
		}
		
		bool search(TrieNode* root,string word)
		{
			if(word.size()==0)
			{
				if(root->isTerminal==true)
				{
					return true;
				}
				else
				{
					return false;
				}
				// or we can simply write return root->isTerminal;
			}
			// Now we search for word[0];
			int index=word[0]-'a';
			if(root->children[index]==NULL) // word[0] is not found in children array means their is no node of such character;
			{
				return false;
			}
			// Otherwise we call for recursion on its child;
			TrieNode* child=root->children[index];
			bool smallAns=search(child,word.substr(1)); // we call on its child with remaning string;
			return smallAns;
		}
		
		void removeWord(TrieNode* root,string word)
		{
			if(word.size()==0)
			{
				// size becames zero then we should mark isTerminal of than node to be false so that it indicate that no word
				// end at this character. So we assume that word is removed;
				root->isTerminal=false;
				return;
			}
			// If their is child with character we go next and if not such node is found we simply return from that point
			// That represent that word not exits;
			TrieNode* child;
			int index=word[0]-'a';
			if(root->children[index]!=NULL)
			{
				child=root->children[index];
			}
			else
			{
				// Means the word is actually not present in trie to delete;
				return;
			}
			removeWord(child,word.substr(1));// then we call to its child with next remaing word;
			
			// Now we have to remove our useless child from trie;
			// For that we have to check that if  child's isterminal is false or not and all childs of child node is null or not;
			// if all child of child node is null means it is useless as isterminal is also false;
			
			if(child->isTerminal==false)
			{
				// Now check that if all childs of child node is null or not if all null then we remove them;
				// So we run a loop to find that;
				
				for(int i=0;i<26;i++)
				{
					if(child->children[i]!=NULL)
					{
						// that represent their may some child that has some use so we do nothing and return;
						return;
					}
				}
				// If we reach that line it means all value are null;
				// For delete we delete the child and also update the index in root's children to null at that index as child is
				// delete now;
				delete child;
				root->children[index]=NULL;
			}	
		}
	
	public:
		Trie()
		{
			root=new TrieNode('\0'); // we create a root node and pass null character;
		}
		void insertWord(string word)
		{
			// helper to insert word in trie;
			insertWord(root,word);
		}
		
		bool search(string word)
		{
			return search(root,word);
		}
		
		void removeWord(string word)
		{
			removeWord(root,word);
		}
};
