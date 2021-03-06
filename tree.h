class Tree {
 public:
  Tree() {
    dag_ = std::make_unique<DirectedAcyclicGraph>();
  }
  Tree(const Tree& tree) noexcept {
    if (tree.dag_.get()) {
      dag_ = std::make_unique<DirectedAcyclicGraph>(*(tree.dag_.get()));
    }
  } 
  bool add(const Vertex* u) {
    if (get_adjacency_list().size() > 0) {
      // Only allowed to add when the tree is empty.
      return false;
    }
    return dag_.get()->add(u);
  }
  bool add_edge(const Vertex* source, const Vertex* dest) {
    return dag_.get()->add_edge(source, dest);
  }
  bool add_edge(const Edge* edge) {
    return dag_.get()->add_edge(edge);
  }
  vector<Edge> get_adjacency_list() {
    return dag_.get()->get_adjacency_list();
  }
  bool are_adjacent(const Vertex* u, const Vertex* v) {
    return dag_.get()->are_adjacent(u, v);
  }
  int edge_count() {
    return dag_.get()->edge_count();
  }
  vector<Vertex*> get_neighbors(Vertex* u) {
    return dag_.get()->get_neighbors(u);
  }
  void remove(const Vertex* u) {
    dag_.get()->remove(u);
  }
  Vertex* top() {
    return dag_.get()->top();
  }
  int vertex_count() {
    return dag_.get()->vertex_count();
  }
  string to_string() {
    return dag_.get()->to_string();
  }

 private:
  unique_ptr<DirectedAcyclicGraph> dag_;
};
