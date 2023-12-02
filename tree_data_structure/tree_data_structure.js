class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.rigth = null;
    }
}
class BSL {
  constructor() {
    this.root = null;
  }
  insert(val) {
    if (this.root === null) {
      this.root = new Node(val);
      return;
    }
    this.add(this.root, val);
  }
  add(node, val) {
    if (node.data < val) {
      if (node.rigth) {
        return this.add(node.rigth, val);
      } else {
        node.rigth = new Node(val);
      }
    } else {
      if (node.left) {
        return this.add(node.left, val);
      } else {
        node.left = new Node(val);
      }
    }
  }
  search(val) {
    if (this.root === null) {
      console.log(null);
      return null;
    }
    this.searchA(this.root, val);
  }
  searchA(node, val) {
    if (!node) {
      console.log("null");
      return;
    }
    if (node.data === val) {
      console.log(node);
      return node;
    } else if (node.data < val) {
      return this.searchA(node.rigth, val);
    } else {
      return this.searchA(node.left, val);
    }
  }
  delete(data) {
    this.root = this.deleteA(this.root, data);
  }
  deleteA(node, data) {
    if (!node) {
      return null;
    }
    if (node.data > data) {
      node.left = this.deleteA(node.left, data);
      return node;
    }
    if (node.data < data) {
      node.rigth = this.deleteA(node.rigth, data);
      return node;
    } else {
      if (!node.left && !node.rigth) {
        node = null;
        return node;
      } else if (!node.rigth) {
        node = node.left;
        return node;
      } else if (!node.left) {
        node = node.rigth;
        return node;
      } else {
        let tmp = this.findMin(node.rigth);
        node.data = tmp.data;
        node.rigth = this.deleteA(node.rigth, node.data);
        return node;
      }
    }
  }
  findmax(node) {
    if (!node.rigth) {
      return node;
    }
    return this.findmax(node.rigth);
  }
  findMin(node) {
    if (!node.left) {
      return node;
    }
    return this.findMin(node.left);
  }
  prev_order_traversal(node) {
    if (!node) {
      return;
    }
    console.log(node.data);
    this.prev_order_traversal(node.left);
    this.prev_order_traversal(node.rigth);
  }
  post_order_traversal(node) {
    if (!node) {
      return;
    }
    this.post_order_traversal(node.left);
    this.post_order_traversal(node.rigth);
    console.log(node.data);
  }
  in_order_traversal(node) {
    if (!node) {
      return;
    }
    this.in_order_traversal(node.left);
    console.log(node.data);
    this.in_order_traversal(node.rigth);
  }
  print(){
    this.in_order_traversal(this.root);
    // this.prev_order_traversal(this.root);
    // this.post_order_traversal(this.root);
  }
}
let vertex = new BSL();
vertex.insert(15);
vertex.insert(89);
vertex.insert(2);
vertex.insert(13);
vertex.insert(1);
vertex.insert(22);
vertex.insert(66);
vertex.delete(15);
vertex.print();