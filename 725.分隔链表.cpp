/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
       vector<ListNode*> output;

        ListNode* temp;
        ListNode* temp2;

       auto flag = 0;
        while(root!=nullptr){
            if(output.size()<k){
                temp = root->next;
                root->next = NULL;
                output.push_back(root);
                root = temp;
            }else
            {   
                if(flag==k-1){
                    temp = output[k-1];
                    while(temp->next) temp = temp->next;
                    temp2 = root->next;
                    root->next = nullptr;
                    temp->next = root;
                    root = temp2;
                }else
                {
                    for(auto i=flag;i<k-1;i++){
                        temp = output[i];
                        if (temp!=nullptr){
                            while(temp->next) temp=temp->next;
                            temp->next = output[i+1];
                            temp = output[i+1]->next;
                            output[i+1]->next = NULL;
                            output[i+1] = temp;
                        }else
                        {
                            output[i] = output[i+1];
                            temp = output[i+1]->next;
                            output[i+1]->next = NULL;
                            output[i+1] = temp;
                        }
                        
                    }
                    temp = output[k-1];
                    if(temp==NULL){
                        output[k-1] = root;
                        temp2 = root->next;
                        root->next = NULL;
                        root = temp2;
                    }else
                    {
                        while(temp->next) temp = temp->next;
                        temp->next = root;
                        temp2 = root->next;
                        root->next = nullptr;
                        root = temp2;
                    }                    
                }
                flag += 1;
                if(flag == k) flag=0;
                
            }
            

        }

        while(output.size()<k) output.push_back(NULL);

        return output;
    }
};
*/

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        

        auto count = 0;

        ListNode* p =root;
        while (p)
        {
            count += 1;
            p = p->next;
        }

        vector<int> nums(k,count/k);

        for(auto i =0;i<count%k;i++)
            nums[i]++;
        
        vector<ListNode*> ret(k,nullptr);
        if(root==nullptr) return ret;
        
        ListNode* start;
        start = root;
        for(auto i=0;i<k;i++){
            ret[i] = start;
            while(nums[i]){
                nums[i] -- ;
                root = start;
                start = start->next;
            }
            root->next=nullptr;
        }

        return ret;
        
    
    }
};

// @lc code=end

