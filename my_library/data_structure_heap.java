import java.io.IOException;
import java.util.Comparator;

public class data_structure_heap {

    static class PqMinTop {
        private int[] heap;
        private int heapEnd;

        PqMinTop(int capacity) {
            heap = new int[capacity + 1];
            heapEnd = 1;
        }

        boolean isEmpty() {
            return heapEnd == 1;
        }

        int size() {
            return heapEnd - 1;
        }

        void push(int x) {
            int curNode = heapEnd++;
            int curParent = curNode / 2;

            while (curParent >= 1 && heap[curParent] > x) {
                heap[curNode] = heap[curParent];
                curNode = curParent;
                curParent /= 2;
            }

            heap[curNode] = x;
        }

        int pop() {
            if (isEmpty()) return 0;

            int valueReturn = heap[1];
            int valueMove = heap[--heapEnd];
            int curNode = 1;
            int curChild = 2;

            while (curChild < heapEnd) {
                if (curChild + 1 < heapEnd && heap[curChild] > heap[curChild + 1]) {
                    curChild++;
                }

                if (valueMove <= heap[curChild]) break;

                heap[curNode] = heap[curChild];
                curNode = curChild;
                curChild *= 2;
            }

            heap[curNode] = valueMove;
            return valueReturn;
        }

        int top() {
            return isEmpty() ? 0 : heap[1];
        }
    }

    static class PqMaxTop {
        private int[] heap;
        private int heapEnd;

        PqMaxTop(int capacity) {
            heap = new int[capacity + 1];
            heapEnd = 1;
        }

        boolean isEmpty() {
            return heapEnd == 1;
        }

        int size() {
            return heapEnd - 1;
        }

        void push(int x) {
            int curNode = heapEnd++;
            int curParent = curNode / 2;

            while (curParent >= 1 && heap[curParent] < x) {
                heap[curNode] = heap[curParent];
                curNode = curParent;
                curParent /= 2;
            }

            heap[curNode] = x;
        }

        int pop() {
            if (isEmpty()) return 0;

            int valueReturn = heap[1];
            int valueMove = heap[--heapEnd];
            int curNode = 1;
            int curChild = 2;

            while (curChild < heapEnd) {
                if (curChild + 1 < heapEnd && heap[curChild] < heap[curChild + 1]) {
                    curChild++;
                }

                if (valueMove >= heap[curChild]) break;

                heap[curNode] = heap[curChild];
                curNode = curChild;
                curChild *= 2;
            }

            heap[curNode] = valueMove;
            return valueReturn;
        }

        int top() {
            return isEmpty() ? 0 : heap[1];
        }
    }

    static class PqCustomTop {
        private int[] heap;
        private int heapEnd;
        private final Comparator<Integer> comparator;

        PqCustomTop(int capacity, Comparator<Integer> comparator) {
            heap = new int[capacity + 1];
            heapEnd = 1;
            this.comparator = comparator;
        }

        boolean isEmpty() {
            return heapEnd == 1;
        }

        int size() {
            return heapEnd - 1;
        }

        void push(int x) {
            int curNode = heapEnd++;
            int curParent = curNode / 2;

            while (curParent >= 1 && comparator.compare(heap[curParent], x) > 0) {
                heap[curNode] = heap[curParent];
                curNode = curParent;
                curParent /= 2;
            }

            heap[curNode] = x;
        }

        int pop() {
            if (isEmpty()) return 0;

            int valueReturn = heap[1];
            int valueMove = heap[--heapEnd];
            int curNode = 1;
            int curChild = 2;

            while (curChild < heapEnd) {
                if (curChild + 1 < heapEnd && comparator.compare(heap[curChild], heap[curChild + 1]) > 0) {
                    curChild++;
                }

                if (comparator.compare(valueMove, heap[curChild]) <= 0) break;

                heap[curNode] = heap[curChild];
                curNode = curChild;
                curChild *= 2;
            }

            heap[curNode] = valueMove;
            return valueReturn;
        }

        int top() {
            return isEmpty() ? 0 : heap[1];
        }
    }

    static void pqMinTopTest() {
        System.out.println("===== pqMinTopTest Begin =====");
        PqMinTop pqMinTop = new PqMinTop(10);

        System.out.println("top : " + pqMinTop.top());
        pqMinTop.push(3);
        System.out.println("top : " + pqMinTop.top());
        pqMinTop.push(1);
        System.out.println("top : " + pqMinTop.top());
        pqMinTop.push(5);
        System.out.println("top : " + pqMinTop.top());

        System.out.println("pop : " + pqMinTop.pop());
        System.out.println("pop : " + pqMinTop.pop());
        System.out.println("pop : " + pqMinTop.pop());
        System.out.println("pop : " + pqMinTop.pop());
        System.out.println();
    }

    static void pqMaxTopTest() {
        System.out.println("===== pqMaxTopTest Begin =====");
        PqMaxTop pqMaxTop = new PqMaxTop(10);

        System.out.println("top : " + pqMaxTop.top());
        pqMaxTop.push(3);
        System.out.println("top : " + pqMaxTop.top());
        pqMaxTop.push(1);
        System.out.println("top : " + pqMaxTop.top());
        pqMaxTop.push(5);
        System.out.println("top : " + pqMaxTop.top());

        System.out.println("pop : " + pqMaxTop.pop());
        System.out.println("pop : " + pqMaxTop.pop());
        System.out.println("pop : " + pqMaxTop.pop());
        System.out.println("pop : " + pqMaxTop.pop());
        System.out.println();
    }

    static void pqAbsMinTopTest() {
        System.out.println("===== pqAbsMinTopTest Begin =====");
        PqCustomTop pqAbsMinTop = new PqCustomTop(10, new Comparator<Integer>() {

            @Override
            public int compare(Integer o1, Integer o2) {
                if (Math.abs(o1) != Math.abs(o2)) return Math.abs(o1) - Math.abs(o2);
                return o1 - o2;
            }

        });

        System.out.println("top : " + pqAbsMinTop.top());
        pqAbsMinTop.push(-3);
        System.out.println("top : " + pqAbsMinTop.top());
        pqAbsMinTop.push(2);
        System.out.println("top : " + pqAbsMinTop.top());
        pqAbsMinTop.push(-2);
        System.out.println("top : " + pqAbsMinTop.top());
        pqAbsMinTop.push(-5);
        System.out.println("top : " + pqAbsMinTop.top());
        pqAbsMinTop.push(0);
        System.out.println("top : " + pqAbsMinTop.top());

        System.out.println("pop : " + pqAbsMinTop.pop());
        System.out.println("pop : " + pqAbsMinTop.pop());
        System.out.println("pop : " + pqAbsMinTop.pop());
        System.out.println("pop : " + pqAbsMinTop.pop());
        System.out.println("pop : " + pqAbsMinTop.pop());
        System.out.println("pop : " + pqAbsMinTop.pop());
        System.out.println();
    }

    public static void main(String[] args) throws IOException {
        pqMinTopTest();
        pqMaxTopTest();
        pqAbsMinTopTest();
    }

}
