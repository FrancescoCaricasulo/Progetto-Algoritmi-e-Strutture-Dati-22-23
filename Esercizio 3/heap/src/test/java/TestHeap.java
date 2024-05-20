import org.testng.annotations.Test;

import java.util.Comparator;

import static org.junit.jupiter.api.Assertions.*;

public class TestHeap {

    Comparator<Integer> compar = new Comparator<Integer>() {
        @Override
        public int compare(Integer o1, Integer o2) {
            if(o1 > o2)
                return 1;
            else if (o1 < o2)
                return -1;
            else return 0;
        }
    };
    @Test
    public void extractMinOneElem() {
        Heap<Integer> heap = new Heap(compar);
        heap.insert(4);
        assertEquals(4, heap.extractMin());
    }

    @Test
    public void extractMinTwoElems() {
        Heap<Integer> heap = new Heap(compar);
        heap.insert(4);
        heap.insert(2);
        assertEquals(2, heap.extractMin());
    }

    @Test
    public void extractMinThreeElems() {
        Heap<Integer> heap = new Heap(compar);
        heap.insert(4);
        heap.insert(2);
        heap.insert(1);
        assertEquals(1, heap.extractMin());
    }

    @Test
    public void testInsert(){
        Heap heap = new Heap(compar);
        heap.insert(44);
        assertEquals(44, heap.extractMin()); // extraction of the element 44

        heap.insert(null);
        assertEquals(0, heap.getSize()); // insertion of a null element

        assertEquals(null, heap.extractMin()); // extraction from an empty heap
    }

    @Test
    public void testGetParent(){
        Heap heap = new Heap(compar);
        heap.insert(1);
        heap.insert(2);
        heap.insert(5);
        assertEquals(1, heap.getParent(1)); // get the parent of an element within the range
        assertEquals(1, heap.getParent(2)); // get the parent of an element within the range
        assertEquals(null, heap.getParent(3));  // get the parent of an element with an out of range index
        assertEquals(null, heap.getParent(-1)); // get the parent of an element with negative index
    }

    @Test
    public void testGetChild(){
        Heap heap = new Heap(compar);
        heap.insert(1);
        heap.insert(2);
        heap.insert(5);
        assertEquals(2, heap.getLeftChild(0)); // get the left child of an element within the range
        assertEquals(5, heap.getRightChild(0)); // get the right child of an element within the range
        assertEquals(null, heap.getLeftChild(3)); // get the left child of an element with an out of range index
        assertEquals(null, heap.getRightChild(3)); // get the right child of an element with an out of range index
        assertEquals(null, heap.getLeftChild(-1)); // get the right child of an element with negative index
        assertEquals(null, heap.getRightChild(-1)); // get the left child of an element with negative index
    }
}

