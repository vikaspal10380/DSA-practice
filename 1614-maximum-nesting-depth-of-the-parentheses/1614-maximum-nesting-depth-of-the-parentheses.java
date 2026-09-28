class Solution {
    public int maxDepth(String s) {
        int count = 0;
        int countMax = 0;
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) == '('){
                count++;
                countMax = Math.max(countMax, count);
            }
            if(s.charAt(i) == ')'){
                count--;
            }

        }
        return countMax;
    }
}