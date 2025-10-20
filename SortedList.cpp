class MergeKLists {
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    
    ListNode* mergeKListsHelper(vector<ListNode*>& lists, int start, int end) {
        if (start == end) return lists[start];
        if (start > end) return nullptr;
        
        int mid = start + (end - start) / 2;
        ListNode* left = mergeKListsHelper(lists, start, mid);
        ListNode* right = mergeKListsHelper(lists, mid + 1, end);
        
        return mergeTwoLists(left, right);
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return mergeKListsHelper(lists, 0, lists.size() - 1);
    }
};
