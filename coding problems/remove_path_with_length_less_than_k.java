import java.util.LinkedList;
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
    public Node createNewNode(int val)
    {
        return new Node(val);
    }

    public void printNodes(Node root)
    {
        Queue<Node> q = new LinkedList<Node>();
    
        q.add(root);

        while(!q.isEmpty())
        {
            Node curr_node = q.remove();

            System.out.print(curr_node.data+" ");

            if(curr_node.left!=null)
            q.add(curr_node.left);

            if(curr_node.right!=null)
            q.add(curr_node.right);
        }

    }

    public Node remove_node(Node root,int k,int lvl)
    {
        if(root==null)
        return null;
        
        root.left = this.remove_node(root.left, k, lvl + 1);
        root.right = this.remove_node(root.right, k, lvl + 1);

        if(root.left==null && root.right==null && lvl<k)
        return null;

        return root;
    }


}
public class remove_path_with_length_less_than_k
{
    public static void main(String[] args) 
    {
        BinaryTree tree = new BinaryTree();

        Node root = tree.createNewNode(2);
        root.left = tree.createNewNode(7);
        root.right = tree.createNewNode(9);
        root.left.left = tree.createNewNode(2);
        root.left.right = tree.createNewNode(6);
        root.left.right.right = tree.createNewNode(11);   

        System.out.print("tree before removing nodes : ");
        tree.printNodes(root);

        root = tree.remove_node(root,3,0);

        System.out.println("\n");
        System.out.print("tree after removing nodes : ");
        tree.printNodes(root);

        System.out.println("\n");
    }    
}