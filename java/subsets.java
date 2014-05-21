import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;
import java.io.File;


public class Subsets {
	
	private HashMap<Integer, HashSet<ArrayList<Integer>>> globmap = null;
	
	// Thought
    // first solution came to mind: just use the first Problem 61 code
    // but add all possible subsets to a HashSet which not allowed duplicate set
    // finally create a ArrayList set by using the hashset
    
    public ArrayList<ArrayList<Integer>> subsetsWithDup(int[] num) {
    	if(num == null) return null;
        globmap = new HashMap<Integer, HashSet<ArrayList<Integer>>>();
        
        // sort the set
        for(int i = 1; i < num.length; i++) {
            int k = i;
            for(int j = i-1; j>=0; j--) 
                if(num[k] < num[j]) {
                    // swap
                    int tmp = num[k];
                    num[k] = num[j];
                    num[j] = tmp;
                    k = j;
                } else break;
        }
        
        // initialize p(0) = {{num[0]}}
        HashSet<ArrayList<Integer>> res1 = new HashSet<ArrayList<Integer>>();
        ArrayList<Integer> res2 = new ArrayList<Integer>();
        res2.add(num[0]);
        res1.add(res2);
        globmap.put(0, res1);
        res1 = calc(num.length-1, num);
        res1.add(new ArrayList<Integer>());
        
        return new ArrayList<ArrayList<Integer>>(res1);
    }
    
    // calculate for a subarray with end position 'end'
    private HashSet<ArrayList<Integer>> calc(int end, int[] num) {
    	HashSet<ArrayList<Integer>> result = new HashSet<ArrayList<Integer>>();
        if(end == 0) return globmap.get(end);
        // add {num[end]}
        ArrayList<Integer> res1 = new ArrayList<Integer>();
        res1.add(num[end]);
        result.add(res1);
        // add p(end-1) and {num[end] V p(end-1)}
        HashSet<ArrayList<Integer>> res2 = globmap.get(end-1);
        if(res2 == null) {
            res2 = calc(end-1, num);
            globmap.put(end-1, res2);
        }
        for(ArrayList<Integer> alist : res2) {
            ArrayList<Integer> alist1 = new ArrayList<Integer>(alist);
            alist1.add(num[end]);
            result.add(alist);
            result.add(alist1);
        }
        return result;
    }
    
    public static void main(String[] args) {
        Subsets subset = new Subsets();
        Scanner scanner = null;
        try {
            scanner = new Scanner(new File(args[0]));
        }catch(Exception e) {
            
        }
        int[] num = null;
        boolean first = true;
        int size = 0;
        int i = 0;
        while(scanner.hasNextInt())
        {
            if(first) {
                first = false;
                size = scanner.nextInt();
                num = new int[size];
            } else
            num[i++] = scanner.nextInt();
        }
        for(ArrayList<Integer> oneres : subset.subsetsWithDup(num)) {
            System.out.print("[");
            for(i = 0; i < oneres.size(); i++)
                if(i != oneres.size() - 1)
                    System.out.print(oneres.get(i) + ",");
                else
                    System.out.print(oneres.get(i));
            System.out.println("],");
        }
    }

}
