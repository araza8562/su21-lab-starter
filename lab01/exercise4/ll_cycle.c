#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
    // Initialize two pointers: slow and fast
    /* TODO: Implement ll_has_cycle */
    node *slow_ptr = head;
    node *fast_ptr = head;

    // Traverse the list with two pointers
    while (fast_ptr != NULL && fast_ptr ->next != NULL) {
        // Move slow pointer by one step
        slow_ptr = slow_ptr ->next;
        // Move fast pointer by two steps
        fast_ptr = fast_ptr ->next->next;

        // If the two pointers meet, there is a cycle
        if (slow_ptr == fast_ptr) {
            return 1; // Return true to indicate cycle detected
        }
    }

    // If we reach here, it means there is no cycle
    return 0; // Return false
}

