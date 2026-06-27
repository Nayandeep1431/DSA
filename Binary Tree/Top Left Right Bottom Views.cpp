//   TOP VIEW
class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans ; 
        if(root == NULL)
            return ans ;
        
        queue<pair<Node* ,int>> q  ; 
        map<int , int> mpp ; 
        q.push({root , 0}) ; 
        
        while(!q.empty()){
            auto it = q.front() ; 
            q.pop() ; 
            Node* top = it.first ; 
            int hd = it.second ; 
            
            if(mpp.find(hd) == mpp.end())
                mpp[hd] = top -> data ;
            
            if(top -> left)
                q.push({top ->left , hd-1}) ;
            if(top-> right)
                q.push({top -> right , hd+1}) ;
        }
        for(auto it : mpp)
            ans.push_back(it.second) ;
        return ans ;    
    }
};

//   BOTTOM VIEW
class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> ans ; 
        if(root == NULL)
            return ans ;
        
        queue<pair<Node* ,int>> q  ; 
        map<int , int> mpp ; 
        q.push({root , 0}) ; 
        
        while(!q.empty()){
            auto it = q.front() ; 
            q.pop() ; 
            Node* top = it.first ; 
            int hd = it.second ; 
            
            mpp[hd] = top -> data ;
            
            if(top -> left)
                q.push({top ->left , hd-1}) ;
            if(top-> right)
                q.push({top -> right , hd+1}) ;
        }
        for(auto it : mpp)
            ans.push_back(it.second) ;
        return ans ;    
    }
};

//   LEFT VIEW
class Solution {
  public:
    void solve(Node* root , vector<int> &ans , int level){
        if(root == NULL)
            return ;
        
        if(ans.size() == level)
            ans.push_back(root -> data) ; 
        
        solve(root -> left , ans , level + 1) ; 
        solve(root -> right , ans , level +1) ;
    }
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans ; 
        solve(root , ans , 0) ; 
        return ans ;
    }
};

//   RIGHT VIEW
class Solution {
  public:
    void solve(Node* root , vector<int> &ans , int level){
        if(root == NULL)
            return ;
        
        if(ans.size() == level)
            ans.push_back(root -> data) ; 
        
        solve(root -> right , ans , level + 1) ; 
        solve(root -> left , ans , level +1) ;
    }
    
    vector<int> rightView(Node *root) {
        //  code here
        vector<int> ans ; 
        if(root == NULL)
            return ans ; 
        solve(root , ans , 0) ; 
        return ans ;
    }
};
