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
    int maxsum=0;

    public Node createNewNode(int val)
    {
        return new Node(val);
    }

    public void maxSum(Node root,int k,int sum)
    {
        if(root==null)
        return;

        if(root.left==null && root.right==null && sum + root.data > this.maxsum)
        {
            this.maxsum = sum + root.data;
            return; 
        }

        this.maxSum(root.left, k,sum + root.data);
        this.maxSum(root.right, k, sum + root.data);
    }

}

public class max_sum_path
{
    public static void main(String[] args) 
    {
        BinaryTree tree = new BinaryTree();

        Node root = tree.createNewNode(1);
        root.left = tree.createNewNode(7);
        root.right = tree.createNewNode(-3);
        root.left.left = tree.createNewNode(-5);
        root.right.left = tree.createNewNode(4);

        tree.maxSum(root,-1,0);

        System.out.print("\nsum: " + tree.maxsum + "\n");
        
    }    

}
