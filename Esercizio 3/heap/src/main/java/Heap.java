import java.util.ArrayList;
import java.util.Comparator;

public class Heap<T> {
    private Comparator<T> compar;
    private ArrayList<T> heap;

    public Heap(Comparator<T> compar){
        this.compar = compar;
        heap = new ArrayList<>();
    }

    public T getParent(int i){
        if(i < 0 || i >= heap.size()){
            return null;
        }
        int p = (i - 1) / 2;
        return heap.get(p);
    }

    public T getLeftChild(int i){
        if(i < 0 || i >= heap.size()){
            return null;
        }

        int l = (i * 2) + 1;
        if(l < heap.size())
            return heap.get(l);
        else return null;
    }

    public T getRightChild(int i){
        if(i < 0 || i >= heap.size()){
            return null;
        }

        int r = (i * 2) + 2;
        if(r < heap.size())
            return heap.get(r);
        else return null;
    }

    public T getElem(int i){
        if(i < 0 || i >= heap.size()){
            return null;
        }

        if(i < heap.size())
            return heap.get(i);
        else return null;
    }

    public boolean insert(T elem){
        if(elem == null){
            return false;
        }
        heap.add(elem);
        int indexOfAddedElem = heap.indexOf(elem);
        while(indexOfAddedElem > 0 && (compar.compare(getElem(indexOfAddedElem), getParent(indexOfAddedElem)) < 0)){
            T added = getElem(indexOfAddedElem);
            T parent = getParent(indexOfAddedElem);

            /* Scambio tra l'elemento aggiunto e il padre */
            heap.set(indexOfAddedElem, parent);
            heap.set(heap.indexOf(getParent(indexOfAddedElem)), added);

            /* L'indice dell'elemento aggiunto cambia ed è quello di suo padre (attuale indice dell'elemento aggiunto) */
            indexOfAddedElem = heap.indexOf(getParent(indexOfAddedElem));
        }
        return true;
    }

    public void printHeap(){
        System.out.println(heap);
    }

    public T extractMin(){
        if(heap.size() == 0){
            return null;
        }
        T min = heap.get(0);
        heap.set(0, getElem(heap.size() - 1));
        heap.remove(heap.size() - 1);
        heapify(0);

        return min;
    }

    public void heapify(int i){
        /* Pre-condizione: i sotto alberi sinistro e destro a partire dall'indice i sono degli heap */
        if(i >= heap.size()){
            // System.out.println("Can't do heapify from a index that does not exist or heapify is empty");
            return;
        }

        T startElem = heap.get(i);
        T left = getLeftChild(i);
        T right = getRightChild(i);

        T min = min(startElem, left, right);

        if(compar.compare(min, startElem) != 0){ // l'elemento max è figlio di qualche nodo ed è maggiore anche dal padre, va sostituito col padre
            int indexOfP = heap.indexOf(startElem);
            int indexOfC = heap.indexOf(min);

            heap.set(indexOfP, min);
            heap.set(indexOfC, startElem);

            heapify(indexOfC);
        }
    }

    public int getSize(){
        return heap.size();
    }

    private T min(T p, T l, T r){
        /* Pre-condizione: p non è nullo */
        if(l == null && r == null){
            return p;
        }else{
            if(l != null) {
                if (compar.compare(p, l) < 0) {
                    if (r == null) {
                        return p;
                    } else {
                        if (compar.compare(p, r) < 0) {
                            return p;
                        } else return r;
                    }
                } else {
                    if (r == null) {
                        return l;
                    } else {
                        if (compar.compare(l, r) < 0) {
                            return l;
                        } else return r;
                    }
                }
            }else{
                if (compar.compare(p, r) < 0) {
                    return p;
                } else return r;
            }
        }
    }
}