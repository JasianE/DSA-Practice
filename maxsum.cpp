/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = curr->next;
        while(curr != nullptr){
            curr->next = prev;
            prev = curr;
            curr = next;
            if(curr != nullptr){
                next = curr->next;
            }
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* copy = head;
        vector<int> ogValues;
        int length = 0;
        while(copy != nullptr){
            copy = copy->next;
            length++;
        }
        
        int counter = 0;
        copy = head;
        while(counter != length / 2){
            ogValues.push_back(copy->val);
            copy = copy->next;
            counter++;
        }
        counter = 0;
        ListNode* reversed = reverseLinkedList(head);

        vector<int> sums;

        while(counter != length / 2){
            
        
            int sum = ogValues[counter] + reversed->val;
            reversed = reversed->next;
            sums.push_back(sum);
            counter++;
        }
    
        int max = sums[0];
        for(int i {0}; i < sums.size(); i++){
            if(sums[i] > max){
                max = sums[i];
            }
        }

        return max;
    }
};
