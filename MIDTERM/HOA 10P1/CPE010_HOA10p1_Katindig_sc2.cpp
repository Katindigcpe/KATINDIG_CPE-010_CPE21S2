#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

// Structure for an edge
template <typename T>
struct Edge {
    size_t src;
    size_t dest;
    T weight;

    bool operator<(const Edge<T>& e) const {
        return this->weight < e.weight;
    }

    bool operator>(const Edge<T>& e) const {
        return this->weight > e.weight;
    }
};

// Graph class
template <typename T>
class Graph {
public:

    // Initialize graph with N vertices
    Graph(size_t N) : V(N) {}

    // Return number of vertices
    auto vertices() const {
        return V;
    }

    // Return all edges
    auto edges() const {
        return edge_list;
    }

    // Add an edge
    void add_edge(const Edge<T>& e) {
        if (e.src >= 1 && e.src <= V &&
            e.dest >= 1 && e.dest <= V) {
            edge_list.push_back(e);
        }
        else {
            cerr << "Vertex out of bounds" << endl;
        }
    }

    // Return all outgoing edges from a vertex
    auto outgoing_edges(size_t v) const {
        vector<Edge<T>> edges_from_v;

        for (auto &e : edge_list) {
            if (e.src == v) {
                edges_from_v.push_back(e);
            }
        }

        return edges_from_v;
    }

private:
    size_t V;
    vector<Edge<T>> edge_list;
};

// Display graph
template <typename T>
ostream& operator<<(ostream& os, const Graph<T>& G) {

    for (auto i = 1; i < G.vertices(); i++) {
        os << i << ":\t";

        auto edges = G.outgoing_edges(i);

        for (auto &e : edges) {
            os << "(" << e.dest << ": " << e.weight << "), ";
        }

        os << endl;
    }

    return os;
};

// Create reference graph
template <typename T>
auto create_reference_graph() {

    Graph<T> G(9);

    map<unsigned, vector<pair<size_t, T>>> edges;

    edges[1] = {{2, 0}, {5, 0}};
    edges[2] = {{1, 0}, {7, 0}, {4, 0}};
    edges[3] = {{4, 0}};
    edges[4] = {{2, 0}, {3, 0}, {5, 0}, {6, 0}, {8, 0}};
    edges[5] = {{1, 0}, {2, 0}, {4, 0}, {8, 0}};
    edges[6] = {{4, 0}, {7, 0}};
    edges[7] = {{3, 0}, {6, 0}};
    edges[8] = {{4, 0}, {5, 0}, {6, 0}};

    for (auto &i : edges) {
        for (auto &j : i.second) {
            G.add_edge(Edge<T>{i.first, j.first, j.second});
        }
    }

    return G;
}

// B.1 Depth-First Search
template <typename T>
auto depth_first_search(const Graph<T>& G, size_t dest) {

    stack<size_t> stack;
    vector<size_t> visit_order;
    set<size_t> visited;

    stack.push(1);

    while (!stack.empty()) {

        auto current_vertex = stack.top();
        stack.pop();

        if (visited.find(current_vertex) == visited.end()) {

            visited.insert(current_vertex);
            visit_order.push_back(current_vertex);

            for (auto &e : G.outgoing_edges(current_vertex)) {

                if (visited.find(e.dest) == visited.end()) {
                    stack.push(e.dest);
                }
            }
        }
    }

    return visit_order;
}

// B.2 Breadth-First Search
template <typename T>
auto breadth_first_search(const Graph<T>& G, size_t dest) {

    queue<size_t> queue;
    vector<size_t> visit_order;
    set<size_t> visited;

    queue.push(1);

    while (!queue.empty()) {

        auto current_vertex = queue.front();
        queue.pop();

        if (visited.find(current_vertex) == visited.end()) {

            visited.insert(current_vertex);
            visit_order.push_back(current_vertex);

            for (auto &e : G.outgoing_edges(current_vertex)) {

                if (visited.find(e.dest) == visited.end()) {
                    queue.push(e.dest);
                }
            }
        }
    }

    return visit_order;
}

// Test DFS
template <typename T>
void test_DFS() {

    auto G = create_reference_graph<unsigned>();

    cout << G << endl;

    cout << "DFS Order of vertices: " << endl;

    auto dfs_visit_order = depth_first_search(G, 1);

    for (auto v : dfs_visit_order) {
        cout << v << " ";
    }

    cout << endl;
}

// Test BFS
template <typename T>
void test_BFS() {

    auto G = create_reference_graph<unsigned>();

    cout << G << endl;

    cout << "BFS Order of vertices: " << endl;

    auto bfs_visit_order = breadth_first_search(G, 1);

    for (auto v : bfs_visit_order) {
        cout << v << " ";
    }

    cout << endl;
}

int main() {

    cout << "B.1 Depth-First Search" << endl;
    test_DFS<unsigned>();

    cout << "\nB.2 Breadth-First Search" << endl;
    test_BFS<unsigned>();

    return 0;
}