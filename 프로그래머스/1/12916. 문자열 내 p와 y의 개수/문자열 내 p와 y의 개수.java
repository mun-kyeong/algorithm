class Solution {
    boolean solution(String s) {
        s = s.toLowerCase();  // 문자열을 소문자로 변환
        int answer = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'p') answer++;
            else if (s.charAt(i) == 'y') answer--;
        }
        return answer == 0;
    }
}
