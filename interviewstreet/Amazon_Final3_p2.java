import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;
import java.util.ArrayList;
import java.util.Stack;

public class Solution {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = br.readLine();
		String[] intStrs = line.split(",");
		List<Integer> destIntList = new ArrayList<Integer>();
		for(String intStr : intStrs) {
			destIntList.add(Integer.valueOf(intStr.trim()));
		}
		
		List<String> ruleList = new ArrayList<String>();
		line = br.readLine();
		while(!(line == null || line.equals(""))) {
			ruleList.add(line);
			line = br.readLine();
		}
		br.close();
		
		Solution s = new Solution();
		s.determineRuleAndOutput(destIntList, ruleList);
	}

	private void determineRuleAndOutput(List<Integer> destIntList, List<String> ruleList) {
            String res = "";
            
            //Put your code here
            for (Integer x : destIntList) {
                String ans = "none";
                for (String rule : ruleList) {
                    String name = rule.substring(0, rule.lastIndexOf(" :"));
                    String cond = rule.substring(rule.lastIndexOf(" :") + 3);
                    if (okOr(cond, x)) {
                        ans = name;
                        break;
                    }
                }
                if (res.length() > 0) {
                    res += ",";
                }
                res += ans;
            }
            System.out.println(res);
	}
    
    private boolean okOr(String cond, Integer x) {
        String[] ors = cond.trim().split("or");
        for (String or : ors) {
            if (okAnd(or, x)) {
                return true;
            }
        }
        return false;
    }

    private boolean okAnd(String cond, Integer x) {
        String[] ands = cond.trim().split("and");
        for (String and : ands) {
            if (!ok(and, x)) {
                return false;
            }
        }
        return true;
    }
    
    private boolean ok(String cond, Integer x) {
        cond = cond.trim();
        if (!cond.matches("a [=<>] \\d+"))while (true);
        
        Integer target = Integer.parseInt(cond.substring(4), 10);
        if (cond.charAt(2) == '=') {
            return x == target;
        } else if (cond.charAt(2) == '<') {
            return x < target;
        } else {
            return x > target;
        }
    }    


}
