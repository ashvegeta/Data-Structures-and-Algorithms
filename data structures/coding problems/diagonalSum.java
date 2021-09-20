import java.util.Queue;
import java.util.LinkedList;

class Node
{
    int data;
    Node left;
    Node right;

    Node(int val)
    {
        this.data = val;
        this.left = null;
        this.right = null;
    }
}

class BinaryTree
{
    public Node createNewNode(int val)
    {
        Node newNode = new Node(val);
        return newNode;
    }

    public void diagSum(Node root)
    {
        Queue<Node> q = new LinkedList<Node>();

        q.add(root);

        while(!q.isEmpty())
        {
            int size = q.size();
            int sum_diag = 0;

            while(size > 0) // itertae through the current queue
            {
                Node curr_node = q.remove();

                while(curr_node!=null)
                {
                    sum_diag = sum_diag + curr_node.data;
                    
                    if(curr_node.left!=null)
                    q.add(curr_node.left);

                    curr_node = curr_node.right;
                }

                size--;
            }

            System.out.println(sum_diag);
        }
    }
}

public class diagonalSum
{
    public static void main(String[] args) 
    {
        BinaryTree tree = new BinaryTree();

        Node root = tree.createNewNode(1);
        root.left = tree.createNewNode(2);
        root.right = tree.createNewNode(3);
        root.left.left = tree.createNewNode(4);
        root.left.right = tree.createNewNode(5);
        root.right.left = tree.createNewNode(6);   
        root.right.right = tree.createNewNode(7);
        root.right.left.right = tree.createNewNode(8);

        tree.diagSum(root);
    }
}
