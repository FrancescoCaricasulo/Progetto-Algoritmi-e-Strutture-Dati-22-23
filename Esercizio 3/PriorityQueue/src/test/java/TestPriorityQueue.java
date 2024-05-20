import org.junit.jupiter.api.Test;

import java.util.Comparator;

import static org.junit.jupiter.api.Assertions.*;
public class TestPriorityQueue {
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
    public void emptyOnEmptyQueue(){
        PriorityQueue<Integer> pq = new PriorityQueue<>(compar);
        assertTrue(pq.empty());
    }

    @Test
    public void emptyOnNotEmptyQueue(){
        PriorityQueue<Integer> pq = new PriorityQueue<>(compar);
        pq.push(10);
        assertFalse(pq.empty());
    }

    @Test
    public void addOneElement(){
        PriorityQueue<Integer> pq = new PriorityQueue<>(compar);
        pq.push(10);
        assertEquals(pq.top(), 10);
    }

    @Test
    public void addThreeElementsTestingTop(){
        PriorityQueue<Integer> pq = new PriorityQueue<>(compar);
        pq.push(10);
        pq.push(8);
        pq.push(11);
        assertEquals(pq.top(),8);
    }

    @Test
    public void addThreeElementsTestingPop(){
        PriorityQueue<Integer> pq = new PriorityQueue<>(compar);
        pq.push(10);
        pq.push(8);
        pq.push(11);
        assertEquals(pq.top(),8);
        pq.pop();
        assertEquals(pq.top(), 10);
    }
}
