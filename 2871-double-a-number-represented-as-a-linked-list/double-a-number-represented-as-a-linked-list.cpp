class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        string s;

        // Store digits in string
        while (head) {
            s.push_back(head->val + '0');
            head = head->next;
        }

        // Reverse the string
        reverse(s.begin(), s.end());

        // Double the number
        int carry = 0;
        for (int i = 0; i < s.size(); i++) {
            int d = (s[i] - '0') * 2 + carry;
            s[i] = (d % 10) + '0';
            carry = d / 10;
        }

        if (carry)
            s.push_back(carry + '0');

        // Reverse back
        reverse(s.begin(), s.end());

        // Create linked list
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        for (char c : s) {
            cur->next = new ListNode(c - '0');
            cur = cur->next;
        }

        return dummy->next;
    }
};