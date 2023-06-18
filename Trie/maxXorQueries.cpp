#include<bits/stdc++.h>

struct Node{
    Node* links[2];

    bool containsKey(int bit){
        return links[bit]!=NULL;
    }

    Node* get(int bit){
        return links[bit];
    }

    void put(int bit, Node* node){
        links[bit]=node;
    }
};

class Trie{
    private: Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int getMax(int num){
        Node* node=root;
        int maxNum=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i) & 1;
            if(node->containsKey(1-bit)){
                maxNum=maxNum | (1<<i);
                node=node->get(1-bit);
            }
            else node=node->get(bit);
        }
        return maxNum;
    }
};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.
	sort(arr.begin(),arr.end());
    vector<pair<int,pair<int,int>>> query;
    for(int i=0;i<queries.size();i++){
        query.push_back({queries[i][1],{queries[i][0], i}});
    }
    sort(query.begin(),query.end());
    vector<int> ans(queries.size(),0);
    int j=0;
    Trie trie;
    for(int i=0;i<query.size();i++){
        int ai=query[i].first;
        int xi=query[i].second.first;
        int qInd=query[i].second.second;
        while(j<arr.size() && arr[j]<=ai){
            trie.insert(arr[j]);
            j++;
        }
        if(j==0) ans[qInd]=-1;
        else ans[qInd]=trie.getMax(xi);
    }
    return ans;
}
