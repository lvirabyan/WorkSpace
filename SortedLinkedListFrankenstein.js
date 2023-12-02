class Node {
    constructor(data) {
        this.desc = null;
        this.prev = null;
        this.data = data;
        this.next = null;
        this.asc = null;
    }
}

class List {
    constructor() {
        this.head = null;
        this.tail = null;
        this.descH = null;
        this.ascH = null;
    }
    pushback(data) {
        if (this.head === null) {
            this.head = new Node(data);
            this.tail = this.head;
            this.ascH = this.head;
            this.descH = this.head;
        } else {

            this.tail.next = new Node(data);
            this.tail.next.prev = this.tail;
            this.tail = this.tail.next;
            this.ascDesc(this.tail, data);
        }
    }

    ascDesc(node, data) {
        let tmp;
        if (node.prev.prev === null) {
            console.log(node.data, '1');
            console.log(node.prev.data, '1');
            if (node.data > node.prev.data) {
                node.desc = node.prev;
                node.desc.asc = node;
            } else {
                node.asc = node.prev;
                node.asc.desc = node;
                this.descH = node;
            }
        } else if (node.prev.data > node.data) {
            console.log(node.data, '2');
            console.log(node.prev.data, "2");
            tmp = node.prev;
            while (tmp.desc !== null && tmp.desc.data > node.data) {
                tmp = tmp.desc;
            }
            if (tmp.desc !== null) {
                tmp.desc.asc = node;
                tmp.desc.asc.asc = tmp;
                tmp.desc.asc.desc = tmp.desc;
                tmp.desc = node;
            } else {
                tmp.desc = node;
                node.asc = tmp;
                if(this.descH.data > node.data) {
                    this.descH = tmp.desc;
                }
            }
        } else {
            console.log(node.data, '3');
            console.log(node.prev.data);
            tmp = node.prev;
            while (tmp.asc !== null && tmp.asc.data < node.data) {
                tmp = tmp.asc;
            }
            if (tmp.asc !== null) {
                tmp.asc.desc = node;
                tmp.asc.desc.desc = tmp;
                tmp.asc.desc.asc = tmp.asc;
                tmp.asc = node;
            } else {
                tmp.asc = node;
                this.ascH = node;
                node.desc = tmp;
            }
        }
    }

        print() {
        let tmp = this.head;
        let str = '';
        while (tmp) {
            str += tmp.data + ' ';
            tmp = tmp.next;
        }
        return str;
    }

    printAscDesc() {
        let str = '';
        let tmp = this.descH;
        while (tmp) {
            // console.log(tmp.asc);
            str += tmp.data + ' ';
            tmp = tmp.asc;
        }
        return str;
    }

}

let list = new List();
list.pushback(9);
list.pushback(6);
list.pushback(-41);
list.pushback(3);
list.pushback(1004);
list.pushback(629);
list.pushback(10);

console.log(list.printAscDesc());
