import java.util.*;

public class Graph<V, L extends Comparable<L>> implements AbstractGraph<V, L>{
    private boolean directed;
    private boolean labelled;
    private AbstractCollection<V> nodes;
    private AbstractCollection<AbstractEdge<V, L>> edges;
    private Map<V, Set<Edge<V, L>>> adjacencyList;

    public Graph(boolean directed, boolean labelled) {
        this.directed = directed;
        this.labelled = labelled;
        this.nodes = new HashSet<>();
        this.edges = new HashSet<>();
        this.adjacencyList = new HashMap<>();
    }

    @Override
    public boolean isDirected() {
        return directed;
    }

    @Override
    public boolean isLabelled() {
        return labelled;
    }

    @Override
    public boolean addNode(V a) {
        return nodes.add(a);
    }

    @Override
    public boolean addEdge(V a, V b, L l) {
        if (!containsNode(a) || !containsNode(b))
            return false;

        Edge<V, L> edge = new Edge<>(a, b, l);
        edges.add(edge);
        adjacencyList.computeIfAbsent(a, k -> new HashSet<>()).add(edge);

        if (!directed) {
            Edge<V, L> reverseEdge = new Edge<>(b, a, l);
            edges.add(reverseEdge);
            adjacencyList.computeIfAbsent(b, k -> new HashSet<>()).add(reverseEdge);
        }

        return true;
    }

    @Override
    public boolean containsNode(V a) {
        return nodes.contains(a);
    }

    @Override
    public boolean containsEdge(V a, V b) {
        if (!containsNode(a) || !containsNode(b))
            return false;

        for (Edge<V, L> edge : adjacencyList.get(a)) {
            if (edge.getEnd().equals(b))
                return true;
        }
        return false;
    }

    @Override
    public boolean removeNode(V a) {
        if (!containsNode(a))
            return false;

        Set<Edge<V, L>> edgesToRemove = adjacencyList.getOrDefault(a, Collections.emptySet());
        for (Edge<V, L> edge : edgesToRemove) {
            V endNode = edge.getEnd();
            adjacencyList.get(endNode).removeIf(e -> e.getEnd().equals(a));
            edges.remove(edge);
        }
        adjacencyList.remove(a);
        nodes.remove(a);
        return true;
    }

    public Edge<V, L> findEdgeByNodes(V a, V b) {
        if (containsEdge(a, b)) {
            for (Edge<V, L> edge : adjacencyList.get(a)) {
                if (edge.getEnd().equals(b))
                    return edge;
            }
        }
        return null;
    }

    @Override
    public boolean removeEdge(V a, V b) {
        if (!containsEdge(a, b))
            return false;

        Edge<V, L> edgeToRemove = findEdgeByNodes(a, b);
        edges.remove(edgeToRemove);
        adjacencyList.get(a).remove(edgeToRemove);

        if (!directed) {
            Edge<V, L> reverseEdgeToRemove = findEdgeByNodes(b, a);
            edges.remove(reverseEdgeToRemove);
            adjacencyList.get(b).remove(reverseEdgeToRemove);
        }

        return true;
    }

    @Override
    public int numNodes() {
        return nodes.size();
    }

    @Override
    public int numEdges() {
        return edges.size();
    }

    @Override
    public AbstractCollection<V> getNodes() {
        return nodes;
    }

    @Override
    public AbstractCollection<AbstractEdge<V, L>> getEdges() {
        return edges;
    }

    @Override
    public AbstractCollection<V> getNeighbours(V a) {
        if (!containsNode(a))
            return null;

        AbstractCollection<V> neighbours = new HashSet<>();
        for (Edge<V, L> edge : adjacencyList.get(a)) {
            neighbours.add(edge.getEnd());
        }
        return neighbours;
    }

    @Override
    public L getLabel(V a, V b) {
        if (!containsNode(a) || !containsNode(b))
            return null;

        for (Edge<V, L> edge : adjacencyList.get(a)) {
            if (edge.getEnd().equals(b)) {
                return edge.getLabel();
            }
        }
        return null;
    }


}
