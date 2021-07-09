/**
 * Definition for singly-linked list.
 */

class ListNode {
    public int val;
    public ListNode next;
    ListNode(int x) { val = x; next = null; }

class Solution {
    public ListNode addTwoNumbers(ListNode A, ListNode B) {

        ListNode a = A;
        ListNode b = B;
        ListNode curr = new ListNode((a.val + b.val)%10);
        int carry = (a.val + b.val)/10;
        a = a.next;
        b = b.next;
        ListNode ans = curr;
        int intA;
        int intB;
        
        while (a != null || b != null) {
            if (a == null) {
                intA = 0;
            }
            else {
                intA = a.val;
                a = a.next;
            }
            
            if (b == null) {
                intB = 0;
            }
            else {
                intB = b.val;
                b = b.next;
            }
            curr.next = new ListNode((intA+intB + carry)%10);
            curr = curr.next;
            carry = (intA+intB+carry)/10;
        }
        
        if (carry != 0){
            curr.next = new ListNode(carry);
        }
        
        return ans;
    }
}
