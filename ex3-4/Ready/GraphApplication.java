import java.io.*;
import java.util.*;

public class GraphApplication {
    static Comparator<Edge<String, Double>> compar = new Comparator<>() {
        public int compare(Edge<String, Double> o1, Edge<String, Double> o2) {
            return o1.getLabel().compareTo(o2.getLabel());
        }
    };

    public static Graph<String, Double> minimumSpanningTreePrim(Graph<String, Double> graph, String source){
        if(!graph.containsNode(source))
            return null; /* The vertex is not present */
        else{
            /* Minimum Spanning Tree */
            Graph<String, Double> result = new Graph<>(false, true);

            /* Set of visited Vertexes */
            HashSet<String> visited = new HashSet<>();
            PriorityQueue<Edge<String, Double>> queue = new PriorityQueue<>(compar);

            /* Visiting the source (source) */
            for(String v : graph.getNeighbours(source)){
                Double l = graph.getLabel(source, v);
                queue.push(new Edge<String, Double>(source, v, l));
            }

            /* Source (source passed) is visited */
            result.addNode(source);
            result.addEdge(source, source,0.0);

            visited.add(source);

            while(result.numNodes() < graph.numNodes() && !queue.empty()){
                Edge<String, Double> minEdge = queue.top();
                while(visited.contains(minEdge.getEnd()) && !queue.empty()){
                    queue.pop();
                    minEdge = queue.top();

                    /* If minEdge is null priority queue is empty */
                    if(minEdge == null){
                        break;
                    }
                }
                if(queue.empty()){
                    /* If priority queue is empty all vertexes are visited */
                    break;
                }

                result.addNode(minEdge.getEnd());
                result.addEdge(minEdge.getStart(), minEdge.getEnd(), minEdge.getLabel());
                queue.pop();

                /* Visiting minEdge */
                for(String v : graph.getNeighbours(minEdge.getEnd())){
                    if(!result.containsNode(v)) {
                        Double l = graph.getLabel(minEdge.getEnd(), v);
                        queue.push(new Edge<>(minEdge.getEnd(), v, l));
                    }
                }
                /* minEdge.getEnd() is visited */
                visited.add(minEdge.getEnd());
            }

            return result;
        }
    }

    public static void main(String[] args) {
        Graph<String, Double> graph = new Graph<>(false, true);

        try {
            BufferedReader br = new BufferedReader(new FileReader(args[1]));
            String line;

            while ((line = br.readLine()) != null) {
                String[] split = line.split(",");
                graph.addNode(split[0]);
                graph.addNode(split[1]);
                graph.addEdge(split[0], split[1], Double.parseDouble(split[2]));
            }
            br.close();
        } catch (FileNotFoundException notFound) {
            System.out.println("File not found: " + notFound);
            System.exit(0);
        } catch (IOException reading) {
            System.out.println("Cannot read the file: " + reading);
            System.exit(0);
        }
        System.out.println("All loaded!\n");
        System.out.println("Graph's size " + graph.numNodes());

        long startTime = System.nanoTime();
        Graph<String, Double> prim = minimumSpanningTreePrim(graph, "rosolini");
        long stopTime = System.nanoTime();
        System.out.println(stopTime - startTime);
        System.out.println("Graph's size after Prim execution: " + prim.numNodes());

        Double sum = 0.0;
        for(AbstractEdge<String, Double> e : prim.getEdges()){
                sum += e.getLabel();
        }

        System.out.format("Total weight of minimum spanning tree: %.2f\n", sum/2000);

        Comparator<Edge<String, Double>> comparator = new Comparator<Edge<String, Double>>() {
            @Override
            public int compare(Edge<String, Double> o1, Edge<String, Double> o2) {
                return o1.getLabel().compareTo(o2.getLabel());
            }
        };

        try {
            String fileOutput = args[1].substring(0, args[1].length() - 4) + "_output.csv";
            FileWriter outputWriter = new FileWriter(fileOutput);

            for (AbstractEdge<String, Double> e : prim.getEdges()) {
                outputWriter.write(e.toString() + "\n");
            }

            outputWriter.close();
            System.out.println("Successfully wrote to the file.");
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }
}
