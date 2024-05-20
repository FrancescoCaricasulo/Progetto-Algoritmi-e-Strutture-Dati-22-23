import java.util.Comparator;

public class PriorityQueue<E extends Comparable<E>> implements AbstractQueue<E> {
    Heap<E> minHeap;

    public PriorityQueue(Comparator<E> compar){
        minHeap = new Heap<>(compar);
    }

    @Override
    public boolean empty() {
        if(minHeap.getSize() == 0)
            return true;
        else return false;
    }

    @Override
    public boolean push(E e) {
        return minHeap.insert(e);
    }

    @Override
    public E top() {
        if(minHeap.getSize() > 0){
            return minHeap.getElem(0);
        }else return null;
    }

    @Override
    public void pop() {
        minHeap.extractMin();
    }
}
