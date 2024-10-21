import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {
    static class Node{
        int x,y;

        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PriorityQueue<Node> pq = new PriorityQueue<>(new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                if(o1.x == o2.x){
                    return o1.y-o2.y;
                }else{
                    return o1.x-o2.x;
                }
            }
        });

        int n = Integer.parseInt(br.readLine());
        StringTokenizer st;
        for(int i=0; i<n; i++){
            st= new StringTokenizer(br.readLine());
            pq.offer(new Node(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken())));
        }

        Stack<Node> stack = new Stack<>();
        stack.push(pq.poll());
        while(!pq.isEmpty()){
            Node poll = pq.poll();
            Node peek = stack.peek();
            if(peek.y <= poll.x) stack.push(poll);
        }
        if(n == stack.size()) {
            System.out.println(1);
        }
        else {
            System.out.println(n-stack.size()+1);
        }
    }
}