import org.junit.jupiter.api.Test;

import java.util.AbstractCollection;
import java.util.HashSet;

import static org.junit.jupiter.api.Assertions.*;

public class TestGraph {
    @Test
    public void graphSizeEmpty(){
        Graph<String, Double> graph = new Graph<>(false, true);
        assertEquals(0, graph.numNodes());
        assertEquals(0, graph.numEdges());
    }

    @Test
    public void graphSizeOneElement(){
        Graph<String, Double> graph = new Graph<>(false, true);
        graph.addNode("Rosolini");
        assertEquals(1, graph.numNodes());
        assertEquals(0, graph.numEdges());
    }

    @Test
    public void graphSizeTwoElementsOneEdge(){
        Graph<String, Double> graph = new Graph<>(false, true);
        graph.addNode("Rosolini");
        graph.addNode("Ispica");
        graph.addEdge("Rosolini", "Ispica", 7.7);
        assertEquals(2, graph.numNodes());
        assertEquals(2, graph.numEdges()); // arco di andata e di ritorno
    }

    @Test
    public void graphSizeMoreElementsMoreEdges(){
        Graph<String, Double> graph = new Graph<>(false, true);
        graph.addNode("Rosolini");
        graph.addNode("Ispica");
        graph.addNode("Pozzallo");
        graph.addNode("Noto");
        graph.addEdge("Rosolini", "Ispica", 7.7);
        graph.addEdge("Rosolini", "Noto", 17.8);
        graph.addEdge("Ispica", "Pozzallo", 15.4);
        assertEquals(4, graph.numNodes());
        assertEquals(6, graph.numEdges()); // archi di andata e di ritorno
    }

    @Test
    public void graphUndirected(){
        Graph<String, Double> graph = new Graph<>(false, true);
        graph.addNode("Rosolini");
        graph.addNode("Ispica");
        graph.addNode("Pozzallo");
        graph.addNode("Noto");
        graph.addEdge("Rosolini", "Ispica", 7.7);
        graph.addEdge("Rosolini", "Noto", 17.8);
        graph.addEdge("Ispica", "Pozzallo", 15.4);
        assertTrue(graph.containsEdge("Rosolini", "Ispica"));
        assertTrue(graph.containsEdge("Ispica", "Rosolini"));
    }

    @Test
    public void graphDirected(){
        Graph<String, Double> graph = new Graph<>(true, true);
        graph.addNode("Rosolini");
        graph.addNode("Ispica");
        graph.addNode("Pozzallo");
        graph.addNode("Noto");
        graph.addEdge("Rosolini", "Ispica", 7.7);
        graph.addEdge("Rosolini", "Noto", 17.8);
        graph.addEdge("Ispica", "Pozzallo", 15.4);
        assertTrue(graph.containsEdge("Rosolini", "Ispica"));
        assertFalse(graph.containsEdge("Ispica", "Rosolini"));
    }

    @Test
    public void graphNodes(){
        Graph<String, Double> graph = new Graph<>(false, true);
        graph.addNode("Rosolini");
        graph.addNode("Ispica");
        graph.addNode("Pozzallo");
        graph.addNode("Noto");
        graph.addEdge("Rosolini", "Ispica", 7.7);
        graph.addEdge("Rosolini", "Noto", 17.8);
        graph.addEdge("Ispica", "Pozzallo", 15.4);

        AbstractCollection<String> nodes = graph.getNodes();

        assertTrue(graph.containsNode("Rosolini"));
        assertTrue(graph.containsNode("Ispica"));
        assertTrue(graph.containsNode("Pozzallo"));
        assertTrue(graph.containsNode("Noto"));
    }

    @Test
    public void graphEdges(){
        Graph<String, Double> graph = new Graph<>(false, true);
        graph.addNode("Rosolini");
        graph.addNode("Ispica");
        graph.addNode("Pozzallo");
        graph.addNode("Noto");
        graph.addEdge("Rosolini", "Ispica", 7.7);
        graph.addEdge("Rosolini", "Noto", 17.8);
        graph.addEdge("Ispica", "Pozzallo", 15.4);

        AbstractCollection<AbstractEdge<String, Double>> nodes = graph.getEdges();

        assertTrue(graph.containsEdge("Rosolini", "Ispica"));
        assertTrue(graph.containsEdge("Ispica", "Rosolini"));
        assertTrue(graph.containsEdge("Rosolini", "Noto"));
        assertTrue(graph.containsEdge("Noto", "Rosolini"));
        assertTrue(graph.containsEdge("Ispica", "Pozzallo"));
        assertTrue(graph.containsEdge("Pozzallo", "Ispica"));
    }

    @Test
    public void graphEdgesDirected(){
        Graph<String, Double> graph = new Graph<>(true, true);
        graph.addNode("Rosolini");
        graph.addNode("Ispica");
        graph.addNode("Pozzallo");
        graph.addNode("Noto");
        graph.addEdge("Rosolini", "Ispica", 7.7);
        graph.addEdge("Rosolini", "Noto", 17.8);
        graph.addEdge("Ispica", "Pozzallo", 15.4);

        AbstractCollection<AbstractEdge<String, Double>> nodes = graph.getEdges();

        assertTrue(graph.containsEdge("Rosolini", "Ispica"));
        assertFalse(graph.containsEdge("Ispica", "Rosolini"));
        assertTrue(graph.containsEdge("Rosolini", "Noto"));
        assertFalse(graph.containsEdge("Noto", "Rosolini"));
        assertTrue(graph.containsEdge("Ispica", "Pozzallo"));
        assertFalse(graph.containsEdge("Pozzallo", "Ispica"));
    }

    @Test
    public void graphLabel(){
        Graph<String, Double> graph = new Graph<>(false, true);
        graph.addNode("Rosolini");
        graph.addNode("Ispica");
        graph.addNode("Pozzallo");
        graph.addNode("Noto");
        graph.addEdge("Rosolini", "Ispica", 7.7);
        graph.addEdge("Rosolini", "Noto", 17.8);
        graph.addEdge("Ispica", "Pozzallo", 15.4);

        assertEquals(7.7, graph.getLabel("Rosolini", "Ispica"));
        assertEquals(7.7, graph.getLabel("Ispica", "Rosolini"));
        assertEquals(17.8, graph.getLabel("Rosolini", "Noto"));
        assertEquals(17.8, graph.getLabel("Noto", "Rosolini"));
        assertEquals(15.4, graph.getLabel("Pozzallo", "Ispica"));
        assertEquals(15.4, graph.getLabel("Ispica", "Pozzallo"));

        assertNull(graph.getLabel("Rosolini", "Pozzallo"));
        assertNull(graph.getLabel("Pozzallo", "Rosolini"));
        assertNull(graph.getLabel("Noto", "Pozzallo"));
        assertNull(graph.getLabel("Pozzallo", "Noto"));
        assertNull(graph.getLabel("Ispica", "Noto"));
        assertNull(graph.getLabel("Noto", "Ispica"));
        assertNull(graph.getLabel("Rosolini", "Enna"));
    }

    @Test
    public void graphLabelDirected(){
        Graph<String, Double> graph = new Graph<>(true, true);
        graph.addNode("Rosolini");
        graph.addNode("Ispica");
        graph.addNode("Pozzallo");
        graph.addNode("Noto");
        graph.addEdge("Rosolini", "Ispica", 7.7);
        graph.addEdge("Rosolini", "Noto", 17.8);
        graph.addEdge("Ispica", "Pozzallo", 15.4);

        assertEquals(7.7, graph.getLabel("Rosolini", "Ispica"));
        assertNull(graph.getLabel("Ispica", "Rosolini"));
        assertEquals(17.8, graph.getLabel("Rosolini", "Noto"));
        assertNull(graph.getLabel("Noto", "Rosolini"));
        assertNull(graph.getLabel("Pozzallo", "Ispica"));
        assertEquals(15.4, graph.getLabel("Ispica", "Pozzallo"));

        assertNull(graph.getLabel("Rosolini", "Pozzallo"));
        assertNull(graph.getLabel("Pozzallo", "Rosolini"));
        assertNull(graph.getLabel("Noto", "Pozzallo"));
        assertNull(graph.getLabel("Pozzallo", "Noto"));
        assertNull(graph.getLabel("Ispica", "Noto"));
        assertNull(graph.getLabel("Noto", "Ispica"));
        assertNull(graph.getLabel("Rosolini", "Enna"));
    }

    @Test
    public void graphNeighbours(){
        Graph<String, Double> graph = new Graph<>(false, true);
        graph.addNode("Rosolini");
        graph.addNode("Ispica");
        graph.addNode("Pozzallo");
        graph.addNode("Noto");
        graph.addEdge("Rosolini", "Ispica", 7.7);
        graph.addEdge("Rosolini", "Noto", 17.8);
        graph.addEdge("Ispica", "Pozzallo", 15.4);

        AbstractCollection<String> adj = graph.getNeighbours("Rosolini");
        assertTrue(adj.contains("Ispica"));
        assertTrue(adj.contains("Noto"));
        assertFalse(adj.contains("Pozzallo"));
    }

    @Test
    public void graphRemoveNode(){
        Graph<String, Double> graph = new Graph<>(false, true);
        graph.addNode("Rosolini");
        graph.addNode("Ispica");
        graph.addNode("Pozzallo");
        graph.addNode("Noto");
        graph.addEdge("Rosolini", "Ispica", 7.7);
        graph.addEdge("Rosolini", "Noto", 17.8);
        graph.addEdge("Ispica", "Pozzallo", 15.4);

        assertTrue(graph.removeNode("Rosolini"));
        assertFalse(graph.containsNode("Rosolini"));
        assertFalse(graph.containsEdge("Rosolini", "Ispica"));
        assertFalse(graph.containsEdge("Ispica", "Rosolini"));
        assertFalse(graph.containsEdge("Rosolini", "Noto"));
        assertFalse(graph.containsEdge("Noto", "Rosolini"));
    }

    @Test
    public void graphRemoveEdge(){
        Graph<String, Double> graph = new Graph<>(false, true);
        graph.addNode("Rosolini");
        graph.addNode("Ispica");
        graph.addNode("Pozzallo");
        graph.addNode("Noto");
        graph.addEdge("Rosolini", "Ispica", 7.7);
        graph.addEdge("Rosolini", "Noto", 17.8);
        graph.addEdge("Ispica", "Pozzallo", 15.4);

        assertTrue(graph.removeEdge("Rosolini", "Ispica"));
        assertFalse(graph.containsEdge("Rosolini", "Ispica"));
        assertFalse(graph.containsEdge("Ispica", "Rosolini"));
    }

    @Test
    public void graphRemoveEdgeDirected(){
        Graph<String, Double> graph = new Graph<>(true, true);
        graph.addNode("Rosolini");
        graph.addNode("Ispica");
        graph.addNode("Pozzallo");
        graph.addNode("Noto");
        graph.addEdge("Rosolini", "Ispica", 7.7);
        graph.addEdge("Rosolini", "Noto", 17.8);
        graph.addEdge("Ispica", "Pozzallo", 15.4);

        assertTrue(graph.removeEdge("Rosolini", "Ispica"));
        assertFalse(graph.containsEdge("Rosolini", "Ispica"));
        assertFalse(graph.containsEdge("Ispica", "Rosolini"));
    }

}
