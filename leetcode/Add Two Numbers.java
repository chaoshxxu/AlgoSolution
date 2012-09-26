/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        ListNode ans = null;
        ListNode track = null;
        
        int carry = 0;
        while (l1 != null || l2 != null || carry > 0) {
            int val1 = l1 != null ? l1.val : 0;
            int val2 = l2 != null ? l2.val : 0;
            if (l1 != null) {
                l1 = l1.next;
            }
            if (l2 != null) {
                l2 = l2.next;
            }
            ListNode node = new ListNode((val1 + val2 + carry) % 10);
            carry = (val1 + val2 + carry) / 10;

            if (track != null) {
                track.next = node;
            }
            if (ans == null) {
                ans = node;
            }
            track = node;
        }
        return ans;
    }
}