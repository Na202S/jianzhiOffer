class Solution {
    public int[] reversePrint(ListNode head) {
        Stack<Integer> stk = new Stack<Integer>();
        ListNode p = head;
        int size = 0;
        while (p != null) {
            stk.push(p.val);
            size++;
            p = p.next;
        }
        int[] res = new int[size];
        for (int i = 0; i < size; i++) {
            res[i] = stk.pop();
        }
        return res;
    }
}

class Solution {

    private ArrayList<Integer> res = new ArrayList<>();

    public int[] reversePrint(ListNode head) {
        if (head != null) {
            reversePrint(head.next);
            res.add(head.val);
        }
        return res.stream().mapToInt(i -> i).toArray();
    }
}