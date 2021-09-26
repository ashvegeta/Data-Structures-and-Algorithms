import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

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

    public Node remove_node(Node root,int k,int sum)
    {
        if(root==null)
        return null;

        if(root.left==null && root.right==null)
            return sum + root.data >= k ? root : null;
        
        root.left = remove_node(root.left, k, sum  + root.data);
        root.right = remove_node(root.right, k, sum + root.data);
        
        return root.left==null && root.right==null ? null : root;
    }

}

public class remove_path_with_sum_less_than_k 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);

        BinaryTree tree = new BinaryTree();

        Node root = tree.createNewNode(1);
        root.left = tree.createNewNode(2);
        root.right = tree.createNewNode(-3);
        root.left.left = tree.createNewNode(-5);
        root.right.left = tree.createNewNode(4);


        System.out.print("enter limit: ");
        int k = sc.nextInt();

        System.out.print("\ntree before removing nodes : ");
        tree.printNodes(root);

        root = tree.remove_node(root,k,0);

        System.out.print("\ntree after removing nodes : ");

        try
        {
            tree.printNodes(root);
        }
        catch(NullPointerException e)
        {
            System.out.print(" root node is empty");
        }
    
        System.out.println("\n");

        sc.close();
        
    }    

}
