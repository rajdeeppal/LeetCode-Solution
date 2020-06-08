ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;

        for (int i = 0; i < lists.size() - 1; i++) {
            lists[i+1] = merge2Lists(lists[i], lists[i+1]);
        }
        return lists[lists.size() - 1];
    }

    ListNode* merge2Lists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL && l2 == NULL) return NULL;
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        ListNode *temp = new ListNode();
        ListNode *ans = temp;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                temp->next = l1;
                l1 = l1->next; 
            } else if (l2->val < l1->val) {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }

        if (l1 != NULL) temp->next = l1;
        if (l2 != NULL) temp->next = l2;

        return ans->next;
    }
