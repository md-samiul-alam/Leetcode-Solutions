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
    vector<int> getVector(ListNode* l) {
        vector<int> v;
        while(l!=NULL) {
            v.push_back(l->val);
            l = l->next;
        }
        return v;
    }

    vector<int> addVectorNumbers(vector<int>& v1, vector<int>& v2) {
        vector<int> result;
        int carry = 0;
        int i = v1.size() - 1;
        int j = v2.size() - 1;

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;

            if (i >= 0) {
                sum += v1[i];
                --i;
            }

            if (j >= 0) {
                sum += v2[j];
                --j;
            }

            result.push_back(sum % 10);
            carry = sum / 10;
        }
        return result;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1 = getVector(l1);
        vector<int> v2 = getVector(l2);
        
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());
        
        vector<int>ans = addVectorNumbers(v1, v2);

        int firstNode = ans[0];
        ListNode* head = new ListNode(firstNode);
        ListNode* root = head;
        for(int i=1; i<ans.size(); ++i) {
            ListNode* temp = new ListNode(ans[i]);
            head->next = temp;
            head = head->next;
        }
        return root;        
    }
};
