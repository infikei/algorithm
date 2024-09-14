import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class shortest_path_dijkstra_2 {

    static class Node {
        int to, weight;
        Node next;

        public Node(int to, int weight, Node next) {
            this.to = to;
            this.weight = weight;
            this.next = next;
        }
    }

    static final int INF = 1_000_000_000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int v = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine(), " ");
        int begin = Integer.parseInt(st.nextToken());
        int end = Integer.parseInt(st.nextToken());

        Node[] adjList = new Node[v + 1];
        int[] minDist = new int[v + 1];
        boolean[] visited = new boolean[v + 1];

        for (int i = 0; i < e; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());
            adjList[from] = new Node(to, weight, adjList[from]);
        }

        for (int u = 1; u <= v; u++) {
            minDist[u] = INF;
        }

        minDist[begin] = 0;

        for (int i = 0; i < v; i++) {
            int curMinDist = INF;
            int curVertex = -1;

            for (int u = 1; u <= v; u++) {
                if (!visited[u] && curMinDist > minDist[u]) {
                    curMinDist = minDist[u];
                    curVertex = u;
                }
            }

            if (curVertex == -1) break;

            visited[curVertex] = true;

            if (curVertex == end) break;

            for (Node tmp = adjList[curVertex]; tmp != null; tmp = tmp.next) {
                if (minDist[tmp.to] > curMinDist + tmp.weight) {
                    minDist[tmp.to] = curMinDist + tmp.weight;
                }
            }
        }

        System.out.printf("Dist from %d to %d : %d%n", begin, end, minDist[end] == INF ? -1 : minDist[end]);
        br.close();
    }

}
