import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Node
{
    int data;
    Node left;
    Node right;


    Node(int val)
    {
        this.data = val;
        this.left = this.right = null;
    }
}

class BinaryTree
{
    List<Integer> list = new ArrayList<Integer>();
    int index = 0;

    Node createNewNode(int val)
    {
        return new Node(val);
    }

    void serialize(Node root)
    {
        if(root==null)
        {
            list.add(-1);
            return;
        }
    
        list.add(root.data);
        this.serialize(root.left);
        this.serialize(root.right);
    }

    Node deserialize()
    {
        if(this.list.get(index)==-1)
        {
            index++;
            return null;
        }

        Node newNode = createNewNode(this.list.get(index++));
        newNode.left = deserialize();
        newNode.right = deserialize();

        return newNode;
    }

    void printList()
    {
        System.out.println(" ");
        for (int i : list) System.out.print(i +" ");
        System.out.println(" ");
    }

    void printTree(Node root)
    {
        Queue<Node> q = new LinkedList<Node>();

        q.add(root);

        while(q.size()!=0)
        {
            int curr_size = q.size();

            System.out.println("");

            for(int i=0;i<curr_size;i++)
            {
                Node curr_node = q.remove();

                System.out.print(curr_node.data + " ");

                if(curr_node.left!=null) q.add(curr_node.left);
                if(curr_node.right!=null) q.add(curr_node.right);
            }

            System.out.println("");
        }
    }

    boolean checkTreeEquality(Node root1,Node root2)
    {
        if(root1==null && root2==null) return true;

        if(root1==null || root2==null) return false;

        return root1.data == root2.data && checkTreeEquality(root1.left, root2.left) && checkTreeEquality(root1.right, root2.right);
    }
}

public class serialize_deserialize_tree 
{
    public static void main(String[] args) 
    {
        BinaryTree tree = new BinaryTree();

        Node root = tree.createNewNode(2);
        root.left = tree.createNewNode(7);
        root.right = tree.createNewNode(9);
        root.left.left = tree.createNewNode(10);
        root.left.right = tree.createNewNode(6);
        root.right.right = tree.createNewNode(3);

        tree.serialize(root);

        tree.printList();

        // set tree.index = 0 every time desrialize is called
        Node deserialized_root = tree.deserialize();

        tree.printTree(deserialized_root);

        System.out.println("\nde-serialized tree and original tree same ? : " + tree.checkTreeEquality(root, deserialized_root));
    }
}