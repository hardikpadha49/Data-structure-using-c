
struct ListNode* deleteMiddle(struct ListNode* head) {
    
    if (!head || !head->next) return NULL;
    
    int count = 0;
    struct ListNode* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    
    int mid = count / 2;
    temp = head;
    
    if (mid == 0) {
        free(head);
        return NULL;
    }
    
    for (int i = 0; i < mid - 1; i++) {
        temp = temp->next;
    }
    
    struct ListNode* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
    
    return head;

}