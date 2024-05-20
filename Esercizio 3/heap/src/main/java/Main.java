import java.util.Comparator;

public class Main {
    public static void main(String[] args) {
        Comparator<Integer> compar = new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return 0;
            }
        };

        Heap<Integer> heap = new Heap<>(compar);
        heap.insert(85);
        heap.insert(75);
        heap.insert(65);
        heap.insert(12);
        heap.insert(32);
        heap.insert(34);
        heap.insert(5);
        heap.insert(1);
        heap.insert(10);
        heap.insert(31);
        heap.insert(18);
        heap.insert(2);
        heap.insert(45);
        heap.insert(72);

        heap.printHeap();
        int m = heap.extractMin();
        heap.printHeap();
        System.out.println("max = " + m);
    }
}