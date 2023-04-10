#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

class Solution1 {
public:
    ListNode* detectCycle(ListNode* head) {
        std::vector<ListNode*> vec_ptrs;
        ListNode* temp_ptr = head;
        while (temp_ptr) {
            // check if temp_ptr is already in vec_ptrs
            if (std::find(vec_ptrs.begin(), vec_ptrs.end(), temp_ptr) != vec_ptrs.end()) {
                return temp_ptr; // found cycle
            }
            vec_ptrs.push_back(temp_ptr);
            temp_ptr = temp_ptr->next;
        }
        return NULL;

    }
};


class Solution2 {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && slow) {
            if (!fast->next || !fast->next->next) return nullptr;
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) break;
        }
        while (head != slow) {
            slow = slow->next;
            head = head->next;
        }
        return head;
    }
};


