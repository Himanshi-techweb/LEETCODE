struct Node{
    public:
    Node* link[2];
    Node(){
        link[0]=NULL;
        link[1]=NULL;
    }
    bool containkey(int i){
        return link[i]!=NULL;
    }
    void put(int n,Node* node){
        link[n]=node;
    }
    Node* get(int n){
        return link[n];
    }
};
class Trie{
    public:
    Node* root=new Node();
    void insert(int n){
        Node* node=root;
        for(int i=30;i>=0;i--){
            int bit=(n>>i) &1;
            if(!node->containkey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int calc(int n){
        Node* node=root;
        int res=0;
        for(int i=30;i>=0;i--){
            int bit=(n>>i) &1;
            int changebit=(bit^1);
            if(node->containkey(changebit)){
                res=(res|(1<<i)); 
                node=node->get(changebit);
            }
            else{
                node=node->get(bit);
            }
        }
        return res;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(int i=0;i<nums.size();i++){
            trie.insert(nums[i]);
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            //try for n^trie;
            int res=trie.calc(n);
            ans=max(ans,res);
            
        } 
        return ans;
    }
};