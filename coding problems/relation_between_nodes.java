import java.util.Queue;
import java.util.ArrayList;
import java.util.LinkedList;

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
    Node createNewNode(int val)
    {
        return new Node(val);
    }

    void printTree(Node root)
    {
        Queue<Node> q = new LinkedList<Node>();

        q.add(root);

        System.out.println("\ntree :");
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

    boolean find(ArrayList<Integer> arr, int val)
    {
        for (Integer i : arr)
        {
            if(i == val) return true;
        }

        return false;
    }

    void printCousins(Node root,int element)
    {   
        if(root==null) return;

        Queue<Node> q = new LinkedList<Node>();
        int found = 0,val = Integer.MIN_VALUE;

        q.add(root);

        while(q.size()!=0)
        {
            int size = q.size();
            ArrayList<Integer> arr = new ArrayList<Integer>();

            for(int i=0;i<size;i++)
            {
                Node curr_node = q.remove();

                arr.add(curr_node.data);

                if(curr_node.data == element)
                {
                    found = 1;
                    val = curr_node.data;
                }

                if(curr_node.left!=null) q.add(curr_node.left);
                if(curr_node.right!=null) q.add(curr_node.right);
            }

            if(found == 1 && arr.size()>1)
            {
                System.out.print("\ncousins of " + val + ":\t");
                for(int i=0;i<arr.size();i++)
                {
                    if(arr.get(i)!=val) System.out.print(arr.get(i) + " ");
                }
                System.out.println("\n");

                return;
            }

            if(found == 1) 
            {
                System.out.println("\ncousins don't exist for "+ val + "\n");
                return ;
            }
        }

        System.out.println("\nelement not found !! \n");
    }


}


public class relation_between_nodes 
{
    public static void main(String[] args) 
    {
        BinaryTree tree = new BinaryTree();

        Node root = tree.createNewNode(1);
        root.left = tree.createNewNode(2);
        root.right = tree.createNewNode(3);
        root.left.left = tree.createNewNode(4);
        root.right.right = tree.createNewNode(5);
        root.right.left = tree.createNewNode(6);

        tree.printTree(root);

        tree.printCousins(root, 3);
    }    
}
